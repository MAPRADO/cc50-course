
# A program that calculates the approximate school level required
# to understand some text

from cs50 import get_string


# Receive input the user
txt = get_string("Text: ")

# Count the number of letters that there is in text
letters = 0
words = 1
sentences = 0

for i in range(len(txt)):
    if (txt[i] >= 'a' and txt[i] <= 'z') or (txt[i] >= 'A' and txt[i] <= 'Z'):
        letters += 1

    # Count the number of words that there is in text
    if txt[i] == ' ':
        words += 1

    # Count the number of sentences that there are in the text
    if txt[i] == '.' or txt[i] == '!' or txt[i] == '?':
        sentences += 1

# Calculating the "Coleman-Liau" index
L = (letters / words) * 100
S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

# Calculate the level of the calculated degree
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
