#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) { // 枚举山顶
        int longest = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i - 1 >= 0 && i + 1 < arr.size() && arr[i] > arr[i + 1] && arr[i] >arr[i + 1]) {
                int length = countMountainLength(arr,i);
                if (length > longest) {
                    longest = length;
                }
            } 
        }
        return longest;
    }

private:
    int countMountainLength(vector<int>& arr, int peak) {
        if (peak == 0 || peak == arr.size() - 1) { // 两端不能是山峰
            return 0;
        }

        int start = peak, end = peak;
        while (start - 1 >= 0 && arr[start] > arr[start - 1]) {
            start--;
        }
        while (end + 1 < arr.size() && arr[end] > arr[end + 1]) {
            end++;
        }

        if (start == peak || end == peak) { // 完全单调
            return 0;
        }
        if (end - start + 1 < 3) {
            return 0;
        } else {
            return end - start + 1;
        }
    }
};

int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    Solution solution;
    int longestMountain = solution.longestMountain(arr);
    cout << longestMountain << endl;
    return 0;
}