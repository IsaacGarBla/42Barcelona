#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_command_quest.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/01 10:09:13 by igarciab        #+#    #+#               #
#  Updated: 2026/06/01 10:39:39 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


def main() -> None:
    print("=== Command Quest ===")
    print("Program name:", sys.argv[0])
    print("Arguments received:", len(sys.argv) - 1)
    for i in range(1, len(sys.argv)):
        print("Argument: ", i, ": ", sys.argv[i], sep="")
    print("Total arguments:", len(sys.argv))


if __name__ == "__main__":
    main()
