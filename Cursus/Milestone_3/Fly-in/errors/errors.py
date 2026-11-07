class ParseException(Exception):
    def __init__(self, error: str, line: int) -> None:
        message:    str

        message = f"[Line: {line:03d}] Format error: {error}"
        super().__init__(message)


class GraphException(Exception):
    def __init__(self, error: str) -> None:
        super().__init__(error)
