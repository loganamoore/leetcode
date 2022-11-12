//O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1,
                 out  = 0;
        
        for(int i = 0; i < 32; i++){
            if(n & mask)
                out++;
            mask = mask << 1;
        }
        
        return out;
    }
};