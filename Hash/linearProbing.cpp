#include <iostream>
using namespace std;
class HashTable
{
    int *table;
    int size;

public:
    HashTable(int s)
    {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; 
    }
    void insert(int key)
    {
        int index = key % size;
        int start = index;
        while (table[index] != -1)
        {
            index = (index + 1) % size;
            if (index == start)
            {
                cout << "Hash Table is full!" << endl;
                return;
            }
        }
        table[index] = key;
    }
    void display()
    {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            if (table[i] != -1)
                cout << table[i];
            else
                cout << "Empty";
            cout << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter hash table size: ";
    cin >> n;
    HashTable h(n);
    int keys[] = {50, 700, 76, 85, 92, 73, 101};
    int totalKeys = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < totalKeys; i++)
        h.insert(keys[i]);
    h.display();
    return 0;
}