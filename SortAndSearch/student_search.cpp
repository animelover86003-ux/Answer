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

void inputStudents(Student s[], int n)
{
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
}

bool searchStudent(Student s[], int n, string searchName, int searchRoll, string searchDiv, string searchYear)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].name == searchName && s[i].roll_no == searchRoll && s[i].division == searchDiv && s[i].year == searchYear)
        {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s[i].name << ", Roll No: " << s[i].roll_no
                 << ", Division: " << s[i].division << ", Year: " << s[i].year << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    Student s[n];

    inputStudents(s, n);

    string searchName = "XYZ";
    int searchRoll = 17;
    string searchDiv = "X";
    string searchYear = "S.Y.";

    if (!searchStudent(s, n, searchName, searchRoll, searchDiv, searchYear))
        cout << "\nStudent Not Found!\n";

    return 0;
}



// #include <iostream>
// #include <string>
// using namespace std;

// struct Student {
//     int rollNo;
//     string name;
// };

// int binarySearch(Student arr[], int n, int key) {
//     int low = 0, high = n - 1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (arr[mid].rollNo == key)
//             return mid;
//         else if (arr[mid].rollNo < key)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return -1;
// }

// int main() {
//     // Assume S.Y. Division X students (sorted by rollNo)
//     Student students[] = {
//         {10, "ABC"},
//         {12, "DEF"},
//         {15, "PQR"},
//         {17, "XYZ"},
//         {20, "LMN"}
//     };

//     int n = sizeof(students) / sizeof(students[0]);
//     int key = 17;

//     int index = binarySearch(students, n, key);

//     if (index != -1) {
//         cout << "Student Found!\n";
//         cout << "Roll No: " << students[index].rollNo << "\n";
//         cout << "Name: " << students[index].name << "\n";
//     } else {
//         cout << "Student with roll no " << key << " not found.\n";
//     }

//     return 0;
// }
