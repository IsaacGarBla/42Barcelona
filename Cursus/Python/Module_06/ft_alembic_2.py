#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_alembic_2.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 19:20:07 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/11 19:27:59 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import alchemy.elements as el


def main() -> None:
    print("=== Alembic 2 ===")
    print("Accessing alchemy/elements.py using 'import ...' structure")
    print("Testing create_earth:", el.create_earth())


if __name__ == "__main__":
    main()
