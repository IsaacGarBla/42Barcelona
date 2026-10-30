#!/usr/bin/python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_data.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/27 10:38:38 by igarciab        #+#    #+#               #
#  Updated: 2026/06/07 19:27:58 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    _name: str
    _height: int
    _age: int

    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def show(self) -> None:
        print(self._name.capitalize(), ": ", self._height, "cm, ",
              self._age, " days old", sep="")


def main() -> None:
    print("=== Garden Plant Registry ===")
    rose = Plant("Rose", 25, 30)
    rose.show()
    sunflower = Plant("Sunflower", 80, 45)
    sunflower.show()
    cactus = Plant("Cactus", 15, 120)
    cactus.show()


if __name__ == "__main__":
    main()
