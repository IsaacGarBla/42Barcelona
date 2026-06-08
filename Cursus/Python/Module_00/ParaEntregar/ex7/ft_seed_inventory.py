# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_seed_inventory.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 20:03:45 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 20:31:13 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if unit == "packets":
        print(seed_type.capitalize(), "seeds:", quantity, "packets available")
    elif unit == "grams":
        print(seed_type.capitalize(), "seeds:", quantity, "grams total")
    elif unit == "area":
        print(seed_type.capitalize(), "seeds: covers",
              quantity, "square meters")
    else:
        print("Unknown unit type")
