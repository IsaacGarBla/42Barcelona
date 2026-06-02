#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_data.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 10:38:38 by igarciab        #+#    #+#               #
#  Updated: 2026/06/02 17:59:41 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    name: str
    height: int
    age: int

    def show(self) -> None:
        print(self.name.capitalize(), ": ", self.height, "cm, ",
              self.age, " days old", sep="")


def main() -> None:
    plant = Plant()
    print("=== Garden Plant Registry ===")
    plant.name = "Rose"
    plant.height = 25
    plant.age = 30
    plant.show()
    plant.name = "Sunflower"
    plant.height = 80
    plant.age = 45
    plant.show()
    plant.name = "Cactus"
    plant.height = 15
    plant.age = 120
    plant.show()


if __name__ == "__main__":
    main()
