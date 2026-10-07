#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_factory.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 11:25:30 by igarciab        #+#    #+#               #
#  Updated: 2026/06/07 19:41:09 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str
    _height: float
    _days_age: int

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = height
        self._days_age = age

    def show(self) -> None:
        print(self._name.capitalize(), ": ", round(self._height, 1), "cm, ",
              self._days_age, " days old", sep="")

    def age(self, days: int) -> None:
        self._days_age += days

    def grow(self, centimeters: float) -> None:
        self._height += centimeters


def main() -> None:
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 25.0, 30)
    print("Created: ", end="")
    rose.show()
    oak = Plant("Oak", 200.0, 365)
    print("Created: ", end="")
    oak.show()
    cactus = Plant("Cactus", 5.0, 90)
    print("Created: ", end="")
    cactus.show()
    sunflower = Plant("Sunflower", 80.0, 45)
    print("Created: ", end="")
    sunflower.show()
    fern = Plant("Fern", 15.0, 120)
    print("Created: ", end="")
    fern.show()


if __name__ == "__main__":
    main()
