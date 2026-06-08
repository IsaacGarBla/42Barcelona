# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_water_reminder.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 19:21:00 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 20:29:30 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_water_reminder() -> None:
    days = input("Days since last watering: ")
    if int(days) > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
