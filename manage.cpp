#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// Product class definition
class Product
{
private:
    int id;          // Product ID
    string name;     // Product name
    string category; // Product category
    double price;    // Product price
    int quantity;    // Quantity in stock

public:
    // Constructor to initialize Product object
    Product(int id, string name, string category, double price, int quantity)
    {
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
        this->quantity = quantity;
    }

    // Getter for Product ID
    int getId() const
    {
        return id;
    }

    // Setter for Product ID
    void setId(int id)
    {
        this->id = id;
    }

    // Getter for Product name
    string getName() const
    {
        return name;
    }

    // Setter for Product name
    void setName(string name)
    {
        this->name = name;
    }

    // Getter for Product category
    string getCategory() const
    {
        return category;
    }

    // Setter for Product category
    void setCategory(string category)
    {
        this->category = category;
    }

    // Getter for Product price
    double getPrice() const
    {
        return price;
    }

    // Setter for Product price
    void setPrice(double price)
    {
        this->price = price;
    }

    // Getter for Product quantity
    int getQuantity() const
    {
        return quantity;
    }

    // Setter for Product quantity
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
};

// Inventory class definition
class Inventory
{
private:
    vector<Product> products; // Vector to store the list of products

public:
    // Function to add a product to the inventory
    void addProduct(Product product)
    {
        bool found = false;
        // Check if the product already exists based on its ID
        for (auto &p : products)
        {
            if (p.getId() == product.getId())
            {
                cout << "ID already exists." << endl;
                found = true;
                break;
            }
        }
        // If product doesn't exist, add it to the inventory
        if (!found)
        {
            products.push_back(product);
            cout << "Product added successfully." << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    }

    // Function to remove a product from the inventory by its ID
    void removeProduct(int id)
    {
        bool found = false;
        // Loop through the products to find the one with the given ID
        for (auto i = products.begin(); i != products.end(); i++)
        {
            if (i->getId() == id)
            {
                products.erase(i); // Remove the product
                found = true;
                cout << "Product removed successfully." << endl;
                cout << "-----------------------------------------------------------" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "ID does not exist." << endl;
        }
    }

    // Function to find a product by its ID
    Product *findProduct(int id)
    {
        // Iterate through the products to find the product with the matching ID
        for (auto i = products.begin(); i != products.end(); i++)
        {
            if (i->getId() == id)
            {
                return &(*i); // Return pointer to the found product
            }
        }
        return nullptr; // Return nullptr if not found
    }

    // Function to update a product's details
    void updateProduct(int id, string name, string category, double price, int quantity)
    {
        bool found = false;
        // Find the product by its ID
        for (auto i = products.begin(); i != products.end(); i++)
        {
            if (i->getId() == id)
            {
                // Update the product's attributes
                i->setName(name);
                i->setCategory(category);
                i->setPrice(price);
                i->setQuantity(quantity);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "ID does not exist." << endl;
        }
    }

    // Function to print all the products in the inventory
    void printProduct() const
    {
        for (auto i = products.begin(); i != products.end(); i++)
        {
            cout << "ID : " << i->getId() << endl;
            cout << "Name : " << i->getName() << endl;
            cout << "Category : " << i->getCategory() << endl;
            cout << "Price : $" << i->getPrice() << endl;
            cout << "Quantity : " << i->getQuantity() << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    }

    // Function to save the inventory to a file
    void saveInventoryToFile(string filename)
    {
        ofstream file(filename, ios::out); // Open the file for writing
        if (!file)
        {
            cout << "Error: Could not open file " << filename << " for writing." << endl;
            return;
        }
        // Write the product data to the file
        for (const auto &p : products)
        {
            file << p.getId() << "," << p.getName() << ","
                 << p.getCategory() << "," << p.getPrice()
                 << "," << p.getQuantity() << "\n";
        }
        file.close(); // Close the file
        cout << "Inventory saved successfully." << endl;
    }

    // Function to load the inventory from a file
    void loadInventoryFromFile(string filename)
    {
        ifstream file(filename); // Open the file

        // Check if the file was opened successfully
        if (!file)
        {
            cout << "Error: Could not open file " << filename << " for reading." << endl;
            return;
        }

        string line;
        int lineNumber = 1; // Keep track of the line number for error reporting

        while (getline(file, line)) // Read the file line by line
        {
            stringstream ss(line);
            string idStr, name, category, priceStr, quantityStr;

            // Parse each part of the line separated by commas
            if (!getline(ss, idStr, ',') ||
                !getline(ss, name, ',') ||
                !getline(ss, category, ',') ||
                !getline(ss, priceStr, ',') ||
                !getline(ss, quantityStr, ','))
            {
                cout << "Error: Malformed data on line " << lineNumber << endl;
                continue; // Skip this line and move to the next
            }

            try
            {
                // Convert strings to appropriate data types
                int id = stoi(idStr);
                double price = stod(priceStr);
                int quantity = stoi(quantityStr);

                // Create a new product and add it to the inventory
                Product p(id, name, category, price, quantity);
                products.push_back(p);
            }
            catch (const exception &e)
            {
                cout << "Error: Failed to parse data on line " << lineNumber << " (" << e.what() << ")" << endl;
            }

            lineNumber++; // Increment the line counter
        }

        file.close(); // Close the file
        cout << "Inventory loaded successfully from " << filename << endl;
    }
};

// Main function - Entry point of the program
int main()
{
    Inventory inventory; // Create an Inventory object
    cout << "-----------------------------------------------------------" << endl;
    cout << "---------------Inventory Management System ----------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "------------------------- Welcome! ------------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;

    char choice;
    // Menu loop
    do
    {
        cout << "Please choose an option:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. Find a product" << endl;
        cout << "4. Update a product" << endl;
        cout << "5. View all products" << endl;
        cout << "6. Save inventory to file" << endl;
        cout << "7. Load Inventory from file" << endl;
        cout << "Q. Quit" << endl;
        cin >> choice;

        // Switch-case to handle user choices
        switch (choice)
        {
        case '1': // Add a product
        {
            int id;
            string name, category;
            double price;
            int quantity;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product category: ";
            cin >> category;
            cout << "Enter product price: $ ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            Product product(id, name, category, price, quantity);
            inventory.addProduct(product);
            break;
        }

        case '2': // Remove a product
        {
            int id;
            cout << "Enter product ID: ";
            cin >> id;
            inventory.removeProduct(id);
            break;
        }

        case '3': // Find a product
        {
            int id;
            cout << "Enter product ID: ";
            cin >> id;
            Product *product = inventory.findProduct(id);
            if (product)
            {
                // Print product details if found
                cout << "Name: " << product->getName() << endl;
                cout << "Category: " << product->getCategory() << endl;
                cout << "Price: $" << product->getPrice() << endl;
                cout << "Quantity: " << product->getQuantity() << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
            else
            {
                cout << "Product not found." << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
            break;
        }

        case '4': // Update a product
        {
            int id;
            string name, category;
            double price;
            int quantity;
            cout << "Enter the product ID: ";
            cin >> id;
            cout << "Enter new product name: ";
            cin >> name;
            cout << "Enter new product category: ";
            cin >> category;
            cout << "Enter new product price: $ ";
            cin >> price;
            cout << "Enter new product quantity: ";
            cin >> quantity;

            // Update the product details in the inventory
            inventory.updateProduct(id, name, category, price, quantity);
            cout << "Product updated successfully." << endl;
            cout << "-----------------------------------------------------------" << endl;
            break;
        }
        case '5': // View all products
        {
            cout << "Displaying all products:" << endl;
            inventory.printProduct(); // Print the list of products
            break;
        }

        case '6': // Save inventory to file
        {
            inventory.saveInventoryToFile("inventory.csv"); // Save data to a file
            cout << "Inventory saved to file." << endl;
            cout << "-----------------------------------------------------------" << endl;
            break;
        }

        case '7': // Load inventory from file
        {
            inventory.loadInventoryFromFile("inventory.csv"); // Load data from a file
            cout << "Inventory loaded from file." << endl;
            cout << "-----------------------------------------------------------" << endl;
            break;
        }

        case 'q': // Quit the program
        case 'Q':
            cout << "Goodbye! Thank you for using the Inventory Management System, Kunal!" << endl;
            cout << "-----------------------------------------------------------" << endl;
            return 0; // Exit the program

        default: // Handle invalid input
            cout << "Invalid choice. Please try again." << endl;
            cout << "-----------------------------------------------------------" << endl;
            break;
        }

    } while (true); // Keep the menu running until the user quits

    return 0; // End of main function
}
