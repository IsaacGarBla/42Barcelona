# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plant_age.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 19:14:00 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 20:28:47 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_plant_age() -> None:
    age = input("Enter plant age in days: ")
    if int(age) > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
