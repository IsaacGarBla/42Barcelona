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

    return lambda target, power: base_spell(target, power * multiplier)


def condition(target: str, power: int) -> bool:
    return power >= 50


def conditional_caster(condition: Callable[[str, int], bool],
                       spell: Callable[[str, int], str]) -> \
                             Callable[[str, int], str]:
    return lambda target, power: spell(target, power) \
                    if condition(target, power) else "Spell fizzled"


def spell_sequence(spells: list[Callable]) -> Callable[[str, int], list[str]]:
    return lambda target, power: [spell(target, power) for spell in spells]


if __name__ == "__main__":
    print("Testing 'spell combiner'.....\n"
          "============================\n"
          "Fisrt spell: 'Fireball'\n"
          "second spell: 'Heal'\n"
          "Target: 'Dragon'\n"
          "Power: '23'")
    combiner = spell_combiner(fireball, heal)
    resultado = combiner("Dragon", 23)
    print("Result of combiner the two spells:", resultado, end="\n\n")

    print("Testing power amplifier.....\n"
          "============================\n\n"
          "Target: 'Dragon'\n"
          "Power: '23'\n"
          "Spell: 'fireball'\n"
          "Multiplier: '10'")
    amplifier = power_amplifier(fireball, 10)
    print("Result of amplifier:", amplifier("Dragon", 23), end="\n\n")

    print("Testing conditional caster.....\n"
          "============================\n\n"
          "Target: 'Dragon'\n"
          "Power: '23'\n"
          "Spell: 'heal'\n")
    cond = conditional_caster(condition, heal)
    print("Result of conditional caster:", cond("Dragon", 23), end="\n\n")

    print("Testing spell sequences.....\n"
          "============================\n\n"
          "Target: 'Dragon'\n"
          "Power: '23'\n"
          "Spells: 'heal', 'fireball'\n")
    sequence = spell_sequence([heal, fireball])
    print("Result of spell sequences", sequence("Dragon", 23), end="\n\n")
