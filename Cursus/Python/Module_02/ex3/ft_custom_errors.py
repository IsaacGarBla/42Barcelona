#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_custom_errors.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/28 18:01:31 by igarciab        #+#    #+#               #
#  Updated: 2026/05/28 18:43:47 by igarciab        ###   ########.fr        #
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


def raise_garden_error(operation_number: int) -> None:
    if operation_number == 0:
        # Plant error without specific message
        raise PlantError
    elif operation_number == 1:
        # Plant error with specific message
        raise PlantError("The tomato plant is wilting!")
    elif operation_number == 2:
        # Water error without specific message
        raise WaterError
    elif operation_number == 3:
        # Water error without specific message
        raise WaterError("Not enough water in the tank!")
    else:
        # Safe operation number: runs successfully and returns nothing
        return


def test_error_types() -> None:
    print("=== Custom Garden Errors Demo ===")

    print("\nTesting PlantError...")
    try:
        raise_garden_error(1)
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print("\nTesting WaterError...")
    try:
        raise_garden_error(3)
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    print("\nTesting catching all garden errors...")
    try:
        raise_garden_error(1)
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        raise_garden_error(3)
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    print("\nAll custom error types work correctly!")


# Execute the test function
if __name__ == "__main__":
    test_error_types()
