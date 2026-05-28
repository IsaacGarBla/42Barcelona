#!/usr/bin/python3

class Plant:
    _name:      str
    _height:    float
    _days_age:  int
    _statistics: "PlantStats"

    class PlantStats:
        _grow_count: int
        _age_count:  int
        _show_count: int

        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def show(self) -> None:
            print("Stats: ", self._grow_count, "grow,",
                  self._age_count, "age,",
                  self._show_count, "show")

        @property
        def grow_count(self) -> int:
            return self._grow_count

        @grow_count.setter
        def grow_count(self, count: int) -> None:
            self._grow_count = count

        @property
        def age_count(self) -> int:
            return self._age_count

        @age_count.setter
        def age_count(self, count: int) -> None:
            self._age_count = count

        @property
        def show_count(self) -> int:
            return self._show_count

        @show_count.setter
        def show_count(self, count: int) -> None:
            self._show_count = count

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._statistics = self.PlantStats()
        if age < 0:
            print(name.capitalize(), "Error, age can't be negative")
            print("Age create rejected, set to 0")
            self._days_age = 0
            return
        else:
            self._days_age = age
        if height < 0:
            print(name.capitalize(), "Error, height can't be negative")
            print("Height create rejected, set to 0")
            self._height = 0
            return
        else:
            self._height = height

    @staticmethod
    def bigger_than_a_year(days: int) -> bool:
        return days / 365 > 1

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0, 0)

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

    @property
    def statistics(self) -> "PlantStats":
        return self._statistics

    def show(self) -> None:
        self._statistics.show_count += 1
        print(self._name.capitalize(), ": ", f"{self._height:.1f}", "cm, ",
              self._days_age, " days old", sep="")

    def age(self, days: int) -> None:
        self._statistics.age_count += 1
        self._days_age += days

    def grow(self, centimeters: float) -> None:
        self._statistics.grow_count += 1
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
    _statistics: "TreeStats"

    class TreeStats(Plant.PlantStats):
        _shade_count: int

        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def show(self) -> None:
            super().show()
            print(self._shade_count, "shade"),

        @property
        def shade_count(self) -> int:
            return self._shade_count

        @shade_count.setter
        def shade_count(self, count: int) -> None:
            self._shade_count = count

    def __init__(self, name: str, height: float, age: int,
                 diameter: float) -> None:
        super().__init__(name, height, age)
        self._statistics = self.TreeStats()
        if diameter < 0:
            print(name.capitalize(), "Error, diameter can't be negative")
            print("Diameter create rejected, set to 0")
            self._trunk_diameter = 0
            return
        else:
            self._trunk_diameter = diameter

    @property
    def trunk_diameter(self) -> float:
        return (self._trunk_diameter)

    @trunk_diameter.setter
    def trunk_diameter(self, diameter: float) -> None:
        if diameter < 0:
            print(self._name.capitalize(), "Error, diameter can't be negative")
            print("Diameter update rejected")
            return
        else:
            print("Diameter update:", round(diameter, 2), "cm")
            self._trunk_diameter = diameter

    @property
    def statistics(self) -> "TreeStats":
        return self._statistics

    def produce_shade(self) -> None:
        self._statistics.shade_count += 1
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
        self._nutritional_value += int(centimeters / 10)

    def show(self) -> None:
        super().show()
        print("Harvest season: ", self._harvest_season.capitalize())
        print("Nutritional value: ", self._nutritional_value)


class Seed(Flower):
    _seeds: int

    def __init__(self, name: str, height: float,
                 age: int, color: str = "") -> None:
        super().__init__(name, height, age, color)
        self._seeds = 0

    def bloom(self) -> None:
        self._bloomed = True
        self._seeds = 45

    def show(self) -> None:
        super().show()
        print("Seeds:", self._seeds)


def show_statistics(plant: "Plant") -> None:
    plant.statistics.show()


def main() -> None:
    print("=== Garden Statistics ===")
    print("=== Check year old")
    print("Is 30 days more than one year? ->", Plant.bigger_than_a_year(30))
    print("Is 400 days more than one year? ->", Plant.bigger_than_a_year(400))
    print("\n=== Flower")
    flower = Flower("Rose", 15, 10, "Red")
    flower.show()
    print("[Statistics for ", flower.name.capitalize(), "]", sep="")
    flower.statistics.show()
    print("[asking the ", flower.name, " to grow and bloom]")
    flower.grow(8)
    flower.bloom()
    flower.show()
    print("[Statistics for ", flower.name.capitalize(), "]", sep="")
    flower.statistics.show()
    print("\n=== Tree")
    tree = Tree("Oak", 200, 365, 5)
    tree.show()
    print("[Statistics for ", tree.name.capitalize(), "]", sep="")
    tree.statistics.show()
    print("[asking the", tree.name.capitalize(), "to produce shade]")
    tree.produce_shade()
    print("[Statistics for ", tree.name.capitalize(), "]", sep="")
    tree.statistics.show()
    show_statistics(tree)
    print("\n=== Seed")
    seed = Seed("Sunflower", 80, 45, "yellow")
    seed.show()
    print("[make", seed.name.capitalize(), "grow, age and bloom]")
    seed.grow(30)
    seed.age(20)
    seed.bloom()
    seed.show()
    print("[Statistics for ", tree.name.capitalize(), "]", sep="")
    seed.statistics.show()
    show_statistics(seed)
    print("\n=== Anonimous")
    anonimous = Plant.anonymous()
    anonimous.show()
    print("[Statistics for ", anonimous.name.capitalize(), "]", sep="")
    anonimous.statistics.show()

# This line means: "If someone runs this file directly, call main()"
# You don't need to understand this yet, just know it makes the program start


if __name__ == "__main__":
    main()
