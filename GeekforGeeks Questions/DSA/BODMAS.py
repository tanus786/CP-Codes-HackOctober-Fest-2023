import re

def calculator():
    
    while True:
        user_input = input("Enter an expression (or 'q' to quit): ")
        if user_input == 'q':
            break
        # check if the input is a valid mathematical expression
        if re.match("^[0-9+\-*/(). ]+$", user_input):
            try:
                result = eval(user_input)
                print("Result:", result)
            except:
                print("Invalid expression.")
        else:
            print("Invalid input. Please enter a valid mathematical expression.")

calculator()

