#include <bits/stdc++.h>
using namespace std;

long long int dp[1005]; //for large number 
long long int fibonacci(int n){       //complexity O(N)
    if(n == 0 || n == 1)  
        return n;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = fibonacci(n-1) + fibonacci(n-2);
    return dp[n];
    
}

int main(){
    memset(dp, -1,sizeof(dp));
    long long int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}