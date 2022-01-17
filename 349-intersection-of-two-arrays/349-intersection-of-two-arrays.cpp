class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mapka;
        for(auto num : nums1){
            mapka[num]++;
        }
        vector<int> res;
        for(auto num : nums2){
            if(mapka.find(num) != mapka.end()){
                    mapka.erase(num);

                res.push_back(num);
            }
        }
        
        return res;
    }
};