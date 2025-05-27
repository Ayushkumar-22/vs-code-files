numbers = [1,2,4,2,6,8]
unique = []
for number in numbers:
    if number not in unique:
        unique.append(number)
print(unique)