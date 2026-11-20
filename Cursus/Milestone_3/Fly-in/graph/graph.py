from common import (Coordinate, Colour, ZoneType, MAX_TRAVEL_TIME)
from errors import GraphException
from flow_graph import FlowGraph, HubTime, Path
from typing import Final, NamedTuple
import sys
from collections import deque

# Defines start and end  HubTime
START_HUBTIME: Final[HubTime] = HubTime("## START ##", -1, "OUT")
END_HUBTIME: Final[HubTime] = HubTime("## END ##", -1, "IN")


# Defines a type
class Solution(NamedTuple):
    paths:  list[Path]
    steps:  int


class Connection:
    _capacity:  int
    _occupacy:  int

    def __init__(self, max_cap: int = 1, occupacy: int = 0) -> None:
        self._capacity = max_cap
        self._occupacy = occupacy

    @property
    def capacity(self) -> int:
        return self._capacity

    @capacity.setter
    def capacity(self, value: int) -> None:
        self._capacity = value

    @property
    def occupacy(self) -> int:
        return self._occupacy

    @occupacy.setter
    def occupacy(self, value: int) -> None:
        self._occupacy = value


class Hub:
    _name:          str
    _position:      Coordinate
    _zone_type:     ZoneType
    _colour:        Colour
    _capacity:      int
    _neighbors:     dict[str, Connection]
    _occupacy:      int

    def dump(self) -> None:
        print(f"Name: {self._name}")
        print(f"Position: {self._position.x} {self._position.y}")
        print(f"Zone type: {self._zone_type}")
        print(f"Colour: {self._colour}")
        print(f"Capacity: {self._capacity}")
        print(f"Occupacy: {self._occupacy}")
        print("  ====== NEIGHBORS =========")
        for node, con in self._neighbors.items():
            print(F"  {node}, max drones {con.capacity}")

    def __init__(self, name: str, position: Coordinate,
                 zone: ZoneType,
                 capacity: int,
                 colour: Colour) -> None:
        self._name = name
        self._position = position
        self._zone_type = zone
        self._colour = colour
        self._capacity = capacity
        self._occupacy = 0
        self._neighbors = {}

    @property
    def name(self) -> str:
        return self._name

    @property
    def position(self) -> Coordinate:
        return self._position

    @property
    def zone_type(self) -> ZoneType:
        return self._zone_type

    @property
    def colour(self) -> Colour:
        return self._colour

    @property
    def capacity(self) -> int:
        return self._capacity

    @property
    def neighbors(self) -> dict[str, Connection]:
        return self._neighbors

    def is_connected(self, neighbor_name: str) -> bool:
        return neighbor_name in self.neighbors

    def add_connection(self, neighbor_name: str, conn: Connection) -> None:

        """ Adds a node as neighbor.
            Args:
                neighbor: the node to add as a neighbor.
                link_capacity: the maximun number of drons
                that can be travelling between nodes.

            Returns:
                None.
        """
        if self.is_connected(neighbor_name):
            raise GraphException(f"[GRAPH ERROR 1 - Adding-connection] Connetion between"
                                 f" {self.name} and {neighbor_name} can't be "
                                 f"added because it already exists.")
            return False
        self.neighbors[neighbor_name] = conn


