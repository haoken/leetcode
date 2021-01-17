#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()==0 || arr.size()==1 || arr.size()==2) return 0;
        vector<int> LIC(arr.size(),1);//longest increasing size from left to right.
        vector<int> LDC(arr.size(),1);//longest decreasing size from left to right. 
        /*正着数一遍，反着数一遍。*/
        /*如果两边的数都不等于1，则这里是一个峰值。LIC[i]+LDC[i]-1就是这个峰的长度。*/
        int cnt=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>arr[i-1])
            {
                cnt++;
                LIC[i]=cnt;
            }
            else
            {
                cnt=1;
                LIC[i]=cnt;
            }
        }
        cnt=1;
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                cnt++;
                LDC[i]=cnt;
            }
            else
            {
                cnt=1;
                LDC[i]=cnt;
            }
        }
        int res=0;
        for(int i=0;i<arr.size();i++)
        {
            if(LIC[i]!=1 && LDC[i]!=1)
            {
                res=max(res,LIC[i]+LDC[i]-1);
            }
        }
        return res;
        
    }
private:
    int max(int a, int b) {
        return a < b ? b : a;
    }
};

int main() {
    vector<int> arr = {1,2,3,5,6,5,3,6,8,7,6,4,2,4,5,7,8,5,3,3,6,7,8};
    Solution solution;
    int longestMountain = solution.longestMountain(arr);
    cout << longestMountain << endl;
    return 0;
}