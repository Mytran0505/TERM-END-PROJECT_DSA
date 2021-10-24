#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <unistd.h>
using namespace std;
#define MAX 100

struct Node
{
    int info;
    struct Node* pNext;
};
struct List
{
    Node* pHead;
    Node* pTail;
};
void CreateList(List& l)
{
    l.pHead = l.pTail = NULL;
}

Node* CreateNode(int x)
{
    Node* p = new Node;
    if (p == NULL)
        exit(1);
    else
    {
        p->info = x;
        p->pNext = NULL;
    }
    return p;
}
void AddHead(List& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(List& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
int DelHead(List& l)
{
    int x;
    Node* p;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        x = l.pHead->info;

        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
        return x;
    }
}
int Count(List l)
{
    int max = l.pHead->info;
    int count = 1;
    Node* p = l.pHead;
    while (p != NULL)
    {
        if (p->info > max)
            max = p->info;
        p = p->pNext;
    }
    while (max >= 10)
    {
        max = max / 10;
        count++;
    }
    return count;
}
void Xuat(List l)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
    cout << endl;
}

int Delay(){
	int choose;
	cout<<endl<<"Ban muon toc do xu ly nhu the nao:"<<endl;
	cout<<"1.Nhanh."<<endl;
	cout<<"2.Trung binh."<<endl;
	cout<<"3.Cham."<<endl;
	cout<<"Lua chon cua ban: ";
	cin>>choose;
	if(choose==1)
		return 1;
	if(choose==2)
		return 4;
	return 8;
}
int menu();
void InterchangeSort(int a[], int& n);
void InterchangeSort_Tang(int a[], int n);
void InterchangeSort_Giam(int a[], int n);
void SelectionSort();
void SelectionSort_Tang(int* a, int n);
void SelectionSort_Giam(int* a, int n);
void Insertion_Sort();
void InsertionSort_Tang(int a[], int n);
void InsertionSort_Giam(int a[], int n);
void BubbleSort(int a[], int& n);
void BubbleSort_Tang(int a[], int n);
void BubbleSort_Giam(int a[], int n);
void BinaryInsertionSort();
void BinaryInsertionSort_Tang(int* a, int n);
void BinaryInsertionSort_Giam(int* a, int n);
void Shaker_Sort();
void ShakerSort_Tang(int a[], int n);
void ShakerSort_Giam(int a[], int n);
void ShellSort(int a[], int& n);
void ShellSort_Tang(int a[], int n);
void ShellSort_Giam(int a[], int n);
void CountingSort();
void CountingSort_Tang(int* a, int n);
void CountingSort_Giam(int* a, int n);
void Radix_Sort();
void RadixSort_Tang(List& l);
void RadixSort_Giam(List& l);
void HeapSort(int a[], int& n);
void Shift_Tang(int a[], int l, int r);
void Shift_Giam(int a[], int l, int r);
void QuickSort();
void QuickSort_Tang(int* a, int l, int r);
void QuickSort_Giam(int* a, int l, int r);
void Merge_Sort();
void Merge_Tang(int a[], int Left, int Mid, int Right);
void MergeSort_Tang(int a[], int Left, int Right);
void Merge_Giam(int a[], int Left, int Mid, int Right);
void MergeSort_Giam(int a[], int Left, int Right);
void NhapThuong(int a[], int& n);
void Xuat(int a[], int n);
void NhapRamdom(int a[], int& n);
void Swap(int& a, int& b);


int main()
{
    int choice;
    int a[1000], n;
    bool flag = true;
    while (flag != false)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            InterchangeSort(a, n);
            break;
        case 2:
            SelectionSort();
            break;
        case 3:
            Insertion_Sort();
            break;
        case 4:
            BubbleSort(a, n);
            break;
        case 5:
            BinaryInsertionSort();
            break;
        case 6:
            Shaker_Sort();
            break;
        case 7:
            ShellSort(a, n);
            break;
        case 8:
            CountingSort();
            break;
        case 9:
            Radix_Sort();
            break;
        case 10:
            HeapSort(a, n);
            break;
        case 11:
            QuickSort();
            break;
        case 12:
            Merge_Sort();
            break;
        case 13:
        {
            flag = false;
            cout << "Ket thuc.";
        }
        break;
        }
    }
    return 0;
}

int menu()
{
    int choice;
    cout << "\nVui long chon kieu sap xep:";
    cout << "\n1. Interchange Sort";
    cout << "\n2. Selection Sort";
    cout << "\n3. Insertion Sort";
    cout << "\n4. Bubble Sort";
    cout << "\n5. Binary Insertion Sort";
    cout << "\n6. Shaker Sort";
    cout << "\n7. Shell Sort";
    cout << "\n8. Counting Sort";
    cout << "\n9. Radix Sort";
    cout << "\n10. Heap Sort";
    cout << "\n11. Quick Sort";
    cout << "\n12. Merge Sort";
    cout << "\n13. Ket thuc chuong trinh";
    cout << "\nLua chon cua ban: ";
    cin >> choice;
    return choice;
}

