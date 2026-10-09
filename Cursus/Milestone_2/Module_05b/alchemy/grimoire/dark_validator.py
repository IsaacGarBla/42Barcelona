# Absolute import
from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed_ingredients = dark_spell_allowed_ingredients()

    if any(ing in ingredients for ing in allowed_ingredients):
        return "VALID"
    else:
        return "INVALID"
