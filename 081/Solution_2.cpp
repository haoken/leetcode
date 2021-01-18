#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }

        int start = 0, end = nums.size() - 1;

        while (start < end && nums[start] == nums[end]) {
            start++;
        }

        if (start == end) {
            if (nums[start] == target) {
                return true;
            } else {
                return false;
            }
        }
        if (nums[start] == target || nums[end] == target) {
            return true;
        }

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if (nums[mid] <= nums[end]) {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }

        if (nums[start] == target || nums[end] == target) {
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    vector<int> a = {3,1,1};
    Solution solution;
    bool flag = solution.search(a,0);
    cout << flag << endl;
    return 0;
}