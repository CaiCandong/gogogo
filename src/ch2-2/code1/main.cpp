#include<stdio.h>
typedef struct {
    int * elem;   // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
    int length;   // 当前顺序表长度（包含多少元素）
    int listsize; // 当前分配的存储容量（可以存储多少元素）
} SqList;

/**
 * 1.从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。
 * 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
 */
int solution(SqList *sq){
    if(sq->length==0){
        printf("顺序表为空");
        return -1;
    }
    int *array=sq->elem;
    //寻找最小数
    int index=0;
    int ret=array[0];
    for(int i=1;i<sq->length;i++){
        if(ret>array[i]){
            ret=array[i];
            index=i;
        }
    }
    array[index]=array[sq->length-1];
    sq->length--;
    return ret;
}
/**
 *  王道代码 
 */
bool Del_Min(SqList &L,int &value){
    if(L.length==0){
        return false;
    }
    int pos=0;
    value=L.elem[0];
    for(int i=1;i<L.length;i++){
        if(L.elem[i]<L.elem[pos]){
            value=L.elem[i];
            pos=i;
        }
    }
    L.elem[pos]=L.elem[L.length-1];
    L.length--;
    return true;
}
int main(){
    return 0;
}

