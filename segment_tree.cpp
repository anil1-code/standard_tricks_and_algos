#include<bits/stdc++.h>
using namespace std;


/*
lazy propagation implemention
*/
class ST {
public:
    int ssz = 0;
    vector<ll> seg;
    vector<ll> lazy;
    ST(int n) {
        ssz = 1 << (32 - __builtin_clz(n));
        seg.resize(2 * ssz - 1);
        lazy.resize(2 * ssz - 1);
    }
    ST(int n, vector<int>& v) {
        ssz = 1 << (32 - __builtin_clz(n));
        seg.resize(2 * ssz - 1);
        lazy.resize(2 * ssz - 1);
        for(int i = 0; i < n; i++) {
            seg[ssz - 1 + i] = v[i];
        }
        for(int i = ssz - 2; i >= 0; i--) {
            seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
        }
    }
    void update(int l, int r, ll value) {
        range_update(0, 0, ssz - 1, l, r, value);
    }
    void range_update(int node, int n_left, int n_right, int r_left, int r_right, ll value) {
        if(lazy[node]) {
            // push down the pending updates
            seg[node] += (n_right - n_left + 1) * lazy[node];
            if(n_left != n_right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(r_left <= n_left and n_right <= r_right) {
            seg[node] += (n_right - n_left + 1) * value;
            if(n_left != n_right) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
        if(n_left > r_right or r_left > n_right) {
            return;
        }
        int mid = (n_left + n_right) / 2;
        range_update(2 * node + 1, n_left, mid, r_left, r_right, value);
        range_update(2 * node + 2, mid + 1, n_right, r_left, r_right, value);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }
    ll query(int l, int r) {
        return range_query(0, 0, ssz - 1, l, r);
    }
    ll range_query(int node, int n_left, int n_right, int r_left, int r_right) {
        // cout << node << ' ' << n_left << ' ' << n_right << ' ' << r_left << ' ' << r_right << endl;;
        if(lazy[node]) {
            // push down the pending updates
            seg[node] += (n_right - n_left + 1) * lazy[node];
            if(n_left != n_right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(r_left <= n_left and n_right <= r_right) {
            return seg[node];
        }
        if(n_left > r_right or r_left > n_right) {
            return 0;
        }
        int mid = (n_left + n_right) / 2;
        return range_query(2 * node + 1, n_left, mid, r_left, r_right) + 
            range_query(2 * node + 2, mid + 1, n_right, r_left, r_right);
    }
};

int main() {
    return 0;
}