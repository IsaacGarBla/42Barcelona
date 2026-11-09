from common import Coordinate, Colour, ZoneType
from errors import GraphException


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

    def _print(self) -> None:
        print(f"Name: {self._name}")
        print(f"Position: {self._position.x} {self._position.y}")
        print(f"Zone type: {self._zone_type}")
        print(f"Colour: {self._colour}")
        print(f"Capacity: {self._capacity}")
        print(f"Occupacy: {self._occupacy}")
        print("====== NEIGHBORS =========")
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
            raise GraphException(f"[ERROR Adding-connection] Connetion between"
                                 f" {self.name} and {neighbor_name} can't be "
                                 f"added because it already exists.")
            return False
        self.neighbors[neighbor_name] = conn


class Graph:
    _nb_drones:     int
    _start_hub:     str
    _end_hub:       str
    _hubs:          dict[str, Hub]

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

    def _print(self) -> None:
        print("=========================================")
        print(f"Number of drones: {self._nb_drones}\n")
        print(f"Start hub : {self.start_hub}")
        print(f"End hub : {self.end_hub}\n")
        print("================= HUBS ==================")
        for hub_name, hub in self._hubs.items():
            if hub_name not in (self._start_hub, self._end_hub):
                hub._print()

    def _capacities_for_work(self) -> dict[tuple[str, str], int]:
        """
            Creates a dict with the capacity of each connection
            for working while we are finding paths.

            Return:
                A dictionary:
                    key: (hub1 , hub2)
                    value: capacity
        """
        result: dict[tuple[str, str], int] = {}

        for hub_ini, hub in self._hubs.items():
            for hub_fin, conn in hub.neighbors.items():
                result[(hub_ini, hub_fin)] = conn.capacity
        return result

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
            raise GraphException("[ERROR drone number] The number of "
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
        else:
            raise GraphException(f"[ERROR Start-hub] Node {start_hub} "
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
        else:
            raise GraphException(f"[ERROR End-hub] Node {end_hub} "
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
            raise GraphException(f"[ERROR Adding-hub] Node {new_hub.name} "
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
            raise GraphException(f"[ERROR Adding-connection] Node {node1_name}"
                                 f" doesn-t exist in the graph.")
        if node2_name not in self._hubs:
            raise GraphException(f"[ERROR Adding-connection] Node {node2_name}"
                                 f" doesn-t exist in the graph.")
        if self._exists_connection(node1_name, node2_name):
            raise GraphException(f"[ERROR Adding-connection] Connetion between"
                                 f" {node1_name} and {node2_name} can't be "
                                 f"added because it already exists.")
        self._hubs[node1_name].add_connection(node2_name, conn)
        self._hubs[node2_name].add_connection(node1_name, conn)
