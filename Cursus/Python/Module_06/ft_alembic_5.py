#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_alembic_5.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 19:28:52 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/15 16:25:00 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

from alchemy import create_air


def main() -> None:
    print("=== Alembic 5 ===")
    print("Accessing the alchemy module using 'from alchemy import ...'")
    print("Testing create_air:", create_air())


if __name__ == "__main__":
    main()
