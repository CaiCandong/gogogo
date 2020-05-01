#include<stdio.h>
// 参数可视为线性表成员展开
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //1.合并后的数组元素个数为m+n
    int i=m-1,j=n-1;
    int k=m+n-1;
    while(k>=0&&i>=0&&j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--]=nums1[i--];
        }else{
            nums1[k--]=nums2[j--];
        }        
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}