#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_alembic_4.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 19:28:52 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/11 20:42:31 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import alchemy


def main() -> None:
    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")
    print("Testing create_air:", alchemy.create_air())
    print("Now show that not all functions can be reached")
    print("This will raise an exception!")
    print("Testing create_earth:", alchemy.create_earth())


if __name__ == "__main__":
    main()
