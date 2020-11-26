#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int max = 1;
        for(int i = 0; i < s.length();i++){
            int thisLength = 1; //以s.at(i)起头的最长无重复字符串，最短一个
            int samePosition = -1;
            for(int j = i+1;j<s.length();j++){
                samePosition = isIn(s[j],s.substr(i,j-i));
                if(samePosition!=-1){//如果在前面子串中有相同的字符
                    if(thisLength>max)
                        max = thisLength;
                    i = i + samePosition ;
                    break;
                }
                else{
                    thisLength++;
                }
            }
            if (samePosition==-1){//全部字符串没有重复
                if(thisLength>max){
                    max = thisLength;
                }
            }
        }
        return max;
    }
private:
    int isIn(char c,string s){
        int flag = -1;
        for(int i=0;i<s.length();i++){
            if(s[i]==c) {
                flag = i; 
                break;
            }
        }
        return flag;
    }
};

int main(){
    Solution solution;
    string input = "aab";
    int length = solution.lengthOfLongestSubstring(input);
    cout<<length<<endl;
}
