class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority_queue<int> pq;
        // for(int i = 0;i<matrix.size();i++){
        //     for(int j = 0;j<matrix[0].size();j++){
        //         pq.push(matrix[i][j]);
        //         if(pq.size() > k) pq.pop();
        //     }
        // }
        // return pq.top();
        
        int n = matrix.size() , m = matrix[0].size();
        int low = matrix[0][0] , high = matrix[n-1][m-1];
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(noOfElementsLessOrEqual(matrix,mid) >= k){
                ans = mid;
                high = mid-1;
            }
            else 
                low = mid + 1;
            
        }
        return ans;
    }
    int noOfElementsLessOrEqual(vector<vector<int>>& matrix,int target){
        // again binary search
        int count = 0;
        int n = matrix.size() , col = matrix[0].size() - 1;
        for(int i = 0;i<n;i++){
            while(col >= 0 && matrix[i][col] > target) col--;
            count += (col + 1);
        }
        return count;
    }
    // 1  5  9
    // 10 11 13
    // 12 13 15  
};