# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_count_harvest_recursive.py                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 19:24:10 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 20:30:46 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_count_harvest_recursive_helper(days: int) -> None:
    if days != 0:
        ft_count_harvest_recursive_helper(days - 1)
        print("Day ", days)
    else:
        return


def ft_count_harvest_recursive() -> None:
    days_to_harvest = input("Days until harvest: ")
    ft_count_harvest_recursive_helper(int(days_to_harvest))
    print("Harvest time!")
