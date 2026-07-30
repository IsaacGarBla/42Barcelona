from abc import ABC, abstractmethod
from ex0.creature import Creature, CreatureFactory


class HealCapability(ABC):

    @abstractmethod
    def heal(self) -> str:
        pass


class TransformCapability(ABC):

    _transformed: bool

    def __init__(self) -> None:
        self._transformed = False

    @abstractmethod
    def transform(self) -> None:
        pass

    @abstractmethod
    def revert(self) -> None:
        pass


class Sproutling(Creature, HealCapability):

    def __init__(self) -> None:
        Creature.__init__(self, "Sproutling", "Grass type Creature")

    def attack(self) -> str:
        return f"{self._name} uses Vine Whip!"

    def heal(self) -> str:
        return f"{self._name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):

    def __init__(self) -> None:
        Creature.__init__(self, "Bloomelle", "Grass/Fairy type Creature")

    def attack(self) -> str:
        return f"{self._name} uses Petal Dance!"

    def heal(self) -> str:
        return f"{self._name} heals itself and others for a large amount"


class HealingCreatureFactory(CreatureFactory):

    def __init__(sefl) -> None:
        super().__init__()
        HealingCreatureFactory.__name__ = "Healing"

    def create_base(self) -> Creature:
        return Sproutling()

    def create_evolved(self) -> Creature:
        return Bloomelle()


class Shiftling(Creature, TransformCapability):

    def __init__(self) -> None:
        Creature.__init__(self, "Shiftling", "Normal type Creature")
        TransformCapability.__init__(self)

    def transform(self) -> None:
        self._transformed = True
        print("Shiftling shifts into a sharper form!")

    def revert(self) -> None:
        self._transformed = False
        print("Shiftling returns to normal.")

    def attack(self) -> str:
        if not self._transformed:
            return f"{self._name} attacks normally!"
        else:
            return f"{self._name} performs a boosted strike!"


class Morphagon(Creature, TransformCapability):

    def __init__(self) -> None:
        Creature.__init__(self, "Morphagon", "Normal/Dragon type Creature")
        TransformCapability.__init__(self)

    def transform(self) -> None:
        self._transformed = True
        print("Morphagon morphs into a dragonic battle form!")

    def revert(self) -> None:
        self._transformed = False
        print("Morphagon stabilizes its form.")

    def attack(self) -> str:
        if not self._transformed:
            return f"{self._name} attacks normally!"
        else:
            return f"{self._name} unleashes a devastating morph strike!"


class TransformCreatureFactory(CreatureFactory):

    def __init__(sefl) -> None:
        super().__init__()
        TransformCreatureFactory.__name__ = "Transform"

    def create_base(self) -> Creature:
        return Shiftling()

    def create_evolved(self) -> Creature:
        return Morphagon()
