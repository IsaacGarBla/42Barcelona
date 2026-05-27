#!usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_security.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 13:26:54 by igarciab        #+#    #+#               #
#  Updated: 2026/05/27 14:03:49 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str
    _height: float = 0
    _days_age: int = 0

    def __init__(self, name: str, height: float, days_age: int) -> None:
        self._name = name
        if days_age < 0:
            print(name.capitalize(), "Error, age can't be negative")
            print("Age create rejected, set to 0")
            return
        else:
            self._days_age = days_age
        if height < 0:
            print(name.capitalize(), "Error, height can't be negative")
            print("Height create rejected, set to 0")
            return
        else:
            self._height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(self._name.capitalize(), "Error, age can't be negative")
            print("Age update rejected")
            return
        else:
            self._days_age = age
            print("Age update:", age, "days")

    def set_height(self, height: int) -> None:
        if height < 0:
            print(self._name.capitalize(), "Error, height can't be negative")
            print("Height update rejected")
            return
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
        self._days_age = self._days_age + days

    def grow(self, centimeters: float) -> None:
        self._height = self._height + centimeters


# This line means: "If someone runs this file directly, call main()"
# You don't need to understand this yet, just know it makes the program start


def main() -> None:
    print("=== Garden Security System ===")
    plant = Plant("Rose", 25.0, 30)
    print("Plant created: ", end="")
    plant.show()
    plant.set_height(25)
    plant.set_age(30)
    plant.set_height(-1)
    plant.set_age(-1)
    print("Current state: ", plant._name.capitalize(), " ",
          round(plant.get_height(), 2),
          "cm, ", plant.get_age(), " days old", sep="")


if __name__ == "__main__":
    main()
