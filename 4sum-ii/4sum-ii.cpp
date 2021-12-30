class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mapka;
        for(auto a : nums1){
            for(auto b:nums2){
                mapka[a+b]++;
            }
        }
        int  count = 0;
        for(auto c:nums3){
            for(auto d:nums4){
                count += mapka[-c-d];
            }
        }
        return count;
    }
};

//a + b + c + d = 0 