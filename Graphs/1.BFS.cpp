//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        queue<int> Q;
        vector<bool> vis(adj.size(), false);
        
        Q.push(0);
        vis[0] = true;
        
        vector<int> ans;
        
        while(Q.size() > 0){
            int node = Q.front();
            Q.pop();
            
            ans.push_back(node);
            
            
            for(int neigh: adj[node]){
                if(vis[neigh] == false){
                    vis[neigh] = true;
                    Q.push(neigh);
                }
            }
        }
        
        return ans;
        
    }
};

int main(){

}