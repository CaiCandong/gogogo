#include<stdio.h>
typedef struct {
    int * elem;   // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
    int length;   // 当前顺序表长度（包含多少元素）
    int listsize; // 当前分配的存储容量（可以存储多少元素）
} SqList;
void reverse(SqList *sq){
    if(sq->length==0){
        return;
    }
    int temp;
    int i=0;
    int j=sq->length-1;
    while(i<j){
        temp=sq->elem[i];
        sq->elem[i]=sq->elem[j];
        sq->elem[j]=temp;
    }
}