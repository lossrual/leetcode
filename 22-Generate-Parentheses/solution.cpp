class Solution {
public:
/*
    vector<string> generateParenthesis(int n) {
        string str = "";
        for(int i = 0; i < n; i++){
            str.push_back('(');
            str.push_back(')');
        }
        vector<string> vs;
        vector<string> res;
        helper(vs, str, 0);
        for(auto c:vs){
            if(check(c)){
                res.push_back(c);
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    void helper(vector<string>& res, string str, int k){
        if(k == str.size() - 1){
            res.push_back(str);
            return;
        }
        for(int i = k; i < str.size(); i++){
            swap(str[i], str[k]);
            helper(res, str, i + 1);
            swap(str[i], str[k]);
        }
    }
    bool check(string str){
        stack<char> s;
        unordered_map<char, char> mp;
        mp['('] = ')';
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(')
                s.push(str[i]);
            else if(s.empty() || mp[s.top()] != str[i])
                return false;
            else 
                s.pop();
        }
        return s.empty();
    }
*/
    vector<string> generateParenthesis(int n){
        vector<string> res;
        string path = "";
        helper(res, path, n, n);
        return res;
    }
    void helper(vector<string>& res, string path, int l, int r){
        if(r < l)
            return;
        if(l == 0 && r == 0)
            res.push_back(path);
        if(l > 0)
            helper(res, path + '(', l - 1, r);
        if(r > 0)
            helper(res, path + ')', l, r - 1);
        
    }
};