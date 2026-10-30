#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_security_v1.py                          :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 13:26:54 by igarciab        #+#    #+#               #
#  Updated: 2026/06/01 10:39:02 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str
    _height: float = 0
    _days_age: int = 0

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        if age < 0:
            print(name.capitalize(), "Error, age can't be negative")
            print("Age create rejected, set to 0")
            return
        else:
            self._age = age
        if height < 0:
            print(name.capitalize(), "Error, height can't be negative")
            print("Height create rejected, set to 0")
            return
        else:
            self._height = height

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, name: str) -> None:
        self._name = name

    @property
    def days_age(self) -> int:
        return self._days_age

    @days_age.setter
    def days_age(self, age: int) -> None:
        if age < 0:
            print(self._name.capitalize(), "Error, age can't be negative")
            print("Age update rejected")
            return
        else:
            self._days_age = age
            print("Age update:", age, "days")

    @property
    def height(self) -> float:
        return self._height

    @height.setter
    def height(self, height: int) -> None:
        if height < 0:
            print(self._name.capitalize(), "Error, height can't be negative")
            print("Height update rejected")
            return
        else:
            self._height = height
            print("Height update:", round(height, 2), "cm")

    def show(self) -> None:
        print(self._name.capitalize(), ": ", round(self._height, 2), "cm, ",
              self._age, " days old", sep="")

    def age(self, days: int) -> None:
        self._days_age = self._days_age + days

    def grow(self, centimeters: float) -> None:
        self._height = self._height + centimeters


def main() -> None:
    print("=== Garden Security System ===")
    plant = Plant("Rose", 25.0, 30)
    print("Plant created: ", end="")
    plant.show()
    plant.height = 25
    plant.days_age = 30
    plant.height = -1
    plant.days_age = -1
    print("Current state: ", plant.name.capitalize(), " ",
          round(plant.height, 2),
          "cm, ", plant.days_age, " days old", sep="")


if __name__ == "__main__":
    main()
