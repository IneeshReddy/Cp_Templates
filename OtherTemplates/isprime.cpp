#include <bits/stdc++.h>
using namespace std;


bool isprime (int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int solve () {
    int n;
    cin >> n;

    cout << isprime(n) << '\n';
}