from cs50 import get_int


# Define the loop for rows and columns
# Print the "#" to form the left pyramid

def main():

    height = get_positive_int()
    for i in range(0, height, 1):
        for j in range(0, height, 1):
            if i + j < height - 1:
                print(" ", end="")
            else:
                print("#", end="")
        print()


# Will prompt the user for the height of the pyramid
# Will receive only integers between 0 and 8
# The function will return the pyramid's height to "main

def get_positive_int():

    while True:
        n = get_int("What height you want? ")
        if n > 0 and n < 9:
            break
    return n


main()

