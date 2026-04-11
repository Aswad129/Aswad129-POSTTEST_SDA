#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Kereta
{
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Transaksi
{
    string namaPenumpang;
    string rute;
};

struct Queue
{
    Transaksi data[MAX];
    int front, rear;
};

void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

bool isFullQueue(Queue *q)
{
    return q->rear == MAX - 1;
}

bool isEmptyQueue(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, Transaksi t)
{
    if (isFullQueue(q))
    {
        cout << "Antrian penuh !!\n";
        return;
    }

    if (isEmptyQueue(q))
        q->front = 0;

    q->rear++;
    *(q->data + q->rear) = t;

    cout << "Penumpang masuk antrian!\n";
}

Transaksi dequeue(Queue *q)
{
    Transaksi t;

    if (isEmptyQueue(q))
    {
        cout << "Antrian kosong!\n";
        return {"", ""};
    }

    t = *(q->data + q->front);
    q->front++;

    if (q->front > q->rear)
        q->front = q->rear = -1;

    return t;
}

void tampilQueue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN TIKET ===\n";
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << "Nama: " << (q->data + i)->namaPenumpang
             << " | Rute: " << (q->data + i)->rute << endl;
    }
}

void peekQueue(Queue *q)
{
    if (!isEmptyQueue(q))
    {
        cout << "Terdepan Antrian: "
             << (q->data + q->front)->namaPenumpang << endl;
    }
    else
    {
        cout << "Antrian kosong!\n";
    }
}

struct Stack
{
    Transaksi data[MAX];
    int top;
};

void initStack(Stack *s)
{
    s->top = -1;
}

bool isFullStack(Stack *s)
{
    return s->top == MAX - 1;
}

bool isEmptyStack(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, Transaksi t)
{
    if (isFullStack(s))
    {
        cout << "Riwayat penuh (Overflow)!\n";
        return;
    }

    s->top++;
    *(s->data + s->top) = t;
}

void pop(Stack *s)
{
    if (isEmptyStack(s))
    {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus transaksi: "
         << (s->data + s->top)->namaPenumpang << endl;

    s->top--;
}

void tampilStack(Stack *s)
{
    if (isEmptyStack(s))
    {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT TRANSAKSI ===\n";
    for (int i = s->top; i >= 0; i--)
    {
        cout << "Nama: " << (s->data + i)->namaPenumpang
             << " | Rute: " << (s->data + i)->rute << endl;
    }
}

void peekStack(Stack *s)
{
    if (!isEmptyStack(s))
    {
        cout << "Transaksi terakhir: "
             << (s->data + s->top)->namaPenumpang << endl;
    }
    else
    {
        cout << "Riwayat kosong!\n";
    }
}

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
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA KERETA ===\n";
    for (int i = 0; i < n; i++)
    {
        cout << "No: " << (arr + i)->nomor << endl;
        cout << "Nama: " << (arr + i)->nama << endl;
        cout << "Asal: " << (arr + i)->asal << endl;
        cout << "Tujuan: " << (arr + i)->tujuan << endl;
        cout << "Harga: " << (arr + i)->harga << endl;
        cout << "------------------\n";
    }
}

void tambahDataKereta(Kereta *arr, int &n)
{
    cout << "\nTambah Data Kereta\n";

    cout << "Nomor: ";
    cin >> (arr + n)->nomor;
    cin.ignore();

    cout << "Nama: ";
    getline(cin, (arr + n)->nama);

    cout << "Asal: ";
    getline(cin, (arr + n)->asal);

    cout << "Tujuan: ";
    getline(cin, (arr + n)->tujuan);

    cout << "Harga: ";
    cin >> (arr + n)->harga;

    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan)
{
    bool ketemu = false;

    for (int i = 0; i < n; i++)
    {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan)
        {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Tidak ditemukan\n";
}

int main()
{
    Kereta data[MAX];
    int jumlah = 0;

    Queue antrian;
    Stack riwayat;

    initQueue(&antrian);
    initStack(&riwayat);

    int pilih;

    do
    {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampil Kereta\n";
        cout << "2. Tambah Kereta\n";
        cout << "3. Cari Rute\n";
        cout << "4. Tambah Antrian\n";
        cout << "5. Proses Tiket\n";
        cout << "6. Tampil Antrian\n";
        cout << "7. Tampil Riwayat\n";
        cout << "8. Pop Riwayat\n";
        cout << "9. Peek\n";
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
            Transaksi t;
            cin.ignore();
            cout << "Nama: ";
            getline(cin, t.namaPenumpang);
            cout << "Rute: ";
            getline(cin, t.rute);
            enqueue(&antrian, t);
            break;
        }

        case 5:
        {
            Transaksi t = dequeue(&antrian);
            if (t.namaPenumpang != "")
            {
                cout << "Diproses: " << t.namaPenumpang << endl;
                push(&riwayat, t);
            }
            break;
        }

        case 6:
            tampilQueue(&antrian);
            break;

        case 7:
            tampilStack(&riwayat);
            break;

        case 8:
            pop(&riwayat);
            break;

        case 9:
            peekQueue(&antrian);
            peekStack(&riwayat);
            break;
        }

    } while (pilih != 0);

    return 0;
}