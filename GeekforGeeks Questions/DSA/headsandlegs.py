#program to identify the number of chickens and rabbits in a farm given the total number of legs and heads
#
#
def headsandlegs(heads,legs):
    #check if the numnber of heads and legs are valid
    if legs%2==0 and legs/2>=heads and legs<=4*heads:
        #calculate the number of rabbits and chickens
        rabbits = (legs/2-heads)
        chickens = heads-rabbits
        return (rabbits,chickens)
    else:
        return None

def main():
    #get the number of heads and legs
    heads = int(input("Enter the number of heads: "))
    legs = int(input("Enter the number of legs: "))
    #check if the number of heads and legs are valid
    if headsandlegs(heads,legs):
        #display the number of rabbits and chickens
        print("The number of rabbits and chickens are: ",headsandlegs(heads,legs))
    else:
        print("The number of heads and legs are invalid")

main()
