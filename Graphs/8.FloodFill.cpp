// https://leetcode.com/problems/flood-fill/

class Solution {
public:

    void dfs(int row, int col, int changeTo, vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int m, int orgClr){
        if(row < 0 || col < 0 || row >= n || col >= m ||  vis[row][col] || grid[row][col] != orgClr){
            return;
        }

        vis[row][col] = true;
        grid[row][col] = changeTo;

        dfs(row-1, col, changeTo, grid, vis, n, m, orgClr);
        dfs(row+1, col, changeTo, grid, vis, n, m, orgClr);
        dfs(row, col+1, changeTo, grid, vis, n, m, orgClr);
        dfs(row, col-1, changeTo, grid, vis, n, m, orgClr);



    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int orgClr = image[sr][sc];

        vector<vector<bool>> vis(n, vector<bool> (m, false));

        dfs(sr, sc, color, image, vis, n, m, orgClr);

        return image;
    }
};