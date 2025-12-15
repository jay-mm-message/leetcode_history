#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    if (minVal == maxVal) return 0; // 所有數字都相同

    // 計算桶大小和桶數
    int bucket_size = max(1, (maxVal - minVal + n - 2) / (n - 1)); // ceil((max-min)/(n-1))
    int bucket_count = (maxVal - minVal) / bucket_size + 1;

    vector<int> bucket_min(bucket_count, INT_MAX);
    vector<int> bucket_max(bucket_count, INT_MIN);
    vector<bool> bucket_used(bucket_count, false);

    // 放入桶
    for (int num : nums) {
        int idx = (num - minVal) / bucket_size;
        bucket_min[idx] = min(bucket_min[idx], num);
        bucket_max[idx] = max(bucket_max[idx], num);
        bucket_used[idx] = true;
    }

    // 計算最大 gap
    int prev_max = minVal;
    int max_gap = 0;

    for (int i = 0; i < bucket_count; ++i) {
        if (!bucket_used[i]) continue;
        max_gap = max(max_gap, bucket_min[i] - prev_max);
        prev_max = bucket_max[i];
    }

    return max_gap;
}

int main() {
    vector<int> nums = {3, 6, 9, 1};
    cout << "Maximum gap: " << maximumGap(nums) << endl;
}
