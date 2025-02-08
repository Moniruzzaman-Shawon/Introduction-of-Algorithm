/*
Link : https://leetcode.com/problems/island-perimeter/description/
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/


class Solution {
    public:
        int cnt;
        bool vis[105][105];
        vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
        int n,m;
        bool valid(int i, int j){
            if(i<0 || i>=n || j<0 || j>=m)
                return false;
            return true;
        }
    
        void dfs(int si,int sj,vector<vector<int>>& grid){
            vis[si][sj] = true;
            for(int i = 0; i<4; i++){
                int ci = si + d[i].first ;
                int cj = sj + d[i].second;
    
                if(valid(ci,cj) ==false)
                    cnt++;
                else if(valid(ci,cj) == true && grid[ci][cj] == 0) 
                    cnt++;
                else if(valid(ci,cj) == true && !vis[ci][cj] && grid[ci][cj] == 1){
                    dfs(ci,cj,grid);
                }
            }
        }
    
        int islandPerimeter(vector<vector<int>>& grid) {
            cnt = 0;
            n = grid.size();
            m = grid[0].size();
            memset(vis,false,sizeof(vis));
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(!vis[i][j] && grid[i][j] == 1)
                        dfs(i,j,grid);
            return cnt;    //return 0 not applicable for this
        }
    };



    //---------------------Another Way Solution--------------------------------//
    class Solution {
        public:
            int islandPerimeter(vector<vector<int>>& grid) {
                int n = grid.size();
                int m = grid[0].size();
                int perimeter = 0;
        
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (grid[i][j] == 1) {
                            perimeter += 4; // Each land cell contributes 4 to perimeter
        
                            // Check adjacent cells and reduce perimeter if connected
                            if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2; // Top neighbor
                            if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2; // Left neighbor
                        }
                    }
                }
                return perimeter;
            }
        };