void SelectionSort_Tang(int* a, int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep mang nhu sau:" << endl;
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0;i < n - 1;i++)   // i là ch? s? d?u tiên trong dãy hi?n hành
    {
        int min = i;   // min là ch? s? ph?n t? nh? nh?t trong dãy hi?n hành, gán min = i
        for (int j = i + 1;j < n;j++)
        {
            if (a[min] > a[j])
                min = j;   // luu v? trí ph?n t? hi?n nh? nh?t
        }
        if (min != i)
        {
            swap(a[min], a[i]);
            sleep(time);
            for (int k = 0;k < n;k++)
                cout << a[k] << " ";
            cout << endl;
        }
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void SelectionSort_Giam(int* a, int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep mang nhu sau:" << endl;
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0;i < n - 1;i++)   // i là ch? s? d?u tiên trong dãy hi?n hành
    {
        int max = i;   // max là ch? s? ph?n t? l?n nh?t trong dãy hi?n hành, gán max = i
        for (int j = i + 1;j < n;j++)
        {
            if (a[max] < a[j])
                max = j;   // luu v? trí ph?n t? hi?n l?n nh?t
        }
        if (max != i)
        {
            swap(a[max], a[i]);
            sleep(time);
            for (int k = 0;k < n;k++)
                cout << a[k] << " ";
            cout << endl;
        }
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void SelectionSort()
{
    cout << "\nBan da chon Selection Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0;i < n;i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            SelectionSort_Tang(a, n);
        if (sx == 2)
            SelectionSort_Giam(a, n);
        delete[] a;
    }
    if (kt == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0;i < n;i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0;i < n;i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            SelectionSort_Tang(a, n);
        if (sx == 2)
            SelectionSort_Giam(a, n);
        delete[] a;
    }
}

void BinaryInsertionSort_Tang(int* a, int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep mang nhu sau:" << endl;
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;
    int l, r, m, x;
    for (int i = 1;i < n;i++)
    {
        l = 0;
        r = i - 1;
        x = a[i];   //luu giá tr? a[i] tránh b? ghi dè khi d?i ch? các ph?n t?
        while (l <= r)   //tìm v? trí chèn x
        {
            m = (l + r) / 2;   //tìm v? trí thích h?p m
            if (a[m] > x)
                r = m - 1;
            else
                l = m + 1;
        }
        for (int j = i;j > l;j--)
            a[j] = a[j - 1];   //d?i các ph?n t? s? d?ng sau x
        a[l] = x;   //chèn x vào dãy
        sleep(time);
        for (int k = 0;k < n;k++)
            cout << a[k] << " ";
        cout << endl;
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void BinaryInsertionSort_Giam(int* a, int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep mang nhu sau:" << endl;
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;
    int l, r, m, x;
    for (int i = 1;i < n;i++)
    {
        l = 0;
        r = i - 1;
        x = a[i];   //luu giá tr? a[i] tránh b? ghi dè khi d?i ch? các ph?n t?
        while (l <= r)   //tìm v? trí chèn x
        {
            m = (l + r) / 2;   //tìm v? trí thích h?p m
            if (a[m] < x)
                r = m - 1;
            else
                l = m + 1;
        }
        for (int j = i;j > l;j--)
            a[j] = a[j - 1];   //d?i các ph?n t? s? d?ng sau x
        a[l] = x;   //chèn x vào dãy
        sleep(time);
        for (int k = 0;k < n;k++)
            cout << a[k] << " ";
        cout << endl;
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void BinaryInsertionSort()
{
    int choice;
    cout << "\nBan da chon Binary Insertion Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    cin >> choice;
    if (choice == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0;i < n;i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            BinaryInsertionSort_Tang(a, n);
        if (sx == 2)
            BinaryInsertionSort_Giam(a, n);
        delete[] a;
    }
    if (choice == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0;i < n;i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            BinaryInsertionSort_Tang(a, n);
        if (sx == 2)
            BinaryInsertionSort_Giam(a, n);
        delete[] a;
    }
}

void CountingSort_Tang(int* a, int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep mang nhu sau:" << endl;
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;
    int max = a[0];
    int min = a[0];
    for (int i = 1;i < n;i++)
    {
        if (a[i] > max)
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }
    int j = max - min + 1;   //s? lu?ng ph?n t? trong m?ng d?m
    int* b = new int[j];   //t?o m?ng d?m d? ch?a s? lu?ng các khóa t? m?ng dã cho
    fill_n(b, j, 0);
    for (int i = 0;i < n;i++)
        b[a[i] - min]++;   //luu s? lu?ng khóa vào m?ng d?m
    for (int i = 1;i < j;i++)
        b[i] += b[i - 1];   //d?i m?ng d?m sao cho ch?a v? trí th?c c?a các ph?n t? c?n s?p x?p theo th? t? tang d?n
    int* c = new int[n];   //t?o m?ng m?i d? ch?a dãy s? s?p x?p
    for (int i = 0;i < n;i++)
    {
        c[b[a[i] - min] - 1] = a[i];
        b[a[i] - min]--;
    }   //s? d?ng v? trí c?a khóa du?c luu trong m?ng d?m d? s?p x?p m?ng m?i
    sleep(time);
    for (int i = 0;i < n;i++)
        cout << c[i] << " "; //in m?ng dã du?c s?p x?p tang d?n
    cout << endl;
    cout << "Hoan thanh viec sap xep." << endl;
}

void CountingSort_Giam(int* a, int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep mang nhu sau:" << endl;
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;
    int max = a[0];
    int min = a[0];
    for (int i = 1;i < n;i++)
    {
        if (a[i] > max)
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }
    int j = max - min + 1;   //s? lu?ng ph?n t? trong m?ng d?m
    int* b = new int[j];   //t?o m?ng d?m d? ch?a s? lu?ng các khóa t? m?ng dã cho
    fill_n(b, j, 0);
    for (int i = 0;i < n;i++)
        b[a[i] - min]++;   //luu s? lu?ng khóa vào m?ng d?m
    for (int i = 1;i < j;i++)
        b[i] += b[i - 1];   //d?i m?ng d?m sao cho ch?a v? trí th?c c?a các ph?n t? c?n s?p x?p theo th? t? tang d?n
    int* c = new int[n];   //t?o m?ng m?i d? ch?a dãy s? s?p x?p
    for (int i = 0;i < n;i++)
    {
        c[b[a[i] - min] - 1] = a[i];
        b[a[i] - min]--;
    }   //s? d?ng v? trí c?a khóa du?c luu trong m?ng d?m d? s?p x?p m?ng m?i
    sleep(time);
    for (int i = n - 1;i >= 0;i--)
        cout << c[i] << " "; //in m?ng s?p x?p gi?m d?n b?ng cách in d?o ngu?c m?ng dã du?c s?p x?p tang d?n
    cout << endl;
    cout << "Hoan thanh viec sap xep." << endl;
}

void CountingSort()
{
    cout << "\nBan da chon Counting Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0;i < n;i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            CountingSort_Tang(a, n);
        if (sx == 2)
            CountingSort_Giam(a, n);
        delete[] a;
    }
    if (kt == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0;i < n;i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0;i < n;i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            CountingSort_Tang(a, n);
        if (sx == 2)
            CountingSort_Giam(a, n);
        delete[] a;
    }
}

void QuickSort_Tang(int* a, int l, int r)
{
    int i, j, x;
    x = a[(l + r) / 2];
    i = l;
    j = r;
    while (i < j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) QuickSort_Tang(a, l, j);
    if (i < r) QuickSort_Tang(a, i, r);
}

void QuickSort_Giam(int* a, int l, int r)
{
    int i, j, x;
    x = a[(l + r) / 2];
    i = l;
    j = r;
    while (i < j)
    {
        while (a[i] > x) i++;
        while (a[j] < x) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) QuickSort_Giam(a, l, j);
    if (i < r) QuickSort_Giam(a, i, r);
}

void QuickSort()
{
    cout << "\nBan da chon Quick Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0;i < n;i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
        {
            cout << "Mang sau khi sap xep la: " << endl;
            QuickSort_Tang(a, 0, n - 1);
            for (int i = 0;i < n;i++)
                cout << a[i] << " ";
            cout << endl;
            cout << "Hoan thanh viec sap xep.";
        }
        if (sx == 2)
        {
            cout << "Mang sau khi sap xep la: " << endl;
            QuickSort_Giam(a, 0, n - 1);
            for (int i = 0;i < n;i++)
                cout << a[i] << " ";
            cout << endl;
            cout << "Hoan thanh viec sap xep.";
        }
    }
    if (kt == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0;i < n;i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0;i < n;i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
        {
            cout << "Mang sau khi sap xep la: " << endl;
            QuickSort_Tang(a, 0, n - 1);
            for (int i = 0;i < n;i++)
                cout << a[i] << " ";
            cout << endl;
            cout << "Hoan thanh viec sap xep." << endl;
        }
        if (sx == 2)
        {
            cout << "Mang sau khi sap xep la: " << endl;
            QuickSort_Giam(a, 0, n - 1);
            for (int i = 0;i < n;i++)
                cout << a[i] << " ";
            cout << endl;
            cout << "Hoan thanh viec sap xep." << endl;
        }
    }
}

void InsertionSort_Tang(int a[], int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep:\n";
    int pos, i;
    int x;// Dùng d? luu a[i] d? tránh b? ghi dè khi d?i ch? các ph?n t?
    for (i = 1; i < n; i++)// Ðo?n a[0] dã s?p x?p
    {
        x = a[i];//Tìm v? trí pos thích h?p trong do?n a[i] – a[i-1] d? chèn  a[i] vào
        pos = i - 1;
        while ((pos >= 0) && (a[pos] > x))// Tìm v? trí chèn x
        {
            a[pos + 1] = a[pos];//k?t h?p d?i ch? các ph?n t? s? d?ng sau x trong dãy m?i
            pos--;
        }
        a[pos + 1] = x;// chèn x vào dãy
        sleep(time);
        //Xu?t ra t?ng bu?c ch?y c?a s?p x?p
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void InsertionSort_Giam(int a[], int n)
{
    int time=Delay();
    cout << "Qua trinh sap xep:\n";
    int pos, i;
    int x;// Dùng d? luu a[i] d? tránh b? ghi dè khi d?i ch? các ph?n t?
    for (i = 1; i < n; i++)// Ðo?n a[0] dã s?p x?p
    {
        x = a[i];//Tìm v? trí pos thích h?p trong do?n a[i] – a[i-1] d? chèn  a[i] vào
        pos = i - 1;
        while ((pos >= 0) && (a[pos] < x))// Tìm v? trí chèn x
        {
            a[pos + 1] = a[pos];//k?t h?p d?i ch? các ph?n t? s? d?ng sau x trong dãy m?i
            pos--;
        }
        a[pos + 1] = x;// chèn x vào dãy
        sleep(time);
        //Xu?t ra t?ng bu?c ch?y c?a s?p x?p
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void Insertion_Sort()
{
    cout << "\nBan da chon Insertion Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            InsertionSort_Tang(a, n);
        if (sx == 2)
            InsertionSort_Giam(a, n);
        delete[] a;
    }
    if (kt == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            InsertionSort_Tang(a, n);
        if (sx == 2)
            InsertionSort_Giam(a, n);
        delete[] a;
    }
}

void ShakerSort_Tang(int a[], int n)
{
    int time=Delay();
    int left, right, pos, j;
    left = 0;
    right = n - 1;
    pos = n - 1;// ghi nh?n v? trí pos x?y ra hoán v? sau cùng d? làm co s? thu h?p do?n left d?n right
    while (left < right)
    {
        for (j = right; j > left; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]); //Ð?i ch? 2 nút t?i v? trí j và j - 1
                pos = j;// Luu l?i noi x?y ra hoán v?
            }
            //Xu?t ra t?ng bu?c ch?y c?a s?p x?p
            sleep(time);
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        left = pos;// Lo?i các ph?n t? dã có th? t? ? d?u dãy
        for (j = left; j < right; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);//Ð?i ch? 2 nút t?i v? trí j và j + 1
                pos = j;// Luu l?i noi x?y ra hoán v?
            }
            sleep(time);
            //Xu?t ra t?ng bu?c ch?y c?a s?p x?p
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        right = pos;// Lo?i các ph?n t? dã có th? t? ? cu?i dãy
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void ShakerSort_Giam(int a[], int n)
{
    int time=Delay();
    int left, right, pos, j;
    left = 0;
    right = n - 1;
    pos = n - 1;// ghi nh?n v? trí pos x?y ra hoán v? sau cùng d? làm co s? thu h?p do?n left d?n right
    while (left < right)
    {
        for (j = right; j > left; j--)
        {
            if (a[j] > a[j - 1])
            {
                swap(a[j], a[j - 1]);//Ð?i ch? 2 nút t?i v? trí j và j - 1
                pos = j;// Luu l?i noi x?y ra hoán v?
            }
            //Xu?t ra t?ng bu?c ch?y c?a s?p x?p
            sleep(time);
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        left = pos;// Lo?i các ph?n t? dã có th? t? ? d?u dãy
        for (j = left; j < right; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);//Ð?i ch? 2 nút t?i v? trí j và j + 1
                pos = j;// Luu l?i noi x?y ra hoán v?
            }
            sleep(time);
            //Xu?t ra t?ng bu?c ch?y c?a s?p x?p
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        right = pos;// Lo?i các ph?n t? dã có th? t? ? cu?i dãy
    }
    cout << "Hoan thanh viec sap xep." << endl;
}

void Shaker_Sort()
{
    cout << "\nBan da chon Shaker Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            ShakerSort_Tang(a, n);
        if (sx == 2)
            ShakerSort_Giam(a, n);
        delete[] a;
    }
    if (kt == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            ShakerSort_Tang(a, n);
        if (sx == 2)
            ShakerSort_Giam(a, n);
        delete[] a;
    }
}

void RadixSort_Tang(List& l)
{
    int time=Delay();
    cout << "Danh sach truoc khi sap xep la:\n";
    Xuat(l);
    cout << endl;
    int Base = 10;
    int SoChuSo = Count(l); // Ð?m s? ch? s? nhi?u nh?t c?a ph?n t? trong m?ng
    cout << "Qua trinh sap xep: \n";
    List Arr[10];
    for (int i = 0; i < SoChuSo; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            CreateList(Arr[i]);//T?o m?ng ch?a các hàng don v?, ch?c tram,...
        }
        while (l.pHead != NULL)
        {
            int x = DelHead(l);
            int sodu = (x % Base) * 10 / Base; //Tính s? du cho các s? l?n
            AddTail(Arr[sodu], CreateNode(x));//Thêm các ph?n t? vào m?ng sau khi chia du ?ng v?i m?i hàng
        }
        for (int i = 0; i < 10; i++)
        {
            Node* k = Arr[i].pHead;
            while (k != NULL)
            {
                AddTail(l, k);
                k = k->pNext;
            }
        }
        Base *= 10;
        sleep(time);
        Xuat(l);
    }
    cout << "\nDanh sach sau khi sap xep la: " << endl;
    Xuat(l);
}

void RadixSort_Giam(List& l)
{
    int time=Delay();
    cout << "Danh sach truoc khi sap xep la:\n";
    Xuat(l);
    cout << endl;
    int Base = 10;
    int SoChuSo = Count(l);// Ð?m s? ch? s? nhi?u nh?t c?a ph?n t? trong m?ng
    cout << "Qua trinh sap xep: \n";
    List Arr[10];
    for (int i = 0; i < SoChuSo; i++)
    {
        for (int i = 9; i >= 0; i--)
        {
            CreateList(Arr[i]);//T?o m?ng ch?a các hàng don v?, ch?c tram,...
        }
        while (l.pHead != NULL)
        {
            int x = DelHead(l);
            int sodu = (x % Base) * 10 / Base;//Tính s? du cho các s? l?n
            AddTail(Arr[sodu], CreateNode(x));//Thêm các ph?n t? vào m?ng sau khi chia du ?ng v?i m?i hàng
        }
        for (int i = 9; i >= 0; i--)
        {
            Node* k = Arr[i].pHead;
            while (k != NULL)
            {
                AddTail(l, k);
                k = k->pNext;
            }
        }
        Base *= 10;
        sleep(time);
        Xuat(l);
    }
    cout << "\nDanh sach sau khi sap xep la: " << endl;
    Xuat(l);
}

void Radix_Sort()
{
    cout << "\nBan da chon Radix Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        List l;
        CreateList(l);
        int x;
        srand(time(NULL));
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        cout << "Nhap mang:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "a[" << i << "]= ";
            cin >> x;
            AddTail(l, CreateNode(x));
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            RadixSort_Tang(l);
        if (sx == 2)
            RadixSort_Giam(l);
    }
    if (kt == 2)
    {
        int n;
        List l;
        CreateList(l);
        int x;
        srand(time(NULL));
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            x = rand() % 100 + 1;
            AddTail(l, CreateNode(x));
        }
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (Node* p = l.pHead; p != NULL; p = p->pNext)
            cout << p->info << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1)
            RadixSort_Tang(l);
        if (sx == 2)
            RadixSort_Giam(l);
    }
}

