# Online Marketplace Application Project

### Mikhail Rybalka 153918

A simple e-commerce system implemented in C++ that allows users to log in as either customers or sellers, perform various actions such as viewing account information, adding products (for sellers), and making purchases (for customers), and features a looped menu for ongoing interactions.

## The application includes:

### 1. User Classes:

User: The base class for both customers and sellers. It includes common attributes such as username, email, password, and balance. It also has methods for retrieving user information and updating the balance.
Customer: Inherits from User and includes additional attributes like the customer's address. It overrides the display_info method to show specific information for customers.
Seller: Inherits from User and includes additional attributes such as rating, number of rates, and a vector of sales. Sellers can add sales, display their information, and update their ratings.

### 2.Product Class:

Product: Represents a product with attributes such as ID, name, category, price, and the seller. It has a method to display product information.

### 3.Database Classes:

Database: An abstract base class for database-related classes.
Customers_DB, Sellers_DB, Products_DB: Implementations of the database classes for customers, sellers, and products, respectively. They provide methods for adding, finding, and retrieving the size of the stored entities.

### 4.User Interface Functions:

seller_ui: Function to handle the seller's user interface, including options for account information, adding products, viewing sales, and logging out.
customer_ui: Function to handle the customer's user interface, including options for account information, product search, balance top-up, and logging out.

### 5.Login and Account Creation:

log_in: Function to handle user login, distinguishing between sellers and customers. It prompts for username and password, checks the credentials, and directs the user to the appropriate interface.
create_account: Function to create a new account. It prompts for account type, username, password, email, and additional details (address for customers).

### 6.Main Function:

main: The main function initializes the system with some predefined sellers, customers, and products. It then presents a menu for logging in, creating an account, or exiting the program. It contains an infinite loop for user interaction.

### 7.Menu and Program Flow:

The program provides a main menu with options to log in, create an account, or exit.
After logging in, users are directed to specific interfaces based on their role (seller or customer).
Users can perform various actions, such as viewing account information, adding products (for sellers), searching for products (for customers), making purchases, and logging out.

### 8.Looping and Exiting:

The program runs in an infinite loop, allowing users to perform multiple actions without restarting.
Users can exit the program by selecting the appropriate option from the main menu.
