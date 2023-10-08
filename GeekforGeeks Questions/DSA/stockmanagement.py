product_name = input("Enter the product name: ")
product_description = input("Enter the product description: ")
# display the menu
print("1. Purchase")
print("2. Sell")
print("3. Stock")
print("q. Quit")
while True:
    option = input("Enter option (1, 2, 3 or q): ")
    if option == '1':
        purchase_name = input("Enter product name: ")
        purchase_quantity = int(input("Enter purchase quantity: "))
        purchase_date = input("Enter purchase date: ")
        # writing purchase information to text file
        with open("purchases.txt", "a") as file:
            file.write(
                f"Product: {purchase_name}, Quantity: {purchase_quantity}, Date: {purchase_date}\n")
    elif option == '2':
        sell_name = input("Enter product name: ")
        sell_quantity = int(input("Enter sell quantity: "))
        sell_amount = float(input("Enter sell amount: "))
        # writing sell information to text file
        with open("sells.txt", "a") as file:
            file.write(
                f"Product: {sell_name}, Quantity: {sell_quantity}, Amount: {sell_amount}\n")
    elif option == '3':
        stock_name = input("Enter product name: ")
        stock_purchases = int(input("Enter number of purchases: "))
        stock_sells = int(input("Enter number of sells: "))
        stock_remaining = int(input("Enter remaining stock: "))
        # writing stock information to text file
        with open("stock.txt", "a") as file:
            file.write(
                f"Product: {stock_name}, Purchases: {stock_purchases}, Sells: {stock_sells}, Remaining: {stock_remaining}\n")
    elif option == 'q':
        break

    else:

        print("Invalid option. Please enter a valid option.")