void Merge_Tang(int a[], int Left, int Mid, int Right)
{
    int* temp = new int[Right - Left + 1];//T?o m?ng t?m temp
    int m;
    int i = Left;
    int j = Mid + 1;
    m = 0;
    //V?a s?p x?p v?a g?p m?ng vào m?ng t?m temp
    while (!(i > Mid && j > Right))
    {
        if ((i <= Mid && j <= Right && a[i] < a[j]) || j > Right)
            temp[m++] = a[i++];
        else
            temp[m++] = a[j++];
    }
    for (i = 0; i < m; i++)
        a[Left + i] = temp[i];
    delete[]temp;
}

void MergeSort_Tang(int a[], int Left, int Right)
{
    if (Left < Right)
    {
        int Mid = (Left + Right) / 2;
        // G?i hàm d? quy ti?p t?c chia dôi t?ng n?a m?ng
        MergeSort_Tang(a, Left, Mid);
        MergeSort_Tang(a, Mid + 1, Right);
        Merge_Tang(a, Left, Mid, Right);
    }
}

void Merge_Giam(int a[], int Left, int Mid, int Right)
{
    int* temp = new int[Right - Left + 1];//T?o m?ng t?m temp
    int m;
    int i = Left;
    int j = Mid + 1;
    m = 0;
    //V?a s?p x?p v?a g?p m?ng vào m?ng t?m temp
    while (!(i > Mid && j > Right))
    {
        if ((i <= Mid && j <= Right && a[i] > a[j]) || j > Right)
            temp[m++] = a[i++];
        else
            temp[m++] = a[j++];
    }
    for (i = 0; i < m; i++)
        a[Left + i] = temp[i];
    delete[]temp;
}

