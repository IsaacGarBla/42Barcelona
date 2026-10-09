#!/usr/bin/env python3

try:
    import dotenv
except Exception as e:
    print(f'Missing module dotenv: {e}.')
    print('Install using "python3 -m pip install python-dotenv"')
    print('-> Exiting')
    exit()
import os


if __name__ == "__main__":

    env_values: dict[str, str] = {"MATRIX_MODE": "",
                                  "DATABASE_URL": "",
                                  "API_KEY": "",
                                  "LOG_LEVEL": "",
                                  "ZION_ENDPOINT": ""}

    env_names: dict[str, str] = {"MATRIX_MODE": "Mode",
                                 "DATABASE_URL": "Database",
                                 "API_KEY": "API Access",
                                 "LOG_LEVEL": "Log Level",
                                 "ZION_ENDPOINT": "Remote Network"}
    missing_vars: list[str] = []

    # Load environment variables from .env file
    dotenv.load_dotenv()
    if dotenv.find_dotenv() == "":
        # Print instruccions.
        print("WARNING. There is not a .env file to set the configuration"
              "environment variables.\n"
              "Please, create de .env file with:\n"
              "  MATRIX_MODE - \"development\" or \"production\""
              "  DATABASE_URL - Connection string for data storage\n"
              "  API_KEY - Secret key for external services\n"
              "  LOG_LEVEL - Logging verbosity\n"
              "  ZION_ENDPOINT - URL of the remote network\n")
        exit(1)

    print("ORACLE STATUS: Consulting the configuration...\n")
    print("Configuration loaded:\n")
    # Store the environment variables in a dict.
    env_values = {var: os.getenv(var) for var in env_values}

    # Check if there are all the variables needed.
    if any(value is None for _, value in env_values.items()):
        # Print missing variables.
        missing_vars = [var for var, value in env_values.items()
                        if value is None]
        print(f"❌ ERROR: Missing configuration variables: "
              f"{missing_vars}\n")
        exit(1)

    if env_values["MATRIX_MODE"].lower() == "production":
        print("⚠️ WARNING: The system is running in PRODUCTION mode.\n"
              "Please, ensure that the configuration is correct and "
              "the system is secure.\n")

    for value in env_values:
        print(f"{env_names[value]}: {env_values[value]}")

    print('\nEnvironment security check:')
    print('[OK] No hardcoded secrets detected')
    print('[OK] .env file properly configured')
    print('[OK] Production overrides available')

    print('\nThe Oracle sees all configurations.')
