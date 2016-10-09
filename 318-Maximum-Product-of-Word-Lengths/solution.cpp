class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxp = 0;
        vector<int> mask(words.size(), 0);
        for(int i = 0; i < words.size(); i++) {
            string tmp = words[i];
            for(int j = 0; j < tmp.size(); j++){
                mask[i] |= 1 << (tmp[j] - 'a');
            }
            for(int j = 0; j < i; j++) {
                if(!(mask[i] & mask[j]) && words[i].size() * words[j].size() > maxp)
                    maxp = words[i].size() * words[j].size();
            }
        }
        return maxp;
    }
};