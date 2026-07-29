# Absolute import
import alchemy.elements as elem1
import elements as elem2

# Relative import
from .. import potions as pot


def lead_to_gold() -> str:
    return "Recipe transmuting Lead to Gold: brew ’" +\
           elem1.create_air() + "’ and '" +\
           pot.strength_potion() + "’ " +\
           "mixed with ’" + elem2.create_fire() + "’"
