#!/usr/bin/env python3

from ex3 import FlameFactory, TransformCreatureFactory


def test(factory: FlameFactory | TransformCreatureFactory) -> None:
    print("Testing factory")
    creature = factory.create_base()
    print(creature.describe())
    print(creature.attack())
    creature = factory.create_evolved()
    print(creature.describe())
    print(creature.attack())


def fight(factory1: FlameFactory | TransformCreatureFactory,
          factory2: FlameFactory | TransformCreatureFactory) -> None:
    print("Testing battle")
    creature1 = factory1.create_base()
    print(creature1.describe())
    print(" vs")
    creature2 = factory2.create_base()
    print(creature2.describe())
    print(" fight!")
    print(creature1.attack())
    print(creature2.attack())


if __name__ == "__main__":
    flame_factory = FlameFactory()
    transform_factory = TransformCreatureFactory()
    test(flame_factory)
    print("")
    test(transform_factory)
    print("")
    fight(flame_factory, transform_factory)
