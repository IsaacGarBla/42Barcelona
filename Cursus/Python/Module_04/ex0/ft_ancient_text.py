#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_ancient_text.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/03 12:25:53 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/03 15:31:15 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys
import typing


# @process_file: Reads and displays the contents of a file, simulating the
# recovery of ancient text from a cyber archive.
# @param filename: The name of the file to read.
# @return: None
def process_file(filename: str) -> None:
    file: typing.TextIO
    line: str

    print(f"Accessing file '{filename}'...")
    try:
        file = open(filename, 'r')
        print("---\n")
        for line in file:
            print(line, end="")
        print("\n---")
        print(f"File '{filename}' closed.")
        file.close()
    except (FileNotFoundError, PermissionError) as e:
        print(f"Error opening file '{filename}': {e}")
    except Exception as e:
        file.close()
        print(f"Error reading file '{filename}': {e}")


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    print("=== Cyber Archives Recovery ===")
    process_file(sys.argv[1])


if __name__ == "__main__":
    main()
