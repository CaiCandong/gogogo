#include<stdio.h>
// typedef struct {
//     int * elem;   // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
//     int length;   // 当前顺序表长度（包含多少元素）
//     int listsize; // 当前分配的存储容量（可以存储多少元素）
// } SqList;
bool isRange(int num,int min,int max){
    if(num<min||num>max){
        return false;
    }
    return true;
}
int remove(int* nums, int numsSize,int min,int max){
    if(min>=max){//错误判断
        return -1;
    }
    int i=0,j=0;
    while(j<numsSize){      
        // 与题6不同的是j在本题中可能越界,而在第6题中不会越界
        nums[i++]=nums[j++];
        for(;j<numsSize&&isRange(nums[j],min,max);j++);//无效的跳过
    }
    return i; 
}
int main(){
    int array[]={1,2,3,7,4,231,43,75,86,65,31,54,22,54,7,3,2,20};
    int len=18;
    len=remove(array,len,1,7);
    if(len==-1){
        printf("min<=max");
    }else{
        for(int i=0;i<len;i++){
            printf("%d ",array[i]);
        }
    }
    return 0;
}