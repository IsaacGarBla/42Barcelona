#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  data_processor.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/04 11:30:41 by igarciab        #+#    #+#               #
#  Updated: 2026/06/05 13:12:24 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    _data: list[tuple[int, str]]
    _index: int = 0

    def __init__(self) -> None:
        self._data = []

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        data: tuple[int, str] = (-1, "")

        if len(self._data) > 0:
            data = self._data[0]
            del self._data[0]
        return data


class NumericProcessor(DataProcessor):
    index: int = 0

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(isinstance(item, (int, float)) for item in data)
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if self.validate(data):
            if not isinstance(data, list):
                self._data += [(self._index, str(data))]
                self._index += 1
            else:
                for item in data:
                    self._data += [(self._index, str(item))]
                    self._index += 1
                return
        raise ValueError("Got exception: Improper numeric data")


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return False

    def ingest(self, data: str | list[str]) -> None:
        if self.validate(data):
            if not isinstance(data, list):
                self._data += [(self._index, str(data))]
                self._index += 1
            else:
                for item in data:
                    self._data += [(self._index, item)]
                    self._index += 1
            return
        raise ValueError("Got exception: Improper string data")


class LogProcessor(DataProcessor):
    _VALID_KEYS: list[str] = ["log_level", "log_message"]

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(isinstance(key, str) and
                       isinstance(data[key], str) for key in data)\
                       and set(data) == set(self._VALID_KEYS)
        if isinstance(data, list):
            return all(isinstance(d, dict) and
                       all(isinstance(key, str) and isinstance(d[key], str) and
                           set(d) == set(self._VALID_KEYS)
                           for key in d) for d in data)
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if self.validate(data):
            if not isinstance(data, list):
                self._data += [(self._index,
                                f"{data[self._VALID_KEYS[0]]}: "
                                f"{data[self._VALID_KEYS[1]]}")]
                self._index += 1
            else:
                for d in data:
                    self._data += [(self._index,
                                    f"{d[self._VALID_KEYS[0]]}: "
                                    f"{d[self._VALID_KEYS[1]]}")]
                    self._index += 1
            return
        raise ValueError("Got exception: Improper log data")


def main() -> None:
    p_number: NumericProcessor = NumericProcessor()
    p_text: TextProcessor = TextProcessor()
    p_log: LogProcessor = LogProcessor()
    value: tuple[int, str]

    print("\nTesting Numeric Processor...")
    print(" Trying validate input '42': ", p_number.validate(42))
    print(" Trying validate input 'Hello': ", p_number.validate('Hello'))
    try:
        print(" Test invalid ingestion of string 'foo'\
              without prior validation:")
        p_number.ingest('foo')
    except Exception as e:
        print(f" {e}")
    print(" Processing data: [1, 2, 3, 4, 5]")
    p_number.ingest([1, 2, 3, 4, 5])
    print(" Extracting 3 values...")
    for i in range(1, 4):
        value = p_number.output()
        print(f" Numeric value {value[0]}: {value[1]}")

    print("\nTesting Test Processor...")
    print(" Trying validate input '42': ", p_text.validate(42))
    print(" Trying validate input 'Hello': ", p_text.validate('Hello'))
    try:
        print(" Test invalid ingestion of not string '42'\
               without prior validation:")
        p_text.ingest(42)
    except Exception as e:
        print(f" {e}")
    print(" Processing data: ['Hello', 'Nexus', 'World']")
    p_text.ingest(['Hello', 'Nexus', 'World'])
    print(" Extracting 1 values...")
    for i in range(1, 2):
        value = p_text.output()
        print(f" Text value {value[0]}: {value[1]}")

    print("\nTesting Log Processor...")
    print(" Trying validate input 'Hello': ", p_log.validate(42))
    print(" Trying validate input '{'log_level': 'NOTICE'}': ",
          p_log.validate({'log_level': 'NOTICE',
                          'log_message': 'Connection to server'}))
    print(" Processing data: [{'log_level': 'NOTICE', 'log_message': \
          'Connection to server'}, {'log_level': 'ERROR', \
          'log_message': 'Unauthorized access!!'}]")
    p_log.ingest([{'log_level': 'NOTICE', 'log_message':
                   'Connection to server'},
                  {'log_level': 'ERROR', 'log_message':
                   'Unauthorized access!!'}])
    print(" Extracting 2 values...")
    for i in range(1, 3):
        value = p_log.output()
        print(f" Log entry {value[0]}: {value[1]}")


if __name__ == "__main__":
    main()
