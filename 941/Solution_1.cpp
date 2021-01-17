#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }

        int peak = INT_MIN;
        int i = 0;
        for (; i < arr.size(); i++) { // 上山
            if (arr[i] > peak) {
                peak = arr[i];
            } else if (arr[i] == peak) {
                return false;
            } else if (arr[i] < peak) {
                break;
            }
        }

        if (i == arr.size() - 1 && arr[i] < peak) {
            return true;
        } else if (i == arr.size()) {
            return false;
        } else if (i == 1) {
            return false;
        }

        for (; i< arr.size(); i++) {
            if (arr[i]< peak) {
                peak = arr[i];
            } else if (arr[i] >= peak) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    Solution solution;
    bool output = solution.validMountainArray(arr);
    cout << output << endl;
    return 0;
}