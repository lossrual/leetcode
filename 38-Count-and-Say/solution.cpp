class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string res = "1";
        while(--n){
            string cur = "";
            for(int i = 0; i < res.size(); i++){
                int count = 1;
                while(res[i] == res[i + 1] && i < res.size() - 1){
                    ++count;
                    ++i;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};