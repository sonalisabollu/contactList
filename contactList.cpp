//bollu


#include <iostream>
#include <string>
using namespace std;

struct Contact
{
    string name;
    string phone;
    Contact* next;
};
class MyVector
{
private:
    Contact* head;
    Contact* tail;
    int list_size;
public:
    MyVector()
    {
        list_size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void push_back(string name, string phone)
    {
        Contact *newContact = new Contact();
        newContact->name = name;
        newContact->phone = phone;
        newContact->next = nullptr;
        if (head == NULL)
        {
            head = newContact;
            tail = newContact;
            list_size++;
        }
        else
        {
            tail->next = newContact;
            tail = newContact;
            list_size++;
        }
        
    }
    
    void remove(string name, string phone)
    {
        Contact* temp = head;
        Contact* prev = NULL;
        if (temp != NULL && (temp->name == name && temp->phone == phone))
        {
            head = temp->next;
            delete temp;
            list_size--;
            return;
        }
        while (temp != NULL && (temp->name != name || temp->phone != phone))
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Nothing to remove....\n";
            return;
        }
        else if (temp->name == name && temp->phone == phone)
        {
            prev->next = temp->next;
            delete temp;
            list_size--;
        }
        
        
    }
    
    string get(string name)
    {
        if (head == NULL)
        {
            cout<<"Contact list is empty.\n\n\n";
            return "";
        }
        Contact* current = head;
        while (current != NULL)
        {
            if (current->name == name)
            {
                return current->phone;
            }
            current = current->next;
        }
        return "Not Found";
    }
    
    void clear()
    {
        Contact *temp = head, *next;
        if (head == NULL)
        {
            return;
        }
        while (temp != NULL)
        {
            next = temp->next;
            delete temp;
            temp = next;
        }
        list_size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int size()
    {
        return list_size;
    }
    ~MyVector()
    {
        Contact *temp = head, *next;
        if (head == NULL)
        {
            return;
        }
        while (temp != NULL)
        {
            next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
        tail = NULL;
        list_size = 0;
    }
    
    
};
int main()
{
    char choice = ' ';
    string name, phone, str;
    str = "";
    MyVector* myVector = new MyVector();
    while (choice != 'q' && choice != 'Q')
    {
        cout << "(A)dd Contact" << endl;
        cout << "(C)lear Contacts" << endl;
        cout << "(F)ind Contact" << endl;
        cout << "(Q)uit" << endl;
        cout << "(R)emove Contact" << endl << endl << endl;;
        cout << "Enter Choice:" << endl;
        cin >> choice;
        if (choice == 'A' || choice == 'a')
        {
            cout << "Enter Name:" << endl;
            cin >> name;
            cout << "Enter Phone:" << endl;
            cin >> phone;
            myVector->push_back(name, phone);
        }
        else if (choice == 'C' || choice == 'c')
        {
            myVector->clear();
        }
        else if (choice == 'F' || choice == 'f')
        {
            cout << "Enter Name:" << endl;
            cin >> name;
            str = myVector->get(name);
            if (str != "")
            {
                cout << "Phone Number: " <<str<< endl << endl;
            }
        }
        
        else if (choice == 'R' || choice == 'r')
        {
            cout << "Enter Name:" << endl;
            cin >> name;
            cout << "Enter Phone:" << endl;
            cin >> phone;
            myVector->remove(name, phone);
        }
    }
    return 0;
}
