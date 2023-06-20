#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<limits> 

using namespace std;

// Customer class for storing customer information and handling operations
class customer
{
public:
    int cno, total; // Customer ID and total bill amount
    string name; // Customer name
    string address; // Customer address
    string laptopName; // Name of the laptop
    int n, x; // Variables for handling repair component selection

public:
    // Function to input customer details
    void give_details()
    {
        system("cls");
        fflush(stdin);
        cout << "Enter Your Name: ";
        getline(cin, name);
        cout << "Enter Your Address: ";
        getline(cin, address);
        cout << "Enter the Name of Your Laptop: ";
        getline(cin, laptopName);
        cout << "Enter Your ID Number: ";
        cin >> cno;
    }

    // Function to display customer details
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Laptop Name: " << laptopName << endl;
        cout << "Unique ID: " << cno << endl;
        cout << "Please remember this ID for further details!" << endl;
    }

    // Function to calculate repair component cost
    void damage()
    {
        total = 0;
        cout << "Enter the number of components you want to get repaired: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << endl << "Choose from the list:";
            cout << endl << "1) Display  2) Hard disk  3) USB ports";
            cout << endl << "4) Graphic card  5) Motherboard  6) Windows";
            cout << endl << "7) Keypad  8) RAM  9) Anti-Virus" << endl;
            cin >> x;

            switch (x)
            {
                case 1:
                    cout << "Cost of display: 3000 Rs" << endl;
                    total += 3000;
                    break;
                case 2:
                    cout << "Cost of hard disk: 4000 Rs" << endl;
                    total += 4000;
                    break;
                case 3:
                    cout << "Cost of USB port: 500 Rs" << endl;
                    total += 500;
                    break;
                case 4:
                    cout << "Cost of graphic card: 10000 Rs" << endl;
                    total += 10000;
                    break;
                case 5:
                    cout << "Cost of motherboard: 8000 Rs" << endl;
                    total += 8000;
                    break;
                case 6:
                    cout << "Cost of Windows: 3000 Rs" << endl;
                    total += 3000;
                    break;
                case 7:
                    cout << "Cost of keypad: 1200 Rs" << endl;
                    total += 1200;
                    break;
                case 8:
                    cout << "Cost of RAM: 1000 Rs" << endl;
                    total += 1000;
                    break;
                case 9:
                    cout << "Cost of anti-virus: 800 Rs" << endl;
                    total += 800;
                    break;
            }
        }
    }

    // Function to display the bill
    void bill()
    {
        cout << "Your total bill to be paid is: " << total << " Rs" << endl;
    }
};

// Function to simulate payment processing
void pay()
{
    system("cls");
    cout << "Your payment is processing..." << endl;
    Sleep(2000); // Simulating payment processing time
    cout << "Your bill is paid. Have a nice day!!!" << endl;
    system("pause");
}

