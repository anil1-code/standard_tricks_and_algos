// author:  anil_1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
this will return the gcd of a and b and fill x and y such that ax + by = gcd(a, b)
TC: log(min(a, b))
*/
int extended_euclid(int a, int b, int& x, int& y) {
	if(a == 0) {
        x = 0, y = 1;
        return b;
    }
	int ans = extended_euclid(b % a, a, x, y);
    int temp = x;
    x = y - (b / a) * x;
    y = temp;
    return ans;
}

int main() {
    int x, y;
    cout << extended_euclid(0, 0, x, y) << ' ' << x << ' ' << y << '\n';
    cout << extended_euclid(0, 7, x, y) << ' ' << x << ' ' << y << '\n';
    cout << extended_euclid(8, 0, x, y) << ' ' << x << ' ' << y << '\n';
    cout << extended_euclid(2, 4, x, y) << ' ' << x << ' ' << y << '\n';
    cout << extended_euclid(40, 24, x, y) << ' ' << x << ' ' << y << '\n';
    return 0;
}