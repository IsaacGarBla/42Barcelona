#!/usr/bin/env python3

from ex3.creature import (CreatureFactory,
                          FlameFactory, TransformCreatureFactory)

from ex4 import (BattleStrategy,
                 NormalStrategy, AggressiveStrategy,
                 BattleError)


def battle(lst_opp: list[tuple[CreatureFactory,
                               BattleStrategy]]) -> None:
    strategy1: BattleStrategy
    strategy2: BattleStrategy

    if len(lst_opp) < 2:
        return

    list_opponents = [(factory.create_base(), strategy)
                      for factory, strategy in lst_opp]

    desc_opponents = [f"({creature.__class__.__name__}+"
                      f"{strategy.__class__.__name__})"
                      for creature, strategy in list_opponents]

    print(f" [{', '.join(desc_opponents)}]")
    print("*** Tournament ***")
    print(f"{len(list_opponents)} opponents involved\n\n"
          " * Battle *")
    while len(list_opponents) > 1:
        creature1, strategy1 = list_opponents.pop(0)
        for creature2, strategy2 in list_opponents:
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
    list_opponents:    list[tuple[CreatureFactory, BattleStrategy]]

    list_opponents = [(FlameFactory(), NormalStrategy()),
                      (TransformCreatureFactory(),
                       AggressiveStrategy())]
    print("Tournament 0 (basic)")
    battle(list_opponents)
    list_opponents = [(TransformCreatureFactory(),
                      AggressiveStrategy()),
                      (FlameFactory(), AggressiveStrategy())]
    print("Tournament 1 (error)")
    battle(list_opponents)
