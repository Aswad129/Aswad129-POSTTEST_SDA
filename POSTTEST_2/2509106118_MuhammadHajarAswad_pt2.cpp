#include <iostream>
#include <string>
using namespace std;

struct Kereta
{
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swapPointer(Kereta *a, Kereta *b)
{
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampilDataKereta(Kereta *arr, int n)
{
    if (n == 0)
    {
        cout << "\nData Kereta kosong!\n";
        return;
    }

    cout << "\n=== DATA KERETA ===\n";
    for (int i = 0; i < n; i++)
    {
        cout << "No Kereta   : " << (arr + i)->nomor << endl;
        cout << "Nama Kereta : " << (arr + i)->nama << endl;
        cout << "Asal        : " << (arr + i)->asal << endl;
        cout << "Tujuan      : " << (arr + i)->tujuan << endl;
        cout << "Harga       : " << (arr + i)->harga << endl;
        cout << "---------------------------\n";
    }
}

void tambahDataKereta(Kereta *arr, int &n)
{
    cout << "\n=== Tambah Data Kereta ===\n";

    cout << "Nomor: ";
    cin >> (arr + n)->nomor;
    cin.ignore();

    cout << "Nama Kereta: ";
    getline(cin, (arr + n)->nama);

    cout << "Asal: ";
    getline(cin, (arr + n)->asal);

    cout << "Tujuan: ";
    getline(cin, (arr + n)->tujuan);

    cout << "Harga Tiket: ";
    cin >> (arr + n)->harga;

    n++;
    cout << "Data berhasil ditambahkan!\n";
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan)
{
    bool ditemukan = false;

    cout << "\nProses Linear Search:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Cek index " << i << " -> "
             << (arr + i)->asal << " - "
             << (arr + i)->tujuan << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan)
        {
            cout << "\nData ditemukan: " << (arr + i)->nama << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan)
        cout << "Data tidak ditemukan\n";
}

void sortNomor(Kereta *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr + j)->nomor < (arr + i)->nomor)
            {
                swapPointer(arr + i, arr + j);
            }
        }
    }
}

int jumpSearch(Kereta *arr, int n, int key)
{
    int step = 2;
    int prev = 0;

    while (prev < n && (arr + (step < n ? step : n) - 1)->nomor < key)
    {
        prev = step;
        step += 2;

        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < (step < n ? step : n); i++)
    {
        if ((arr + i)->nomor == key)
            return i;
    }

    return -1;
}

void merge(Kereta *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);

    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].nama < R[j].nama)
            *(arr + k++) = L[i++];
        else
            *(arr + k++) = R[j++];
    }

    while (i < n1)
        *(arr + k++) = L[i++];

    while (j < n2)
        *(arr + k++) = R[j++];
}

void mergeSort(Kereta *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr + j)->harga < (arr + minIdx)->harga)
                minIdx = j;
        }
        swapPointer(arr + i, arr + minIdx);
    }
}

int main()
{
    Kereta data[100];
    int jumlah = 0;
    int pilih;

    do
    {
        cout << "\n=== MENU MANAJEMEN KEBERANGKATAN KERETA API ===\n";
        cout << "1. Tampilkan Data Kereta\n";
        cout << "2. Tambah Data Kereta\n";
        cout << "3. Cari Berdasarkan Rute (Linear Search)\n";
        cout << "4. Cari No Kereta (Jump Search)\n";
        cout << "5. Sort Berdasarkan Nama Kereta  (Merge Sort)\n";
        cout << "6. Sort Harga Tiket Termurah (Selection Sort)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tampilDataKereta(data, jumlah);
            break;

        case 2:
            tambahDataKereta(data, jumlah);
            break;

        case 3:
        {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal: ";
            getline(cin, asal);
            cout << "Tujuan: ";
            getline(cin, tujuan);

            linearSearch(data, jumlah, asal, tujuan);
            break;
        }

        case 4:
        {
            if (jumlah == 0)
            {
                cout << "Data belum ada!\n";
                break;
            }

            sortNomor(data, jumlah);

            int key;
            cout << "Nomor kereta: ";
            cin >> key;

            int idx = jumpSearch(data, jumlah, key);

            if (idx != -1)
                cout << "Data ditemukan : " << (data + idx)->nama << endl;
            else
                cout << "Data tidak ditemukan\n";
            break;
        }

        case 5:
            mergeSort(data, 0, jumlah - 1);
            cout << "\nData diurutkan berdasarkan nama\n";
            tampilDataKereta(data, jumlah);
            break;

        case 6:
            selectionSort(data, jumlah);
            cout << "\nData diurutkan berdasarkan harga!\n";
            tampilDataKereta(data, jumlah);
            break;
        }

    } while (pilih != 0);

    return 0;
}