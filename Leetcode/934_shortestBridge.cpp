class Solution {
public:
    int n;
    
    bool isValid(int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= n) return false;
        else return true;
    }
    
    void dfs(int i, int j){
       if(!isValid(i, j) || grid[i][j] == 0 || vis[i][j] = true) return;
//         valid land (grid[i][j] == 1) cell 
        vis[i][j] = true;
        for(int di = 0; di < d.size(); di++){
            dfs(i+d[di][0], j + d[di][1]);
        }
    }
    
    int bfs(){
        int ans, q = 0;
        
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> d = [[0,1],[0,-1],[-1,0],[1,0]];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    dfs(i,j);
                    return bfs();
                    }
            }
        }
        
    }
};