#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_command_quest.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/01 10:09:13 by igarciab        #+#    #+#               #
#  Updated: 2026/06/16 10:43:21 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


def main() -> None:
    print("=== Command Quest ===")
    program_name, *args = sys.argv
    print("Program name:", program_name)
    print("Arguments received:", len(args))
    for i in range(len(args)):
        print("Argument: ", i + 1, ": ", args[i], sep="")
    print("Total arguments:", len(sys.argv))


if __name__ == "__main__":
    main()
