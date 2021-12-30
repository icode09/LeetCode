class Solution {
public:
    vector<int> original,shuffled;
    int n;
    Solution(vector<int>& nums) {
        srand(time(NULL));
        this->original = nums;
        this->shuffled = nums;
        this->n = nums.size();
    }
    
    vector<int> reset() {
        return this->original;
    }
    
    vector<int> shuffle() {
        for(int i = n-1;i>0;i--){
            int j = rand()%(i+1);
            swap(shuffled[i],shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */