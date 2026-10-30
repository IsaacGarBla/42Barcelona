#!usr/bin/env python3
from typing import Callable, Any
import functools
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    if len(spells) == 0:
        return 0
    match operation:
        case "add":
            return functools.reduce(lambda x, y: x + y,
                                    spells)
        case "multiply":
            return functools.reduce(lambda x, y: x * y,
                                    spells)
        case "max":
            return functools.reduce(lambda x, y: x if x >= y else y,
                                    spells)
        case "min":
            return functools.reduce(lambda x, y: x if x <= y else y,
                                    spells)
        case _:
            raise ValueError(f"Unknown operation {operation}")


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {"fire": functools.partial(base_enchantment, power=50,
                                      element='fire'),
            "light": functools.partial(base_enchantment, power=50,
                                       element='light'),
            "water": functools.partial(base_enchantment, power=50,
                                       element='water')
            }


@functools.lru_cache(maxsize=128)
def memoized_fibonacci(n: int) -> int:
    if n == 0 or n == 1:
        return n
    else:
        return memoized_fibonacci(n - 2) + memoized_fibonacci(n - 1)


def spell_dispatcher() -> Callable[[Any], str]:

    @functools.singledispatch
    def dispatch(data: Any) -> str:
        return "Unknown spell type"

    @dispatch.register
    def _(data: int) -> str:
        return f"Damage spell: {data} damage"

    @dispatch.register
    def _(data: str) -> str:
        return f"Echantment: {data}"

    @dispatch.register
    def _(data: list) -> str:
        return f"Multi-cast: {len(data)} spells"

    return dispatch


if __name__ == "__main__":
    print("Testing 'spell_reducer'.....\n"
          "===========================")
    print("   Spells power: 1, 2, 3, 4, 5, 6, 7, 8")
    print("   add: "
          f"{spell_reducer([1, 2, 3, 4, 5, 6, 7, 8], 'add')}")
    print("   multiply: "
          f"{spell_reducer([1, 2, 3, 4, 5, 6, 7, 8], 'multiply')}")
    print("   max: "
          f"{spell_reducer([1, 2, 3, 4, 5, 6, 7, 8], 'max')}")
    print("   min: "
          f"{spell_reducer([1, 2, 3, 4, 5, 6, 7, 8], 'min')}")
    print()

    print("Testing 'memoized_fibonacci'.....\n"
          "===========================")
    print(f" Fib(0): {memoized_fibonacci(0)}")
    print(f" Fib(1): {memoized_fibonacci(1)}")
    print(f" Fib(10): {memoized_fibonacci(10)}")
    print(f" Fib(15): {memoized_fibonacci(15)}")
    print()

    print("Testing 'spell_dispacher'.....\n"
          "===========================")
    dispatcher = spell_dispatcher()
    print(f"{dispatcher(42)}")
    print(f"{dispatcher('fireball')}")
    print(f"{dispatcher([1, 2, 3])}")
    print(f"{dispatcher(3.14)}")
    print()
