# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plot_area.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: igarcia- <igarcia-@student.42barcelona.   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 18:58:38 by igarcia-         #+#    #+#              #
#    Updated: 2026/05/26 19:01:47 by igarcia-        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def ft_plot_area() -> None:
    lenght = input("Enter length: ")
    width = input("Enter widht: ")
    print("Plot area:", int(lenght) * int(width))
