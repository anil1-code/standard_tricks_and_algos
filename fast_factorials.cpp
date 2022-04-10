// author:  anil_1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1'00'000, mod = 1'000'000'007;
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

/*
this function precomptes factorials and inverse of factorials which in turn can be used
to calculate ncr in O(1)
*/
int fact[N], invfact[N];
void precompute() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
    invfact[N - 1] = bin_expo(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--) {
        invfact[i] = 1ll * (i + 1) * invfact[i + 1] % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        // test_case();
    }
    return 0;
}