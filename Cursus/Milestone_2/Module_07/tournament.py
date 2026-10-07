#!/usr/bin/env python3

from ex0 import FlameFactory, AquaFactory
from ex0.creature import CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (BattleStrategy, NormalStrategy,
                 AggressiveStrategy, DefensiveStrategy, BattleError)


def battle(lst_opp: list[tuple[CreatureFactory,
                               BattleStrategy]]) -> None:

    if len(lst_opp) < 2:
        return
    elems_format = [f"({factory.__class__.__name__}+"
                    f"{strategy.__class__.__name__})"
                    for factory, strategy in lst_opp]

    print(f" [ {", ".join(elems_format)}]")
    print("*** Tournament ***")
    print(f"{len(lst_opp)} opponents involved\n")
    while len(lst_opp) > 1:
        factory1, strategy1 = lst_opp.pop(0)
        creature1 = factory1.create_base()
        for factory2, strategy2 in lst_opp:
            creature2 = factory2.create_base()
            print("* Battle *")
            print(creature1.describe())
            print(" vs")
            print(creature2.describe())
            print(" now fight")
            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
            except BattleError as e:
                print(f"{e}")
            print()


if __name__ == "__main__":
    flame = FlameFactory()
    aqua = AquaFactory()
    heal = HealingCreatureFactory()
    trans = TransformCreatureFactory()

    normal = NormalStrategy()
    defen = DefensiveStrategy()
    aggress = AggressiveStrategy()

    list_opponents = [(flame, normal), (heal, defen)]
    print("Tournament 0 (basic)")
    battle(list_opponents)
    list_opponents = [(flame, aggress), (heal, defen)]
    print("Tournament 1 (error)")
    battle(list_opponents)
    list_opponents = [(aqua, normal), (heal, defen), (trans, aggress)]
    print("Tournament 2 (multiple)")
    battle(list_opponents)
