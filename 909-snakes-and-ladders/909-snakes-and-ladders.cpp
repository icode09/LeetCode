class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<int> q;
        q.push(1);
        visited[n-1][0]  = true;
        
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int currPos = q.front();
                q.pop();
                
                if(currPos == n*n) return steps;
                
                for(int i = 1;i<=6;i++){
                    int nextPos = currPos + i;
                    
                    if(nextPos > n*n) break;
                    
                    int row = n - (nextPos - 1)/n -1;
                    int col = (nextPos - 1)%n;
                    
                    if(row%2 == n%2)
                        col = n - col - 1;
                    
                    if(!visited[row][col]){
                        visited[row][col] = true;
                        if(board[row][col] != -1 && board[row][col] == currPos){
                             continue;
                        }
                        else if(board[row][col] != -1){
                            q.push(board[row][col]);
                        } else{
                          q.push(nextPos);  
                        } 
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};