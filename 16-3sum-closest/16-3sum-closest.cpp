class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minDiff = INT_MAX;
        int sum = 0;
        for(int i=0;i<nums.size() - 2;i++){
            int j = i+1 , k = n - 1;
            while(j < k){
                int close = (nums[i] + nums[j] + nums[k]) - target;
                if(close == 0) return target;
                if(abs(close) < minDiff){
                    minDiff = abs(close);
                    sum = target + close;
                }
                if(close > 0) k--;
                if(close < 0) j++;
            }
        }
        return sum;
    }
};