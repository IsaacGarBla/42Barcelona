# Absolute import
from alchemy.elements import create_air
from elements import create_fire


# Relative import
from ..potions import strength_potion


def lead_to_gold() -> str:
    return "Recipe transmuting Lead to Gold: brew ’" +\
           create_air() + "’ and '" +\
           strength_potion() + "’ " +\
           "mixed with ’" + create_fire() + "’"
