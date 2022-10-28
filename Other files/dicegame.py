'''''''''

Dice Game v2.3
Press RUN and roll your dice.
Can you beat your opponent?

v2.3 updates:
- Damo helped me.
- Code looks more beautiful now |^_^|

v2.2 updates:
- Mostafa Amean helped me.
- Code is now more more more short ^_^

v2.1 updates:
- Defines changed.
- Code is now more more short.

v2.0 updates:
- Now both players rolls 2 dice.
- Code is now more short.

'''''''''

### Thanks for all repo like  ^_^ ###
## This code is very easy to understand ##

print(" Dice Game v2.3 \n Made by Vishal Kumar \n")
###die define
def die(num):
 print("|------------|")
 if num == 1:
    print("|            |")
    print("|            |")
    print("|      O     |")
    print("|            |")
    print("|            |")
 if num == 2:
    print("|            |")
    print("|         O  |")
    print("|            |")
    print("|   O        |")
    print("|            |")
 if num == 3:
    print("|            |")
    print("|         O  |")
    print("|      O     |")
    print("|   O        |")
    print("|            |")
 if num == 4:
    print("|            |")
    print("|   O     O  |")
    print("|            |")
    print("|   O     O  |")
    print("|            |")
 if num == 5:
    print("|   O     O  |")
    print("|            |")
    print("|      O     |")
    print("|            |")
    print("|   O     O  |")
 if num == 6:
    print("|   O     O  |")
    print("|            |")
    print("|   O     O  |")
    print("|            |")
    print("|   O     O  |")
 print("|------------|")

from random import randint as r
##d=random.randint(1,6) >> d=r(1,6)

###Die 1###
d1=r(1,6)
die(d1)
###Die 2###
d2=r(1,6)
die(d2)
a = d1+d2
print("\n You rolled", a, "\n")

###Die 3###
d3=r(1,6)
die(d3)
###Die 4###
import random
d4=r(1,6)
die(d4)
b = d3+d4
print("\n Your opponent rolled", b,"\n")
print("",a,"-",b)

###Results###
if a == b:
    print(" Draw! \n Try again.")
elif a >b:
    print(" You won! \n Wanna play again?")
elif a <b:
    print(" Your opponent won. \n Wanna play again?")
print("\n \n Please like repo if you like it. \n Thanks for playing.")
