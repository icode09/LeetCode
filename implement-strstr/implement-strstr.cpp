class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0 ) return 0;
        
        size_t found_at = haystack.find(needle);
        if(found_at != string::npos) return static_cast<int>(found_at);
        
        return -1;
    }
};