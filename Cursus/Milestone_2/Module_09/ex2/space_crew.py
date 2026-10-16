#!/usr/bin/env python3

from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime


# Define ContactType enum with contact types.
class Rank(str, Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id:          str = Field(min_length=3, max_length=10,
                                    description="Member ID")
    name:               str = Field(min_length=2, max_length=50,
                                    description="Name")
    rank:               Rank = Field(description="Rank")
    age:                int = Field(ge=18, le=88,
                                    description="Age")
    specialization:     str = Field(min_length=3, max_length=30,
                                    description="Specializaation")
    years_experience:   int = Field(ge=0, le=50,
                                    description="Years of experience")
    is_active:          bool = Field(default=True,
                                     description="Is active")


class SpaceMission(BaseModel):
    mission_id:         str = Field(min_length=5, max_length=15,
                                    description="Mission ID")
    mission_name:       str = Field(min_length=3, max_length=100,
                                    description="Mission name")
    destination:        str = Field(min_length=3, max_length=150,
                                    description="Mission destination")
    launch_date:        datetime = Field(description="Launch date")
    duration_days:      int = Field(ge=1, le=3650,
                                    description="Duration (days)")
    crew:               list[CrewMember] = Field(min_length=1, max_length=12,
                                                 description="Crew")
    mission_status:     str = Field(default="planned",
                                    description="Mission status")
    budget_millions:    float = Field(ge=1, le=10000,
                                      description="Mission budget")

    @model_validator(mode="after")
    def validate_space_mission(self) -> 'SpaceMission':

        if not all(crew.is_active for crew in self.crew):
            raise ValueError("All crew members need to be active")
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")
        if not any(crew.rank == Rank.COMMANDER for crew in self.crew) and \
           not any(crew.rank == Rank.CAPTAIN for crew in self.crew):
            raise ValueError("The crew needs, at least, "
                             "one Captain or Commander.")
        if self.duration_days > 365 and \
           sum(1 for crew in self.crew if crew.years_experience >= 5) / \
           len(self.crew) < 0.5:
            raise ValueError("For long missions (> 365 days) 50% of "
                             "crew members must have, at least, 5 years"
                             "of exerience")
        if not all(crew.is_active for crew in self.crew):
            raise ValueError("All crew members need to be active")

        return self


def show_space_mission(space_mission: SpaceMission) -> None:
    print("Space Mission Crew Validation\n"
          "========================================")
    print("Valid mission created:")
    print(f"Mission: {space_mission.mission_name}")
    print(f"ID: {space_mission.mission_id}")
    print(f"Destination: {space_mission.destination}")
    print(f"Duration: {space_mission.duration_days} days")
    print(f"Budget: ${space_mission.budget_millions:.1f}M")
    print(f"Crew size: {len(space_mission.crew)}")
    for crew in space_mission.crew:
        print(f" - {crew.name} ({crew.rank}) - {crew.specialization}")
    print("========================================")


if __name__ == "__main__":
    # Example usage
    mission_data = {
        "mission_id": "M2024_MARS",
        "mission_name": "Mars Colony Establishment",
        "destination": "Mars",
        "launch_date": datetime(2025, 12, 10),
        "duration_days": 900,
        "crew": [{
            "member_id": "Member_01",
            "name": "Sarah Connor",
            "rank": Rank.COMMANDER,
            "age": 45,
            "specialization": "Mission Command",
            "years_experience": 7,
            "is_active": True,
            },
            {
            "member_id": "Member_02",
            "name": "John Smith",
            "rank": Rank.LIEUTENANT,
            "age": 35,
            "specialization": "Navigation",
            "years_experience": 5,
            "is_active": True
            },
            {
            "member_id": "Member_03",
            "name": "Alice Johnson",
            "rank": Rank.OFFICER,
            "age": 35,
            "specialization": "Engineering",
            "years_experience": 10,
            "is_active": True
            }],
        "budget_millions": 2500
    }

    space_mission = SpaceMission(**mission_data)
    show_space_mission(space_mission)

    # mission_data["crew"][0]["years_experience"] = 1
    # mission_data["crew"][1]["years_experience"] = 1
    mission_data["crew"][0]["rank"] = Rank.OFFICER
    print("Expected validation error:")
    try:
        space_mission = SpaceMission(**mission_data)
    except ValidationError as e:
        print(f"{e}")
