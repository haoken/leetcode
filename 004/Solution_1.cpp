#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m+n+1)/2;
        int right = (m+n+2)/2;
        double mid = (findKth(nums1,0,nums2,0,left)+findKth(nums1,0,nums2,0,right))/2.0;
        return  mid; 
    }
private:
    //i：nums1的起始位置 
    //j: nums2的起始位置
    //k: 寻找第k大的数。
    //返回：第k大的数。
    int findKth(vector<int>& nums1,int i,vector<int>& nums2,int j,int k){
        if(i>=nums1.size()) return nums2.at(j+k-1); //边界值考虑1
        if(j>=nums2.size()) return nums1.at(i+k-1); 
        if(k==1){                                   //边界值考虑2
            return nums1.at(i)>nums2.at(j)?nums2.at(j):nums1.at(i);
        }
        int midVal1 = (i+k/2-1<nums1.size()) ? nums1.at(i+k/2-1) : INT_MAX; //边界值考虑3
        int midVal2 = (j+k/2-1<nums2.size()) ? nums2.at(j+k/2-1) : INT_MAX;

        if(midVal1<midVal2){// 淘汰nums1 前k/2
            return findKth(nums1,i+k/2,nums2,j,k-k/2);
        }else {
            return findKth(nums1,i,nums2,j+k/2,k-k/2);
        }
    }
};


int main(){
    Solution solution;
    vector<int> nums1 = {1,3,4,6,8,10};
    vector<int> nums2 = {0,2,5,7,9,11}; //0 1 2 3 4 5 6 7 8 9 10 11 12 13
    double mid = solution.findMedianSortedArrays(nums1,nums2);
    cout<<mid<<endl;
}


//以下思路是学习Wait想念用户的解题方法。
//中位数为  第(m+n+1)/2个位置的值和 第(m+n+2)/2个位置的值 的平均值  
//难点：找到两个有序数组中的第k大的数。
//思路：比较两个数组的k/2位置中的数。将较少的那个数组的前k/2个排除。即 m+n中找第k大 变成 m+n-k/2 中找第k-k/2大。以此类推。知道找到k=1为止。
///////简单的说，每次递归过程都砍掉中间值较小的那个数组的前k/2个。知道砍4剩下1个为止。注意砍掉较小的k/2后，第k大的数就变成了第k-k/2大了。
//边界值考虑：
    //1. 如果一个数组的起始位置>=数组长度， 则该数组被淘汰，即其中不存在第K个值。 这样就可以在另外一个数组中直接找到答案（有序数组）
    //2. 如果一个数组中没有k/2，则附上最大的整型，保证能够进入递归过程,知道k足够小时才进行比较。这时只需要淘汰另外一个数组的前k/2个元素即可
    //3. 如果k==1 ，则比较两个数组起始位置的数，哪个小，就哪个是第k大的数。