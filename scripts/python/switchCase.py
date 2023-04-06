"""

"""


def printIfElse(keys=[], values=[], opt="opt", indent=""):
    """

    """

    if len(keys) != len(values):
        raise ValueError("The number of keys and values must be identical.")

    for i in range(0, len(keys)):
        print(f"{indent}if ({opt} == {keys[i]}) {{ return \"{values[i]}\"; }}")


def printSwitch(keys=[], values=[], opt="opt", indent=""):
    """

    """

    if len(keys) != len(values):
        raise ValueError("The number of keys and values must be identical.")

    print(f"{indent}switch ({opt}) {{")
    for i in range(0, len(keys)):
        print(f"{indent * 2}case {keys[i]}:")
        print(f"{indent * 3}return \"{values[i]}\";")
    print(f"{indent}}}")


if __name__ == "__main__":
    types = [
        "NONE",
        "BUG",
        "DRAGON",
        "ELECTRIC",
        "FIGHTING",
        "FIRE",
        "FLYING",
        "GHOST",
        "GRASS",
        "GROUND",
        "ICE",
        "NORMAL",
        "POISON",
        "PSYCHIC",
        "ROCK",
        "WATER"
    ]

    prefix = "    "
    qualified = ["Type::" + str(t) for t in types]

    printIfElse(types, qualified, opt="string", indent=prefix)
    printIfElse(qualified, types, opt="type", indent=prefix)
