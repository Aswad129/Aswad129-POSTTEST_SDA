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

struct Node
{
    Transaksi data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, Transaksi t)
{
    Node *baru = new Node;
    baru->data = t;
    baru->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = baru;
    }
    else
    {
        q->rear->next = baru;
        q->rear = baru;
    }

    cout << "Penumpang masuk antrian!\n";
}

Transaksi dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        cout << "Antrian kosong!\n";
        return {"", ""};
    }

    Node *hapus = q->front;
    Transaksi t = hapus->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    delete hapus;
    return t;
}

void tampilQueue(Queue *q)
{
    if (q->front == NULL)
    {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN TIKET ===\n";
    Node *temp = q->front;

    while (temp != NULL)
    {
        cout << "Nama: " << temp->data.namaPenumpang
             << " | Rute: " << temp->data.rute << endl;
        temp = temp->next;
    }
}

void peekQueue(Queue *q)
{
    if (q->front != NULL)
    {
        cout << "Terdepan: " << q->front->data.namaPenumpang << endl;
    }
    else
    {
        cout << "Antrian kosong!\n";
    }
}

struct Stack
{
    Node *top;
};

void initStack(Stack *s)
{
    s->top = NULL;
}

void push(Stack *s, Transaksi t)
{
    Node *baru = new Node;
    baru->data = t;
    baru->next = s->top;
    s->top = baru;
}

void pop(Stack *s)
{
    if (s->top == NULL)
    {
        cout << "Riwayat kosong!\n";
        return;
    }

    Node *hapus = s->top;
    cout << "Hapus transaksi: " << hapus->data.namaPenumpang << endl;

    s->top = s->top->next;
    delete hapus;
}

void tampilStack(Stack *s)
{
    if (s->top == NULL)
    {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT TRANSAKSI ===\n";
    Node *temp = s->top;

    while (temp != NULL)
    {
        cout << "Nama: " << temp->data.namaPenumpang
             << " | Rute: " << temp->data.rute << endl;
        temp = temp->next;
    }
}

void peekStack(Stack *s)
{
    if (s->top != NULL)
    {
        cout << "Transaksi terakhir: "
             << s->top->data.namaPenumpang << endl;
    }
    else
    {
        cout << "Riwayat kosong!\n";
    }
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