# Laptop-Service-Center

This project is a laptop service center management system implemented in C++. It allows users to perform various operations such as adding a new customer, paying the bill, deleting a customer record, modifying a customer record, and displaying customer records.

# Features

- New Customer: Allows users to add a new customer by entering their details, including name, address, laptop name, and ID. Users can also select the repair components they want to get repaired and calculate the total repair cost.
- Pay the Bill: Users can directly pay the bill by entering the amount to be paid. The program simulates the payment processing and displays a confirmation message.
- Delete a Record: Users can delete a customer record by specifying the customer ID. The program prompts for confirmation before deleting the record. The updated records are displayed afterward.
- Modify a Record: Users can modify a customer record by specifying the customer ID. The program displays the existing record, allows the user to update the customer details, select repair components, and calculates the total repair cost. The modified record is then updated in the file.
- Display Records: Users can view all the customer records stored in the file. The program displays the customer details, including name, address, laptop name, ID, and total bill amount.
  
# How to Use

1.Clone the repository from GitHub.
2.Compile the source code using a C++ compiler.
3.Run the compiled executable file.
4.Use the menu options to perform different operations:
- Enter 1 to add a new customer, provide details, and calculate the repair cost.
- Enter 2 to pay the bill directly.
- Enter 3 to delete a customer record by specifying the customer ID.
- Enter 4 to modify a customer record by specifying the customer ID.
- Enter 5 to display all the customer records stored in the file.
- Enter 0 to exit the program.

  # File Handling

The program uses file handling to store and retrieve customer records. The customer records are stored in a file named "Laptop_shop.txt" in a specific format. Each customer's details are stored on separate lines, including their name, address, laptop name, ID, and total bill amount. The records are separated by a line of dashes for easy readability.
