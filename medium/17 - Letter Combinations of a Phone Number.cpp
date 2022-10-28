#include <string>

class Solution {
public:

    vector<string> processLetter(const char& digit, const vector<string>& in){

        int letterCount = (digit == '9' || digit == '7') ? 4 : 3;

        char base = digit - 50;
        char character = (digit + 47) + (base * 3) - base;

        if(digit == '8' || digit == '9')
            character++;

        vector<string> combinations;

        if(!in.size()){
            for(int i = 0; i < letterCount; i++)
                combinations.push_back(string(1, character + i));

            return combinations;
        }

        for(int i = 0; i < in.size(); i++)
            for(int j = 0; j < letterCount; j++)
                combinations.push_back(in.at(i) + string(1, character + j));

        return combinations;
    }

    vector<string> letterCombinations(string digits) {

        vector<string> combinations;

        for(int i = 0; i < digits.size(); i++){
            combinations = processLetter(digits[i], combinations);
        }

        return combinations;

    }
};
