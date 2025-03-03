#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int fibonacci[n+1];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2; i <=2 ;i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i=2]; 
    }
    cout << fibonacci[n] << endl;
    return 0;
}