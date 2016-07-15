class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count  = 0;
        while(n){
            if(n & (n - 1) == 0)
                ++count;
        }
        return count;
    }
};