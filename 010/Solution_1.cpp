#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p==""&&s=="") return true;
        else if(p==""||s=="") return false;

        int i = 0;//s的游标
        int j = 0;//p的游标
        char prev = 0;
        while(i<s.length() &&j<p.length()){
            if(p[j]=='.'){//匹配任意单个字符
                j++;
                prev = '.';//匹配一个字符
                i++;
            }else if(p[j]=='*'){
                while(s[i]==prev||prev=='.'){
                    i++;

                }//这些都匹配，也可能第一个就匹配了。
                j++;
            }else{//a-z
                prev = s[i];
                if(s[i]==p[j]){
                    i++;
                    j++;
                }else{
                    cout<< i << s[i]<<" "<< j <<p[j]<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    string s = "aabbc";
    string p = ".*";
    bool output = solution.isMatch(s,p);
    if(output){
        cout<<"match"<<endl;
    }else {
        cout<<"not match"<<endl;
    }
}