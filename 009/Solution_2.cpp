#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int tmp = x;
        int res = 0;
        while(tmp>0){//2,147,483,647
            if(res> INT32_MAX/10||(res==INT32_MAX/10&&tmp%10>7)) return false;//因为x不可能越界，所以x的回文数也不可能越界。
            res = res*10 + tmp%10;
            tmp /= 10;
        }
        return res==x;
    }
};


int main() {
    int input = 12321;
    Solution solution;
    bool output = solution.isPalindrome(input);
    if(output){
        cout<<"true"<<endl;
    }else {
        cout<<"false"<<endl;
    }
}
