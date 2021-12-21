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

void NhapMang(int arr[100], int& n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Phan tu arr[" << i << "]= ";
        cin >> arr[i];
    }
}

void XuatMang(int arr[100], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

bool Tang(int a, int b) {
    return a > b;
}

bool Giam(int a, int b) {
    return a < b;
}

bool ChanTang(int a, int b) {
    if (a % 2 == 0 && b % 2 == 0)
        return a > b;
    return false;
}

bool ChanTangLeGiam(int a, int b) {
    if (a % 2 == 0 && b % 2 == 0)
        return a > b;
    if (a % 2 != 0 && b % 2 != 0)
        return a < b;
    return false;
}

void SapXep(int arr[100], int n, bool (*func)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (func(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    void (*ptr)() = &A;
    B(ptr);

    //
    int arr[100] = { 1,8,2,9,5,20,98,11,53,78 };
    int n = 10;
    XuatMang(arr, n);
    /*SapXep(arr, n, Tang);
    XuatMang(arr, n);*/
    /*SapXep(arr, n, Giam);
    XuatMang(arr, n);*/
    /*SapXep(arr, n, ChanTang);
    XuatMang(arr, n);*/
    SapXep(arr, n, ChanTangLeGiam);
    XuatMang(arr, n);

    return 0;
}