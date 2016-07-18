class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vs(numRows, "");
        string res;
        int m = s.size();
        int count = 0;
        while(count < m){
            for(int i = 0; i < numRows && count < m; i++)
                vs[i].push_back(s[count++]);
            for(int i = numRows - 2; i >= 1 && count < m; i--)
                vs[i].push_back(s[count++]);
        }
        for(auto c:vs)
            res += c;
        return res;
    }   
};