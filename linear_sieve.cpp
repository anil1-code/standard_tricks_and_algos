// author:  anil_1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1 << 20;
vector<int> lp(N);
vector<int> primes;

/*
after returning, lp[i] will store the smallest prime factor of i for i > 1 and primes will store all the primes in the range [2, N - 1]
lp->lowest prime
TC: O(N)
idea: every number i, can be uniquely represented in the form lp[i] * x where lp[i] and x are unique integers and lp[i] <= lp[x]
*/
void linear_sieve() {
    for(int i = 2; i < N; i++)	{
        if(lp[i] == 0) {
            primes.push_back(i);
            lp[i] = i;
        }
        for(int j = 0; j < (int)primes.size() and primes[j] * i < N and primes[j] <= lp[i]; j++) {
            lp[i * primes[j]] = primes[j];
        }
    }
}

int main() {
    linear_sieve();
    for(int i = 1; i < 20; i++) {
        cout << lp[i] << '\n';
    }
    return 0;
}