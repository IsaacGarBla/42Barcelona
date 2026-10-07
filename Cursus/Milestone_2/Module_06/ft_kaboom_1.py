#!/usr/bin/env python3

if __name__ == "__main__":
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly",
          "Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION",
          flush=True)

    from alchemy.grimoire.dark_spellbook import dark_spell_record

    print(dark_spell_record("Fantasy", "Earth, wind and fire"))
