#include <bits/stdc++.h>
using namespace std;

long long tetranacci(int n) {
    if (n == 0) 
        return 0;
    else if (n == 1) 
        return 1;
    else if (n == 2) 
        return 1;
    else if (n == 3) 
        return 2;

    long long T0 = 0, T1 = 1, T2 = 1, T3 = 2;

    for (int i = 4; i <= n; i++) {
        long long Tn = T0 + T1 + T2 + T3;  
        T0 = T1;
        T1 = T2;
        T2 = T3;
        T3 = Tn;
    }

    return T3;
}

int main() {
    int n;
    cin >> n; 
    cout << tetranacci(n) << endl;  
}
