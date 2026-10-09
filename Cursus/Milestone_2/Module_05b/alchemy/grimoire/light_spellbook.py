def light_spell_allowed_ingredients() -> list[str]:
    """
    Return a list of allowed ingredients for the light spell.
    """
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    # Absolute import
    from . import validate_ingredients

    return f"Spell recorded: {spell_name} ({ingredients} - " +\
           validate_ingredients(ingredients) + ")"
