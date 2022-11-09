class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Set initial output to highest number in vector
        int out = *max_element(nums.begin(), nums.end()),
            min = 1,
            max = 1;
        
        // Iterate over each number in the vector
        for(int i = 0; i < nums.size(); i++){
            int t = max * nums[i];
            // Get the max value between number itself and product of min and max
            max = std::max(std::max(nums[i], max * nums[i]), min * nums[i]);
            // Get the min value between number itself and product of min and max
            min = std::min(std::min(nums[i], t), min * nums[i]);
            out = std::max(out, max);
        }
        
        return out;
    }
};