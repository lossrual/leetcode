class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        res.push_back(0);
        for(auto num : nums){
            sum += num;
            res.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return res[j + 1] - res[i];
    }
private:
    vector<int> res;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);