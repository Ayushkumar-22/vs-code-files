secret_number = 4
guess_count = 0
guess_limit = 8
print("THE SECRET NUMBER IS IN BETWEEN 0 - 10")
for guess_count in range (guess_count , 4):
    guess = int(input("guess the secret number - "))
    guess_count += 1
    if guess > secret_number:
        print("secret number is less than entered number")
    if guess < secret_number:
        print("secret number is larger than entered number")
    if guess == secret_number :
        print("You won the game")
        break
    elif guess_count == 4:
        print("THANK YOU")
try_again = int (input("Press 1 for continue or press 2 for quit - "))
if try_again == 1:
    print("THE SECRET NUMBER IS IN BETWEEN 0 - 10")
    for guess_count in range (guess_count ,guess_limit):
        guess = int(input("guess the secret number - "))
        guess_count += 1
        if guess > secret_number:
            print("secret number is less than entered number")
        if guess < secret_number:
            print("secret number is larger than entered number")
        if guess == secret_number :
            print("CONGRATULATIoNS You won the game")
            break
        elif guess_count == guess_limit:
            print("better luck next time")
    
