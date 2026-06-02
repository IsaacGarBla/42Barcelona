#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_types.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 16:20:25 by igarciab        #+#    #+#               #
#  Updated: 2026/06/03 00:17:30 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str = ""
    _height: float = 0
    _days_age: int = 0

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        if age < 0:
            print(name.capitalize(), "Error, age can't be negative")
            print("Age create rejected, set to 0")
            return
        else:
            self._days_age = age
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

    @property
    def color(self) -> str:
        return self._color

    @color.setter
    def color(self, color: str) -> None:
        self._color = color

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
        self._trunk_diameter = diameter

    @property
    def trunk_diameter(self) -> float:
        return (self._trunk_diameter)

    @trunk_diameter.setter
    def trunk_diameter(self, diameter: float) -> None:
        if diameter < 0:
            print(self.name.capitalize(), "Error, diameter can't be negative")
            print("Diameter update rejected")
            return
        else:
            print("Diameter update:", round(diameter, 2), "cm")
            self._trunk_diameter = diameter

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

    @property
    def harvest_season(self) -> str:
        return (self._harvest_season)

    @harvest_season.setter
    def harvest_season(self, harvest_season: str) -> None:
        self._harvest_season = harvest_season

    @property
    def nutritional_value(self) -> int:
        return (self._nutritional_value)

    @nutritional_value.setter
    def nutritional_value(self, nutritional_value: int) -> None:
        self._nutritional_value = nutritional_value

    def age(self, days: int) -> None:
        super().age(days)
        self._nutritional_value = self.nutritional_value + days

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
