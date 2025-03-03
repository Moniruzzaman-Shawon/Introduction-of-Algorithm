#include <bits/stdc++.h>
using namespace std;

void rec(int n){
    if(n > 5)
        return;
    cout << n << endl;
    rec(n+1); //call ownself to do again and again until the condition comes true
}
//recursion time complexity in general O(N)

int main(){
    rec(1);
    return 0;
}