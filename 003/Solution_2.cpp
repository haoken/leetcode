#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int index[128] = {0}; //每个符号的顺序。
        int count = 0;
        int max = 0;
        int i = 0;     //目前指针下标
        int start = 0; //子串开始位置
        int len = s.length();
        for (i=0; i<len; i++) {
            if (start < index[s[i]]) { 
                count = i - start;     //子串长度
                max = (max<=count)?count:max; 
                start = index[s[i]];  //子串开始位置 = 第一次出现时的位置后面的位置
            }
            index[s[i]] = i + 1;   //指向s[i]后面的一个字符的下标
        }
        count = i - start;

        return count>max?count:max;
    }

};

int main(){
    Solution solution;
    string input = "asdasdfsdsdfSDFSDFasdf";
    int length = solution.lengthOfLongestSubstring(input);
    cout<<length<<endl;
}
