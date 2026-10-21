/*
**Q4. Online Shopping Cart Bill Calculator**
Scenario: An online shopping system contains multiple products in a customer's shopping cart. The system needs to calculate the total bill recursively.
Task:
Write a recursive C++ function calculateBill() that calculates the total cost of all products in the cart.
Requirements:
- Each product has a price and quantity.
- Calculate the subtotal of each product.
- Use recursion to process the remaining products.
- Return the final bill.
Example:
| **Product** | **Price** | **Quantity** |
| ----------- | --------- | ------------ |
| Keyboard    | 2000      | 2            |
| Mouse       | 1000      | 1            |
| Headphones  | 3000      | 2            |

Expected Output:
Total Bill = Rs. 11000
*/
#include <iostream>
using namespace std;

struct Product {
    char name[50];
    int price;
    int quantity;
};

int calculateBill(Product cart[], int size, int index) {
    if (index == size)
        return 0;

    int subtotal = cart[index].price * cart[index].quantity;

    return subtotal + calculateBill(cart, size, index + 1);
}

int main() {
    Product cart[3] = {
        {"Keyboard", 2000, 2},
        {"Mouse", 1000, 1},
        {"Headphones", 3000, 2}
    };

    cout << "Total Bill = Rs. "
         << calculateBill(cart, 3, 0);

    return 0;
}
