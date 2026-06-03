#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_stream_management.py                           :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/03 12:25:53 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/03 15:38:32 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys
import typing


# @process_file: Reads and displays the contents of a file, simulating the
# recovery of ancient text from a cyber archive.
# @param filename: The name of the file to read.
# @return: A list of strings, where each string is a line from the file.
def process_file(filename: str) -> list[str]:
    file: typing.TextIO
    line_list: list[str] = []

    print(f"Accessing file '{filename}'...")
    try:
        file = open(filename, 'r',)
        print("---\n")
        for line in file:
            print(line, end="")
            line_list += [line]
        print("\n---")
        file.close()
        print(f"File '{filename}' closed.\n")
    except (FileNotFoundError, PermissionError) as e:
        sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
    except Exception as e:
        file.close()
        sys.stderr.write(f"[STDERR] Error reading file '{filename}': {e}\n")
        line_list = []
    return line_list


# @transform_data: Transforms the list of lines by adding a char '#' at the
# end of each line.
# @param line_list: A list of lines (strings)
# @return: None. The function performs the transformation and optionally saves
# the data to a new file based on user input.
def transform_data(line_list: list[str]) -> None:
    file: typing.TextIO
    filename: str = ""
    i: int

    print("Transform data:")
    print("---\n")
    for i in range(len(line_list)):
        if line_list[i] and line_list[i][-1] == '\n':
            line_list[i] = line_list[i][:-1] + "#\n"
        else:
            line_list[i] = line_list[i] + "#"
        print(line_list[i], end="")
    print("\n---")
    print("Enter new file name (or empty): ")
    filename = sys.stdin.readline()
    filename = filename[:-1]
    if filename != "":
        print(f"Saving data to '{filename}'...")
        try:
            file = open(filename, 'w')
            for i in range(len(line_list)):
                file.write(line_list[i])
            file.close()
            print(f"Data saved in file '{filename}'.")
        except (FileNotFoundError, PermissionError) as e:
            sys.stderr.write(f"[STDERR] Error opening file '{filename}'\
                             : {e}\n")
        except Exception as e:
            file.close()
            sys.stderr.write(f"[STDERR] Error writting file '{filename}'\
                             :{e}\n")


def main() -> None:
    line_list: list[str]

    if len(sys.argv) != 2:
        print("Usage: ./ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery ===")
    line_list = process_file(sys.argv[1])
    if len(line_list) > 0:
        transform_data(line_list)


if __name__ == "__main__":
    main()
