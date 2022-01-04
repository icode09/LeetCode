class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
         bitset<32> vec(N);
        int x = log2(N) + 1;
        
        for(int i = 0;i<x;i++){
            vec.flip(i);
        }
        
        return (int)(vec.to_ulong());
    }
};