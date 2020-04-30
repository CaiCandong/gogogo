#include<stdio.h>
typedef struct {
    int * elem;   // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
    int length;   // 当前顺序表长度（包含多少元素）
    int listsize; // 当前分配的存储容量（可以存储多少元素）
} SqList;
void removeX(SqList *sq,int x){
    //双指针,将j处的数据拷贝到i处
    int i=0,j=0;
    while(i<sq->length&&j<sq->length){
        if(sq->elem[j]==x){
            j++;
        }else if(i!=j){
            sq->elem[i++]=sq->elem[j++];
        }else{
            i++;
            j++;
        }
    }
    sq->length=i;
}
int main(){
    SqList s;
    int array[]={1,2,3,4,4,5,2,4,5,7};
    s.elem=array;
    s.length=10;
    s.listsize=10;
    // removeX(&s,4);
    removeX(&s,5);
    for(int i=0;i<s.length;i++){
        printf("%d ",s.elem[i]);
    }

}