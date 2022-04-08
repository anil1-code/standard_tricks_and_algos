// author:  anil_1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1'000'000'007;

/*
this will return (a ^ p) % mod
TC: log(p)
*/
int bin_expo(int a, int p) {
    int result = 1;
    while (p) {
        if (p & 1)
            result = 1LL * a * result % mod;
        a = 1LL * a * a % mod;
        p >>= 1;
    }
    return result;
}

int main() {
    cout << bin_expo(2, 3) << '\n';
    cout << bin_expo(3, 2) << '\n';
    cout << bin_expo(1, 1) << '\n';
    cout << bin_expo(2, 0) << '\n';
    cout << bin_expo(1, 0) << '\n';
    cout << bin_expo(0, 0) << '\n';
    return 0;
}