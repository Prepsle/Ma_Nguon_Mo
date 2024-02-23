#include<bits/stdc++.h>
using namespace std;
int MaxNoRecursion (int *a, int n)
{
    int max = a[0];
    for (int i = 1 ; i < n ;  i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int MaxRecursive1(int *arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }
    int mid = (start + end) / 2;
    int maxLeft = MaxRecursive1(arr, start, mid);
    int maxRight = MaxRecursive1(arr, mid + 1, end);
    return max(maxLeft, maxRight);
}

int MaxRecursive2(int *arr, int n) {
    if (n == 1) {
        return arr[0];
    }
    return max(arr[n - 1], MaxRecursive2(arr, n - 1));
}

int main()
{
    int a[100] = {10, 20, 30, 40, 50};

    cout << "max =" << MaxNoRecursion(a,100) << endl;
    cout << "max(De quy c1) =" << MaxRecursive1(a,0,99) << endl;
    cout << "max(De quy c2) =" << MaxRecursive2(a,100) << endl;
}