class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //string res = "";
        int i;
        for(i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};