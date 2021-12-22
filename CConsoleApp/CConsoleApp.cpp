#include <iostream>
#include <stdio.h>
using namespace std;

void A() {
    cout << "Hello World!" << endl;
}

// callback function
void B(void (*ptr)())
{
    (*ptr) (); // callback to A
}

void NhapMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Phan tu arr[" << i << "]= ";
        cin >> *(arr + i);
    }
}

void XuatMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr+i) << "\t";
    }
    cout << endl;
}

void HoanDoi(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool Tang(int *a, int *b) {
    return *a > *b;
}

bool Giam(int *a, int *b) {
    return *a < *b;
}

bool ChanTang(int *a, int *b) {
    if (*a % 2 == 0 && *b % 2 == 0)
        return *a > *b;
    return false;
}

bool ChanTangLeGiam(int *a, int *b) {
    if (*a % 2 == 0 && *b % 2 == 0)
        return *a > *b;
    if (*a % 2 != 0 && *b % 2 != 0)
        return *a < *b;
    return false;
}

void SapXep(int *arr, int n, bool (*pFunc)(int *, int *)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pFunc(arr+i, arr+j)) {
                HoanDoi(arr + i, arr + j);
            }
        }
    }
}

void CapPhat(int**& matrix, int soDong, int soCot)
{
    matrix = new int* [soDong];
    for (int i = 0; i < soDong; i++)
    {
        matrix[i] = new int[soCot];
    }
}


void CapPhat2(int**& matrix, int soDong, int soCot)
{
    matrix = (int**)calloc(soDong, sizeof(int*));
    if (matrix == NULL)
        return;
    for (int i = 0; i < soDong; i++)
    {
        matrix[i] = (int*)calloc(soCot, sizeof(int));
    }
}

void ThuHoi(int** matrix, int soDong)
{
    for (int i = 0; i < soDong; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void ThuHoi2(int*** matrix, int soDong)
{
    for(int i = 0; i < soDong; i++)
    {
        delete [](*matrix)[i];
    }
    delete [](*matrix);
}


void NhapMaTran(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Phan tu matrix[" << i << "][" << j << "]= ";
            cin >> matrix[i][j];
        }
    }
}

void XuatMaTran(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    void (*ptr)() = &A;
    B(ptr);

    int* a;
    int b = 10;
    a = &b;
    cout << *&a << "\t" << a << endl;

    //
    /*int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int* arr = (int*)malloc(n * sizeof(int *));
    NhapMang(arr, n);
    XuatMang(arr, n);*/
    /*SapXep(arr, n, Tang);
    XuatMang(arr, n);*/
    /*SapXep(arr, n, Giam);
    XuatMang(arr, n);*/
    /*SapXep(arr, n, ChanTang);
    XuatMang(arr, n);*/
    /*SapXep(arr, n, ChanTangLeGiam);
    XuatMang(arr, n);*/

    /*int soDong, soCot;
    int** matrix;
    cout << "Nhap so dong cua ma tran: ";
    cin >> soDong;
    cout << "Nhap so cot cua ma tra: ";
    cin >> soCot;

    CapPhat(matrix, soDong, soCot);
    NhapMaTran(matrix, soDong, soCot);
    XuatMaTran(matrix, soDong, soCot);

    if (matrix != NULL) {
        ThuHoi(matrix, soDong);
    }*/

    return 0;
}