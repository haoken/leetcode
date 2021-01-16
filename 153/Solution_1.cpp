#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        int start = 0, end = nums.size() - 1;
        int length = nums.size() ;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[length - 1]) { // 在断点左边
                start = mid;
            } else if (nums[mid] <= nums[length - 1]) { // 在断电右边
                end = mid;
            }
        }

        if (nums[start] < nums[end]) {//旋转后和原数组一致
            return nums[start];
        } else {
            return nums[end];
        }
    }
};

int main(){
    vector<int> a = {2,3,1};
    Solution solution;
    int result = solution.findMin(a);
    cout << "min:" << result << endl;
    return 0;
}