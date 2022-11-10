// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> out;
        out.push_back(0);                   // left iter
        out.push_back(numbers.size() - 1);  // right iter
        
        while(out[0] < out[1]){
            
            // get the sum of the numbers at the left and right iters
            int sum = numbers[out[0]] + numbers[out[1]];
            
            if(sum < target)
                out[0]++;           // move left iter right
            else if(sum > target)
                out[1]--;           // move right iter left
            else
                break;              // target found
            
        }
        
        // increment both iters
        out[0]++;
        out[1]++;
        
        return out;
    }
};