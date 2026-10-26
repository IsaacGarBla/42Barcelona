#!/usr/bin/env python3

from ex3 import TransformCreatureFactory


if __name__ == "__main__":

    base = TransformCreatureFactory().create_base()
    evolved = TransformCreatureFactory().create_evolved()

    print("Testing creatura with transform capability")
    print(" base:")
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())
