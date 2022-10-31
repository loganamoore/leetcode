#include <stack>

class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(c == ')' || c == '}' || c == ']'){
                int diff = (c == ')') ? 1 : 2;

                if(stk.size() && c - diff == stk.top())
                    stk.pop();
                else
                    return false;
            }
            else
                stk.push(c);
        }

        return !stk.size();
    }
};
