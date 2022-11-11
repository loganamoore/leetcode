#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <climits>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Print out an array of integers.
void printArray(vector<int>& nums){
	cout << "[";
	for(int i = 0; i < nums.size(); i++)
		cout << ((i) ? ", " : "") << nums[i];
	cout << "]" << endl;
}

// A test case for binary search.
struct test{
	int target,
		targetIndex;
	vector<int> nums;
};

// Verify that a test is valid.
bool verifyTest(test& t){
	int lastNumber = INT_MIN;
	bool targetVerified = false;
	
	// O(n)
	for(int i = 0; i < t.nums.size(); i++){
		// Verify ascending order of list
		if(lastNumber > t.nums[i])
			return false;
		lastNumber = t.nums[i];

		// Verify the target
		if(i == t.targetIndex && t.nums[i] == t.target)
			targetVerified = true;
	}

	return targetVerified;
}

// Create a test case for binary search.
test makeTest(int size, int target){
	// Generate an ordered number set.
	vector<int> nums;

	srand(time(0));

	int lastNumber = 0,
		targetIndex = -1,				// index of target in array
		offset = rand() % (size + 1);	// offset (to include negatives)

	for(int i = 0; i < size; i++){
		// Generate a number based on the last number.
		int num = lastNumber + (rand() % 7 + 1);

		// Determine if the target should be inserted at this position.
		if(targetIndex == -1 && num - offset >= target){
			// Insert target and increment num so there are no duplicates.
			nums.push_back(target);
			targetIndex = i;
			i++;
			num++;
		}

		// Add this number to the array.
		nums.push_back(num - offset);
		lastNumber = num;
	}

	// Add the target to the list if it never was.
	if(targetIndex == -1){
		nums.push_back(target);
		targetIndex = nums.size() - 1;
	}

	// Return the test case.
	return (test){ target, targetIndex, nums };
}

// O(n)
int bruteSearch(vector<int>& nums, int target){
	// Look through every number for target. Return if found.
	for(int i = 0; i < nums.size(); i++)
		if(nums[i] == target)
			return i;

	// Return error -1 if not found.
	return -1;
}


// Binary Search O(log n)
int binarySearch(vector<int>& nums, int target){
	int m,
		l = 0,
		r = nums.size() - 1;

	while(l < r)
	{
		m = floor((r + l) * 0.5);

		if(nums[m] < target)
			l = m + 1;
		else
			r = m;
	}

	return l;
}

#define TEST_SIZE 10000
#define TARGET 123

int main(int arv, char** arc){
	// Generate and validate tests for binary search.
	cout << "Making and validating " << TEST_SIZE <<  " tests... ";
	test t[TEST_SIZE];
	for(int i = 0; i < TEST_SIZE; i++){
		t[i] = makeTest(i, TARGET);

		// Check if the generated test is correct and handle failures.
		if(!verifyTest(t[i])){
			cout << endl << "Test #" << i << ": FAILED VERIFICATION!" << endl;
			cout << "Target: " << t[i].target << " @ " << t[i].targetIndex << endl;
			printArray(t[i].nums);
			return 1;
		}
	}
	cout << "Done!" << endl;

	// Perform brute search over all test cases.
	cout << "Brute force... ";
	double bfAvg = 0;
	for(int i = 0; i < TEST_SIZE; i++){
		// Add to the average speed of brute force search.
		auto clock = steady_clock::now();
		int index = bruteSearch(t[i].nums, t[i].target);
		auto diff = duration_cast<microseconds>(steady_clock::now() - clock);
		bfAvg = (bfAvg + diff.count()) * 0.5;

		// Check if this search failed.
		if(index != t[i].targetIndex){
			cout << endl << "Test #" << i << " FAILED!" << endl;
			cout << "Target: " << t[i].target << " @ " << t[i].targetIndex << " RETURNED " << index << endl;
			printArray(t[i].nums);
			return 1;
		}
	}
	cout << "  " << bfAvg << "ms" << endl;

	// Perform binary search over all test cases.
	cout << "Binary search... ";
	double bsAvg = 0;
	for(int i = 0; i < TEST_SIZE; i++){
		// Add to the average speed of binary search.
		auto clock = high_resolution_clock::now();
		int index = binarySearch(t[i].nums, t[i].target);
		auto diff = duration_cast<microseconds>(steady_clock::now() - clock);
		bsAvg = (bsAvg + diff.count()) * 0.5;

		// Check if this search failed.
		if(index != t[i].targetIndex){
			cout << endl << "Test #" << i << " FAILED!" << endl;
			cout << "Target: " << t[i].target << " @ " << t[i].targetIndex << " RETURNED " << index << endl;
			printArray(t[i].nums);
			return 1;
		}
	}
	cout << bsAvg << "ms" << endl;


	double avgDelta = bfAvg / bsAvg;
	cout << "Binary search performed " << avgDelta << "x "
		 << ((avgDelta < 1) ? "slower " : "faster ")
		 << "than brute force." << endl;


	return 0;
}