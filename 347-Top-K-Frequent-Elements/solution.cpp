class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map_;
        vector<int> res;
        //unordered_set<int> set_;
        for(int i = 0; i < nums.size(); i++){
            map_[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it = map_.begin(); it != map_.end(); it++){
            //second:num, first:frequency
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map_.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};