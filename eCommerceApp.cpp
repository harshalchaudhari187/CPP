#include <iostream>
#include <vector>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& name) : name(name) {}
};

class Product {
private:
    int id;
    std::string product_name;
    double price;

public:
    Product(int id, const std::string& product_name, double price)
        : id(id), product_name(product_name), price(price) {}

    int getId() const {
        return id;
    }

    std::string getProductName() const {
        return product_name;
    }

    double getPrice() const {
        return price;
    }
};

class Seller : public Person {
private:
    int seller_id;
    std::vector<Product> products;

public:
    Seller(const std::string& seller_name, int seller_id)
        : Person(seller_name), seller_id(seller_id) {}

    int getSellerId() const {
        return seller_id;
    }
    std::string getName() const {
    return name;
}
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    std::vector<Product> getProducts() const {
        return products;
    }
};

class ECommerceApplication {
private:
    std::vector<Seller> sellers;
    std::vector<Product> allProducts;

public:
    void addSeller() {
        std::string name;
        int sellerId;

        std::cout << "Enter seller name: ";
        std::cin >> name;

        std::cout << "Enter seller ID: ";
        std::cin >> sellerId;

        Seller seller(name, sellerId);
        sellers.push_back(seller);
    }

    void addProduct() {
        int sellerId, productId;
        std::string productName;
        double price;

        std::cout << "Enter seller ID to add product: ";
        std::cin >> sellerId;

        std::cout << "Enter product ID: ";
        std::cin >> productId;

        std::cout << "Enter product name: ";
        std::cin >> productName;

        std::cout << "Enter product price: ";
        std::cin >> price;

        Product product(productId, productName, price);

        for (auto& seller : sellers) {
            if (seller.getSellerId() == sellerId) {
                seller.addProduct(product);
                allProducts.push_back(product);
                std::cout << "Product added for seller ID " << sellerId << std::endl;
                return;
            }
        }
        std::cout << "Seller with ID " << sellerId << " not found." << std::endl;
    }

    void displayProductsBySeller() {
        int sellerId;
        std::cout << "Enter seller ID to display products: ";
        std::cin >> sellerId;

        for (const auto& seller : sellers) {
            if (seller.getSellerId() == sellerId) {
                std::vector<Product> sellerProducts = seller.getProducts();
                std::cout << "Products sold by seller " << sellerId << ":\n";
                for (const auto& product : sellerProducts) {
                    std::cout << "ID: " << product.getId() << " Name: " << product.getProductName() << " Price: $" << product.getPrice() << std::endl;
                }
                return;
            }
        }
        std::cout << "Seller with ID " << sellerId << " not found." << std::endl;
    }

    void displayAllSellers() {
        std::cout << "All Sellers:\n";
        for (const auto& seller : sellers) {
            std::cout << "Name: " << seller.getName() << " ID: " << seller.getSellerId() << std::endl;
        }
    }

    void displayAllProducts() {
        std::cout << "All Products:\n";
        for (const auto& product : allProducts) {
            std::cout << "ID: " << product.getId() << " Name: " << product.getProductName() << " Price: Rs." << product.getPrice() << std::endl;
        }
    }
};

int main() {
    ECommerceApplication app;
    int choice;

    do {
        std::cout << "\nMenu:\n"
                     "1. Add Seller\n"
                     "2. Add Product\n"
                     "3. Display products sold by specific seller\n"
                     "4. Display All Sellers\n"
                     "5. Display All Products\n"
                     "6. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                app.addSeller();
                break;
            case 2:
                app.addProduct();
                break;
            case 3:
                app.displayProductsBySeller();
                break;
            case 4:
                app.displayAllSellers();
                break;
            case 5:
                app.displayAllProducts();
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