void MergeSort_Giam(int a[], int Left, int Right)
{
    if (Left < Right)
    {
        int Mid = (Left + Right) / 2;
        // G?i hàm d? quy ti?p t?c chia dôi t?ng n?a m?ng
        MergeSort_Giam(a, Left, Mid);
        MergeSort_Giam(a, Mid + 1, Right);
        Merge_Giam(a, Left, Mid, Right);
    }
}

void Merge_Sort()
{
    cout << "\nBan da chon Merge Sort";
    cout << "\nKhoi tao mang thu cong hay ngau nhien?";
    cout << "\n1. Thu cong";
    cout << "\n2. Ngau nhien";
    cout << "\nLua chon cua ban: ";
    int kt;
    cin >> kt;
    if (kt == 1)
    {
        int n;
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        cout << "Nhap mang:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "a[" << i << "]= ";
            cin >> a[i];
        }
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1) {
            cout << "Mang truoc khi sap xep: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            MergeSort_Tang(a, 0, n - 1);
            cout << "Mang sau khi sap xep la: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        if (sx == 2) {
            cout << "Mang truoc khi sap xep: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            MergeSort_Giam(a, 0, n - 1);
            cout << "Mang sau khi sap xep la: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        delete[] a;
    }
    if (kt == 2)
    {
        int n;
        cout << "\nNhap so phan tu mang: ";
        cin >> n;
        int* a = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100 + 1;
        cout << "Mang vua duoc khoi tao la:" << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\nSap xep tang hay giam?";
        cout << "\n1. Tang";
        cout << "\n2. Giam";
        cout << "\nLua chon cua ban: ";
        int sx;
        cin >> sx;
        if (sx == 1) {
            MergeSort_Tang(a, 0, n - 1);
            cout << "Mang sau khi sap xep la: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        if (sx == 2) {
            MergeSort_Giam(a, 0, n - 1);
            cout << "Mang sau khi sap xep la: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        delete[] a;
    }
}

