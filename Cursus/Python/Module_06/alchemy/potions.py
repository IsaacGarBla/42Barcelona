import alchemy.elements as elem1
import elements as elem2


def healing_potion() -> str:
    return "Healing potion brewed with ’" + elem1.create_earth() + \
           "' and ’" + elem1.create_air() + "’"


def strength_potion() -> str:
    return "Strength potion brewed with ’" + elem2.create_fire() + \
           "' and ’" + elem2.create_water() + "’"
