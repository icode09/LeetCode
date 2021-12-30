class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return {0};
        
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int,int>> new_nums;
        for(int i = 0;i<n;i++){
            new_nums.push_back({nums[i],i});
        }
        
        mergeSortAndCount(new_nums,0,n-1,res);
        
        return res;
    }
    void mergeSortAndCount(vector<pair<int,int>>& new_nums,int start,int end,vector<int>& res){
        if(start >= end) return ;
        
        int mid = start + (end - start)/2;
        mergeSortAndCount(new_nums,start,mid,res);
        mergeSortAndCount(new_nums,mid+1,end,res);
        
        int left = start;
        int right = mid + 1;
        vector<pair<int,int>> merged;
        int numRightElmLessThanLeft = 0;
        while(left <= mid && right <= end){
            if(new_nums[left].first > new_nums[right].first){
                numRightElmLessThanLeft++;
                merged.push_back(new_nums[right]);
                right++;
            }
            else{
                res[new_nums[left].second] += numRightElmLessThanLeft;
                merged.push_back(new_nums[left]);
                left++;
            }
        }
        
        while(left <= mid){
                res[new_nums[left].second] += numRightElmLessThanLeft;
                merged.push_back(new_nums[left]);
                left++;
        }
        
        while(right <= end){
            merged.push_back(new_nums[right]);
            right++;
        }
        
        int idx = start;
        for(auto it : merged){
            new_nums[idx] = it;
            idx++;
        }
        
    }
};