class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> Q;
        vector<vector<int>> status(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    Q.push({i,j});
                    status[i][j] = 0;
                }
            }
        }
        while(!Q.empty()){
            auto p = Q.front();
            Q.pop();
            int i = p.first;
            int j = p.second;
            // right
            if(j+1 < m && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                status[i][j+1] = status[i][j] + 1;
                Q.push({i, j+1});
            }

            // left
            if(j-1 >= 0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                status[i][j-1] = status[i][j] + 1;
                Q.push({i, j-1});
            }

            // up
            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                status[i-1][j] = status[i][j] + 1;
                Q.push({i-1, j});
            }

            // down
            if(i+1 < n && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                status[i+1][j] = status[i][j] + 1;
                Q.push({i+1, j});
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                    return -1;

                ans = max(ans, status[i][j]);
            }
        }
        return ans;
    }
};
