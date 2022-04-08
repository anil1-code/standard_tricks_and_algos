// author:  anil_1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
this will return the gcd of a and b
TC: log(min(a, b))
*/
int euclid(int a, int b) {
	if(a == 0) return b;
	return euclid(b % a, a);
}

int main() {
    cout << euclid(0, 0) << '\n';
    cout << euclid(0, 7) << '\n';
    cout << euclid(8, 0) << '\n';
    cout << euclid(2, 4) << '\n';
    cout << euclid(3, 9) << '\n';
    return 0;
}