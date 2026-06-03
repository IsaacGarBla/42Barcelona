#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_vault_security.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/03 12:25:53 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/03 17:25:49 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

READ = "R"
WRITE = "W"


def secure_archive(filename: str, oper: str = WRITE,
                   content: str = "") -> tuple[bool, str]:
    result: bool = False
    assoc_content: str = content

    try:
        if oper == WRITE:
            with open(filename, "w") as file:
                file.write(content)
                result = True
        elif oper == READ:
            with open(filename, "r") as file:
                assoc_content = file.read()
                result = True
        else:
            assoc_content = f"Error, operation {oper} not admitted."
    except Exception as e:
        assoc_content = f"{e}"
    return (result, assoc_content)


def main() -> None:
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file", "R"), "\n")
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("ancient_fragment_blocked.txt", "R"), "\n")
    print("Using 'secure_archive' to read from a regular file:")
    print(secure_archive("ancient_fragment.txt", "R"), "\n")
    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_file.txt", "W",
                         "Content successfully written to file"), "\n")
    print("Using 'secure_archive' with a WRONG operation:")
    print(secure_archive("ancient_fragment.txt", "X"), "\n")
    return


if __name__ == "__main__":
    main()
