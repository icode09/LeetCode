class Solution {
public:
    struct myComp{
      bool operator()(const vector<int>& v1, const vector<int>& v2){
          return (v1[0] + v1[1]) > (v2[0] + v2[1]);
      }  
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n == 0 || m == 0 || k == 0) return {};
        
        vector<vector<int>> vec;
        priority_queue<vector<int>,vector<vector<int>>,myComp> pq;
        
        for(int i = 0;i<n && i < k;i++){
            pq.push({nums1[i] , nums2[0] , 0});
        }
        
        while(k-- && !pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            vec.push_back({it[0] , it[1]});
            
            if(it[2] == m - 1) continue;
            
            pq.push({it[0] , nums2[it[2] + 1], it[2] + 1});
        }
        
        return vec;
    }
};