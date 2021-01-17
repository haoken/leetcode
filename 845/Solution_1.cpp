#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int length = arr.size();
        if (length < 3) {
            return 0;
        }

        int i = 0;
        int begin = 0;
        int end = 0;
        int longest = 0;
        while (i < length) {
            while (i + 1 < length && arr[i] < arr[i + 1]) { // 上升
                i++;
            }

            if (i == length -1) {
                return 0;
            }
            if (i == 0){
                
            }

        }

        
    }
};

int main() {

}