class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       if(n == 1) return 1;

        
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        for(int i = 0;i<trust.size();i++){
            int p1 = trust[i][0];
            int p2 = trust[i][1];
            indegree[p2]++;
            outdegree[p1]++;
        }
        
        for(int i = 1;i<=n;i++){
            if(indegree[i] == n-1 && outdegree[i] == 0) return i;
        }
        
        return -1;
    }
};