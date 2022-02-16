class Solution {
public:
    string removeDuplicates(string s, int k) {
       vector<pair<int, char>> stack = {{0, '#'}};
        for (char c: s) {
            if (stack.back().second != c) {
                stack.push_back({1, c});
            } else if (++stack.back().first == k)
                stack.pop_back();
        }
        string res = "";
        for(int i = 1;i<stack.size();i++){
            res += string(stack[i].first,stack[i].second);
        }
        // reverse
        return res;
    }
};