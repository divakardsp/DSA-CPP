//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
  
    vector<int> dfsCore(int src, vector<bool> &vis, vector<int> &ans, vector<vector<int>>& adj){
        // Code here
        vis[src] = true;
        
        ans.push_back(src);
        
        for(int neigh: adj[src]){
            if(vis[neigh] == false){
                dfsCore(neigh, vis, ans, adj);
            }
        }
        
        return ans;
        
    }
    
    
    vector<int> dfs(vector<vector<int>>& adj) {
       vector<bool> vis(adj.size(), false);
       vector<int> ans;
       
       
       return dfsCore(0, vis, ans, adj);
       
    }
};