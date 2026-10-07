#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}


void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}


void display()
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " --> ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}


void search(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            cout << "Key " << key << " found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Key " << key << " not found.\n";
}

int main()
{
    
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        insert(key);
    }

    display();

    cout << "\nEnter key to search: ";
    cin >> key;

    search(key);

    return 0;
}