#program to check if the three numbers are sides of a triangle or not
#


def triangle(a,b,c):
    if a+b>c and b+c>a and c+a>b:
        return True
    else:
        return False

def main():

    #get the three sides of the triangle
    a=float(input("Enter the first side: "))
    b=float(input("Enter the second side: "))
    c=float(input("Enter the third side: "))
    if triangle(a,b,c):
        print("The three sides form a triangle")
    else:
        print("The three sides do not form a triangle")

        

main()


