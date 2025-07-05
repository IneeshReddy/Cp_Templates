#include <bits/stdc++.h>
using namespace std;

   int main () {
    // N is sqrt
    int n;
    cin >> n;
    vector <array <int, 3>> q(n);
    const int N = sqrt(n);
    sort(q.begin(), q.end(), [&](array<int, 3> x, array<int, 3> y){
        if(x[0] / N != y[0] / N) return (x[0] / N) < (y[0] / N);
        return ((x[0] / N) & 1) ? (x[1] < y[1]) : (x[1] > y[1]);
    });

    int l = 0, r = -1;

    for(auto &it : q) {
        while(l > it[0]) {
            l--;
            add();
        }
        while(r < it[1]) {
            r++;
            add();
        }
        while(l < it[0]) {
            rem();
            l++;
        }
        while(r > it[1]) {
            rem();
            r--;
        }
        // ret[it[2]] = ans; 
    }
   }
