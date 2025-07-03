#include <bits/stdc++.h>
using namespace std;


struct Fenwick{
     vector<int> v;
     int n;
     void in_it(int nn){
         n = nn + 10;
         v.resize(n);
     }
     void add(int i, int val){
         for(; i < n; i += i & (-i)){
            v[i] += val;
         }
     }

     int query(int i){
         int ans = 0;
         for(; i; i -= i & (-i)){
            ans += v[i];
         }
         return ans;
     }

     int query(int i, int j){
         if(i == 1) return query(j);
         return query(j) - query(i - 1);
     }
};


int main () {
    // VV.Imp Use 1based indexing for Fenwick tree always
    // 0 will give TLE to you for this template
    
}