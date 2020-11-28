#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> tmp ;
        while(x>0){
            tmp.push_back(x%10);
            x /= 10;
        }
        bool flag = true;
        int len = tmp.size();
        for(int i = 0; i < len/2;i++){
            if(tmp[i]!=tmp[len-i-1]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};


int main() {
    int input = 1;
    Solution solution;
    bool output = solution.isPalindrome(input);
    if(output){
        cout<<"true"<<endl;
    }else {
        cout<<"false"<<endl;
    }
}
