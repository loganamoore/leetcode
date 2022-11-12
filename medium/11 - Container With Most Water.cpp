// O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0,                  // left iter
            r = height.size() - 1,  // right iter
            m = INT_MIN;            // maximum area
        
        // update max and increment the iter with the smallest height
        while(l < r){
            if(height[l] <= height[r]){
                m = std::max(m, (r - l) * height[l]);
                l++;
            }
            else{
                m = std::max(m, (r - l) * height[r]);
                r--;
            }
            
        }
        
        return m;
        
    }
};