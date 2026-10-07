#!/usr/bin/env python3
import importlib


def check_reagent(name: str) -> tuple[str | None, bool]:
    """ Tries to import a reagent library and returns """
    """ its version if available. """
    try:
        # Import the reagent dynamically
        module = importlib.import_module(name)
        # Get the version of the reagent if it exists
        version = getattr(module, "__version__", "Unknown version")
        return version, True
    except ImportError:
        return None, False


def main():
    reagents:   dict[str, str] = {"pandas": "Data manipulation ready",
                                  "numpy": "Numerical computation ready"}
    missing_reagents: list[str] = []

    print("REAGENT STATUS: Loading reagents...\n")
    for reagent in reagents:
        version, available = check_reagent(reagent)
        if available:
            print(f"[OK] {reagent} ({version}) - {reagents[reagent]}")
        else:
            print(f"[ERR] Reagent '{reagent}' "
                  "is not available in this environment.")
            missing_reagents.append(reagent)

    print("\n-------------------------------------------")

    if missing_reagents:
        print("\n[HELP] To restore the missing reagents, "
              "uses one of this commands:\n")

        print("  OPTION A: Using pip")
        print(f"    pip install {' '.join(missing_reagents)}")
        print("    Or restoring the whole laboratory: "
              "pip install -r ex0/requirements.txt\n")

        print("  OPTION B: Using Poetry")
        print(f"    poetry add {' '.join(missing_reagents)}")
        print("    Or restoring the whole laboratory: poetry install\n")
    else:
        print("\n[SUCCESS] All reagents are ready for the transmutation!\n")

    print("pip vs Poetry")
    print("  requirements.txt declares what to install; "
          "pip resolves it at install time.\n"
          "  pyproject.toml declares the same constraints, "
          "and Poetry pins the resolved\n"
          "  versions in poetry.lock so every install is identical.\n")
    print("----------------------------------------------")


if __name__ == "__main__":
    main()
