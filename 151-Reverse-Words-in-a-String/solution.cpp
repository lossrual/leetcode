class Solution {
public:
/*
    void reverseWords(string &s) {
        if(s == "") return;
        stack<char> ss;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            ss.push(s[i]);
        }
        s.clear();
        while(!ss.empty()){
            auto cur = ss.top();
            ss.pop();
            s += cur; 
        }
    }
*/
    void reverseWords(string& s){
        string res = "";
        for(int i = 0; i < s.size(); i++){
            int pos = i;
            if(s[i] == ' ') continue;
            while(s[i] != ' ' && i < s.size()) ++i;
            if(res.size() > 0) res = ' ' + res;
            res = s.substr(pos, i - pos) + res;
        }
        s = res;
    }
};