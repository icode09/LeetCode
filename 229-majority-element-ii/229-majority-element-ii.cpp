class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0 , count2 = 0;
        int firstCandidate = INT_MAX , secondCandidate = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(firstCandidate == nums[i]){
                count1++;
            }else if(secondCandidate == nums[i]){
                count2++;
            }else if(count1 == 0){
                firstCandidate = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                secondCandidate = nums[i];
                count2 = 1;
            }else{
                count1-- , count2--;
            }
        }
        
        count1 = 0 ,count2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(firstCandidate == nums[i]) count1++;
            else if(secondCandidate == nums[i]) count2++;
        }
        vector<int> ans;
        if(count1 > nums.size()/3) ans.push_back(firstCandidate);
        if(count2 > nums.size()/3) ans.push_back(secondCandidate);
        
        return ans;
    }
};