#include<iostream>
#include<vector>
using namespace std;


int binarySearch(const vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }

    int begin = 0;
    int end = arr.size() - 1;

    while (begin + 1 < end) {// 最后结果begin和end需要再进行一次判断
        int mid = begin + (end - begin) / 2;
        if (arr[mid] == target) { //找最后一个
            begin = mid;
        } else if (arr[mid] < target) {
            begin = mid ;
        } else {
            end = mid ;
        }
    }

    if (arr[end] == target) { return end; }
    if (arr[begin] == target) { return begin; }
    return -1;
}

int main(){
    vector<int> arr = {1,3,5,7,9,10,10,10,15,22};
    int result = binarySearch(arr,10);
    cout << result << endl;
    return 0;
}