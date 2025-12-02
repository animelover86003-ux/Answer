#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int roll_no;
    string division;
    string year;
};
int main()
{
    int n;
    cout << "Enter total number of students: ";
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of student " << i + 1 << endl;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Roll No: ";
        cin >> s[i].roll_no;
        cout << "Division: ";
        cin >> s[i].division;
        cout << "Year (S.Y./T.Y./B.Tech.): ";
        cin >> s[i].year;
    }
    string searchName = "XYZ";
    int searchRoll = 17;
    string searchDiv = "X";
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i].name == searchName && s[i].roll_no == searchRoll && s[i].division == searchDiv && s[i].year == "S.Y.")
        {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s[i].name << ", Roll No: " << s[i].roll_no
                 << ", Division: " << s[i].division << ", Year: " << s[i].year << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nStudent Not Found!\n";
    return 0;
}
