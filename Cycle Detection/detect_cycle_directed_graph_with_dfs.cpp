#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int>adj_list[105];
bool pathvis[105]; 
bool cycle;
void dfs(int src){
    vis[src]= true;
    pathvis[src] = true;
    for(int child: adj_list[src]){

        if(vis[child] && pathvis[src])
                cycle = true;

                
        if(!vis[child]){
            
            
            dfs(child);

        }
    }
    //return 
    pathvis[src] = false;
}

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        
    }
    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    cycle = false;
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
    for(int i = 0; i<n;i++){
        //cout <<  "Parent : " << pathvis[i] << endl;
    }
    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not Detected\n"; 
    return 0;
}