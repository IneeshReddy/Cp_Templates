#include <bits/stdc++.h>
using namespace std;


struct Sieve {
    int n;
    vector <int> lp, hp;
    vector <vector <int>> F, Pf;
 
    Sieve (int n) : n(n), hp(n, -1), lp(n, -1), F(n), Pf(n) {}
 
    void pre() {
        lp[1] = 0;
        for (int i = 2; i < n; i++) {
            if (lp[i] != -1) continue;
            lp[i] = i;
            hp[i] = i;
            Pf[i].push_back(i);
 
            for (int j = 2 * i; j < n; j += i) {
                if (lp[j] == -1) {
                    lp[j] = i;
                }
                hp[j] = i;
                Pf[j].push_back(i);
            }
        }
    } 
 
    void fact() {
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j += i) {
                F[j].push_back(i);
            }
        }
    }
 
    bool ok(int x) {
        return lp[x] == x;
    }
};


int main () {

}