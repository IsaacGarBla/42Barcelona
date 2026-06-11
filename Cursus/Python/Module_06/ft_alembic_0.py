#!/usr/bin/env python3
# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  alembic_0.py                                      :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/11 17:53:49 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/11 19:13:33 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import elements


def main() -> None:
    print("=== Alembic 0 ===")
    print("Using: 'import ...' structure to access elements.py")
    print("Testing create_fire:", elements.create_fire())


if __name__ == "__main__":
    main()