void NhapThuong(int a[], int& n)
{
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << "Nhap Mang: " << endl;
    for (int i = 0;i < n;i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
}

void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void NhapRamdom(int a[], int& n)
{
    cout << "\nNhap so phan tu mang: ";
    cin >> n;
    for (int i = 0;i < n;i++)
        a[i] = rand() % 100 + 1;
    cout << "Mang vua duoc khoi tao la:" << endl;
    Xuat(a, n);
}

void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void InterchangeSort_Tang(int a[], int n)
{
	int time=Delay();
	cout << "Qua trinh sap xep mang nhu sau:" << endl;
	Xuat(a, n);
	for (int i = 0; i < n - 1; i++)// b?t d?u vòng l?p t? d?u dãy
	{
		for (int j = i + 1; j < n; j++)//Tìm t?t c? c?p ngh?ch th? a[j]<a[i], v?i j>i
		{
			if (a[j] < a[i])// xét c?p a[i], a[j]
				Swap(a[j], a[i]);// d?i ch? a[i], a[j]
		}

		sleep(time);
		Xuat(a, n);
	}
	cout << "Hoan thanh sap xep." << endl;
}

void InterchangeSort_Giam(int a[], int n)
{
	int time=Delay();
	cout << "Qua trinh sap xep mang nhu sau:" << endl;
	for (int i = 0; i < n - 1; i++) // b?t d?u vòng l?p t? d?u dãy
	{
		for (int j = i + 1; j < n; j++)//Tìm t?t c? c?p ngh?ch th? a[j]>a[i], v?i j>i
		{
			if (a[j] > a[i]) // xét c?p a[i], a[j]
				Swap(a[j], a[i]); // d?i ch? a[i], a[j]
		}
		sleep(time);
		Xuat(a, n);
	}
	cout << "Hoan thanh sap xep." << endl;
}

void InterchangeSort(int a[], int& n)
{
	int choice, sx;
	cout << "\nBan da chon Interchange Sort";
	cout << "\nKhoi tao mang thu cong hay ngau nhien?";
	cout << "\n1. Thu cong";
	cout << "\n2. Ngau nhien";
	cout << "\nLua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
	{
		NhapThuong(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
			InterchangeSort_Tang(a, n);
		else
			InterchangeSort_Giam(a, n);
	}
	else
	{
		NhapRamdom(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
			InterchangeSort_Tang(a, n);
		else
			InterchangeSort_Giam(a, n);
	}
}

void BubbleSort_Tang(int a[], int n)
{
	int time=Delay();
	cout << "Qua trinh sap xep mang nhu sau:" << endl;
	for (int i = 0; i <= n - 2; i++)
	{
		for (int j = n - 1; j >= i + 1; j--)// vòng l?p duy?t t? cu?i dãy ngu?c v? v? trí i
			if (a[j] < a[j - 1])// Xét c?p a[j], a[j-1],
			{
				Swap(a[j], a[j - 1]);// dua giá tr? nh? nh?t v? d?u do?n [(i-1)...(n-1)]
				sleep(time);
				Xuat(a, n);
			}
	}
	cout << "Hoan thanh sap xep." << endl;
}

void BubbleSort_Giam(int a[], int n)
{
	int time=Delay();
	cout << "Qua trinh sap xep mang nhu sau:" << endl;
	for (int i = 0; i <= n - 2; i++)
	{
		for (int j = n - 1; j >= i + 1; j--)// vòng l?p duy?t t? cu?i dãy ngu?c v? v? trí i
			if (a[j] > a[j - 1])// Xét c?p a[j], a[j-1],
			{
				Swap(a[j], a[j - 1]);// dua giá tr? l?n nh?t v? d?u do?n [(i-1)...(n-1)]
				sleep(time);
				Xuat(a, n);
			}
	}
	cout << "Hoan thanh sap xep." << endl;

}

void BubbleSort(int a[], int& n)
{
	int choice, sx;
	cout << "\nBan da chon Bubble Sort";
	cout << "\nKhoi tao mang thu cong hay ngau nhien?";
	cout << "\n1. Thu cong";
	cout << "\n2. Ngau nhien";
	cout << "\nLua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
	{
		NhapThuong(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
			BubbleSort_Tang(a, n);
		else
			BubbleSort_Giam(a, n);
	}
	else
	{
		NhapRamdom(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
			BubbleSort_Tang(a, n);
		else
			BubbleSort_Giam(a, n);
	}
}
void ShellSort_Tang(int a[], int n)
{
	int time=Delay();
	int gap, temp, j;
	cout << "Qua trinh sap xep mang nhu sau:" << endl;
	for (gap = n / 2; gap > 0; gap /= 2)//gap s? nh?n giá tr? l?n lu?t là n/2, n/4,n/8... cho d?n khi gap=1.
	{
		for (int i = gap; i < n; i++)// s?p x?p t?ng dãy con b?ng thu?t toán InsertionSort
		{
			temp = a[i];
			for (j = i; j >= gap && a[j - gap] > temp; j = j - gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
			sleep(time);
			Xuat(a, n);
		}
	}
	cout << "Hoan thanh sap xep." << endl;
}

void ShellSort_Giam(int a[], int n)
{
	int time=Delay();
	int gap, temp, j;
	cout << "Qua trinh sap xep mang nhu sau:" << endl;
	for (gap = n / 2; gap > 0; gap /= 2)//gap s? nh?n giá tr? l?n lu?t là n/2, n/4,n/8... cho d?n khi gap=1.
	{
		for (int i = gap; i < n; i++)// s?p x?p t?ng dãy con b?ng thu?t toán InsertionSort
		{
			temp = a[i];
			for (j = i; j >= gap && a[j - gap] > temp; j = j - gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
			sleep(time);
			Xuat(a, n);
		}
	}
	cout << "Hoan thanh sap xep." << endl;
}

void ShellSort(int a[], int& n)
{
	int choice, sx;
	cout << "\nBan da chon shell Sort";
	cout << "\nKhoi tao mang thu cong hay ngau nhien?";
	cout << "\n1. Thu cong";
	cout << "\n2. Ngau nhien";
	cout << "\nLua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
	{
		NhapThuong(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
			ShellSort_Tang(a, n);
		else
			ShellSort_Giam(a, n);
	}
	else
	{
		NhapRamdom(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
			ShellSort_Tang(a, n);
		else
			ShellSort_Giam(a, n);
	}
}

void Shift_Tang(int a[], int l, int r)
{
	int i, j;
	i = l;
	j = 2 * i + 1;
	while (j <= r)
	{
		if (j < r && a[j] < a[j + 1])//Tìm ph?n t? nh? hon gi?a a[j] và a[j+1]
			j++;//luu ch? s? c?a ph?n t? nh? hon trong hai ph?n t?
		if (a[j] <= a[i])
			return;
		swap(a[i], a[j]);
		i = j;
		j = 2 * i + 1;
	}
}

void Shift_Giam(int a[], int l, int r)
{
	int i, j;
	i = l;
	j = 2 * i + 1;
	while (j <= r)
	{
		if (j < r && a[j] > a[j + 1])//Tìm ph?n t? l?n hon gi?a a[j] và a[j+1]
			j++;//luu ch? s? c?a ph?n t? l?n hon trong hai ph?n t?
		if (a[j] >= a[i])
			return;
		swap(a[i], a[j]);
		i = j;
		j = 2 * i + 1;
	}
}
void HeapSort(int a[], int& n)
{
	int choice, sx;
	cout << "\nBan da chon Heap Sort";
	cout << "\nKhoi tao mang thu cong hay ngau nhien?";
	cout << "\n1. Thu cong";
	cout << "\n2. Ngau nhien";
	cout << "\nLua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
	{
		NhapThuong(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
		{
			int time=Delay();
			cout << "Qua trinh sap xep mang nhu sau:" << endl;
			Xuat(a,n);
			int l = n / 2 - 1;
			while (l >= 0)
			{
				Shift_Tang(a, l, n - 1);//t?o MaxHeap
				l--;
			}
			int r = n - 1;
			while (r > 0)
			{
				swap(a[0], a[r]);//a[0] là nút g?c, dua ph?n t? l?n nh?t vào cu?i dãy
				sleep(time);
				Xuat(a, n);
				r--;//lo?i phân t? l?n nh?t ra kh?i heap
				if (r > 0)
				{
					Shift_Tang(a, 0, r);//Th?c hi?n l?i thao tác
					sleep(time);
					Xuat(a, n);
				}
			}
			cout << "Hoan thanh sap xep." << endl;
		}
		else
		{
			int time=Delay();
			cout << "Qua trinh sap xep mang nhu sau:" << endl;
			Xuat(a,n);
			int l = n / 2 - 1;
			while (l >= 0)
			{
				Shift_Giam(a, l, n - 1);//t?o MinHeap
				l--;
			}
			int r = n - 1;
			while (r > 0)
			{
				swap(a[0], a[r]);//a[0] là nút g?c, dua ph?n t? nh? nh?t vào cu?i dãy
				sleep(time);
				Xuat(a, n);
				r--;//lo?i b? ph?n t? nh? nh?t ra kh?i heap
				if (r > 0)
				{
					Shift_Giam(a, 0, r);//th?c hi?n l?i thao tác
					sleep(time);
					Xuat(a, n);
				}
			}
			cout << "Hoan thanh sap xep." << endl;
		}
	}
	else
	{
		NhapRamdom(a, n);
		cout << "\nSap xep tang hay giam?";
		cout << "\n1. Tang";
		cout << "\n2. Giam";
		cout << "\nLua chon cua ban: ";
		cin >> sx;
		if (sx == 1)
		{
			int time=Delay();
			cout << "Qua trinh sap xep mang nhu sau:" << endl;
			Xuat(a,n);
			int l = n / 2 - 1;
			while (l >= 0)
			{
				Shift_Tang(a, l, n - 1);//T?o MaxHeap
				l--;
			}
			int r = n - 1;
			while (r > 0)
			{
				swap(a[0], a[r]);//a[0] là nút g?c, dua ph?n t? l?n nh?t vào cu?i dãy
				sleep(time);
				Xuat(a, n);
				r--;//lo?i b? ph?n t? l?n nh?t ra kh?i heap
				if (r > 0)
				{
					Shift_Tang(a, 0, r);//th?c hi?n l?i thao tác
					sleep(time);
					Xuat(a, n);
				}
			}
			cout << "Hoan thanh sap xep." << endl;
		}
		else
		{
			int time=Delay();
			cout << "Qua trinh sap xep mang nhu sau:" << endl;
			Xuat(a,n);
			int l = n / 2 - 1;
			while (l >= 0)
			{
				Shift_Giam(a, l, n - 1);//T?o MinHeap
				l--;
			}
			int r = n - 1;
			while (r > 0)
			{
				swap(a[0], a[r]);//a[0] la nut goc, dua ph?n t? nh? nh?t vào cu?i dãy
				sleep(time);
				Xuat(a, n);
				r--;//lo?i b? ph?n t? nh? nh?t ra kh?i heap
				if (r > 0)
				{
					Shift_Giam(a, 0, r);//th?c hi?n l?i thao tác
					sleep(time);
					Xuat(a, n);
				}
			}
			cout << "Hoan thanh sap xep." << endl;
		}
	}
}


