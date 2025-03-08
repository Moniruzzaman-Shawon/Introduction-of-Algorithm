#include <bits/stdc++.h>
using namespace std;

vector<bool> reachable(100001, false);      //Keep track of reachable numbers up to 10^5

void makeIt() {
    reachable[1] = true;
    
    for (int i = 1; i <= 100000; ++i) {
        if (reachable[i]) {
            if (i + 3 <= 100000) {
                reachable[i + 3] = true;
            }
            if (i * 2 <= 100000) {
                reachable[i * 2] = true;
            }
        }
    }
}

int main() {
    makeIt();  
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        if (reachable[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
