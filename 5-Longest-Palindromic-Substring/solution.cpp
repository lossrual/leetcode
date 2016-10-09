class Solution {
public:
//DP O(N2) time and O(N2) space，　最长回文子串
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, maxlen = 1;
        bool table[1000][1000] = {false};
        for(int i = 0; i < n; i++)
            table[i][i] = true;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && table[i+1][j-1] == true){
                    table[i][j] = true;
                    start = i;
                    maxlen = len;
                }
            }
        }
        return s.substr(start, maxlen);
    }
//中间朝两边凑 O(N2) time and O(1) space:
    string longestPalindrome1(string s) {
        int n = s.length();
        if(n == 0) return "";
        if(n == 1) return s;
        string longest = s.substr(0, 1);
        for(int i = 0; i < n; i++){
            string p1 = expendAroundCenter(s, i, i);
            if(p1.length() > longest.length())
                longest = p1;
                
            string p2 = expendAroundCenter(s, i, i + 1);
            if(p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
private:
    string expendAroundCenter(string s, int c1, int c2){
        int l = c1, r = c2;//c1,c2为中间center，分s长度奇偶
        int n = s.length();
        while(l >= 0 && r <= n - 1 && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};