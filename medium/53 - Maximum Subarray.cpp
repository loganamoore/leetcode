// O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN,
            sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum = sum > 0 ? nums[i] + sum : nums[i];
            max = std::max(max, sum);
        }
        
        return max;
    }
};