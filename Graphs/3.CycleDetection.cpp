

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