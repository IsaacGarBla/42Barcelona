#!/usr/bin/env python3

import alchemy


def main() -> None:
    print("=== Alembic 1 ===")
    print("Accessing the alchemy module using 'import alchemy\n"
          "Testing create_air:", alchemy.create_air())
    print("Now show that not all functions can be reached\n"
          "This will raise an exception!\n"
          "Testing the hidden create_earth:", alchemy.create_earth())


if __name__ == "__main__":
    main()
