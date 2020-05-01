#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
    //快慢指针 i指向被插入的位置 
    //j始终执行重复元素的最后一个
    int i=0,j=0;
    while(j<numsSize){      
        for(;j+1<numsSize&&nums[j+1]==nums[j];j++);
        nums[i++]=nums[j++];
    }
    return i;
}
int main(){
    int array[3]={1,1,2};
    int len=removeDuplicates(array,3);
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    return 0;
}