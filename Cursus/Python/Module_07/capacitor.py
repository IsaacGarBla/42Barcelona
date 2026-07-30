#!/usr/bin/env python3

from ex1 import (HealingCreatureFactory, HealCapability,
                 TransformCapability, TransformCreatureFactory)

if __name__ == "__main__":
    factory1 = HealingCreatureFactory()
    print("Testing Creature with healing capability")
    print(" base:")
    creature1 = factory1.create_base()
    print(creature1.describe())
    print(creature1.attack())
    if isinstance(creature1, HealCapability):
        print(creature1.heal())
    print(" evolved:")
    creature1 = factory1.create_evolved()
    print(creature1.describe())
    print(creature1.attack())
    if isinstance(creature1, HealCapability):
        print(creature1.heal())
    print("")
    factory2 = TransformCreatureFactory()
    print("Testing Creature with transform capability")
    print(" base:")
    creature2 = factory2.create_base()
    print(creature2.describe())
    print(creature2.attack())
    if isinstance(creature2, TransformCapability):
        creature2.transform()
        print(creature2.attack())
        creature2.revert()
    print(" evolved:")
    creature2 = factory2.create_evolved()
    print(creature2.describe())
    print(creature2.attack())
    if isinstance(creature2, TransformCapability):
        creature2.transform()
        print(creature2.attack())
        creature2.revert()
    print("")
