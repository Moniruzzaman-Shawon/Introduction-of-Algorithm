#include <bits/stdc++.h>
using namespace std;

void conquer(int c[], int l, int mid, int r){
    int n;
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
}

void divide(int a[],int l, int r){
    
    if(l>=r)
        return;
    int mid = (l+r)/2;
    divide(a,l,mid);
    divide(a,mid+1, r);
    conquer(a,l,mid,r);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    divide(a, 0, n-1);
    return 0;
}