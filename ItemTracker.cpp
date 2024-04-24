#include <iostream> // For std::cout, std::cin
#include <string>   // For std::string

using namespace std; // Makes std namespace available throughout your code

class ItemTracker {
    // Ensure your class is fully defined here
public:
    ItemTracker() {
        // Constructor implementation
    }

    // Other public methods and private members
};

int main() {
    ItemTracker tracker; // Ensure ItemTracker is defined before this line
    string inputItem;

    cout << "Enter item name: ";
    getline(cin, inputItem); // Make sure cin is recognized

    // Assuming you have methods to handle the logic after input
    // cout << "You entered: " << inputItem << endl;

    return 0;
}

