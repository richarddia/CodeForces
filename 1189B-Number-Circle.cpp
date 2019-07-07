// https://codeforces.com/problemset/problem/1189/B
// 思路: 先排序，排序过后其实除了最大的那个数，其他的都满足条件了，因为右侧总是比自己大的数
// 根本不用担心自己大于等于邻居的和，连右边数都比不过
// 最大的那个数为了保证满足条件，就用第二大和第三大的数去试一下，如果不行，那真是没救了

#include<bits/stdc++.h>
const int N = 1e5 + 10;
int arr[N];
using namespace std;
int main() {
    int n;
    cin >> n;
    for ( int i = 0; i < n; ++i ) cin >> arr[i];
    sort(arr, arr + n);
    if ( arr[n-1] >= arr[n-2] + arr[n-3] ) {
        cout << "NO" << endl;
    } else {
        int temp = arr[n-1];
        arr[n-1] = arr[n-2];
        arr[n-2] = temp;
        cout << "YES" << endl;
        for ( int i = 0; i < n; ++i ) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}