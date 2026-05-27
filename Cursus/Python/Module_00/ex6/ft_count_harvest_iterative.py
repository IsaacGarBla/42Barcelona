# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_count_harvest_iterative.py                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 19:31:46 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 20:24:39 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_count_harvest_iterative() -> None:
    days = input("Days until harvest: ")
    numbers = range(1, int(days) + 1)
    for i in numbers:
        print("Day ", i)
    print("Harvest time!")
