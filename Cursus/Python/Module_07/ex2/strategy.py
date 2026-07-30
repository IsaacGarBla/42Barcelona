from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1 import (HealCapability, TransformCapability)


class BattleError(Exception):

    def __init__(self, error: str) -> None:
        super().__init__(error)


class BattleStrategy(ABC):

    @abstractmethod
    def act(self, card: Creature) -> None:
        pass

    @abstractmethod
    def is_valid(self, card: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def __init__(self) -> None:
        super().__init__()
        NormalStrategy.__name__ = "Normal"

    def is_valid(self, card: Creature) -> bool:
        return True

    def act(self, card: Creature) -> None:
        if self.is_valid(card):
            print(card.attack())
        return


class AggressiveStrategy(BattleStrategy):

    def __init__(self) -> None:
        super().__init__()
        AggressiveStrategy.__name__ = "Aggressive"

    def is_valid(self, card: Creature) -> bool:
        return isinstance(card, TransformCapability)

    def act(self, card: Creature) -> None:
        if isinstance(card, TransformCapability):
            card.transform()
            print(card.attack())
            card.revert()
        else:
            raise BattleError("Battle error, aborting tournament: " +
                              "Invalid creature '" + card.name +
                              "' for this aggressive strategy")
        return


class DefensiveStrategy(BattleStrategy):

    def __init__(self) -> None:
        super().__init__()
        DefensiveStrategy.__name__ = "Defensive"

    def is_valid(self, card: Creature) -> bool:
        return isinstance(card, HealCapability)

    def act(self, card: Creature) -> None:
        if isinstance(card, HealCapability):
            print(card.attack())
            print(card.heal())
        else:
            raise BattleError("Battle error, aborting tournament: " +
                              "Invalid creature '" + card.name +
                              "' for this defensive strategy")
        return
