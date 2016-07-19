class Solution {
public:
//交换元音字母
    string reverseVowels1(string s) {
        //int i = 0, j = s.size() - 1;
        auto p1 = s.begin(), p2 = s.end() - 1;
        bool vowels[256] = {false}; 
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o']= vowels['u'] = true; 
        vowels['A'] = vowels['E'] = vowels['I'] = vowels['O']= vowels['U'] = true;
        while(p1 < p2){
            while(p1 < p2 && !vowels[*p1]) ++p1;
            while(p1 < p2 && !vowels[*p2]) --p2;
            if(p1 < p2)  swap(*p1, *p2);
            p1++;
            p2--;
        }
        return s;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        //auto p1 = s.begin(), p2 = s.end() - 1;
        bool vowels[256] = {false}; 
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o']= vowels['u'] = true; 
        vowels['A'] = vowels['E'] = vowels['I'] = vowels['O']= vowels['U'] = true;
        for(; i < s.size() / 2, j > i; i++, j--){
            while(i < j && !vowels[s[i]]) ++i;
            while(i < j && !vowels[s[j]]) --j;
            if(s[i] == s[j]) continue;
            if(i < j)  swap(s[i], s[j]);
            //i++;
            //j--;
        }
        return s;
    }
};