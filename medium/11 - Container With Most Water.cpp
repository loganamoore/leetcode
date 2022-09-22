class Solution {
public:
    int maxArea(vector<int>& height) {

        int max = 0,
            i = 0,
            j = height.size() - 1,
            r = 0;

        while(i < j){
            if(height[i] <= height[j]){
                r = height[i] * (j - i);
                i++;
            }
            else{
                r = height[j] * (j - i);
                j--;
            }

            if(r > max)
                max = r;
        }

        return max;

    }
};
