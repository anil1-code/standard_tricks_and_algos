// author:  anil_1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (1 << 20);
vector<int> prime(N, 1);

/*
after returning prime[i] tells whether i is prime or not
TC = nloglogn
*/
void sieve() {
	prime[0] = prime[1] = 0;
	for(int i = 2; i * i < N; i++) {
		if(prime[i]) {
			for(int j = i * i; j < N; j += i) {
				prime[j] = 0;
			}
		}
	}
}
/*
Idea for segmented sieve:
say we want to find the primes in the range [l, r] where r < 1e12
r - l < 1e6

then we can first find primes till root(r)
these primes will be enough to mark all number composite in the range [l, r]
*/
int main() {
    sieve();
    cout << N << '\n';
    return 0;
}