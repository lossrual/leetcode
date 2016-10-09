class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unit32_t res = 0;
        for(int i = 0; i < 32; i++) {
            res = res << 1 + (n >> i & 1);
        }
        return res;
    }
};