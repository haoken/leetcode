#include <iostream>
#include <vector>
using namespace std;

class MountainArray {
private:
    vector<int> arr = {1,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,19,18,17,16,15,14,11,8,5,4,3,2,1};
public:
    int get (int index) {
        if (index < arr.size()) {
            return arr[index];
        }
        return -1;
    }
    int length() {
        return arr.size();
    }
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // 先找到山顶
        int length = mountainArr.length();
        int start = 0, end = length ;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            int numMid = mountainArr.get(mid);
            int numMidNext = mountainArr.get(mid+1);

            if (mid + 1 < length && numMid < numMidNext) {
                start = mid;
            } else if (mid + 1 < length && numMid > numMidNext) {
                end = mid;
            }
        }

        int startLeft = 0, endLeft = start;
        int startRight = end, endRight = length - 1;
        while (startLeft + 1 < endLeft) {
            int mid = startLeft + (endLeft - startLeft) / 2;
            int numMid = mountainArr.get(mid);

            if (mountainArr.get(mid) == target) {
                endLeft = mid;
            } else if (numMid > target) {
                endLeft = mid;
            } else if (numMid < target) {
                startLeft = mid;
            }
        }
        
        if (mountainArr.get(startLeft) == target) {
            return startLeft;
        }
        if (mountainArr.get(endLeft) == target) {
            return endLeft;
        }

        while (startRight + 1 < endRight) { //注意这里是倒序
            int mid = startRight + (endRight - startRight) / 2;
            int numMid = mountainArr.get(mid);

            if (numMid == target) {
                endRight = mid;
            } else if (numMid > target) {
                startRight = mid;
            } else if (numMid < target) {
                endRight = mid;
            }
        }

        if (mountainArr.get(startRight) == target) {
            return startRight;
        }
        if (mountainArr.get(endRight) == target) {
            return endRight;
        }
        return -1;
    }
};

int main(){
    MountainArray mountainArr;
    Solution solution;
    int result = solution.findInMountainArray(4,mountainArr);
    cout << "result : " << result << endl;
    return 0;
}