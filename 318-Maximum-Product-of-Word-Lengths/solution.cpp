class Solution {
public:
    int maxProduct(vector<string>& words) {
        //if(words.size() == 0) return 0;
        int len = words.size();
        int res = 0;
        vector<int> mask(len);
        for(int i = 0; i < len; i++){
            string tmp = words[i];
            for(char c: tmp){
                mask[i] |= 1 << (c - 'a');
            }
            for(int j = 0; j < i; j++){
                if(!(mask[i] & mask[j]) && (words[i].size() * words[j].size() > res)){
                    res = words[i].size() * words[j].size();
                }
            }
        }
        return res;
    }
};