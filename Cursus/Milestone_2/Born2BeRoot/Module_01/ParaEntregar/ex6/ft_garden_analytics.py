#!/usr/bin/python3

class Plant:
    _name:      str
    _height:    float
    _days_age:  int
    _statistics: "_PlantStats"

    class _PlantStats:
        _grow_count: int
        _age_count:  int
        _show_count: int

        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def _show(self) -> None:
            print("Stats: ", self._grow_count, "grow,",
                  self._age_count, "age,",
                  self._show_count, "show")

        def _increment_grow_count(self) -> None:
            self._grow_count += 1

        def _increment_age_count(self) -> None:
            self._age_count += 1

        def _increment_show_count(self) -> None:
            self._show_count += 1

    @staticmethod
    def bigger_than_a_year(days: int) -> bool:
        return days / 365 > 1

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0, 0)

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._statistics = self._PlantStats()
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
        self._statistics._increment_show_count()
        print(self._name.capitalize(), ": ", f"{self._height:.1f}", "cm, ",
              self._days_age, " days old", sep="")

    def age(self, days: int) -> None:
        self._statistics._increment_age_count()
        self._days_age += days

    def grow(self, centimeters: float) -> None:
        self._statistics._increment_grow_count()
        self._height += centimeters

    def show_statistics(self) -> None:
        self._statistics._show()


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
    _statistics: "_TreeStats"

    class _TreeStats(Plant._PlantStats):
        _shade_count: int

        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def _show(self) -> None:
            super()._show()
            print(self._shade_count, "shade"),

        def _increment_shade_count(self) -> None:
            self._shade_count += 1

    def __init__(self, name: str, height: float, age: int,
                 diameter: float) -> None:
        super().__init__(name, height, age)
        self._statistics = self._TreeStats()
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
        self._statistics._increment_shade_count()
        print("Tree ", self._name.capitalize(),
              " now produces a shade of ", round(self._height, 2),
              "cm long and ", round(self._trunk_diameter),
              " cm wide.", sep="")

    def show(self) -> None:
        super().show()
        print("Trunk diameter: ", round(self._trunk_diameter, 2), "cm", sep="")

    def show_statistics(self) -> None:
        self._statistics._show()


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
        self._seeds = 42

    def show(self) -> None:
        super().show()
        print("Seeds:", self._seeds)


def show_statistics(plant: "Plant") -> None:
    plant.show_statistics()


def main() -> None:
    print("=== Garden Statistics ===")
    print("=== Check year old")
    print("Is 30 days more than one year? ->", Plant.bigger_than_a_year(30))
    print("Is 400 days more than one year? ->", Plant.bigger_than_a_year(400))
    print("\n=== Flower")
    flower = Flower("Rose", 15, 10, "Red")
    flower.show()
    print("[Statistics for Rose]", sep="")
    show_statistics(flower)
    print("[asking the Rose to grow and bloom]")
    flower.grow(8)
    flower.bloom()
    flower.show()
    print("[Statistics for Rose ]", sep="")
    show_statistics(flower)
    print("\n=== Tree")
    tree = Tree("Oak", 200, 365, 5)
    tree.show()
    print("[Statistics for Oak]", sep="")
    show_statistics(tree)
    print("[asking the Oak to produce shade]")
    tree.produce_shade()
    print("[Statistics for Oak]", sep="")
    show_statistics(tree)
    print("\n=== Seed")
    seed = Seed("Sunflower", 80, 45, "yellow")
    seed.show()
    print("[make Sunflower grow, age and bloom]")
    seed.grow(30)
    seed.age(20)
    seed.bloom()
    seed.show()
    print("[Statistics for Sunflower]", sep="")
    show_statistics(seed)
    print("\n=== Anonimous")
    anonimous = Plant.anonymous()
    anonimous.show()
    print("[Statistics for Unknow plant]", sep="")
    show_statistics(anonimous)

# This line means: "If someone runs this file directly, call main()"
# You don't need to understand this yet, just know it makes the program start


if __name__ == "__main__":
    main()
