#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return -1;
        }

        int start = 0, end = arr.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (mid - 1 >= 0 && mid + 1 < arr.size() && arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            } else if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1]) {
                end = mid;
            } else if (mid + 1 < arr.size() && arr[mid] < arr[mid + 1]) {
                start = mid; 
            }
        }

        if (arr[start] > arr[end]) {
            return start;
        } else {
            return end;
        }
    }
};

int main() {
    vector<int> a = {24,69,100,99,79,78,67,36,26,19};
    Solution solution;
    int peak = solution.peakIndexInMountainArray(a);
    cout << "peak:" << peak << endl;
    return 0;
}