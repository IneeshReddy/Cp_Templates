#include <bits/stdc++.h>
using namespace std;

struct DSU{
      vector<int> sz, p;
      int cnt;
      DSU(int n){
         p = vector<int> (n);
         sz = vector<int> (n);
         for(int i = 0; i < n; i++){
             sz[i] = 1;
             p[i] = i;
         }
         cnt = n;
      }

      int get(int x){
          return (x == p[x] ? x : p[x] = get(p[x]));
      }

      bool same(int x, int y){
         return get(x) == get(y);
      }

      int size(int x){
         return sz[get(x)];
      }

      void merge(int x, int y){
          x = get(x), y = get(y);
          if(x == y){
             return;
          }
          cnt--;
          if(sz[x] > sz[y]){
             swap(x, y);
          }
          sz[y] += sz[x];
          p[x] = y;
      }
};


int main () {
    int n;
    cin >> n;

    DSU d(n);
    // Here cnt is the count is the number of components
    
}