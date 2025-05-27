import mysql.connector

# Establishing connection with MySQL database
db_connection = mysql.connector.connect(
    host="localhost",
    user="your_username",
    password="your_password",
    database="restaurant_db"
)

# Creating cursor object to execute SQL queries
cursor = db_connection.cursor()

# Function to display menu
def display_menu():
    cursor.execute("SELECT * FROM menu")
    menu_items = cursor.fetchall()
    print("Menu:")
    for item in menu_items:
        print(item[0], item[1], item[2])

# Function to place order
def place_order():
    display_menu()
    order_id = int(input("Enter item id to order: "))
    quantity = int(input("Enter quantity: "))
    cursor.execute("SELECT item_name, price FROM menu WHERE item_id = %s", (order_id,))
    item = cursor.fetchone()
    total_price = quantity * item[1]
    print(f"You ordered {quantity} {item[0]}(s). Total Price: {total_price}")
    confirm_order = input("Confirm order (yes/no): ")
    if confirm_order.lower() == "yes":
        cursor.execute("INSERT INTO orders (item_id, quantity, total_price) VALUES (%s, %s, %s)",
                       (order_id, quantity, total_price))
        db_connection.commit()
        print("Order placed successfully!")
    else:
        print("Order canceled.")

# Main function
def main():
    while True:
        print("\nWelcome to Our Restaurant!")
        print("1. Display Menu")
        print("2. Place Order")
        print("3. Exit")
        choice = input("Enter your choice: ")
        if choice == "1":
            display_menu()
        elif choice == "2":
            place_order()
        elif choice == "3":
            break
        else:
            print("Invalid choice! Please enter a valid option.")

    cursor.close()
    db_connection.close()
    print("Thank you for visiting our restaurant!")

if __name__ == "__main__":
    main()
