#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    int accountNumber;
    float balance;
public:
    void createAccount() {
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Account Number: "; cin >> accountNumber;
        cout << "Enter Initial Balance: "; cin >> balance;
        ofstream out("accounts.txt", ios::app);
        out << name << " " << accountNumber << " " << balance << endl;
        out.close();
        cout << "Account created successfully!\n";
    }

    void displayAll() {
        ifstream in("accounts.txt");
        string name;
        int acc;
        float bal;
        while (in >> name >> acc >> bal) {
            cout << "Name: " << name << ", Account #: " << acc << ", Balance: $" << bal << endl;
        }
        in.close();
    }

    void balanceInquiry() {
        int accNum; bool found = false;
        cout << "Enter Account Number: "; cin >> accNum;
        ifstream in("accounts.txt");
        string name; int acc; float bal;
        while (in >> name >> acc >> bal) {
            if (acc == accNum) {
                cout << "Account Found - Name: " << name << ", Balance: $" << bal << endl;
                found = true; break;
            }
        }
        if (!found) cout << "Account not found!\n";
        in.close();
    }
};

int main() {
    BankAccount b;
    int choice;
    do {
        cout << "\n1. Create Account\n2. Display All Accounts\n3. Balance Inquiry\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: b.createAccount(); break;
        case 2: b.displayAll(); break;
        case 3: b.balanceInquiry(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid Option!\n";
        }
    } while (choice != 4);
    return 0;
}