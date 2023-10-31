import os
import math
import sys

def main():

    differ = 0
    press = 0
    read = 0

    press = int(input("What pressure do you want? "))
    read = int(input("Machine reading: "))

    if press > 30:
        print("Reading Error")

    elif press == read:
        print("Pressure is okay")

    elif press < read:
        differ = read - press
        print("Remove pressure from: ", differ)

    elif press > read:
        differ = press - read
        print("Add pressure from: ", differ)


if __name__ == "__main__":

    main()