#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj_list[105];
int dis[105];

        //------------**Brute Force Way**------------//
        
void dijkstra(int src){                      //O(V*E)
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while(!q.empty()){                            //O(V)
        pair<int,int> par = q.front();
        q.pop();
        int par_node = par.first;
        int par_dis = par.second;

        for(auto child : adj_list[par_node])  // pair or auto   //O(E)
        {
            int child_node = child.first;
            int child_dis = child.second;

            if(child_dis + par_dis < dis[child_node]){         //path relaxation: yes or not  
                
                dis[child_node] = par_dis + child_dis;
                q.push({child_node, dis[child_node]});
            }
        }
    }

}

int main(){
    int n,e;
    cin >> n >> e;

    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});

    }
    for(int i = 0; i<n; i++)
        dis[i] = INT_MAX;
    dijkstra(0);
    for(int i = 0; i<n;i++){
        cout << i << "->" << dis[i] << endl;
    }
    return 0;
}