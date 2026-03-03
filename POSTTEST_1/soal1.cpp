#include <iostream>
using namespace std;

// 1  min <- A[0]
// 2  for i <- 1 to n-1
// 3      if A[i] < min
// 4          min <- A[i]
// 5      end if
// 6  end for
// 7  return min

// Tmin(n) = c1 + c2(n-1) + c3(n-1) + c5
//         = c1 + (c2 + c3)(n-1) + c5
//         = an + b

// Big-O Best Case = O(n)

// --

// Tmax(n) = c1 + c2(n-1) + c3(n-1) + c4(n-1) + c5
//         = c1 + (c2 + c3 + c4)(n-1) + c5
//         = an + b

// Big-O Worst Case = O(n)

int FindMin(int A[], int n, int &indexmin)
{
    int min = A[0];
    indexmin = 0;

    for (int i = 1; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
            indexmin = i;
        }
    }

    return min;
}

int main()
{
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int indexmin;

    int minimum = FindMin(A, n, indexmin);

    cout << "array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;
    cout << "nilai minimum = " << minimum << endl;
    cout << "indeks minimum = " << indexmin << endl;

    return 0;
}