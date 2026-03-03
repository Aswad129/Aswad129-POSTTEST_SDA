#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
};

int main()
{
    Mahasiswa mhs[5];
    int i, maks = 0;

    for (i = 0; i < 5; i++)
    {
        cout << "data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);

        cout << "NIM  : ";
        getline(cin, mhs[i].nim);

        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();

        cout << endl;
    }

    for (i = 1; i < 5; i++)
    {
        if (mhs[i].ipk > mhs[maks].ipk)
        {
            maks = i;
        }
    }

    cout << "Mahasiswa dengan IPK Tertinggi" << endl;
    cout << "Nama : " << mhs[maks].nama << endl;
    cout << "NIM  : " << mhs[maks].nim << endl;
    cout << "IPK  : " << mhs[maks].ipk << endl;

    return 0;
}