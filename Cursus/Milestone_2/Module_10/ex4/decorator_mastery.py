#!python3 /usr/bin/env python3

import functools
from typing import Callable, Any
import time


def spell_timer(func: Callable) -> Callable:

    @functools.wraps(func)
    def counter(*args: Any, **kwargs) -> Callable:

        print(f"Casting {func.__name__}")
        init = time.perf_counter()
        result = func(*args, **kwargs)
        end = time.perf_counter()
        print(f"Spell completed in {end - init:.3f} seconds")

        return result

    return counter


@spell_timer
def test() -> None:
    print("Function for testing....")
    time.sleep(2.3)


if __name__ == "__main__":
    test()
