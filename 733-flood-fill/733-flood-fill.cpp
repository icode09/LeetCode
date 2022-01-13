class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int startingColor = image[x][y];
            image[x][y] = newColor;
            
            for(int i = 0;i<4;i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if(xx < n && xx >= 0 && yy >= 0 && yy < m && image[xx][yy] == startingColor && image[xx][yy] != newColor){
                    q.push({xx,yy});
                }
            }
        }
        
        return image;
    }
};