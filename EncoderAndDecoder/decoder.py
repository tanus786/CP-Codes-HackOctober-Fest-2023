password = input("\nEnter the Encrypted password : ")
encrypted_list = password.split("_")
alphadict = {}
decoded_password = ""
file = open("hash.txt", "r")

for i in file.read().splitlines():
    temp = i.split(":")
    alphadict[temp[1]] = temp[0]

file.close()

for i in encrypted_list:
    if i == "":
        pass
    else:
        decoded_password += alphadict[i]

print("\nDecrypted password : ", decoded_password)
