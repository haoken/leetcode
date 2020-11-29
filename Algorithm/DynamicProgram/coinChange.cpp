#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Solution{
public:
    //使用A中各类面值硬币，用最少的数量拼出M面值。例如[2,5,7] 拼出27 最少使用5枚硬币（7 5 5 5 5）
    //A:所有硬币面值
    //M:需要拼出的大小
    int coinChange(vector<int>& A,int M){
        //确认状态  f[m] = min{f[m-2],f[m-5],f[m-7]} 
        //初值：f[minus] = 无穷    f[0] = 0
        vector<int> f = vector<int>(M+1);//从0~M的状态
        f[0] = 0;
        for(int i = 1 ; i <= M ; i++){
            f[i] = INT_MAX;
            for(int j = 0;j<A.size();j++){
                if(i>=A[j]&&f[i-A[j]]!=INT_MAX){ //i<A[j] 情况下 f[i-A[j]]为负数值为无穷大，不需考虑。
                    f[i] = min(f[i],f[i-A[j]]+1);
                }
            }
        }
        if(f[M]==INT_MAX){
            return -1;
        }
        return f[M];
    }
    //按照同样的方法回溯，找到加入的硬币序列。
    vector<int> coinChangeList(vector<int>&A, int M){
        vector<int> result; 
        vector<int> f = vector<int>(M+1);//从0~M的状态
        f[0] = 0;
        for(int i = 1 ; i <= M ; i++){
            f[i] = INT_MAX;
            for(int j = 0;j<A.size();j++){
                if(i>=A[j]&&f[i-A[j]]!=INT_MAX){ //i<A[j] 情况下 f[i-A[j]]为负数值为无穷大，不需考虑。
                    f[i] = min(f[i],f[i-A[j]]+1);
                }
            }
        }
        if(f[M]==INT_MAX){
            return result;
        }
        int i = M;
        result.push_back(M);
        while(i>0){
            int res = INT_MAX;
            int minIndex = 0;
            for(int j = 0;j<A.size();j++){
                if(i>=A[j]&&f[i-A[j]]<res){  //f[M] = min{f[M-2],f[M-5],f[M-7]} +1
                    minIndex = j;//找到M-ak。
                    res = f[i-A[j]];             
                }
            }
            result.push_back(i- A[minIndex]);
            i = i - A[minIndex];
        }
        for(int i = 0; i <result.size()-1;i++){
            result[i] = result[i]-result[i+1];
        }
        result.pop_back();
        return result;
    }
private:
    int min(int a,int b){
        return a>b?b:a;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    void printVector(vector<int> A){
        for(int i = 0; i < A.size();i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> A = {2,5,7};
    int M = 27;
    Solution solution;
    int output = solution.coinChange(A,M);
    vector<int> outputList = solution.coinChangeList(A,M);
    cout<<output<<endl;
    for(int i = 0; i < outputList.size();i++){
        cout<<outputList[i]<<" ";
    }
}