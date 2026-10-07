#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_types.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 16:20:25 by igarciab        #+#    #+#               #
#  Updated: 2026/06/08 02:08:14 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str = ""
    _height: float = 0
    _days_age: int = 0

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        if self._check_age(age):
            self._days_age = age
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

    def set_height(self, height: int) -> None:
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


class Flower(Plant):
    _color:     str
    _bloomed:   bool

    def __init__(self, name: str, height: float,
                 age: int, color: str = "") -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False

    def bloom(self) -> None:
        self._bloomed = True

    def show(self) -> None:
        super().show()
        print("Color:", self._color)
        if self._bloomed:
            print(self._name.capitalize(), "is blooming beautifully!")
        else:
            print(self._name.capitalize(), "has not bloomed yet")


class Tree(Plant):
    _trunk_diameter: float = 0

    def __init__(self, name: str, height: float, age: int,
                 diameter: float) -> None:
        super().__init__(name, height, age)
        if self._check_diameter(diameter):
            self._trunk_diameter = diameter

    def _check_diameter(self, diameter: float) -> bool:
        if diameter < 0:
            print(self._name.capitalize(), "Error, diameter can't be negative")
            return False
        else:
            return True

    def set_trunk_diameter(self, diameter: float) -> None:
        if not self._check_diameter(diameter):
            print("Diameter update rejected")
        else:
            self._trunk_diameter = diameter
            print("Diameter update:", round(diameter, 2), "cm")

    def produce_shade(self) -> None:
        print("Tree ", self._name.capitalize(),
              " now produces a shade of ", round(self._height, 2),
              "cm long and ", round(self._trunk_diameter),
              " cm wide.", sep="")

    def show(self) -> None:
        super().show()
        print("Trunk diameter: ", round(self._trunk_diameter, 2), "cm", sep="")


class Vegetable(Plant):
    _harvest_season:    str
    _nutritional_value: int

    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str = "", nutritional_value: int = 0) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def age(self, days: int) -> None:
        super().age(days)
        self._nutritional_value += days

    def grow(self, centimeters: float) -> None:
        super().grow(centimeters)

    def show(self) -> None:
        super().show()
        print("Harvest season: ", self._harvest_season.capitalize())
        print("Nutritional value: ", self._nutritional_value)


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower = Flower("Rose", 25.0, 30, "rose")
    flower.show()
    print("[Asking the rose to bloom]")
    flower.bloom()
    flower.show()
    print("\n=== Tree")
    tree = Tree("Oak", 200, 365, 25)
    tree.show()
    print("[Asking the oak to produce shade]")
    tree.produce_shade()
    print("\n=== Vegetable")
    vegetable = Vegetable("Tomato", 5, 10, "April")
    vegetable.show()
    print("[Make tomato grow and age for 20 days]")
    vegetable.grow(42)
    vegetable.age(20)
    vegetable.show()


if __name__ == "__main__":
    main()
