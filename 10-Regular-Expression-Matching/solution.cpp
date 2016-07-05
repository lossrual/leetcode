class Solution {
public:
    bool isMatch1(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1] == '*')
            return isMatch(s, p.substr(2)) || (!s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
    bool isMatch2(string s, string p){
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]);
                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return dp[m][n];
    }
    bool isMatch(string s, string p){
        if(s[0] == '\0' && p[0] == '\0') return true;
        if(s[0] != '\0' && p[0] == '\0') return false;
        if(p[1] == '*'){
            if(s[0] == p[0] || p[0] == '.' && s[0] != '\0')
                return isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(2)) || isMatch(s, p.substr(2));
            else
                return isMatch(s, p.substr(2));
        }
        if(p[0] == s[0] || p[0] == '.' && s[0] != '\0')
            return isMatch(s.substr(1), p.substr(1));
        return false;
    }
};