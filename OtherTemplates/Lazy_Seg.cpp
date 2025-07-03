#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

struct LSegmentTree {
    vector <int> seg, Lz;
    int n;
 
    LSegmentTree (int n) : n(n), seg(4 * n), Lz(4 * n) {}
 
    void push(int i, int l, int r, int v) {
        seg[i] += v;
        if (l != r) {
            Lz[2 * i] += v;
            Lz[2 * i + 1] += v;
        }
        Lz[i] = 0;
    } 
 
    void upd(int lx, int rx, int i, int l, int r, int v) {
        push(i, l, r, Lz[i]);
        if (l > rx || r < lx) return;
        if (l >= lx && r <= rx) {
            push(i, l, r, v);
            return;
        }
 
        int m = (l + r) / 2;
        upd(lx, rx, 2 * i, l, m, v);
        upd(lx, rx, 2 * i + 1, m + 1, r, v);
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
 
    int qry(int lx, int rx, int i, int l, int r) {
        push(i, l, r, Lz[i]);
        if (l > rx || r < lx) return -INF;
        if (l >= lx && r <= rx) {
            return seg[i];
        }
        int m = (l + r) / 2;
        return max(qry(lx, rx, 2 * i, l, m), qry(lx, rx, 2 * i + 1, m + 1, r));
    }   
 
    void upd(int l, int r, int val) {
        upd(l, r, 1, 0, n - 1, val);
    }  
 
    int qry (int l, int r) {
        return qry(l, r, 1, 0, n - 1);
    }
};


int main () {

}