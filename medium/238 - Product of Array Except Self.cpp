class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // Create an array the same size as the input.
        vector<int> answer(nums.size(), 0);
        
        // Set the first and last value to 1.
        answer[0] = 1;
        answer[nums.size() - 1] = 1;
        
        int l = 1,                  // product to the left of iterator
            r = 1,                  // product to the right of iterator
            i = 1,                  // left iterator
            j = nums.size() - 2;    // right iterator
        
        // Iterate over the input in both directions
        while(i < nums.size()){
            // Multiply l by the number before the left iterator
            l *= nums[i - 1];
            // Multiply r by the number after the right iterator
            r *= nums[j + 1];
            
            // Check if the left iter. hasn't passed the right iter.
            if(i < j){
                // Set answers to the products to the left and right
                answer[i] = l;
                answer[j] = r;
            }
            else
                // Check if both iters are the same
                if(i == j)
                    // Set answer to the product to the left and right products
                    answer[i] = l * r;
                else{
                    // Multiply answer by the products to the left and right
                    answer[i] *= l;
                    answer[j] *= r;
                }
            
            // Update each iterator
            i++;
            j--;
        }
        
        return answer;
    }
};