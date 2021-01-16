#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search (vector<int>& nums, int target) {
        if (nums.empty()){
            return -1;
        }
        int length = nums.size();
        if (target == nums[0]) return 0;
        if (target == nums[length-1]) return length - 1;

        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {//找旋转点
            int mid = start + (end - start)/2;

            if (nums[mid] > nums[length - 1]) {
                start = mid;
            } else if (nums[mid] <= nums[length - 1]) {
                end = mid;
            }
        }

        if (nums[start] <= nums[end]) { // 根据旋转点找起点终点
            start = 0;
            end = length - 1;
        } else {
            if (target > nums[length - 1]) {
                end = start;
                start = 0;
            } else {
                start = end;
                end = length - 1;
            }
        }

        while (start + 1 < end) { // first target 二分法
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
};

int main() {
    vector<int> a = {4,5,6,7,0,1,2};
    Solution solution;
    int firstPos = solution.search(a,0);
    cout << "firstPosition: " << firstPos << endl;
    return 0;
}