/*
Problem: Wiggle Sort

Given an integer array nums, reorder it in-place such that it satisfies the “wiggle” property:

nums[0]<=nums[1]>=nums[2]<=nums[3]>=nums[4]…

In other words:

Elements at even indices should be ≤ the next element.

Elements at odd indices should be ≥ the next element.

You must reorder the array in-place without using extra arrays.

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: The output is not unique, as long as it satisfies the wiggle property.


Input: nums = [1,2,3,4,5,6]
Output: [1,3,2,5,4,6] or any other valid wiggle arrangement


*/

#include <iostream>
using namespace std;

void ptr(vector<int> nums, string tag) {
	cout << tag << ": ";
	for(int n : nums) {
		cout << n << ' ';
	}
	cout << endl;
}

void wiggle_sort(vector<int> &nums) {
	for(int i = 0 ; i < nums.size() ; ++i) {
		if (((i % 2 == 0) && (nums[i] > nums[i+1])) ||
			((i % 2 == 1) && (nums[i] < nums[i+1]))) {
			swap(nums[i], nums[i+1]);
		}
	}
}

bool check_1(vector<int> &nums) {
	vector<int> chk = {1,3,2,5,4,6};
	for(int i = 0 ; i < nums.size() ; ++i) {
		if (chk[i] != nums[i])
			return false;
	}
	return true;
}

bool check_2(vector<int> &nums) {
	vector<int> chk = {3,5,1,6,2,4};
	for(int i = 0 ; i < nums.size() ; ++i) {
		if (chk[i] != nums[i])
			return false;
	}
	return true;
}

int main() {
	vector<int> nums = {1,2,3,4,5,6};
	wiggle_sort(nums);
	if (check_1(nums)) {
		cout << "check 1 case success." << endl;
	} else {
		cout << "check 1 case failed." << endl;
	}

	vector<int> nums2 = {3,5,2,1,6,4};
	wiggle_sort(nums2);
	if (check_2(nums2)) {
		cout << "check 2 case success." << endl;
	} else {
		cout << "check 2 case failed." << endl;
	}

	return 0;
}