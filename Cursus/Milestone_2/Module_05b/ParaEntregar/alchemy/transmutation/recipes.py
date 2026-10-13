# Absolute import (file in the root of the project)
import elements as elem1

# Relative import
from .. import elements as elem2
from .. import potions as pot


def lead_to_gold() -> str:
    return "Recipe transmuting Lead to Gold: brew ’" +\
           elem2.create_air() + "’ and '" +\
           pot.strength_potion() + "’ " +\
           "mixed with ’" + elem1.create_fire() + "’"
