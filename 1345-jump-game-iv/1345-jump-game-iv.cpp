class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return 0;
        
        unordered_map<int,vector<int>> mapka;
        for(int i = 0;i<n;i++){
            mapka[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        visited[0] = true;
        
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr_index = q.front();
                q.pop();
                
                if(curr_index == n - 1) return steps;
                
                vector<int>& neigh = mapka[arr[curr_index]];
                
                neigh.push_back(curr_index - 1);
                neigh.push_back(curr_index + 1);
                
                for(auto j : neigh){
                    if(j >= 0 && j < n && !visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
                
                neigh.clear();
            }
            
            steps++;
        }
        
        return -1;
        
    }
};