class Solution {
public:
//O(n)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int index = 0, total = 0, tank = 0;
        for(int i = 0; i < n; i++){
            tank += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if(tank < 0){
                index = i + 1;
                //total += tank;
                tank = 0;
            }
        }
        return total < 0 ? -1 : index;
    }
    //O(n),O(1)
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1, end = 0;
        int total = gas[start] - cost[start];
        while(end < start){
            if(total >= 0){
                total += gas[end] - cost[end];
                ++end;
            }else{
                --start;
                total += gas[start] - cost[start];
            }
        }
        return total < 0 ? -1 : start;
    }
};