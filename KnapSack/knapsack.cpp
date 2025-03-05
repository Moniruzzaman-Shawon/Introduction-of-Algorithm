#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];

int knapsack(int i, int max_weight){ //complexity 2^n

    //base case
    if(i<0 || max_weight <= 0)
        return 0;
    // if(max_weight <= 0) //in upper line 
    //     return 0;

        
    if(weight[i] <= max_weight){
    //2 options
    //1. keep in bag    2. not keep in bag
        int option1 = knapsack(i-1, max_weight - weight[i]) + val[i];
        int option2 = knapsack(i-1, max_weight);
        return max(option1, option2);
    }
    else{
    // 1 option
    // not keep in bag
        // int option2 = knapsack(i-1, max_weight);
        // return option2;

        //or
        return knapsack(i-1, max_weight); //short
    }
}

int main(){
    int n,max_weight;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        cin >> val[i];
    }
    for(int i = 0; i<n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;

    //knapsack(n-1,max_weight);
    //last index - 1 , val, weight


    cout << knapsack(n-1, max_weight) << endl;
    return 0;
}