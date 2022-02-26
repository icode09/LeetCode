class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // 1 =>  We cannot do sorting , because if we do, the element to indices mapping will change
        //2 => We cannot map element to indices mapping directly as there may be duplicates => eg.
        // {3,3} and target  = 6;
        
        // We have to first check if the target - num exists or not, if exist, directly return from there or else map it.
        
        
        unordered_map<int,int> mapka;
       
       for(int i  = 0;i<n;i++){
           int secondNum = target - nums[i];
           if(mapka.find(secondNum) != mapka.end()){
               return {i , mapka[secondNum]};
           }
           mapka[nums[i]] = i;
       }
        
        return {};
    }
};