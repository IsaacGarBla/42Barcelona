import alchemy.grimoire


def light_spell_allowed_ingredients() -> list[str]:
    """
    Return a list of allowed ingredients for the light spell.
    """
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:

    return f"Spell recorded: {spell_name} ({ingredients} - " +\
           alchemy.grimoire.validate_ingredients(ingredients) + ")"
