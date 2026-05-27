#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_factory.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 11:25:30 by igarciab        #+#    #+#               #
#  Updated: 2026/05/27 17:15:12 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    name: str
    height: float
    days_age: int

    def __init__(self, name: str, height: float, days_age: int) -> None:
        self.name = name
        self.height = height
        self.days_age = days_age

    def show(self) -> None:
        print(self.name.capitalize(), ": ", round(self.height, 2), "cm, ",
              self.days_age, " days old", sep="")

    def age(self, days: int) -> None:
        self.days_age = self.days_age + days

    def grow(self, centimeters: float) -> None:
        self.height = self.height + centimeters


# This line means: "If someone runs this file directly, call main()"
# You don't need to understand this yet, just know it makes the program start


def main() -> None:
    print("=== Plant Factory Output ===")
    plant = Plant("Rose", 25.0, 30)
    print("Created: ", end="")
    plant.show()
    plant = Plant("Oak", 200.0, 365)
    print("Created: ", end="")
    plant.show()
    plant = Plant("Cactus", 5.0, 90)
    print("Created: ", end="")
    plant.show()
    plant = Plant("Sunflower", 80.0, 45)
    print("Created: ", end="")
    plant.show()
    plant = Plant("Fern", 15.0, 120)
    print("Created: ", end="")
    plant.show()


if __name__ == "__main__":
    main()
