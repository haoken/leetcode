#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int length = arr.size();
        if (length < 3) {
            return false;
        }

        int i = 0;
        while (i + 1 < length && arr[i] < arr[i + 1]) { //递增
            i++;
        }

        if (i == 0 || i == length - 1) { // 不能是第一个点和最后一个点
            return false;
        }

        while (i + 1 < length && arr[i] > arr[i + 1]) {
            i++;
        }
        
        return i == length - 1;
    }
};