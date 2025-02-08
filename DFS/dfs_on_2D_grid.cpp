#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int,int>>d = {{-1,0},{1,0},{0,-1},{0,1}};//four child per node shortcut every value is a pair
//vector size () not []
int n,m;

bool valid(int i, int j){
    if(i<0 || i >= n || j < 0 || j>=m) //corner case
        return false;
    return true;
}

void dfs(int si, int sj){
    //base case if needed
    //if(condition)
    //print
    cout << si << " "<< sj << endl ;
    vis[si] [sj] = true;
    for(int i = 0; i < 4; i++){ //four child per node so 4 times loop
        int ci = si + d[i].first;
        int cj = sj+ d[i].second;
        if(valid(ci,cj) && !vis[ci][cj])
            dfs(ci,cj);
        
        }
}

int main(){
    
    cin >> n >> m;
    //char grid[n],[m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int si,sj;  //source of i and j 
    cin >> si >> sj;
    memset(vis,false, sizeof(vis));
    dfs(si,sj);    

    //print 
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}