class Solution {
public:
    string addBinary(string a, string b) {
        int len = a.size() > b.size() ? a.size() : b.size();
        int extra = 0;
        string res;
        for(int i = 0; i < len; i++){
            int val1 = i < a.size() ? a[a.size() - i - 1] - '0' : 0;
            int val2 = i < b.size() ? b[b.size() - i - 1] - '0' : 0;
            int sum = val1 + val2 + extra;
            res = to_string(sum % 2) + res;
            extra = sum / 2;
        }
        if(extra) res = "1" + res;
        return res;
    }
};