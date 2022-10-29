class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int last = nums.at(0);
        int place = 1;

        for(int i = 1; i < nums.size(); i++){

            int curr = nums.at(i);

            if(curr != last){

                // swap the two values
                int t = nums[place];
                nums[place] = curr;
                nums[i] = t;

                place++;
                last = curr;
            }

        }

        return place;

    }
};
