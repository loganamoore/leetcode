// O(n)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int min = INT_MAX,	// smallest price
		max = 0;			// maximum profit

		// Iterate over each price in the list.
		for(int i = 0; i < prices.size(); i++){
			// If a new smallest price is found, replace it.
			if(prices[i] < min)
				min = prices[i];
			// Set the max profit to the highest.
			max = std::max(max, prices[i] - min);
		}
		
		return max;
	}
};