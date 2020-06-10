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
//带头节点
LinkList nums2List(int nums[],int lenght){
    LinkList head=(LinkList)malloc(sizeof(ListNode));
    LinkList p=head;
    for(int i=0;i<lenght;i++){
        p->next=NewNode(nums[i]);
        p=p->next;
    }
    return head;
}

void travel(LinkList head){
    LinkList p=head;
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
//链表分割
LinkList divide(LinkList A){
   LinkList B=(LinkList)malloc(sizeof(ListNode)); 
   B->next=NULL;
   LinkList p=A->next;
   LinkList pa=A;
   LinkList tmp;
   A->next=NULL;
   bool flag=true;
   while(p!=NULL){
       tmp=p->next;
       if(flag){
           //尾插法
           pa->next=p;
           pa=pa->next;
       }else{
           //头插法
           p->next=B->next;
           B->next=p;
       }
        flag=!flag;
        p=tmp;
   }
   pa->next=NULL;
   return B;
}
LinkList merge(LinkList A,LinkList B){
    LinkList ret=(LinkList)malloc(sizeof(ListNode)); 
    ret->next=NULL;
    LinkList pa=A->next;
    LinkList pb=B->next;
    free(A);free(B);
    //升序变降序 头插法
    LinkList tmp;//辅助移动
    while(pa!=NULL&&pb!=NULL){
        if(pa->val<pb->val){
            tmp=pa->next;
            pa->next=ret->next;
            ret->next=pa;
            pa=tmp;
        }else{
            tmp=pb->next;
            pb->next=ret->next;
            ret->next=pb;
            pb=tmp;
        }
    }
    if(pa==NULL){
        pa=pb;
    }
    while(pa!=NULL){
        tmp=pa->next;
        pa->next=ret->next;
        ret->next=pa;
        pa=tmp;
    }
    // while(pb!=NULL){
    //     tmp=pb->next;
    //     pb->next=ret->next;
    //     ret->next=pb;
    //     pb=tmp;
    // } 
    return ret;
}
int  main(){
    int nums1[]={1,3,5,7,9};
    int nums2[]={2,4,6,8,10};
    LinkList ret1=nums2List(nums1,5);
    LinkList ret2=nums2List(nums2,5);
    LinkList ret=merge(ret1,ret2);
    travel(ret->next);
    // removeRepeat(head);
    // travel(head->next);
}