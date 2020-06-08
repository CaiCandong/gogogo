#include<stdio.h>
#include<stdlib.h>
//单链表
typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode,*LinkList;

//数组转链表
LinkList NewNode(int num){
    LinkList ret=(LinkList)malloc(sizeof(ListNode));
    ret->val=num;
    ret->next=NULL;
    return ret;
}

// 输入数组
// 返回链表(不带头节点)
LinkList nums2List(int nums[],int lenght){
    ListNode dummy;
    LinkList p=&dummy;
    for(int i=0;i<lenght;i++){
        p->next=NewNode(nums[i]);
        p=p->next;
    }
    return dummy.next;
}

void travel(LinkList head){
    LinkList p=head;
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
//反向输出
//利用递归压栈
void reverseTravel(LinkList head){
    if(head->next==NULL){
        return;
    }
   if(head->next->next!=NULL){
       reverseTravel(head->next);
   } 
   // 输出下一个节点的val
    printf("%d ",head->next->val);
}
//删除最小的数字
void solution4(LinkList head){
    // 1.链表没有数据
   if(head->next==NULL){
        return ;
   } 
    LinkList p=head;
   //2.寻找最小的数字
   LinkList pre=head;
   while(p->next!=NULL){
       if(p->next->val<pre->next->val){
           pre=p;
       }
       p=p->next;
   }
   //3.删除最小的数字
   LinkList tmp=pre->next;
   pre->next=pre->next->next;
   free(tmp);
}
void solution5(LinkList head){
    LinkList p=head->next;
    head->next=NULL;
    //头插法
    LinkList tmp;
    while(p!=NULL){
        tmp=p->next;   
        p->next=head->next; 
        head->next=p;
        p=tmp;
    }
}
void Remove(LinkList head,int key){
    LinkList p=head;
    LinkList tmp=NULL;
    while(p!=NULL&&p->next!=NULL){
        if(p->next->val==key){
            tmp=p->next;
            p->next=p->next->next;
            free(tmp);
        }
        p=p->next;
    }
}

int  main(){
    int nums[]={1,2,3,5,-1,8};
    int length=6;
    LinkList ret=nums2List(nums,length);
    LinkList head=(LinkList)malloc(sizeof(ListNode));
    head->next=ret;
    travel(head->next);
    solution5(head);
    travel(head->next);
}