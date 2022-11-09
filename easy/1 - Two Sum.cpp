// First solution - O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector <int> answers;	// Output

		// Iterate over the list of numbers.
        for(int i = 0; i < nums.size(); i++){
			// Iterate over the list of numbers starting after the current number.
            for(int j = i+1; j < nums.size(); j++){
				// Check if both numbers add up to the target.
                if(nums[i] + nums[j] == target){
                    answers.push_back(i);
                    answers.push_back(j);
                }
            }
        }

        return answers;

    }
};


// Better solution - O(n)
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> n;	// Map of numbers
        vector<int> o;		// Output
        
		// Map the number at i to its position in the vector.
        for(int i = 0; i < nums.size(); i++)
            n.insert({ nums[i], i });
        
		// Iterate over each of the numbers in the vector.
        for(int i = 0; i < nums.size(); i++){
			// Calculate what number is needed for this to be a match.
            int compliment = target - nums[i];
    
			// Check if the compliment is in the hash map but not the same number.
            if((bool)n.count(compliment) && i != n[compliment]){
                o.push_back(i);
                o.push_back(n[compliment]);
                return o;
            }  
        }
        
        return o;
        
    }
};