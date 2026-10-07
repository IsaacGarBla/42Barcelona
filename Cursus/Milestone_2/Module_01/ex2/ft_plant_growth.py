#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_growth.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 11:03:14 by igarciab        #+#    #+#               #
#  Updated: 2026/06/07 19:33:42 by igarciab        ###   ########.fr        #
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
    week_grow: float = 0
    dayly_grow: float = 0.8

    rose = Plant("Rose", 25, 30)
    print("=== Garden Plant Registry ===")
    rose.show()
    for i in range(1, 8):
        print("=== Day", i, "===")
        rose.age(1)
        rose.grow(dayly_grow)
        rose.show()
        week_grow += dayly_grow
    print("Growth this week: ", round(week_grow, 2), "cm", sep="")


if __name__ == "__main__":
    main()
