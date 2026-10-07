# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_harvest_total.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 19:08:09 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 20:27:22 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_harvest_total() -> None:
    day1 = input("Day 1 harvest: ")
    day2 = input("Day 2 harvest: ")
    day3 = input("Day 3 harvest: ")
    print("Total harvest:", int(day1) + int(day2) + int(day3))
