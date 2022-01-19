class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size();
        int m = list2.size();
        
        unordered_map<string,int> mapka;
        for(int i = 0;i<n;i++){
            mapka[list1[i]] = i;
        }
        
        int minnSum = INT_MAX;
        vector<string> ans;
        for(int i = 0;i<m;i++){
            if(mapka.find(list2[i]) != mapka.end()){
                if(i + mapka[list2[i]] <= minnSum){
                    if(i + mapka[list2[i]] < minnSum){
                        minnSum = i + mapka[list2[i]];
                        ans.clear();
                    }
                    ans.push_back(list2[i]);
                }
            }   
        }
        
        return ans;
    }
};