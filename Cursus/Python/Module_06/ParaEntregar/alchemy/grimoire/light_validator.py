import alchemy.grimoire


def validate_ingredients(ingredients: str) -> str:

    allowed_ingredients = alchemy.grimoire.light_spell_allowed_ingredients()

    if any(ing in ingredients for ing in allowed_ingredients):
        return "VALID"
    else:
        return "INVALID"
