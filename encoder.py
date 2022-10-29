original = input("\n Enter your password : ")
print("\n Your entered password is ",original)

alphadict = { }
file = open("hash.txt",'r')
for i in file.read().splitlines():
    temp = i.split(":")
    alphadict[temp[0]] = temp[1] 
file.close()
newpass = " "
for i in original:
    newpass+=alphadict[i]+"_"

print("\nEncrypted password : ",newpass)
