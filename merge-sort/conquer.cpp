#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)            //take an arr
        cin >> a[i];
    
    int m;
    cin >> m;
    int b[m];
    for(int j=0;j<m;j++)               //take another arr
        cin >> b[j];

    int c[n+m]; 

    int i=0,j=0, curr = 0;
    while(i<n && j<m){
        if(a[i] < b[i]){
            c[curr] = a[i];
            i++;
            curr++;
        }
        else{                           //a[i] > b[i]
            c[curr] = b[j];
            j++;
            curr ++;
        }

    }
    while(i<n){
        c[curr] = a[i];
        i++;
        curr++;
    }

    while (j<m)
    {
        c[curr] = b[j];
        j++;
        curr++;
    }
    for(int i = 0; i<n+m;i++){
        cout << c[i]<< " ";
    }

    return 0;
}