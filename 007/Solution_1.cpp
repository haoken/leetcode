#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {// 123456  
        int res = 0;
        if(x==-2147483648) return 0;
        bool isMinus = x>0? false:true;
        isMinus? x = -x:x = x;
        while(x > 0) {
            if(res > INT32_MAX/10){
                res = 0;
                break;
            }
            res = res*10 + x%10;
            x = x/10;
        }
        return isMinus?-res:res;
    }
};

int main(){
    int input = -2147483648;
    Solution solution;
    int output = solution.reverse(input);
    cout<<output<<endl;
}