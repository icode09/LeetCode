class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0) continue;
                
                perimeter += 4;
                for(int k = 0;k<4;k++){
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    
                    if(xx < 0 || xx == grid.size() || yy < 0 || yy == grid[0].size() || grid[xx][yy] == 0) continue;
                    perimeter--;
                }
            }
        }
        return perimeter;
    }
};