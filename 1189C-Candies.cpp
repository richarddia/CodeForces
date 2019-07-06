#include <bits/stdc++.h>
// 这道题思路不是很难，写起来坑比较多
using namespace std;
const int N = 1e5 + 10;
int A[N];
int dp[N][20];
int n;
int main() {
    cin >> n;
    int pt = 0;
    int queryN;
    for ( int i = 0; i < n; ++i ) {
        cin >> A[pt++];
        if ( i > 0 ) A[i] += A[i-1];
    }
    int k = 1;
    while ( n >>= 1 ) ++k;
    for ( int i = 0; i < pt; ++i ) {
        dp[i][0] = 0;
    }
    for ( int j = 1; j <= k; ++j ) {
        for ( int i = 0; i < pt; ++i ) {
            if ( i + ( 1 << j ) <= pt ) {
                int l = i;
                int r = i + ( 1 << j ) - 1;
                
                int mid = ( l + r ) / 2;
                dp[i][j] = dp[i][j-1] + dp[mid+1][j-1];
                int m1 = ( A[mid] - ( i == 0 ? 0 : A[l - 1] ) ) % 10;
                int m2 = ( A[r] - A[mid] ) % 10;
                dp[i][j] += ( m1 + m2 >= 10 );
            } else
                break;
        }
    }
    cin >> queryN;
    for ( int i = 0; i < queryN; ++i ) {
        int l; int r;
        cin >> l >> r;
        int cnt = r - l + 1;
        int k1 = 0;
        while ( cnt >>= 1 ) ++k1;
        cout << dp[l-1][k1] << endl;
    }
    return 0;
}
