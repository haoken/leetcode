#include<iostream>

class Solution {
public:
    int countDigitOne(int n) {
        int temp = n;
        long long digit = 1; // 当前数位，1 代表个位，  10 代表十位....
        int sum = 0;    //1 的总数
        while (temp > 0) {
            int digitNum= temp % 10 ; // 当前位的数字
            temp = temp / 10;
            int before = n / (digit * 10); // 当前位之前的数字
            int behind = n % digit;  // 当前位之后的数字
            
            if (digitNum == 0) {
                sum += before * digit;
            } else if (digitNum == 1) {
                sum += before * digit + behind + 1;
            } else if (digitNum > 1) { 
                sum += before * digit + digit;
            }
            digit *= 10;    
        }
        return sum;
    }
};

int main() {
    Solution s;
    int result = s.countDigitOne(123456);
    std::cout << result;

}