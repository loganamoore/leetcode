// O(log n) - binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0],
            l = 0,                  // left iter
            r = nums.size() - 1;    // right iter
        
        while(l <= r){
            if(nums[l] < nums[r]){
                min = std::min(min, nums[l]);
                break;
            }
            
            // Find the middle between the left and right iter.
            int m = std::round((l + r) * 0.5);
            // Update the min.
            min = std::min(min, nums[m]);
            
            // Check to see if the middle is part of the left or right rotated side.
            if(nums[m] >= nums[l])
                l = m + 1;     // move the left iter right of middle
            else
                r = m - 1;     // move the right iter left of middle
        }
        
        return min;
    }
};