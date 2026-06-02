#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_growth.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 11:03:14 by igarciab        #+#    #+#               #
#  Updated: 2026/06/01 10:39:18 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    name: str
    height: float
    days_age: int

    def show(self) -> None:
        print(self.name.capitalize(), ": ", round(self.height, 2), "cm, ",
              self.days_age, " days old", sep="")

    def age(self, days: int) -> None:
        self.days_age = self.days_age + days

    def grow(self, centimeters: float) -> None:
        self.height = self.height + centimeters


def main() -> None:
    week_grow: float = 0
    dayly_grow: float = 0.8

    plant = Plant()
    plant.name = "Rose"
    plant.height = 25
    plant.days_age = 30
    print("=== Garden Plant Registry ===")
    plant.show()
    for i in range(1, 8):
        print("=== Day", i, "===")
        plant.age(1)
        plant.grow(dayly_grow)
        plant.show()
        week_grow = week_grow + dayly_grow
    print("Growth this week: ", round(week_grow, 2), "cm", sep="")


if __name__ == "__main__":
    main()
