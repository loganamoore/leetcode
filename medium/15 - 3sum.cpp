// O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(n log n)
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            
            // ignore this number if it's the same as the last
            if(n == nums[i-1])
                continue;
            
            int l = i + 1,           // left iter
                r = nums.size() - 1; // right iter
            
            while(l < r){
                // get the sum
                int sum = n + nums[l] + nums[r];
                
                if(sum < 0)
                    l++;         //increase the left iter
                else if(sum > 0)
                    r--;        // decrease the right iter
                else{
                    // append these values to the out vector
                    vector<int> t;
                    t.insert(t.end(), { n, nums[l], nums[r] });
                    out.push_back(t);
                    
                    // increment the left vector
                    l++;
                    
                    // avoid duplicates
                    while(nums[l] == nums[l - 1] && l < r)
                        l++;
                }
            }
            
        }
        
        return out;
    }
};