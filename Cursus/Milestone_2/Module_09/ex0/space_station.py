#!/usr/bin/env python3

from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
import json
from pathlib import Path


class SpaceStation(BaseModel):
    """
    A Pydantic model for validating user data.
    """
    station_id:         str = Field(min_length=3, max_length=10,
                                    description="The station's ID")
    name:               str = Field(min_length=1, max_length=50,
                                    description="The station's name")
    crew_size:          int = Field(ge=1, le=20, description="Crew size")
    power_level:        float = Field(ge=0, le=100,
                                      description="Power level")
    oxygen_level:       float = Field(ge=0, le=100,
                                      description="Oxygen level")
    last_maintenance:   datetime = Field(
                                         description="Last maintenance date")
    is_operational:     bool = Field(default=True,
                                     description="Is operational")
    notes:              str | None = Field(default=None, min_length=1,
                                           max_length=200, description="Notes")


if __name__ == "__main__":
    # Example usage

    # Obtain folder sript
    folder = Path(__file__).parent.resolve()
    # Create de file
    file = folder / "../generated_data/space_stations.json"

    # Read space stations
    space_stations = json.loads(file.read_text(encoding="utf-8"))
    # Validate each space station.
    for station_data in space_stations:
        try:
            space_station = SpaceStation(**station_data)
            print("Space Station Data Validation\n"
                  "========================================")
            print("Valid station created:")
            print(f"ID: {space_station.station_id}")
            print(f"Name: {space_station.name}")
            print(f"Crew: {space_station.crew_size}")
            print(f"Power: {space_station.power_level}")
            print(f"Oxygen: {space_station.oxygen_level}")
            status = 'Operational' if space_station.is_operational \
                     else 'No Operational'
            print(f"Status: {status}")
            print("========================================\n")
        except ValidationError as e:
            print("========================================")
            print("VALIDATION Error:")
            print(f"{e}")
            print("========================================\n")
            break
