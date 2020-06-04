#include<stdio.h>
#include<stdlib.h>
//单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//数组转链表
LinkList NewNode(int num){
    LinkList ret=(LinkList)malloc(sizeof(LNode));
    ret->data=num;
    ret->next=NULL;
    return ret;
}
// 输入数组
// 返回链表(不带头节点)
LinkList nums2List(int nums[],int lenght){
    LNode dummy;
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
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

LinkList delete_key(LinkList head,int key){
    if(head==NULL){
        return NULL;
    }
    LinkList p=head->next;
    if(head->data==key){
        free(head);
        return  delete_key(p,key);
    }else{
        head->next=delete_key(p,key);
        return head;
    }
}
int  main(){
    int nums[]={1,2,3,5,7,8};
    int length=6;
    LinkList ret=nums2List(nums,length);
    ret=delete_key(ret,8);
    travel(ret);
}