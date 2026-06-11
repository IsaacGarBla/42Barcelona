#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_alembic_3.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 19:25:31 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/11 20:40:44 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

from alchemy.elements import create_air


def main() -> None:
    print("=== Alembic 3 ===")
    print("Accessing alchemy/elements.py using '", sep="")
    print("from ... import ...' structure")
    print("Testing create_air:", create_air())


if __name__ == "__main__":
    main()