int main()
{
    while (true)
    {
        system("cls");
        fstream f1, f2;
        customer c1, c;
        char found = 'f';
        char confirm = 'n';
        int choice;

        // Menu for user options
        cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "\n\t\t\t*     1. NEW CUSTOMER              *" << endl;
        cout << "\t\t\t*     2. PAY THE BILL              *" << endl;
        cout << "\t\t\t*     3. DELETE A RECORD           *" << endl;
        cout << "\t\t\t*     4. MODIFY A RECORD           *" << endl;
        cout << "\t\t\t*     5. DISPLAY RECORDS           *" << endl;
        cout << "\t\t\t*     0. EXIT                      *\n" << endl;
        cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "\n\t Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 0:
                exit(0);
            case 1:
                c1.give_details();
                c1.damage();
                char ch;
                f1.open("Laptop_shop.txt", ios::app);
                cout << "\n\nDo you want to save the record? (y/n): ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    f1 << "Name: " << c1.name << endl;
                    f1 << "Address: " << c1.address << endl;
                    f1 << "Laptop Name: " << c1.laptopName << endl;
                    f1 << "Unique ID: " << c1.cno << endl;
                    f1 << "Total Bill: " << c1.total << " Rs" << endl;
                    f1 << "-----------------------------------------" << endl;
                }
                f1.close();
                c1.bill();
                cout << "Do you want to pay now? (y/n): ";
                char ifelse;
                cin >> ifelse;
                if (ifelse == 'y' || ifelse == 'Y')
                {
                    pay();
                }
                break;
            case 2:
                cout << "Enter the amount to be paid: ";
                int temp;
                cin >> temp;
                pay();
                break;
            case 3:
                f1.open("Laptop_shop.txt", ios::in);
                f2.open("temp.txt", ios::out);
                int rno;
                cout << "\n\nEnter the Customer ID you want to DELETE: ";
                cin >> rno;

                while (getline(f1, c.name))
                {
                    getline(f1, c.address);
                    getline(f1, c.laptopName);
                    f1 >> c.cno;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1 >> c.total;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (c.cno == rno)
                    {
                        c.display();
                        found = 't';
                        cout << "\n\nAre you sure you want to DELETE this record? (y/n): ";
                        cin >> confirm;
                        if (confirm == 'n' || confirm == 'N')
                        {
                            f2 << "Name: " << c.name << endl;
                            f2 << "Address: " << c.address << endl;
                            f2 << "Laptop Name: " << c.laptopName << endl;
                            f2 << "Unique ID: " << c.cno << endl;
                            f2 << "Total Bill: " << c.total << " Rs" << endl;
                            f2 << "-----------------------------------------" << endl;
                        }
                    }
                    else
                    {
                        f2 << "Name: " << c.name << endl;
                        f2 << "Address: " << c.address << endl;
                        f2 << "Laptop Name: " << c.laptopName << endl;
                        f2 << "Unique ID: " << c.cno << endl;
                        f2 << "Total Bill: " << c.total << " Rs" << endl;
                        f2 << "-----------------------------------------" << endl;
                    }
                }

                if (found == 'f')
                    cout << "\n\n\tRECORD NOT FOUND\n";
                f1.close();
                f2.close();
                remove("Laptop_shop.txt");
                rename("temp.txt", "Laptop_shop.txt");

                f1.open("Laptop_shop.txt", ios::in);
                cout << "\n\nNow the file contains:\n\n";
                while (getline(f1, c.name))
                {
                    getline(f1, c.address);
                    getline(f1, c.laptopName);
                    f1 >> c.cno;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1 >> c.total;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    c.display();
                    cout << endl;
                }
                f1.close();
                system("pause");
                break;
            case 4:
                f1.open("Laptop_shop.txt", ios::in | ios::out);
                long pos;
                cout << "\n\nEnter the Customer ID you want to MODIFY: ";
                cin >> rno;
                while (getline(f1, c.name))
                {
                    getline(f1, c.address);
                    getline(f1, c.laptopName);
                    f1 >> c.cno;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1 >> c.total;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (c.cno == rno)
                    {
                        c.display();
                        pos = f1.tellg();
                        pos -= (c.name.length() + c.address.length() + c.laptopName.length() + 4);
                        f1.seekp(pos, ios::beg);
                        c.give_details();
                        c.damage();
                        f1 << "Name: " << c.name << endl;
                        f1 << "Address: " << c.address << endl;
                        f1 << "Laptop Name: " << c.laptopName << endl;
                        f1 << "Unique ID: " << c.cno << endl;
                        f1 << "Total Bill: " << c.total << " Rs" << endl;
                        f1 << "-----------------------------------------" << endl;
                        found = 't';
                        break;
                    }
                }
                if (found == 'f')
                    cout << "\n\n\tRECORD NOT FOUND\n";
                f1.close();
                system("pause");
                break;
            case 5:
                f1.open("Laptop_shop.txt", ios::in);
                if (!f1)
                {
                    cout << "\n\n\tFILE NOT FOUND\n";
                    system("pause");
                    break;
                }
                cout << "\n\n\t\tDISPLAYING THE RECORDS\n";
                while (getline(f1, c.name))
                {
                    getline(f1, c.address);
                    getline(f1, c.laptopName);
                    f1 >> c.cno;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1 >> c.total;
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    f1.ignore(numeric_limits<streamsize>::max(), '\n');
                    c.display();
                    cout << endl;
                }
                f1.close();
                system("pause");
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
                system("pause");
                break;
        }
    }
    return 0;
}
