#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_alembic_1.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 19:12:10 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/11 19:21:38 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #
from elements import create_water


def main() -> None:
    print("=== Alembic 1 ===")
    print("Using: 'from ... import ...' structure to access elements.py")
    print("Testing create_water:", create_water())


if __name__ == "__main__":
    main()
