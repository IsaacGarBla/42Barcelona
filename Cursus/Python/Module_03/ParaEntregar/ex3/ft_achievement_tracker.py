#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_achievement_tracker.py                         :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/01 18:02:39 by igarciab        #+#    #+#               #
#  Updated: 2026/06/16 13:14:51 by igarcia-        ###   ########.fr        #
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
    all_achievs: list[set[str]]
    common_achiev: set[str]
    all_dist_achiev: set[str]
    other_achiev: set[str]

    players.append(("Alice", set(gen_player_achievements(achievs, 6))))
    players.append(("Bob", set(gen_player_achievements(achievs, 7))))
    players.append(("Charlie", set(gen_player_achievements(achievs, 9))))
    players.append(("Dylan", set(gen_player_achievements(achievs, 5))))

    for p in players:
        print(f"Player {p[0]}: {p[1]}")

    all_achievs = [item[1] for item in players]
    common_achiev = set.intersection(*all_achievs)
    all_dist_achiev = set.union(*all_achievs)
    print(f"All distinct achievements: {all_dist_achiev}\n")
    print(f"Common achievements {common_achiev}\n")

    for p in players:
        other_achiev = set.union(*(pl[1] for pl in players
                                   if pl and pl is not p))
        print(f"Only {p[0]} has: {p[1].difference(other_achiev)}")

    for p in players:
        print(f"{p[0]} is missing: "
              f"{set(achievs).difference(p[1])}")


if __name__ == "__main__":
    main()
