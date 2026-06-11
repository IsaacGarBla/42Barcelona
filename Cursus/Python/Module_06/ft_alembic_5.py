#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_alembic_5.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 19:28:52 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/11 20:40:49 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

from alchemy import elements


def main() -> None:
    print("=== Alembic 5 ===")
    print("Accessing the alchemy module using 'from alchemy import ...'")
    print("Testing create_air:", elements.create_air())


if __name__ == "__main__":
    main()
