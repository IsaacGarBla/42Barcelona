#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_data_alchemist.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/04 09:32:25 by igarciab        #+#    #+#               #
#  Updated: 2026/06/08 17:56:12 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import random

PLAYERS = ["Alice", "bob", "Charlie", "dylan", "Emma", "Gregory", "jhon",
           "kevin", "Liam"]


def main() -> None:
    players = ["Alice", "bob", "Charlie", "dylan", "Emma", "Gregory", "jhon",
           "kevin", "Liam"]
    capitalize_list: list[str] = []
    only_upper_list: list[str] = []
    score_dict: dict[str, int] = {}
    average_score: float
    high_scores_dict: dict[str, int] = {}

    print("=== Game Data Alchemist ===\n")
    print("Initial list of players:", players)
    capitalize_list = [item.capitalize() for item in players]
    print("New list with all names capitalize:", capitalize_list)
    only_upper_list = [item for item in players if item and item[0].isupper()]
    print("New list of capitalized names only:", only_upper_list)
    score_dict = {item: random.randrange(1, 1000) for item in capitalize_list}
    print("\nScore dict:", score_dict)
    average_score = round(sum([score_dict[key] for
                               key in score_dict]) / len(score_dict), 2)
    print("Score average: ", average_score)
    high_scores_dict = {key: score_dict[key]
                        for key in score_dict
                        if key and score_dict[key] > average_score}
    print("High scores:", high_scores_dict)


if __name__ == "__main__":
    main()
