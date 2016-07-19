class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto word: strs){
            string tmp = word;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(word);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
};