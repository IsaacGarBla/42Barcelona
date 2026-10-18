#!/usr/bin/env python3

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    artifacts.sort(key=lambda x: x["power"])
    return artifacts


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda x: x["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: "* " + x + " *", spells))


def mage_stats(mages: list[dict]) -> dict:
    powers = list(map(lambda x: x["power"], mages))
    return {"max_power": max(powers),
            "min_power": min(powers),
            "avg_power": round(sum(powers) / len(powers), 2)}


if __name__ == "__main__":

    artifacts = [{'name': 'Fire Staff',
                  'power': 62, 'type':
                  'armor'},
                 {'name': 'Ice Wand',
                  'power': 86, 'type':
                  'weapon'},
                 {'name': 'Ice Wand',
                  'power': 109, 'type':
                  'accessory'},
                 {'name': 'Lightning Rod',
                  'power': 99,
                  'type': 'armor'}]

    mages = [{'name': 'Phoenix',
              'power': 89,
              'element': 'ice'},
             {'name': 'Zara',
              'power': 64,
              'element': 'fire'},
             {'name': 'Riley',
              'power': 75,
              'element': 'water'},
             {'name': 'Casey',
              'power': 86,
              'element': 'shadow'},
             {'name': 'Riley',
              'power': 97,
              'element': 'wind'}]

    spells = ['tornado', 'meteor', 'tsunami', 'shield']

    print("Testing artifact sorter...")
    for artifact in artifact_sorter(artifacts):
        print(f"  {artifact["name"]} ({artifact["power"]} power)")

    print("\nTesting power filter (power >= 75)...")
    for mage in power_filter(mages, 75):
        print(f"  {mage["name"]} ({mage["power"]} power)")

    print("\nTesting spell transformer...")
    for spell in spell_transformer(spells):
        print(f"  {spell}")

    print("\nTesting mage stats...")
    m_stats = mage_stats(mages)
    print(f"Max power: {m_stats["max_power"]}\n"
          f"Min power: {m_stats["min_power"]}\n"
          f"Avg power: {m_stats["avg_power"]}\n")
