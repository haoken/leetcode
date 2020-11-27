#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        int range[2] = {0,0};
        for(int i = 0; i < s.length();i++){
            i = findLongest(s,i,range);
        }
        return s.substr(range[0],range[1]-range[0]+1);
    }
private:
    // low 回文串中间部分开始位置
    // range 回文串在s上的下标范围。
    int findLongest(string s,int low,int range[]){
        //将中间相同的部分看作一个字符
        int high = low;
        //low是中间部分的左端，下面循环找到中间部分的右端。
        while(high<s.size()&&s[high+1]==s[low]){
            high++;
        }
        int end_mid = high;//中间部分的最后一个字符。 因为由中间剩余部分组成的最长回文串都长不过由中间部分的第一个字符所组成的回文串。
        //从中间到两端
        while(high<s.size() && low>0 && s[low-1]==s[high+1]){
            high++;
            low--;
        }
        if((high-low)>(range[1]-range[0])){
            range[0] = low;
            range[1] = high;
        }
        return end_mid;
    }
    
};

int main(){
    string input = "asdasdasdasdadasdasdadasdasdasdasdasdasdsdasdassdasdadasdasdasdasdasdasdasdasdasdasdasdasdasdasdsdasdassdsdssdasasdasdadad";
    Solution solution;
    string output = solution.longestPalindrome(input);
    cout<<output<<endl;
}