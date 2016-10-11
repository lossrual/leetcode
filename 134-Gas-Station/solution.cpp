class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, take = 0, index = 0;
        for(int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            take += diff;
            total += diff;
            if(take < 0) {
                take = 0;
                index = i + 1;
            }
        }
        return total < 0 ? -1 : index;
    }
};