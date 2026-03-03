#include <iostream>
using namespace std;

void reverseArray(int *array, int n)
{
    int *awal = array;
    int *akhir = array + n - 1;

    while (awal < akhir)
    {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main()
{
    int array[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "array sebelum di reverse:\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "Nilai: " << *(array + i)
             << " | Alamat: " << (array + i) << endl;
    }

    reverseArray(array, 7);

    cout << "\narray setelah direverse:\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "Nilai: " << *(array + i)
             << " | Alamat: " << (array + i) << endl;
    }

    return 0;
}