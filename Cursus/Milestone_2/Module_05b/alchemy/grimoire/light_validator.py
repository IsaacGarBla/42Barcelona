def validate_ingredients(ingredients: str) -> str:

    from . import light_spell_allowed_ingredients

    allowed_ingredients = light_spell_allowed_ingredients()

    if any(ing in ingredients for ing in allowed_ingredients):
        return "VALID"
    else:
        return "INVALID"
