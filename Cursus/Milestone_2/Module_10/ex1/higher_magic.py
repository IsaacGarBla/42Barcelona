#!usr/bin/env python3
from typing import Callable, Tuple


# Defining spells
def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def fireball(target: str, power: int) -> str:
    return f"Fireball deals {power} damage to {target}"


# Defining spell_combiner.
def spell_combiner(spell1: Callable[[str, int], str],
                   spell2: Callable[[str, int], str]) -> \
                       Callable[[str, int], Tuple[str, str]]:
    return lambda target, power: (spell1(target, power), spell2(target, power))


# Defining power_amplifier
def power_amplifier(base_spell: Callable[[str, int], str], 
                    multiplier: int) -> Callable[[str, int], str]:
    """
    Amplifica el poder d'un encanteri. Retorna un nou encanteri on el poder
    es multiplica pel multiplicador indicat abans de ser llançat.
    """
    return lambda target, power: base_spell(target, power * multiplier)


def conditional_caster(condition: Callable[[str, int], bool],
                       spell: Callable[[str, int], str]) -> str:
    return lambda target, power: spell(target, power) \
                    if condition(target, power) else "Spell fizzled"


if __name__ == "__main__":
    combiner = spell_combiner(heal, fireball)
    resultado = combiner("Dragon", 23)
    print(resultado)
