class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size(),
            o = 0,
            i = 0,
            characters[255] = {-1};

        for(int j = 0; j < 255; j++){
            characters[j] = -1;
        }

        for(int j = 0; j < n; j++){
            i = max(i, characters[ s[j] ] + 1);
            o = max(o, j - i + 1);
            characters[ s[j] ] = j;
        }

        return o;
    }
};
