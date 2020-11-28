#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;//空字符串
        int start = 0;
        while(start<s.length()&&s.at(start)==' ') start++;
        if(start>=s.length()) return 0;//都是空符号
        char first = s.at(start);
        if(first!='+'&&first!='-'&&!isValid(first)){//无效字符串
            return 0;
        }
        //处理第一个字符
        bool isMinus =(first=='-');
        int32_t result = 0;
        if(isValid(first)){
            result = isMinus? '0'-first: first-'0';
        }
        start++;
        if(isMinus){//负数
            while(start<s.length()&&isValid(s.at(start))){//-2147483648
                if(result<INT32_MIN/10) return INT32_MIN;
                else if(result==INT32_MIN/10&&s.at(start)>'8') return INT32_MIN;//越界
                result = result*10 + ('0' - s.at(start));
                start++; 
            }
        }else{//正数
            while(start<s.length() && isValid(s.at(start))){
                if(result>INT32_MAX/10 ) return INT32_MAX;
                else if(result==INT32_MAX/10&&s.at(start)>'7') return INT32_MAX;//越界
                result = result*10 + (s.at(start)-'0');
                start++;
            }
        }
        return result;
    }
private:
    bool isValid(char c){
        bool flag = false;
        (c>='0'&&c<='9')?flag = true: flag = false;
        return flag;
    }
};

int main(){
    string input = " ";
    Solution solution;
    int output = solution.myAtoi(input);
    cout<<output<<endl;
}