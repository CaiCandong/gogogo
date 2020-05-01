#include<stdio.h>
void reverse(int *nums,int i,int j){
    while(i<j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        i++;
        j--;
    }
}
void rotate(int* nums, int numsSize, int k){
    //三次逆转
    k=numsSize-k%numsSize;
    // if(k==0){
    //     return;
    // }
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
    reverse(nums,0,numsSize-1);
}