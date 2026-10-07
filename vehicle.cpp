#include <iostream>
using namespace std;

#define SIZE 10

int parking[SIZE];


int hashFunction(int vehicleNo)
{
    return vehicleNo % SIZE;
}


void parkVehicle(int vehicleNo)
{
    int index = hashFunction(vehicleNo);
    int start = index;

    while (parking[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            cout << "Parking is full!\n";
            return;
        }
    }

    parking[index] = vehicleNo;

    cout << "Vehicle " << vehicleNo
         << " parked at slot " << index << endl;
}


void display()
{
    cout << "\nParking Slots:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Slot " << i << " : ";

        if (parking[i] == -1)
            cout << "Empty";
        else
            cout << parking[i];

        cout << endl;
    }
}


void searchVehicle(int vehicleNo)
{
    int index = hashFunction(vehicleNo);
    int start = index;

    while (parking[index] != -1)
    {
        if (parking[index] == vehicleNo)
        {
            cout << "Vehicle " << vehicleNo
                 << " found at slot " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Vehicle not found.\n";
}

int main()
{
    
    for (int i = 0; i < SIZE; i++)
        parking[i] = -1;

    int n, vehicleNo;

    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle numbers:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> vehicleNo;
        parkVehicle(vehicleNo);
    }

    display();

    cout << "\nEnter vehicle number to search: ";
    cin >> vehicleNo;

    searchVehicle(vehicleNo);

    return 0;
}