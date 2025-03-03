#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 1)
        return 1;
    //int mul = fact(n-1);
    //return n * mul;
    
    return n * fact(n-1); //two lines together;
}

int main(){
    cout << fact(5);
    return 0;
}