#!/usr/bin/env python3

from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime


# Define ContactType enum with contact types.
class ContactType(str, Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    """
    A Pydantic model for validating user data.
    """
    contact_id:         str = Field(min_length=5, max_length=15,
                                    description="The contact's ID")
    timestamp:          datetime = Field(
                                         description="DateTime of contact")
    location:           str = Field(min_length=3, max_length=100,
                                    description="Contact's location")
    contact_type:       ContactType = Field(description="Type of contact")
    signal_strength:    float = Field(ge=0, le=10,
                                      description="Signal Strength")
    duration_minutes:   int = Field(ge=1, le=1440,
                                    description="Duration")
    witness_count:      int = Field(ge=1, le=100,
                                    description="Number of witness")
    message_received:  str | None = Field(default=None, max_length=500,
                                           description="Message received")
    is_verified:        bool = Field(default=False, description="Verified")

    @model_validator(mode='after')
    def verificar_coherencia_sistema(self) -> 'AlienContact':
        # Check rules

        # contact_id must starts with AC
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must starts with 'AC'")

        # Physical contact reports must be verified
        if self.contact_type == ContactType.PHYSICAL and not self.is_verified:
            raise ValueError("Physical contacts must be verified")

        # Telepathoc contact requieres at least 3 witness
        if self.contact_type == ContactType.TELEPATHIC and \
           self.witness_count < 3:
            raise ValueError("Telepathic contacts "
                                  "needs at least 3 witnesses")

        # Strong signals (> 7.0) should include received messages
        if self.signal_strength > 7 and \
           self.message_received is None:
            raise ValueError("Strong signals (> 7.0) should include received messages")

        return self


if __name__ == "__main__":
    # Example usage
    contact_data = {
        "contact_id": "AC_2024_001",
        "timestamp": datetime.now(),
        "contact_type": "radio",
        "location": "Area 51, Nevada",
        "signal_strength": 8.5,
        "duration_minutes": 45,
        "witness_count": 5,
        "message_received": "Greetings from Zeta Reticuli"
    }

    alien_contact = AlienContact(**contact_data)
    print("Alien Contact Log Validation\n"
          "========================================")
    print("Valid contact report:")
    print(f"ID: {alien_contact.contact_id}")
    print(f"Type: {alien_contact.contact_type}")
    print(f"Location: {alien_contact.location}")
    print(f"Signal: {alien_contact.signal_strength}//10")
    print(f"Duration: {alien_contact.duration_minutes}")
    print(f"Witness: {alien_contact.witness_count}")
    print(f"Message: {alien_contact.message_received}")
    print("========================================")

    contact_data["message_received"] = None
    try:
        print("Expected validation error:")
        alien_contact = AlienContact(**contact_data)
    except ValidationError as e:
        print(e)

    contact_data["message_received"] = "Greetings from Zeta Reticuli"
    contact_data["contact_id"] = "XX" + contact_data["contact_id"]
    try:
        print("Expected validation error:")
        alien_contact = AlienContact(**contact_data)
    except ValidationError as e:
        print(e)

    contact_data["contact_id"] = "AC_2024_001"
    contact_data["contact_type"] = ContactType.PHYSICAL
    try:
        print("Expected validation error:")
        alien_contact = AlienContact(**contact_data)
    except ValidationError as e:
        print(e)

    contact_data["contact_type"] = ContactType.TELEPATHIC
    contact_data["witness_count"] = 1
    try:
        print("Expected validation error:")
        alien_contact = AlienContact(**contact_data)
    except ValidationError as e:
        print(e)