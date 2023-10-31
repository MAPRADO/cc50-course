from cs50 import get_int


def main():

    # Define the loop for the rows
    height = get_positive_int()
    lines = 0
    for lines in range(height, lines > 0, -1):

        # Print the "#" to form the left pyramid
        bloc1 = 1
        for bloc1 in range(1, height + 1, 1):
            if lines > bloc1:
                print(" ", end="")
            else:
                print("#", end="")

        # Forming the spaces between the pyramids
        print("  ", end="")

        # Print the "#" to form the right pyramid
        bloc2 = 0
        for bloc2 in range(height, bloc2 > 0, -1):
            if lines < bloc2 or lines == bloc2:
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

