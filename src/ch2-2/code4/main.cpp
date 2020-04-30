#include<stdio.h>
// typedef struct {
//     int * elem;   // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
//     int length;   // 当前顺序表长度（包含多少元素）
//     int listsize; // 当前分配的存储容量（可以存储多少元素）
// } SqList;

//为方便测试 使用leetcode接口函数定义
int min=2,max=24;
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0){
        // return -1;
        return numsSize;
    }
    //1.找到下界
    int i,j;
    for(i=0;i<numsSize&&nums[i]<min;i++);
    //2.判断 全部都比min小 无需删除
    if(i==numsSize){
        // reutrn -1;
        return numsSize;
    }
    //3.找上界
    for(j=i;j<numsSize&&nums[j]<=max;j++);
    //4.判断 i后续都比max小
    if(j==numsSize){
        numsSize=i;//直接删除
    }
    while(j<numsSize){
        nums[i++]=nums[j++];
    }
    numsSize=i;
    return numsSize;
}
