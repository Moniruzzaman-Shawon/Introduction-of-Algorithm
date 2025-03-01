#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<vector<pair<int, long long>>> adj; 


vector<long long> dijkstra(int n, int src) {  //function will return long long int value as vetcor
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[src] = 0;
    pq.push(make_pair(0, src)); 
    
    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();
        
        long long d = top.first;
        int u = top.second;

        if (d > dist[u]) continue; 

        for (size_t i = 0; i < adj[u].size(); i++) {
            pair<int, long long> edge = adj[u][i];
            int v = edge.first;
            long long w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {
    int n, e;
    cin >> n >> e;

    adj.resize(n + 1);
    
    for (int i = 0; i < e; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w)); 
    }

    int Q;
    cin >> Q;
    
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        
        vector<long long> dist = dijkstra(n, X);
        
        if (dist[Y] == INF)
            cout << "-1" <<endl;
        else
            cout << dist[Y] << endl;
    }

    return 0;
}
