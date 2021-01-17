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
private:
    int binarySearch(MountainArray& mountainArr, int target, int start, int end, int key(int)){
        target = key(target); 
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int numMid = key(mountainArr.get(mid));

            if (numMid == target) {
                end = mid;
            } else if (numMid < target) {
                start = mid;
            } else if (numMid > target) {
                end = mid;
            }
        }

        if (key(mountainArr.get(start)) == target) {
            return start;
        }
        if (key(mountainArr.get(end)) == target) {
            return end;
        }
        return -1;
    }

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
        int pos = binarySearch(mountainArr,target,startLeft,endLeft,[](int x){return x;});
        if (pos != -1) {
            return pos;
        }
        
        pos = binarySearch(mountainArr,target,startRight,endRight,[](int x){return -x;});
        if (pos != -1) {
            return pos;
        }
        return -1;
    }
};

int main(){
    MountainArray mountainArr;
    Solution solution;
    int result = solution.findInMountainArray(2,mountainArr);
    cout << "result : " << result << endl;
    return 0;
}