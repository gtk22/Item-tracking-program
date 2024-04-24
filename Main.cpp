#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequencies;

public:
    ItemTracker(const string& filename) {
        loadItems(filename);
        backupData("frequency.dat");
    }

    void loadItems(const string& filename) {
        ifstream file(filename);
        string item;
        int frequency;

        while (file >> item >> frequency) {
            itemFrequencies[item] = frequency;
        }
    }

    int getItemFrequency(const string& item) {
        return itemFrequencies[item];
    }

    void printAllItems() {
        for (const auto& pair : itemFrequencies) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void printHistogram() {
        for (const auto& pair : itemFrequencies) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    void backupData(const string& backupFilename) {
        ofstream backupFile(backupFilename);
        for (const auto& pair : itemFrequencies) {
            backupFile << pair.first << " " << pair.second << endl;
        }
    }
};

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    string inputItem;
    int choice;

    do {
        cout << "1. Search Item Frequency\n";
        cout << "2. Print All Items\n";
        cout << "3. Print Histogram\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline after integer input

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            getline(cin, inputItem);
            cout << "Frequency: " << tracker.getItemFrequency(inputItem) << endl;
            break;
        case 2:
            tracker.printAllItems();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
