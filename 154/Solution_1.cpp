#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        
        int length = nums.size();
        int start = 0, end = length - 1;

        while (start < end && nums[start] == nums[end]) {
            start++ ;
        }

        if (start == end) {//全都一样
            return nums[0];
        } else if (start + 1 == end && nums[start]<nums[end]) {// 剩两个数
            return nums[start];
        } else if (start + 1 == end && nums[start]>nums[end]) {
            return nums[end];
        }

        while (start + 1 < end) { // 找分割点
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[length - 1]) {
                start = mid;
            } else if (nums[mid] <= nums[length - 1]) {
                end = mid;
            }
        }
        // start 是分割点的左边， end 是分割点的右边
        if (nums[start] < nums[end]) { // 和原数组一样
            return nums[start];
        } else {
            return nums[end];
        }
    }
};

int main(){
    vector<int> a = {3,1,3,3};
    Solution solution;
    int result = solution.findMin(a);
    cout << "result : " << result << endl;
    return 0;
}