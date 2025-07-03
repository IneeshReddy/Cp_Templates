#include <bits/stdc++.h>
using namespace std;


const int N = (int)1e6 + 10, M = (int)1e9 + 7;
int fact[N];


inline int add(int x, int y){
    x %= M,y %= M;
    x += y;
    if(x >= M) return x - M;
    x += M;
    if(x >= M) return x - M;
    return x;
}

 inline int sub(int x, int y){
    x %= M, y %= M;
    x -= y;
    x += M;
    if(x >= M) return x - M;
    return x;
}

inline int mul(int x, int y){
    x %= M, y %= M;
    return (x * y) % M;
}

inline int power(int x, int y){
    int ans = 1;
    while(y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y /= 2;
    }
    return ans;
}

inline int inv(int x){
    return power(x, M - 2);
}

 void pre(){
     fact[0] = 1;
     for(int i = 1; i < N; i++){
         fact[i] = (fact[i - 1] * i) % M;
     }
 }

int nCr(int n, int r){
    if(r > n) return 0;
    if(r < 0)return -1;
    int x = (fact[n - r] * fact[r]) % M;
    int in = inv(x);
    n = fact[n];
    return (n * in) % M;
}


int main () {
    pre();    
}