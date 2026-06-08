#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_achievement_tracker.py                         :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/01 18:02:39 by igarciab        #+#    #+#               #
#  Updated: 2026/06/08 11:06:25 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import random


def gen_player_achievements(achiev_list: list[str],
                            number: int = 1) -> list[str]:
    return random.sample(achiev_list, number)


def main() -> None:
    achievs: list[str] = ['Crafting Genius', 'World Savior',
                          'Master Explorer', 'Collector Supreme',
                          'Untouchable', 'Boss Slayer',
                          'Crafting Genius', 'Strategist',
                          'World Savior', 'Unstoppable',
                          'Untouchable', 'Speed Runner',
                          'Survivor', 'Treasure Hunter',
                          'First Steps', 'Sharp Mind']
    players: list[tuple[str, set[str]]] = []

    players.append(("Alice", set(gen_player_achievements(achievs, 6))))
    players.append(("Bob", set(gen_player_achievements(achievs, 7))))
    players.append(("Charlie", set(gen_player_achievements(achievs, 9))))
    players.append(("Dylan", set(gen_player_achievements(achievs, 5))))

    print(f"Player {players[0][0]}: {players[0][1]}")
    print(f"Player {players[1][0]}: {players[1][1]}")
    print(f"Player {players[2][0]}: {players[2][1]}")
    print(f"Player {players[3][0]}: {players[3][1]}\n")

    print(f"All distinct achievements: {set.union(players[0][1],
                                                  players[1][1],
                                                  players[2][1],
                                                  players[3][1])}\n")

    print(f"Common achievements {set.intersection(players[0][1],
                                                  players[1][1],
                                                  players[2][1],
                                                  players[3][1])}\n")

    print(f"Only {players[0][0]} has: "
          f"{players[0][1].difference(players[1][1],
                                      players[2][1],
                                      players[3][1])}")
    print(f"Only {players[1][0]} has: "
          f"{players[1][1].difference(players[0][1],
                                      players[2][1],
                                      players[3][1])}")
    print(f"Only {players[2][0]} has: "
          f"{players[2][1].difference(players[0][1],
                                      players[1][1],
                                      players[3][1])}")
    print(f"Only {players[3][0]} has: "
          f"{players[3][1].difference(players[0][1],
                                      players[1][1],
                                      players[2][1])}\n")

    print(f"{players[0][0]} is missing: "
          f"{set(achievs).difference(players[0][1])}")
    print(f"{players[1][0]} is missing: "
          f"{set(achievs).difference(players[1][1])}")
    print(f"{players[2][0]} is missing: "
          f"{set(achievs).difference(players[2][1])}")
    print(f"{players[3][0]} is missing: "
          f"{set(achievs).difference(players[3][1])}")


if __name__ == "__main__":
    main()
