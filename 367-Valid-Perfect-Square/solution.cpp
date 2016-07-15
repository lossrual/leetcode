class Solution {
public:
    bool isPerfectSquare(int num) {
        int tmp = sqrt(num);
        return tmp * tmp == num;
    }
    int sqrt(int x){
        if(x == 0) return 0;
        if(x < 0) return INT_MIN;
        int low = 1, high = x;
        while(low < high){
            int mid = (low + high) / 2;
            if(mid > x / mid){
                high = mid;
            }else{
                low = mid + 1;
                if(mid + 1 > x / (mid + 1))
                    return mid;
            }
        }
        return low;
    }
};