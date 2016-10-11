class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int low = 1, high = x;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(mid > x / mid) {
                high = mid;
            }else {
                low = mid + 1;
                if(mid + 1 > x / (mid + 1))
                    return mid;
            }
        }
        return low;
    }
};