#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool search (vector<int>& nums, int target) { 
        if (nums.empty()) {
            return false;
        }
        
        int length = nums.size();
        int start = 0, end = length - 1;
        if (nums[start] == target || nums[end] == target) {
            return true;
        }
        while (start + 1 < end && nums[start] == nums[end]){// 去掉边界重复
            start++;
            end--;
        }
        if (start + 1 < end && nums[start] == nums[end] && nums[start] != target) {//全都一样
            return false;
        } else if (nums[start] == target || nums[end] == target) {
            return true;
        }

        int flag = nums[end];
        while (start + 1 < end) { // 找旋转点
            int mid = start + (end - start) / 2;

            if (nums[mid] <= flag) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (nums[start] <= nums[end]) { // 旋转后和原数组相同
            end = length - 1;
            start = 0;
        } else if (target > nums[length - 1]) { // 旋转点前
            end = start;
            start = 0;
        } else if (target < nums[length - 1]) { // 旋转点后
            start = end;
            end = length - 1;
        }

        while (start + 1 < end) { // first target
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                end = mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            }
        }

        if (nums[start] == target || nums[end] == target) {
            return true;
        }
        return false;
    }
};
   

int main(){
    vector<int> a = {2,3,0,0,1,2};
    Solution solution;
    bool flag = solution.search(a,2);
    cout << flag << endl;
    return 0;
}