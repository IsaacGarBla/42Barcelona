#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_different_errors.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/28 17:38:02 by igarciab        #+#    #+#               #
#  Updated: 2026/06/08 02:49:24 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        # ValueError: Attempting to convert invalid string into an integer
        int("five_trees")
    elif operation_number == 1:
        # ZeroDivisionError: Attempting to divide by zero
        100 / 0
    elif operation_number == 2:
        # FileNotFoundError: Attempting to open a file that not exists.
        open("non_existent_file.txt", "r")
    elif operation_number == 3:
        # TypeError: Types that can't to be mixed.
        10 + " centimeters"
    else:
        # Safe operation number: runs successfully and returns nothing
        return


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    # Testing operations 0 through 4 (0-3 are faulty, 4 is safe)
    for op_num in range(5):
        print(f"Testing Operation #{op_num}...")
        try:
            garden_operations(op_num)
            print("Operation completed successfully")
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")
    print("\nAll error types tested successfully!")


# Execute the test function
if __name__ == "__main__":
    test_error_types()
