#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_different_errors.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/28 17:38:02 by igarciab        #+#    #+#               #
#  Updated: 2026/06/03 17:41:40 by igarcia-        ###   ########.fr        #
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
    print("=== STARTING GARDEN SYSTEM ERROR TEST ===\n")
    # Testing operations 0 through 4 (0-3 are faulty, 4 is safe)
    for op_num in range(5):
        print(f"Executing Operation #{op_num}...")
        try:
            garden_operations(op_num)
            print("-> Success: ",
                  f"Operation #{op_num} completed with no faults.")
        except ValueError as e:
            print("-> Caught ValueError: ",
                  f"You provided bad or incompatible data! Details: {e}")
        except ZeroDivisionError as e:
            print("-> Caught ZeroDivisionError: ",
                  f"You attempted a division by zero! Details: {e}")
        except FileNotFoundError as e:
            print("-> Caught FileNotFoundError: ",
                  f"The requested file could not be found! Details: {e}")
        except TypeError as e:
            print("-> Caught TypeError: ",
                  f"Incompatible data types cannot be mixed! Details: {e}")
        print("-> Status: The program is still healthy and running.\n")
    print("=== GARDEN SYSTEM ERROR TEST COMPLETE ===")


# Execute the test function
if __name__ == "__main__":
    test_error_types()
