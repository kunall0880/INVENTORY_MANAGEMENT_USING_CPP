# Inventory Management System

## Overview
The Inventory Management System is a C++ application designed to facilitate the management of product inventories. This system allows users to perform various operations such as adding, removing, updating, and viewing products. Additionally, users can save the current inventory to a CSV file and load inventory data from a CSV file.

## Features
- **Add Products:** Users can add new products to the inventory by providing necessary details such as ID, name, category, price, and quantity.
- **Remove Products:** Users can remove products from the inventory using their unique ID.
- **Find Products:** Users can search for products by their ID to retrieve specific details.
- **Update Products:** Users can update the details of existing products in the inventory.
- **View All Products:** Users can view the details of all products currently in the inventory.
- **Save Inventory to File:** The system can save the inventory data to a CSV file for persistence.
- **Load Inventory from File:** Users can load product data from a CSV file to restore previous inventory states.

## Code Structure

### Classes
1. **Product Class**
   - Represents an individual product in the inventory.
   - Attributes:
     - `id`: A unique identifier for the product.
     - `name`: The name of the product.
     - `category`: The category under which the product falls.
     - `price`: The price of the product.
     - `quantity`: The available stock of the product.
   - Methods:
     - Getters and setters for each attribute to access and modify product information.

2. **Inventory Class**
   - Manages a collection of `Product` objects.
   - Attributes:
     - `products`: A vector that holds all the products in the inventory.
   - Methods:
     - `addProduct`: Adds a new product to the inventory while checking for duplicate IDs.
     - `removeProduct`: Removes a product from the inventory by its ID.
     - `findProduct`: Searches for a product by its ID and returns a pointer to the product if found.
     - `updateProduct`: Updates the details of an existing product.
     - `printProduct`: Displays the details of all products in the inventory.
     - `saveInventoryToFile`: Saves the current inventory to a specified CSV file.
     - `loadInventoryFromFile`: Loads products from a specified CSV file into the inventory.

### Main Function
- The `main` function serves as the entry point for the application. It presents a menu-driven interface allowing users to interact with the inventory system. Users can select options to perform various operations, and the program will execute the corresponding actions based on user input.

## Usage
1. **Compiling the Code:** Use a C++ compiler (e.g., g++) to compile the code. Ensure that the necessary libraries are included.
   ```bash
   g++ -o inventory_management inventory_management.cpp
