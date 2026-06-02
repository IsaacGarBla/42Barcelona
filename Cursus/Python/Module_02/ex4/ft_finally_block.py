#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_finally_block.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/28 18:47:11 by igarciab        #+#    #+#               #
#  Updated: 2026/05/28 19:24:49 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class GardenError(Exception):

    def __init__(self, desc_error: str = "Unknown garden error") -> None:
        super().__init__(desc_error)


class PlantError(GardenError):

    def __init__(self, desc_error: str = "Unknown plant error") -> None:
        super().__init__(desc_error)


class WaterError(GardenError):

    def __init__(self, desc_error: str = "Unknown water error") -> None:
        super().__init__(desc_error)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise GardenError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system(plant_names: list[str]) -> None:
    print("Opening watering system")
    try:
        for plant_name in plant_names:
            water_plant(plant_name)
    except GardenError as error:
        print(f"Caught PlantError: {error}")
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")


def main() -> None:
    print("=== Garden Watering System ===\n")
    print("Testing valid plants...")
    test_watering_system(["Tomato", "Lettuce", "Carrots"])
    print("\nTesting invalid plants...")
    test_watering_system(["Tomato", "lettuce", "Carrots"])
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    main()
