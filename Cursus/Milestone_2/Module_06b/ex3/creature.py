from abc import ABC, abstractmethod


class Creature(ABC):
    _name: str
    _type: str

    def __init__(self, name: str, type: str) -> None:
        self._name = name
        self._type = type

    @abstractmethod
    def attack(self) -> str:
        pass

    def describe(self) -> str:
        return f"{self._name} is a {self._type}."

    @property
    def name(self) -> str:
        return self._name

    @property
    def type(self) -> str:
        return self._type


class Flameling(Creature):
    def __init__(self) -> None:
        super().__init__("Flameling", "Fire type Creature")

    def attack(self) -> str:
        return f"{self._name} uses Ember!"


class Pyrodon(Creature):
    def __init__(self) -> None:
        super().__init__("Pyrodon", "Fire/Flying type Creature")

    def attack(self) -> str:
        return f"{self._name} uses Flamethrower!"


class TransformCapability(ABC):
    _transformed_state: str

    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Shiftling(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal type Creature")
        self._transformed_state = "attacks normally."

    def attack(self) -> str:
        return f"{self._name} {self._transformed_state}"

    def transform(self) -> str:
        self._transformed_state = "performs a boosted strike!"
        return f"{self._name} shifts into a sharper form!"

    def revert(self) -> str:
        self._transformed_state = "attacks normally."
        return f"{self._name} returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon type Creature")
        self._transformed_state = "attacks normally."

    def attack(self) -> str:
        return f"{self._name} {self._transformed_state}"

    def transform(self) -> str:
        self._transformed_state = "unleashes a devastating morph strike!"
        return f"{self._name} morphs into a dragonic battle form!"

    def revert(self) -> str:
        self._transformed_state = "attacks normally."
        return f"{self._name} stabilizes its form."


class CreatureFactory(ABC):

    @abstractmethod
    def create_base(self) -> Creature:
        pass

    @abstractmethod
    def create_evolved(self) -> Creature:
        pass


class FlameFactory(CreatureFactory):

    def __init__(self) -> None:
        FlameFactory.__name__ = "FlameFactory"

    def create_base(self) -> Creature:
        return Flameling()

    def create_evolved(self) -> Creature:
        return Pyrodon()


class TransformCreatureFactory(CreatureFactory):

    def __init__(self) -> None:
        TransformCreatureFactory.__name__ = "TransformCreatureFactory"

    def create_base(self) -> Shiftling:
        return Shiftling()

    def create_evolved(self) -> Morphagon:
        return Morphagon()
