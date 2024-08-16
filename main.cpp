#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

// Class for contact management system
class ContactManager {
private:
    vector<Contact> contacts;

public:
    // To add contact
    void addContact(const string& name, const string& phoneNumber, const string& email) {
        Contact newContact = { name, phoneNumber, email };
        contacts.push_back(newContact);
    }

    // To view all contacts
    void viewContacts() const {
        if (contacts.empty()) {
            cout << "No contacts available." << endl;
            return;
        }

        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << endl;
            cout << "Phone Number: " << contact.phoneNumber << endl;
            cout << "Email: " << contact.email << endl;
            cout << "***************************************" << endl;
        }
    }

    // Delete a contact by name
    void deleteContact(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(),
                            [&name](const Contact& contact) { return contact.name == name; });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact deleted." << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }
};

int main() {
    ContactManager manager;
    int choice;

    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after entering the choice

        switch (choice) {
            case 1: {
                string name, phoneNumber, email;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, phoneNumber);
                cout << "Enter Email: ";
                getline(cin, email);

                manager.addContact(name, phoneNumber, email);
                break;
            }
            case 2:
                manager.viewContacts();
                break;
            case 3: {
                string name;
                cout << "Enter the name of the contact to delete: ";
                getline(cin, name);
                manager.deleteContact(name);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
