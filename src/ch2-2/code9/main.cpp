#include<stdio.h>
#include<malloc.h>
typedef struct {
    int * elem;   // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
    int length;   // 当前顺序表长度（包含多少元素）
    int listsize; // 当前分配的存储容量（可以存储多少元素）
} SqList;
void searchInsert(SqList *s, int target){
    //二分查找
    int left=0,right=s->length-1;
    int mid;
    // 若没有找到,left>right left指向插入位置
    while(left<=right){
       mid=(left+right)/2; 
        if(s->elem[mid]<target){
            left=mid+1;
        }else if(s->elem[mid]>target){
            right=mid-1;
        }else{
            break;
        }
    }
    printf("%d \n",mid);
    //2.1判断是否找到并且存在后继节点
    if(mid==s->length-1){
        printf("不存在后续节点,操作失败\n");
        return ;
    }
    if(s->elem[mid]==target){
        //进行交换
        int temp=s->elem[mid];
        s->elem[mid]=s->elem[mid+1];
        s->elem[mid+1]=temp;
        return ;
    }
    //3.进行插入
    //3.1 容量是否充足
    if(s->length+1<s->listsize){
        s->elem=(int*)realloc(s->elem,sizeof(int)*(s->length+10));
    }
    for(int i=s->length;i>left;i--){
        s->elem[i]=s->elem[i-1];
    }
    s->elem[left]=target;
    s->length++;
}
int main(){
    SqList s;
    int array[]={1,2,3,4,5,7,8};
    s.elem=array;
    s.length=7;
    s.listsize=7;
    //尾部插入测试:
    // searchInsert(&s,9);
    // 1 2 3 4 5 7 8 9 
    // 中部插入测试:
    // searchInsert(&s,6);
    // 1 2 3 4 5 6 7 8
    // 头部插入测试:
    // searchInsert(&s,0);
    // 0 1 2 3 4 5 7 8
    // 中部交换测试:
    // searchInsert(&s,2);
    // 1 3 2 4 5 7 8
    // 尾部交换测试:
    searchInsert(&s,8);
    //不存在后续节点,操作失败 
    for (int i = 0; i <s.length; i++)
    {
        printf("%d ",s.elem[i]);
    }
    
}