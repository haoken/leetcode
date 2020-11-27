#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s; //只有一行的情况下只需返回原来字符串。
        string *row = new string[numRows];//每个元素代表一行的字符串
        int pre = -1;
        int index = 0;
        for(int i = 0;i< s.length();i++){
            row[index] = row[index] + s.at(i);
            int tmp = index;
            index = next(numRows,pre,index);
            pre = tmp;
        }
        string res = "";
        for(int i = 0;i<numRows;i++){
            res = res + row[i]; 
        }
        delete[] row;
        return res;
    }

private:
    int next(int numRows,int pre,int i){// 0123210123210123210  （层数=4）按照该顺序得出下一个数字
        int res = 0;
        if(i>pre){
            if(i!=numRows-1) res = i+1;
            else res = i-1;
        }else{
            if(i!=0) res = i-1;
            else res = i+1;
        }
        return res;
    }
};

int main(){
    string input = "AB";
    int numRows = 1;
    Solution solution;
    string output = solution.convert(input,numRows);
    cout<<output<<endl;
}