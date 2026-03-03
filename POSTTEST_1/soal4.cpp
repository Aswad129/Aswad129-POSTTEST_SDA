#include <iostream>
using namespace std;

void tukar(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x, y;

    cout << "masukkan nilai pertama (x): ";
    cin >> x;
    cout << "masukkan nilai kedua (y): ";
    cin >> y;

    cout << "\nSebelum pertukaran:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukar(x, y);

    cout << "\nSetelah pertukaran:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}