class Graph:
    _nb_drones:     int
    _start_hub:     str
    _end_hub:       str
    _hubs:          dict[str, Hub]
    _flow_graph:    FlowGraph

    def _exists_connection(self, node1_name: str, node2_name: str) -> bool:
        """ Checks if there is already a connections beetwen two nodes.
            Args:
                node_name1: the name of first node.
                node_name2: the name of the second node.
            Returns:
                True if already exist a connection between the nodes.
                False otherwise.
        """
        return (node2_name in self._hubs[node1_name].neighbors or
                node1_name in self._hubs[node2_name].neighbors)

    def _exists_node(self, node_name: str) -> bool:
        """ Checks if there is already a node with the same name.
            Args:
                node_name: the name of the node.
            Returns:
                True if already exist a node with this name.
                False otherwise.
        """
        return node_name in self._hubs

    def dump(self) -> None:
        print("=========================================")
        print(f"Number of drones: {self._nb_drones}\n")
        print(f"Start hub : {self.start_hub}")
        print(f"End hub : {self.end_hub}\n")
        print("================= HUBS ==================")
        for hub_name, hub in self._hubs.items():
            if hub_name not in (self._start_hub, self._end_hub):
                hub.dump()

    def __init__(self) -> None:
        self._nb_drones = 0
        self._start_hub = ""
        self._end_hub = ""
        self._hubs = {}

    @property
    def nb_drones(self) -> int:
        return self._nb_drones

    @nb_drones.setter
    def nb_drones(self, value: int) -> None:
        if value < 0:
            raise GraphException("[GRAPH ERROR 2 - Drone number] The number of "
                                 "drones can't be negative.")
        self._nb_drones = value

    @property
    def start_hub(self) -> str:
        return self._start_hub

    @start_hub.setter
    def start_hub(self, start_hub: str) -> None:
        if self._exists_node(start_hub):
            self._start_hub = start_hub
            self._hubs[start_hub]._zone_type = ZoneType.INI
            self._hubs[start_hub]._capacity = self._nb_drones
        else:
            raise GraphException(f"[GRAPH ERROR 3 - Start-hub] Node {start_hub} "
                                 f"can't be added as start hub because "
                                 f"it doesn't exist in the graph.")

    @property
    def end_hub(self) -> str:
        return self._end_hub

    @end_hub.setter
    def end_hub(self, end_hub: str) -> None:
        if self._exists_node(end_hub):
            self._end_hub = end_hub
            self._hubs[end_hub]._zone_type = ZoneType.END
            self._hubs[end_hub]._capacity = self.nb_drones
        else:
            raise GraphException(f"[GRAPH ERROR 4 - End-hub] Node {end_hub} "
                                 f"can't be added as end hub because "
                                 f"it doesn't exist in the graph.")

    def add_hub(self, new_hub: Hub) -> None:
        """ Adds a hub to the graph.
            Args:
                new_node: the node to add.

                Throws a Graph exception if there is already a hub
                with the same name.
            Returns:
                None.
        """
        if self._exists_node(new_hub.name):
            raise GraphException(f"[GRAPH ERROR 5 - Adding-hub] Node {new_hub.name} "
                                 f"can't be added because there is already "
                                 f"a node with de samen name.")
        self._hubs[new_hub.name] = new_hub

    def add_connection(self, node1_name: str,
                       node2_name: str,
                       capacity: int = 1, occupacy: int = 0) -> None:
        conn:   Connection = Connection(capacity, occupacy)

        """ Adds a connection between nodes.
            Args:
                node1_name: the name of the first node.
                node2_name: the name of the second node.
                capacity: the maximun capacity of de link.

                Throws a Graph exception if one of the hubs
                doesn't exist or the connectios exists.
            Returns:
                None.
        """
        if node1_name not in self._hubs:
            raise GraphException(f"[GRAPH ERROR 6 - Adding-connection] Node {node1_name}"
                                 f" doesn-t exist in the graph.")
        if node2_name not in self._hubs:
            raise GraphException(f"[GRAPH ERROR 6 - Adding-connection] Node {node2_name}"
                                 f" doesn-t exist in the graph.")
        if self._exists_connection(node1_name, node2_name):
            raise GraphException(f"[GRAPH ERROR 7 - Adding-connection] Connetion between"
                                 f" {node1_name} and {node2_name} can't be "
                                 f"added because it already exists.")
        self._hubs[node1_name].add_connection(node2_name, conn)
        self._hubs[node2_name].add_connection(node1_name, conn)

    """
    def _create_flowgraph(self, nb_turns: int) -> FlowGraph:
        f_graph:        FlowGraph = FlowGraph()
        neighbor:       Hub
        travel_turns:   int

        f_graph.add_edge(START_HUBTIME,
                         (self.start_hub, 0),
                         self._hubs[self.start_hub].capacity)

        for t in range(nb_turns + 1):
            f_graph.add_edge((self.end_hub, t),
                             END_HUBTIME,
                             self.nb_drones)

        for hub in self._hubs.values():

            # Skip blocked zones.
            if hub.zone_type == ZoneType.BLOCKED:
                continue

            for t in range(nb_turns):
                # Wait at the same hub
                f_graph.add_edge((hub.name, t),
                                 (hub.name, t + 1),
                                 hub.capacity)
                # Go to neighbors
                for neighbor_name, conn in hub.neighbors.items():
                    neighbor = self._hubs[neighbor_name]

                    # Skip blocked zones.
                    if neighbor.zone_type == ZoneType.BLOCKED:
                        continue

                    travel_turns = (
                        MAX_TRAVEL_TIME
                        if neighbor.zone_type == ZoneType.RESTRICTED
                        else 1)
                    # Skip if total turs its bigger than
                    # the number of the turns we are trying.
                    if t + travel_turns > nb_turns:
                        continue

                    f_graph.add_edge((hub.name, t),
                                     (neighbor_name, t + travel_turns),
                                     conn.capacity)
        return f_graph
        """

    def _create_flowgraph_new(self, nb_turns: int) -> FlowGraph:
        self._flow_graph:   FlowGraph = FlowGraph()
        neighbor:           Hub
        travel_turns:       int

        self._flow_graph.turns = nb_turns

        self._flow_graph.add_edge(START_HUBTIME,
                                  HubTime(self.start_hub, 0, "IN"),
                                  self._hubs[self.start_hub].capacity)

        for t in range(nb_turns + 1):
            self._flow_graph.add_edge(HubTime(self.end_hub, t, "IN"),
                                      END_HUBTIME,
                                      self.nb_drones)

        for hub in self._hubs.values():
            # Skip blocked zones.
            if hub.zone_type == ZoneType.BLOCKED:
                continue

            for t in range(nb_turns + 1):
                # Split HUBS for capacity control.
                self._flow_graph.add_edge(HubTime(hub.name, t, "IN"),
                                          HubTime(hub.name, t, "OUT"),
                                          hub.capacity,
                                          hub.zone_type == ZoneType.PRIORITY)

            for t in range(nb_turns):
                # Wait at the same hub
                self._flow_graph.add_edge(HubTime(hub.name, t, "OUT"),
                                          HubTime(hub.name, t + 1, "IN"),
                                          sys.maxsize,
                                          hub.zone_type == ZoneType.PRIORITY)
                # Go to neighbors
                for neighbor_name, conn in hub.neighbors.items():
                    neighbor = self._hubs[neighbor_name]

                    # Skip blocked zones.
                    if neighbor.zone_type == ZoneType.BLOCKED:
                        continue

                    travel_turns = (
                        MAX_TRAVEL_TIME
                        if neighbor.zone_type == ZoneType.RESTRICTED
                        else 1)
                    # Skip if total turs its bigger than
                    # the number of the turns we are trying.
                    if t + travel_turns > nb_turns:
                        continue

                    self._flow_graph.add_edge(HubTime(hub.name, t, "OUT"),
                                              HubTime(neighbor_name, t +
                                                      travel_turns,
                                                      "IN"),
                                              conn.capacity,
                                              neighbor.zone_type ==
                                              ZoneType.PRIORITY)
        return self._flow_graph

    def _extend_flow_graph(self, nb_turns: int) -> FlowGraph:

        for t in range(max(0, self._flow_graph.turns + 1), nb_turns + 1):
            self._flow_graph.add_edge(HubTime(self.end_hub, t, "IN"),
                                      END_HUBTIME,
                                      self.nb_drones)

        for hub in self._hubs.values():
            # Skip blocked zones.
            if hub.zone_type == ZoneType.BLOCKED:
                continue

            for t in range(max(0, self._flow_graph.turns + 1), nb_turns + 1):
                # Split HUBS for capacity control.
                self._flow_graph.add_edge(HubTime(hub.name, t, "IN"),
                                          HubTime(hub.name, t, "OUT"),
                                          hub.capacity)

            for t in range(max(0,
                               self._flow_graph.turns - MAX_TRAVEL_TIME + 1),
                           nb_turns):

                # Wait at the same hub
                self._flow_graph.add_edge(HubTime(hub.name, t, "OUT"),
                                          HubTime(hub.name, t + 1, "IN"),
                                          sys.maxsize)
                # Go to neighbors
                for neighbor_name, conn in hub.neighbors.items():
                    neighbor = self._hubs[neighbor_name]

                    # Skip blocked zones.
                    if neighbor.zone_type == ZoneType.BLOCKED:
                        continue

                    travel_turns = (
                        MAX_TRAVEL_TIME
                        if neighbor.zone_type == ZoneType.RESTRICTED
                        else 1)
                    # Skip if total turs its bigger than
                    # the number of the turns we are trying.
                    if t + travel_turns > nb_turns:
                        continue

                    self._flow_graph.add_edge(HubTime(hub.name, t, "OUT"),
                                              HubTime(neighbor_name,
                                                      t + travel_turns,
                                              "IN"),
                                              conn.capacity)
        self._flow_graph.turns = nb_turns
        return self._flow_graph

    def _solve_current_flowgraph(self) -> None | list[Path]:
        solution:           list[Path]
        path:               None | tuple[list[HubTime], int]
        total_flow:         int = 0

        solution = []
        self._flow_graph.reset_flow()
        while True:
            path = self._flow_graph.find_path(START_HUBTIME, END_HUBTIME)
            if path is None:
                break
            self._flow_graph.flow(path.hubs, path.bottleneck)
            total_flow += path.bottleneck
            solution.append(path)
        if total_flow >= self.nb_drones:
            return (solution)
        return None

    def has_solution(self) -> bool:
        stack:          deque = deque()
        current_hub:    str
        next_hub:       str
        visited:        set[str] = set()

        stack.append(self.start_hub)
        visited.add(self.start_hub)
        while stack:
            current_hub = stack.popleft()

            if current_hub == self.end_hub:
                return True
            for hub, conn in self._hubs[current_hub].neighbors.items():
                if conn.capacity <= 0 or self._hubs[hub].capacity <= 0:
                    continue
                next_hub = hub
                if next_hub not in visited:
                    visited.add(next_hub)
                    stack.append(next_hub)
        return False

    def find_solution(self) -> Solution:
        solution:           list[Path] | None = None
        turns:              int = 1
        max_turns:          int = len(self._hubs) * self._nb_drones * 2

        if not self.has_solution():
            raise GraphException("[GRAPH ERROR 8 - Solving] The grapf is insoluble")
        self._create_flowgraph_new(turns)
        solution = self._solve_current_flowgraph()
        while solution is None and turns <= max_turns:
            turns += 1
            self._extend_flow_graph(turns)
            solution = self._solve_current_flowgraph()
        if solution is None:
            raise GraphException(f"[GRAPH ERROR 9 - Solving] Maxim number of turns ({max_turns})"
                                 "reached without finding a solution")
        return Solution(solution, turns)
