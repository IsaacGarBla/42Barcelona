#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_security.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 13:26:54 by igarciab        #+#    #+#               #
#  Updated: 2026/06/08 02:29:55 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str
    _height: float = 0
    _days_age: int = 0

    def __init__(self, name: str, height: float, days_age: int) -> None:
        self._name = name
        if self._check_age(days_age):
            self._days_age = days_age
        if self._check_height(height):
            self._height = height

    def _check_age(self, age: int) -> bool:
        if age < 0:
            print(self._name.capitalize(), "Error, age can't be negative")
            return False
        else:
            return True

    def _check_height(self, height: float) -> bool:
        if height < 0:
            print(self._name.capitalize(), "Error, height can't be negative")
            return False
        else:
            return True

    def set_age(self, age: int) -> None:
        if not self._check_age(age):
            print("Age update rejected")
        else:
            self._days_age = age
            print("Age update:", age, "days")

    def set_height(self, height: float) -> None:
        if not self._check_height(height):
            print("Height update rejected")
        else:
            self._height = height
            print("Height update:", round(height, 2), "cm")

    def get_age(self) -> int:
        return self._days_age

    def get_height(self) -> float:
        return self._height

    def show(self) -> None:
        print(self._name.capitalize(), ": ", round(self._height, 2), "cm, ",
              self._days_age, " days old", sep="")

    def age(self, days: int) -> None:
        self._days_age += days

    def grow(self, centimeters: float) -> None:
        self._height += centimeters


def main() -> None:
    print("=== Garden Security System ===")
    rose = Plant("Rose", 25.0, 30)
    print("Plant created: ", end="")
    rose.show()
    print("")
    rose.set_height(25)
    rose.set_age(30)
    rose.set_height(-1)
    rose.set_age(-1)
    print("\nCurrent state: ", end="")
    rose.show()


if __name__ == "__main__":
    main()
