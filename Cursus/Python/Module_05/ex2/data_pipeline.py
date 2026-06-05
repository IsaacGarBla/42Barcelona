#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  data_pipeline.py                                  :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/04 23:55:50 by igarciab        #+#    #+#               #
#  Updated: 2026/06/05 13:15:46 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import abc
import typing


class ExportPlugin(typing.Protocol):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class ExportCSV(ExportPlugin):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        if data:
            print(*(text for _, text in data), sep=", ")


class ExportJSON(ExportPlugin):
    contenido: str

    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")
        if data:
            contenido = ", ".join((f"\"item_{number}\": \"{text}\""
                                   for number, text in data))
            print(f"{{{contenido}}}")


class DataProcessor(abc.ABC):
    _data: list[tuple[int, str]]
    _statistics: "Statistics"

    class Statistics:
        _items_processed: int
        _items_remaining: int

        def __init__(self) -> None:
            self._items_processed = 0
            self._items_remaining = 0

        @property
        def items_processed(self) -> int:
            return self._items_processed

        @items_processed.setter
        def items_processed(self, n: int) -> None:
            self._items_processed = n

        @property
        def items_remaining(self) -> int:
            return self._items_remaining

        @items_remaining.setter
        def items_remaining(self, n: int) -> None:
            self._items_remaining = n

    @property
    def statistics(self) -> Statistics:
        return self._statistics

    def __init__(self) -> None:
        self._data = []
        self._statistics = self.Statistics()

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        data: tuple[int, str] = (-1, "")

        if len(self._data) > 0:
            data = self._data[0]
            del self._data[0]
            self.statistics.items_remaining -= 1
        return data


class NumericProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__()
        self.__class__.__name__ = "Numeric Processor"

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(isinstance(item, (int, float)) for item in data)
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if self.validate(data):
            if not isinstance(data, list):
                self._data += [(self.statistics.items_processed, str(data))]
                self.statistics.items_remaining += 1
                self.statistics.items_processed += 1
            else:
                for item in data:
                    self._data += [(self.statistics.items_processed,
                                    str(item))]
                    self.statistics.items_remaining += 1
                    self.statistics.items_processed += 1
            return
        raise ValueError("Got exception: Improper numeric data")


class TextProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__()
        self.__class__.__name__ = "Text Processor"

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return False

    def ingest(self, data: str | list[str]) -> None:
        if self.validate(data):
            if not isinstance(data, list):
                self._data += [(self.statistics.items_processed, str(data))]
                self.statistics.items_remaining += 1
                self.statistics.items_processed += 1
            else:
                for item in data:
                    self._data += [(self.statistics.items_processed,
                                    str(data))]
                    self.statistics.items_remaining += 1
                    self.statistics.items_processed += 1
            return
        raise ValueError("Got exception: Improper string data")


class LogProcessor(DataProcessor):
    _VALID_KEYS: list[str] = ["log_level", "log_message"]

    def __init__(self) -> None:
        super().__init__()
        self.__class__.__name__ = "Log Processor"

    def validate(self, data: typing.Any) -> bool:
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
                self._data += [(self.statistics.items_processed,
                                f"{data[self._VALID_KEYS[0]]}: "
                                f"{data[self._VALID_KEYS[1]]}")]
                self.statistics.items_remaining += 1
                self.statistics.items_processed += 1
            else:
                for d in data:
                    self._data += [(self.statistics.items_processed,
                                    f"{d[self._VALID_KEYS[0]]}: "
                                    f"{d[self._VALID_KEYS[1]]}")]
                    self.statistics.items_remaining += 1
                    self.statistics.items_processed += 1
            return
        raise ValueError("Got exception: Improper log data")


class DataStream:
    _processors: list[DataProcessor]

    def __init__(self) -> None:
        self._processors = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for data in stream:
            for processor in self._processors:
                if processor.validate(data):
                    processor.ingest(data)
                    break
            else:
                print("DataStream error - Can't process element in stream:",
                      data)

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if len(self._processors) == 0:
            print("No processor found, no data")
            return

        for process in self._processors:
            print(f"{process.__class__.__name__}: "
                  f"total {process.statistics.items_processed} processed "
                  f"remaining {process.statistics.items_remaining} "
                  "on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        cont: int = 0
        item_list: list[tuple[int, str]]

        for process in self._processors:
            cont = 1
            item_list = []
            while cont <= nb and process.statistics.items_remaining > 0:
                item_list += [process.output()]
                cont += 1
            plugin.process_output(item_list)
        pass


def main() -> None:
    d_stream: DataStream

    print("=== Code Nexus - Data pipeline ===\n")
    print("Inicialice Data Stream...\n")
    d_stream = DataStream()
    d_stream.print_processors_stats()

    print("Registerin processors...\n")
    d_stream.register_processor(NumericProcessor())
    d_stream.register_processor(TextProcessor())
    d_stream.register_processor(LogProcessor())

    stream = ['Hello world', [3.14, -1, 2.71],
              [{'log_level': 'WARNING',
                'log_message': 'Telnet access! Use ssh instead'},
               {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
              42, ['Hi', 'five']]
    print("Send first batch of data on stream:", stream, "\n")
    d_stream.process_stream(stream)
    d_stream.print_processors_stats()

    print("Send 3 processed data from each processor to a CSV plugin:")
    d_stream.output_pipeline(3, ExportCSV())
    print("")
    d_stream.print_processors_stats()

    stream = [21, ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
              [{'log_level': 'ERROR', 'log_message': '500 server crash'},
               {'log_level': 'NOTICE', 'log_message':
                'Certificate expires in 10 days'}],
              [32, 42, 64, 84, 128, 168], 'World hello']
    print("Send another batch of data:", stream, "\n")
    d_stream.process_stream(stream)
    d_stream.print_processors_stats()

    print("Send 5 processed data from each processor to a JSON plugin:")
    d_stream.output_pipeline(5, ExportJSON())
    print("")
    d_stream.print_processors_stats()


if __name__ == "__main__":
    main()
