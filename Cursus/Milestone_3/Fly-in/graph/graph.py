from common import Coordinate, Colour, ZoneType
from errors import GraphException


class Connection:
    _capacity:  int
    _occupacy:      int

    def __init__(self, max_cap: int = 1, occupacy: int = 0) -> None:
        self._capacity = max_cap
        self._occupacy = occupacy

    @property
    def capacity(self) -> int:
        return self._capacity

    @property
    def occupacy(self) -> int:
        return self._occupacy

    @occupacy.setter
    def occupacy(self, value: int) -> None:
        self._occupacy = value


class Node:
    _name:          str
    _position:      Coordinate
    _zone_type:     ZoneType
    _colour:        Colour
    _capacity:      int
    _neighbors:     dict[str, Connection]
    _occupacy:      int

    def __init__(self, name: str, position: Coordinate,
                 zone: ZoneType = ZoneType.NORMAL.value,
                 colour: Colour = Colour.BLUE.value,
                 capacity: int = 1) -> None:
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

    def add_connection(self, neighbor_name: str, link_capacity: int = 1,
                       occupacy: int = 0) -> bool:
        """ Adds a node as neighbor.
            Args:
                neighbor: the node to add as a neighbor.
                link_capacity: the maximun number of drons
                that can be travelling between nodes.
            Returns:
                True if the node could be added as neighbor.
                False if the node already exists as neighbor.
        """
        if self.is_connected(neighbor_name):
            return False
        self.neighbors[neighbor_name] = Connection(link_capacity)
        return True


class Graph:
    _start_hub:     str
    _end_hub:       str
    _hubs:          dict[str, Node]

    def __init__(self) -> None:
        self._start_hub = ""
        self._end_hub = ""
        self._hubs = {}

    @property
    def start_hub(self) -> str:
        return self._start_hub

    @start_hub.setter
    def start_hub(self, start_hub: str) -> None:
        if self._exists_node(start_hub):
            self._start_hub = start_hub
            self._hubs[start_hub].zone_type = (
                ZoneType.INI.value
            )
        else:
            raise GraphException(f"[ERROR Start-hub] Node {start_hub} "
                                 f"can't be added as start hub because "
                                 f"it doesn't exist in the graph.")

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

    def add_node(self, new_node: Node) -> bool:
        """ Adds a node to the graph.
            Args:
                new_node: the node to add.
            Returns:
                True if the node could be added as neighbor.
                False if there is a node with the same name in the graph.
        """
        if self._exists_node(new_node.name):
            return False
        self._hubs[new_node.name] = new_node
        return True

    def add_connection(self, node1_name: str,
                       node2_name: str,
                       capacity: int = 1, occupacy: int = 0) -> bool:
        """ Adds a connection between nodes.
            Args:
                node1_name: the name of the first node.
                node2_name: the name of the second node.
                capacity: the maximun capacity of de link.
            Returns:
                True if the node could be added as neighbor.
                False if node1_name or node2_name don't exist or there
                is aready a connection between these nodes.
        """
        if (node1_name not in self._hubs or node2_name not in self._hubs or
                self._exists_connection(node1_name, node2_name)):
            return False
        self._hubs[node1_name].add_connection(node2_name, capacity, occupacy)
        return True
