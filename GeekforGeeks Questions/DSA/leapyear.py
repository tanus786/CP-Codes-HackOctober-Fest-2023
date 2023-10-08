#python program to generate the next 15 leap years starting from a given year


def leapyear(year):
    #checking if the given year is leap year or not
    if year %4==0:
        #checking if the given year is century year or not
        if year %100==0:
            #checking if the given year is divisible by 400 or not
            if year %400==0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False

def main():
    year = int(input("Enter the year: "))
    print("The next 15 leap years are: ")
    for i in range(60):
        year = year + 1
        if leapyear(year):
            print(year)

main()

