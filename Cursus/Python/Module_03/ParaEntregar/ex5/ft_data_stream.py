#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_data_stream.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/02 11:37:27 by igarciab        #+#    #+#               #
#  Updated: 2026/06/02 17:40:34 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import typing
import random

PLAYERS = ["Bob", "Alice", "Dylan", "Charlie"]
EVENTS = ["run", "eat", "sleep", "grab", "move", "climb", "swim"]


# @get_event: A generator function that yields random player-event pairs
# indefinitely.
# @return: A tuple containing a random player and a random event.
def get_event() -> typing.Generator[tuple[str, str], None, None]:
    while True:
        player = random.choice(PLAYERS)
        event = random.choice(EVENTS)
        yield (player, event)


# @consume_event: A generator function that consumes events from a list and
# yields them one by one in random order until the list is empty.
# @param event_list: A list of events to be consumed.
# @return: A generator that yields events from the list in random order.
def consume_event(event_list: list[tuple[str, str]]) -> \
                    typing.Generator[tuple[str, str], None, None]:
    while event_list:
        index = random.randrange(len(event_list))
        event = event_list[index]
        del event_list[index]
        yield event


def main() -> None:
    event_list: list[tuple[str, str]] = []
    event: tuple[str, str]

    event_generator = get_event()
    for i in range(1000):
        event = next(event_generator)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")

    for i in range(10):
        event = next(event_generator)
        event_list += [event]

    print("Built list of 10 event:", event_list)

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print("Remains in list:", event_list)


if __name__ == "__main__":
    main()
