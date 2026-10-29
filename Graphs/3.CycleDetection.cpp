

bool isCycleDFS(int src, vector<bool>& vis, vector<vector<int>>& adj, int parent){

    vis[src] = true;

    for(int v: adj[src]){
        if(!vis[v]){
            if(isCycleDFS(v, vis, adj, src)){
                return true
            }
        }else if(v != parent){
            return true;
        }
    }

    return false;
}


bool isCycleBFS(int src, vector<bool>& vis, vector<vector<int>>& adj) {
    
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int v : adj[node]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({v, node});
            } 
            else if (v != parent) {
                return true;
            }
        }
    }

    return false;
}
s