from cs50 import get_float

# Positive value input and float
cash = 0
coins25 = 0
coins10 = 0
coins5 = 0
coins1 = 0

while True:
    cash = get_float("Change owed: ")
    if cash > -1:
        break

# Convert "float" to "int". The "round" is a function that returns
# The integer closest to the number passed as argument
cents = round(cash * 100, 2)

# Counting the quarter coins
while cents > 25 or cents == 25:
    cents = cents - 25
    coins25 += 1

# Counting the 10 cents coins
while cents > 10 or cents == 10:
    cents = cents - 10
    coins10 += 1

# Counting the 5 cents coins
while cents > 5 or cents == 5:
    cents = cents - 5
    coins5 += 1

# Counting the 1 cent coins
while cents > 1 or cents == 1:
    cents = cents - 1
    coins1 += 1

# Printing the result
print(f"{coins25} coins of 25 cents")
print(f"{coins10} coins of 10 cents")
print(f"{coins5} coins of 5 cents")
print(f"{coins1} coins of 1 cents")
print(f"{coins25 + coins10 + coins5 + coins1}")
