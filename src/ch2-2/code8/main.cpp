#include<stdio.h>
// 等价定义:m+n=numsSize ,m=k
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
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
    reverse(nums,0,numsSize-1);
}
int main(){
    //a:1 2
    //b:3 4 5 6 7 
    int array[]={1,2,3,4,5,6,7};
    int m=2,n=5;
    rotate(array,m+n,m);
    for(int i=0;i<m+n;i++){
        printf("%d ",array[i]);
    }
    //3 4 5 6 7 1 2
}