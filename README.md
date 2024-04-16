Bank Management System in C++ with Users and Clients
This project is a console-based bank management system implemented in C++. It allows users and clients to perform various banking operations, such as creating accounts, depositing funds, withdrawing funds, transferring funds between accounts, and checking account balances. The system distinguishes between users, who are bank employees with administrative privileges, and clients, who are regular bank customers.

Features:

User Management: Users (bank employees) can create, update, and delete client accounts, as well as view transaction history and perform administrative tasks.
Client Operations: Clients can create new bank accounts, deposit and withdraw funds, transfer funds between accounts, view account details, and check transaction history.
Transaction History: All transactions are logged and can be viewed by both users and clients for tracking financial activities.
Compile: Compile the source code using a C++ compiler such as g++.
Run: Execute the compiled program to launch the bank management system.
Login: Users must log in using their credentials (username and password) to access administrative functions. (For Example =>  UserName : User1 and Password : 1234)
Menu Options: Users and clients are presented with menu options based on their roles:
Users (Administrators): Create, update, or delete client accounts
View transaction history and account details
Perform administrative tasks

Clients:

Create new bank accounts
Deposit and withdraw funds
Transfer funds between accounts
View account details and transaction history
Logout: Users can log out of the system to end their session securely.

Technologies Used

C++ programming language
Standard C++ libraries for input/output and data manipulation
Authentication and authorization mechanisms for user management

Requirements

C++ compiler (e.g., g++)
Terminal or command prompt for running the compiled program

Project Structure:

BankSystem.cpp: Contains the main source code for the bank management system.
clsUser.h, User.cpp: Implementations for the User class, handling user authentication, authorization, and administrative functions.
clsClient.h, Client.cpp: Implementations for the Client class, handling client-specific banking operations.
Account.h, Account.cpp: Implementations for the Account class, including account creation, deposit, withdrawal, and transaction history.
clsBankSystem.h, BankSystem.cpp: Main logic and menu-driven interface for the bank management system.
...

Contributing:

Contributions are welcome! If you have suggestions for improvements or new features, feel free to submit a pull request.

License:
This project is licensed under the MIT License - see the LICENSE.md file for details.
