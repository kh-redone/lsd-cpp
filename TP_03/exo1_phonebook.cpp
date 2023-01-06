#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact {
public:
    string first_name;
    string last_name;
    string nickname;
    string phone_number;

    Contact(const string& first_name, const string& last_name,
            const string& nickname, const string& phone_number)
        : first_name(first_name), last_name(last_name), nickname(nickname),
          phone_number(phone_number) {}
};


class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void add(const Contact& contact) {
        if (contacts.size() == 8) {
            contacts.erase(contacts.begin());
        }
        contacts.push_back(contact);
    }

    void search() {
        cout << "Index | First Name | Last Name | Nickname" << endl;
        cout << "------|------------|-----------|---------" << endl;
        for (int i = 0; i < contacts.size(); i++) {
            const Contact& contact = contacts[i];
            cout << right << " | " << i << " | "
                 << contact.first_name.substr(0, 10) << " | " << "      "
                 << contact.last_name.substr(0, 10) << " | " <<  "      "
                 << contact.nickname.substr(0, 9) << endl;
        }
        cout << "Enter the index of the entry to display: ";
        int index;
        cin >> index;
        if (index < 0 || index >= contacts.size()) {
            cout << "Invalid index" << endl;
            return;
        }
        const Contact& contact = contacts[index];
        cout << "First Name: " << contact.first_name << endl;
        cout << "Last Name: " << contact.last_name << endl;
        cout << "Nickname: " << contact.nickname << endl;
        cout << "Phone Number: " << contact.phone_number << endl;
    }
};

int main() {
    PhoneBook phonebook;
    while (true) {
        cout << "Enter a command (ADD, SEARCH, EXIT): ";
        string command;
        cin >> command;
        if (command == "ADD") {
            cout << "Enter the first name: ";
            string first_name;
            cin >> first_name;
            cout << "Enter the last name: ";
            string last_name;
            cin >> last_name;
            cout << "Enter the nickname: ";
            string nickname;
            cin >> nickname;
            cout << "Enter the phone number: ";
            string phone_number;
            cin >> phone_number;
            Contact contact(first_name, last_name, nickname, phone_number);
            phonebook.add(contact);
        } else if (command == "SEARCH") {
            phonebook.search();
        } else if (command == "EXIT") {
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}

