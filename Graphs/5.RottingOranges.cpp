// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

       vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<pair<int,int>,int>> Q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    Q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;

        while(Q.size() > 0){
            int i = Q.front().first.first;
            int j = Q.front().first.second;
            int t = Q.front().second;
            Q.pop();

           ans = max(ans, t);

            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                Q.push({{i-1, j}, t + 1});
                vis[i-1][j] = true;
            }

            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
                Q.push({{i+1, j}, t + 1});
                vis[i+1][j] = true;
            }

            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                Q.push({{i, j-1}, t + 1});
                vis[i][j-1] = true;
            }

            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
                Q.push({{i, j+1}, t + 1});
                vis[i][j+1] = true;
            }

        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && ! vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;

    }
};