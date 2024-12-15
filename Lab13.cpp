#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}
    virtual ~Product() {} 

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }

    virtual double getFinalPrice() const = 0;
};

class Book : public Product {
public:
    Book(string n, double p) : Product(n, p) {}

    double getFinalPrice() const override {
        return price * 0.5;
    }
};

class Pen : public Product {
public:
    Pen(string n, double p) : Product(n, p) {}

    double getFinalPrice() const override {
        return (price > 5) ? price - 5 : price;
    }
};

int main() {
    vector<Product*> products; 
    int choice;
    double price;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Add Pen\n";
        cout << "3. Show All Products\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the price of the Book: ";
                cin >> price;
                products.push_back(new Book("Book", price));
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter the price of the Pen: ";
                cin >> price;
                products.push_back(new Pen("Pen", price));
                cout << "Pen added successfully!" << endl;
                break;
            }
            case 3: {
                cout << "\nList of Products:\n";
                for (const auto& product : products) {
                    cout << "Product: " << product->getName() << endl;
                    cout << "Base Price: " << product->getPrice() << " USD" << endl;
                    cout << "Final Price after discount: " << product->getFinalPrice() << " USD" << endl << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    for (auto product : products) {
        delete product;
    }

    return 0;
}
