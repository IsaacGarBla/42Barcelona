#!usr/bin/env python3
from typing import Callable, Any


def mage_counter() -> Callable[[], int]:
    calls:  int = 0

    def count_calls() -> int:
        nonlocal calls
        calls += 1
        return calls
    return count_calls


def spell_accumulator(ini_power: int) -> Callable[[int], int]:
    act_power:  int = ini_power

    def accumulate(power_to_add: int) -> int:
        nonlocal act_power
        act_power += power_to_add
        return act_power
    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    return lambda item_name: f"{enchantment_type} {item_name}"


def memory_vault() -> dict[str, Callable]:
    memory:     dict = {}

    def store(key: str, value: Any) -> None:
        memory[key] = value

    def recall(key: str) -> Any:
        value:  Any

        value = memory.get(key)
        if value is None:
            return "Memory not found"
        return value

    return {"store": store, "recall": recall}


if __name__ == "__main__":

    print("Testing 'mage_counter'.....\n"
          "============================")
    counter_calls = mage_counter()
    for x in range(1, 10):
        print(f"   Call {x} retunrs: {counter_calls()}")
    print()

    print("Testing 'spell_accumulator'.....\n"
          "============================\n"
          "   Initial power: 10")
    inc_power = spell_accumulator(10)
    for x in range(10, 50, 10):
        print(f"   Actual power: {inc_power(x)}")
    print()

    print("Testing 'enchantment_factory'.....\n"
          "============================")
    enchantment_types = ['Radiant', 'Earthen', 'Dark']
    items_to_enchant = ['Staff', 'Amulet', 'Cloak', 'Wand']
    enchantments = [enchantment_factory(type) for type in enchantment_types]
    for enchantment in enchantments:
        for item in items_to_enchant:
            print(f"{enchantment(item)}")
    print()

    print("Testing 'memory_vault'.....\n"
          "============================")
    memory_v = memory_vault()
    print("   Storing values...")
    print("   Storing 'name' = 'Light Prism'...")
    memory_v["store"]("name", "Light Prism")
    print("   Storing 'power' = '35'...")
    memory_v["store"]("power", 35)
    print("   Recalling values")
    print(f"   Recall 'name' = {memory_v["recall"]("name")}")
    print(f"   Recall 'power' = {memory_v["recall"]("power")}")
    print(f"   Recall 'powers' = {memory_v["recall"]("powers")}")
