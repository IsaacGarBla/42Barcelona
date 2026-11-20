from __future__ import annotations
from collections import defaultdict, deque
from typing import NamedTuple
import sys


# Defines a type
class HubTime(NamedTuple):
    hub:    str
    time:   int
    in_out: str     # Values 'IN' or 'OUT'


class Path(NamedTuple):
    hubs:           list[HubTime]
    bottleneck:     int


class Edge:
    _to:        HubTime
    _capacity:  int
    _flow:      int
    _reverse:   Edge
    _priority:  bool

    def __init__(self, to: HubTime, capacity: int,
                 priority: bool = False) -> None:
        self._to = to
        self._capacity = capacity
        self._flow = 0
        self._priority = priority

    @property
    def to(self) -> HubTime:
        return self._to

    @property
    def capacity(self) -> int:
        return self._capacity

    @property
    def flow(self) -> int:
        return self._flow

    @flow.setter
    def flow(self, value: int) -> None:
        self._flow = value

    @property
    def reverse(self) -> 'Edge':
        return self._reverse

    @reverse.setter
    def reverse(self, value: 'Edge') -> None:
        self._reverse = value

    @property
    def priority(self) -> bool:
        return self._priority

    @priority.setter
    def priority(self, value: bool) -> None:
        self._priority = value

    @property
    def residual_capacity(self) -> int:
        return self._capacity - self._flow


class FlowGraph:
    _graph: dict[HubTime, list[Edge]]
    _turns: int

    def __init__(self):
        self._graph = defaultdict(list)
        self._turns = 0

    @property
    def flow_graph(self) -> dict[HubTime, list[Edge]]:
        return self._graph

    @property
    def turns(self) -> int:
        return self._turns

    @turns.setter
    def turns(self, value: int) -> None:
        self._turns = value

    def add_edge(self, source: HubTime,
                 target: HubTime, capacity: int, priority: bool = False):

        forw:   Edge = Edge(target, capacity, priority)
        back:   Edge = Edge(source, 0, priority)

        forw.reverse = back
        back.reverse = forw

        # Check if the Edge doesn't exists yet.
        if not any(
                edge.to == target
                for edge in self._graph[source]
        ):
            self._graph[source].append(forw)
            self._graph[target].append(back)

    def neighbors(self,
                  source: HubTime) -> list[Edge]:
        return self._graph.get(source, [])

    def hubs(self) -> list[HubTime]:
        return list(self._graph.keys())

    def dump(self) -> None:
        for source, edges in self._graph.items():
            for edge in edges:
                print(f"{source} -> {edge.to} "
                      f"(cap={edge.capacity})")

    def _construct_path(self,
                        parents: dict[HubTime, tuple[HubTime, Edge]],
                        source: HubTime,
                        target: HubTime) -> Path:
        path:         list[HubTime] = []
        current:        HubTime = target
        bottle_neck:    int = sys.maxsize

        while current != source and current in parents:
            path.append(current)
            parent, edge = parents[current]
            bottle_neck = min(bottle_neck, edge.residual_capacity)
            current = parent
        if current == source:
            path.append(source)
            path.reverse()
            return Path(path, bottle_neck)
        return Path([], 0)

    def _BFS(self, source: HubTime, target: HubTime) -> \
            None | dict[HubTime, tuple[HubTime, Edge]]:
        stack:          deque = deque()
        current_hub:    HubTime
        next_hub:       HubTime
        parents:        dict[HubTime, tuple[HubTime, Edge]] = {}
        visited:        set[HubTime] = set()
        priority_neig:  list[Edge]

        stack.append(source)
        visited.add(source)
        while stack:
            current_hub = stack.popleft()

            if current_hub == target:
                return parents
            priority_neig = sorted(self.neighbors(current_hub),
                                   key=lambda e:
                                   e.priority is False)
            for edge in priority_neig:

                if edge.residual_capacity <= 0:
                    # Edge satured.
                    continue
                next_hub = edge.to
                if next_hub not in visited:
                    visited.add(next_hub)
                    parents[next_hub] = (current_hub, edge)
                    stack.append(next_hub)
        return None

    def find_path(self, source: HubTime, target: HubTime) -> \
            None | Path:
        parents:    dict[HubTime, tuple[HubTime, Edge]] | None

        parents = self._BFS(source, target)
        if parents is not None:
            return self._construct_path(parents, source, target)
        return None

    def flow(self, path: list[HubTime], flow: int) -> None:
        for i in range(0, len(path) - 1):
            for edge in self._graph[path[i]]:
                if edge.to == path[i + 1]:
                    edge.flow += flow
                    edge.reverse.flow -= flow
                    break

    def reset_flow(self) -> None:
        for list_edges in self._graph.values():
            for edge in list_edges:
                edge.flow = 0
