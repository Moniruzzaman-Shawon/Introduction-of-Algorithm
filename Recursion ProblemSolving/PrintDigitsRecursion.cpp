/*Problem Link : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/D*/

#include <bits/stdc++.h>
using namespace std;

void rec(int n) {
    if (n == 0) return;  //stop when n becomes 0

    rec(n / 10);  // Recursive call with n/10 to process previous digits first

    cout << (n % 10) << " ";  // Print last digit of current number
}

int main() {
    int t;
    cin >> t; // Read number of test cases
    
    while (t--) {
        int n;
        cin >> n; // Read each number
        if (n == 0) cout << "0";  // Special case for input 0
        else rec(n);
        cout << endl;
    }

    return 0;
}
