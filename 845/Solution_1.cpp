#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) { // 枚举谷底
        if (arr.size() < 3) {
            return 0;
        }

        int longest = 0;
        int start = -1; // 前一个谷底
        for (int i = 0; i < arr.size(); i++) { 
            if (i == 0 && arr[i] < arr[i+1]) { // 第一个
                start = 0;
            } else if (i == arr.size() - 1 && start != -1 && arr[i] < arr[i-1]) { //最后一个
                if (i - start + 1 > longest) {
                    longest = i - start + 1;
                }
                start = i;
            } else if (i - 1 >= 0 && i + 1 < arr.size() && arr[i] <= arr[i + 1] && arr[i] < arr[i - 1]) {// 中间
                if (start != -1 && i - start + 1 > longest) {
                    longest = i - start + 1;    
                }
                start = i;
            } else if (i - 1 >= 0 && i + 1 < arr.size() && arr[i] == arr[i + 1]) {// 有相同的
                start = i + 1;
                i++;
                if (i == arr.size() - 1) {
                    break;
                }
            }
        }
        return longest;
    }
};

int main() {
    vector<int> arr = {3,3,1};
    Solution solution;
    int longestMountain = solution.longestMountain(arr);
    cout << longestMountain << endl;
    return 0;
}