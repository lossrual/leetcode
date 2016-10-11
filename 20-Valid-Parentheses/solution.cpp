class Solution {
public:
     bool isValid(string s) {
        stack<char> ss;
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                ss.push(s[i]);
            else if(ss.empty() || mp[ss.top()] != s[i])
                return false;
            else 
                ss.pop();
        }
        return ss.empty();
     }
};