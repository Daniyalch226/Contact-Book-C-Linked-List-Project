#include <iostream>
using namespace std;

int getInt() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number: ";
        } else {
            return num;
        }
    }
}

class Node {
private:
    string name;
    int number;
    Node* next;

public:
    Node() {
        name = "";
        number = 0;
        next = 0;
    }

    void setName(string n) {
	 name = n;
	  }
    void setNumber(int num) {
	 number = num; 
	 }
    void setNext(Node* n) {
	 next = n; 
	 }

    string getName() { 
	return name; 
	}
    int getNumber() {
	 return number; 
	 }
    Node* getNext() {
	 return next; 
	 }
};

class ContactBook {
private:
    Node* head;

public:
    ContactBook() { 
	head = 0;
	 }

    void addContact() {
        Node* n = new Node;
        string nm;
        int num;

        cout << "Enter Name: ";
        cin >> nm;

        cout << "Enter Number: ";
        num = getInt();   

        n->setName(nm);
        n->setNumber(num);
        n->setNext(0);

        if (head == 0) head = n;
        else {
            Node* temp = head;
            while (temp->getNext() != 0)
                temp = temp->getNext();
            temp->setNext(n);
        }

        cout << "Contact Added." << endl;
    }

    void displayContacts() {
        if (head == 0) { 
		cout << "No contacts available." << endl; 
		return; 
		}

        Node* temp = head;
        int count = 1;
        cout << "--- Contact List ---" << endl;
        while (temp != 0) {
            cout << count++ << ". " << temp->getName() << " - " << temp->getNumber() << endl;
            temp = temp->getNext();
        }
        cout << "-------------------" << endl;
    }

    void searchContact() {
        if (head == 0) { cout << "No contacts to search." << endl; return; }

        cout << "1. Search by Name\n2. Search by Number\nChoice: ";
        int ch = getInt(); // <-- Safe 

        bool found = false;
        Node* temp = head;

        if (ch == 1) {
            string x; 
            cout << "Enter name: "; 
            cin >> x;

            while (temp != 0) {
                if (temp->getName() == x) {
                    cout << "Found: " << temp->getName() << " - " << temp->getNumber() << endl;
                    found = true;
                    break;
                }
                temp = temp->getNext();
            }
        }
        else if (ch == 2) {
            int y;
            cout << "Enter number: ";
            y = getInt();  // <-- Safe input

            while (temp != 0) {
                if (temp->getNumber() == y) {
                    cout << "Found: " << temp->getName() << " - " << temp->getNumber() << endl;
                    found = true;
                    break;
                }
                temp = temp->getNext();
            }
        }

        if (!found) cout << "Contact not found." << endl;
    }

    void editContact() {
        if (head == 0) { cout << "No contacts." << endl; return; }

        string n; 
        cout << "Enter name to edit: "; 
        cin >> n;

        Node* temp = head;
        while (temp != 0) {
            if (temp->getName() == n) {
                string newName;
                int newNum;

                cout << "Enter new name: "; 
                cin >> newName;
                cout << "Enter new number: ";
                newNum = getInt();  // <-- Safe input

                temp->setName(newName);
                temp->setNumber(newNum);

                cout << "Contact updated." << endl;
                return;
            }
            temp = temp->getNext();
        }
        cout << "Contact not found." << endl;
    }

    void deleteContact() {
        if (head == 0) { cout << "Contact list empty." << endl; return; }

        string n; 
        cout << "Enter name to delete: "; 
        cin >> n;

        Node* temp = head;
        Node* prev = 0;

        while (temp != 0) {
            if (temp->getName() == n) {
                if (prev == 0) head = temp->getNext();
                else prev->setNext(temp->getNext());
                delete temp;
                cout << "Contact deleted." << endl;
                return;
            }
            prev = temp;
            temp = temp->getNext();
        }
        cout << "Contact not found." << endl;
    }

    void deleteAll() {
        Node* temp = head;
        while (temp != 0) {
            Node* d = temp;
            temp = temp->getNext();
            delete d;
        }
        head = 0;
        cout << "All contacts deleted." << endl;
    }

    void menu() {
        int ch;
        do {
            system("cls");
            cout << "----- CONTACT BOOK -----" << endl;
            cout << "1. Add Contact" << endl;
            cout << "2. Display Contacts" << endl;
            cout << "3. Search Contact" << endl;
            cout << "4. Edit Contact" << endl;
            cout << "5. Delete Contact" << endl;
            cout << "6. Delete All" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter choice: ";
            ch = getInt();  

            cout << endl;

            switch (ch) {
                case 1: addContact(); break;
                case 2: displayContacts(); break;
                case 3: searchContact(); break;
                case 4: editContact(); break;
                case 5: deleteContact(); break;
                case 6: deleteAll(); break;
                case 7: cout << "Goodbye!" << endl; break;
                default: cout << "Invalid choice!" << endl;
            }

            if (ch != 7) {
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }

        } while (ch != 7);
    }
};

int main() {
    ContactBook cb;
    cb.menu();
    return 0;
}
