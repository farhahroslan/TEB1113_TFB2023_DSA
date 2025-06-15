/*
id: 22011136
name: nur farhah solehah
group: g3
lab: L1
*/

#include <iostream>
#include <string>
using namespace std;

struct Student{
int id;
string name;
string phone;
string email;
};

int main()
{
    Student students[5];

    cout << "Enter details for 5 students:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Enter ID: ";
        cin >> students[i].id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, students[i].name);
        cout << "Enter Email: ";
        getline(cin, students[i].email);
        cout << "Enter Phone Number: ";
        getline(cin, students[i].phone);
    }

    cout << "\nStudent Database:\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1;
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nEmail: " << students[i].email;
        cout << "\nContact: " << students[i].phone;
        cout << "\n------------------------------------------------\n";
    }

    return 0;
}