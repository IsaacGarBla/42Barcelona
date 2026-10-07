#!/usr/bin/env python3

import sys
import os
import site


def virtual_enviroment() -> None:
    return sys.prefix != sys.base_prefix


if __name__ == "__main__":

    exec_route = sys.executable
    enviroment_route = os.path.dirname(exec_route)
    enviroment_name = os.path.basename(enviroment_route)

    if virtual_enviroment():
        print("\nMATRIX STATUS: You're still plugged in")
        print("\nCurrent Python: ", sys.executable)
        print("Virtual Enviroment: ", os.path.basename(sys.prefix))
        print("Enviroment Path: ", sys.prefix)
        print("\nSUCCESS: You're in an isolated environment!\n"
              "Safe to install packages without affecting\n"
              "the global system.")
        print("\nPackage installation path:", site.getsitepackages()[0])
    else:
        print("\nLABORATORY STATUS: You are working in the open")
        print("\nCurrent Python: ", sys.executable)
        print("Virtual Enviroment: None detected")
        print("\nWARNING: You're in the global environment!")
        print("Every reagent you install here leaks into the whole system.")
        print("\nTo seal the laboratory, run:")
        print("python -m venv lab_env")
        print("source lab_env/bin/activate # On Unix")
        print("lab_env\\Scripts\\activate # On Windows")
        print("\nThen run this program again.")
