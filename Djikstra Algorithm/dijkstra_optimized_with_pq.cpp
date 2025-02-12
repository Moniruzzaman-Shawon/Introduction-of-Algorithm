#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj_list[105];
int dis[105];
 
void dijkstra(int src){        //dijkstra complexity :  O( logV (E+V) ) or O(ElogV)
    
    /*-------Complexity--------*/
    
    /*      -----Calculation-----
    =>O( (E+V) logV )
    =>O((E + E)) logV  //because between vertex and edge, edge is greater we can take E insted of V
    =>O(2E logV)
    =>O(ElogV)
    */

    //All are not check that's why it can't be nested loop
    //for priority queue pop & push complexity is O(logN) because it arranges (heap)
    //so complexity is O(V+E)
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while(!pq.empty()){                 //loop O(V)        
        pair<int,int> par = pq.top();
        pq.pop();                  //1->value = O(logV) & for many values O(VlogV)
        int par_dis = par.first;
        int par_node = par.second;

        for(auto child : adj_list[par_node])  //O(E)
        {
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node]){         //path relaxation: yes or not  
                
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node],child_node});   //O(logV) & for many values O(ElogV)
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