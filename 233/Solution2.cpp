#include<iostream>

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += helper(i);
        }
        return count;
    }

private:
    int helper(int n){ // 计算某个数字中1的个数
        int temp = n;
        int sum = 0;
        while (temp > 0) {
            int digit = temp % 10 ;
            if (digit == 1) {
                sum++;
            }
            temp /= 10;
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.countDigitOne(123456);
    return 0;
}
