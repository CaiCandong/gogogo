# 习题2-2 综合题
## 1.从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。

``` c
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
```

## 2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为0(1)。

``` c
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
```

## 3.对长度为n的顺序表L，编写一个时间复杂度为0(n)) 空间复杂度为0(1)的算法，该算法删除线性表中所有值为x的数据元素。

``` c
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
    removeX(&s,5);
    for(int i=0;i<s.length;i++){
        printf("%d ",s.elem[i]);
    }
}
```

## 4.从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行。

``` c
#include<stdio.h>
int remove(int* nums, int numsSize,int min,int max){
    //1.输入是否合理
    if(min>max||numsSize<=0){
        return -1;
    }
    //2.找到下界
    int i,j;
    for(i=0;nums[i]<min;i++){
        if(i>numsSize){//i越界表明整个数组都比min值要大,无需删除
            return numsSize;
        }
    }//i指向比min大的第一个数
    //3.找上界
    for(j=i;j<numsSize&&nums[j]<=max;j++){
        if(j>numsSize){//j越界表明i之后的所以数都比max要小
            return  i;
        }
    }
    //4.进行拷贝
    while(j<numsSize){
        nums[i++]=nums[j++];
    }
    return i;
}
int main(){
    int array[100];
    for(int i=0;i<50;i++){
        array[i]=i;
    }
    int length=remove(array,50,30,49); 
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

```

## 5.同第4题

## 6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。

``` c
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
```

## 7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。

``` c
#include<stdio.h>
#include<malloc.h>
int *merge(int* nums1, int nums1Size,  int* nums2, int nums2Size){
    //1.返回值
    int *ret=(int *)malloc(sizeof(int)*(nums1Size+nums2Size));
    //2.合并
    int i,j;
    for(i=0,j=0;i<nums1Size&&j<nums2Size;){
        if(nums1[i]<nums2[j]){
            ret[i+j]=nums1[i];
            i++;
        }else{
            ret[i+j]=nums2[j];
            j++;
        }
    }
    while(i<nums1Size){
        ret[i+j]=nums1[i++];
    }
    while(j<nums2Size){
        ret[i+j]=nums2[j++];
    }
    return ret;
}
int main(){
    int array1[10];
    for(int i=0;i<10;i++){
        array1[i]=i*2+1;
    }
    int array2[10];
    for(int i=0;i<10;i++){
        array2[i]=i*2;
    }
    int *ret=merge(array1,10,array2,10);
    for(int i=0;i<10+10;i++){
        printf("%d ",ret[i]);
    }
    printf("\n");
}
```

## 8.已知在一维数组A[m+n]中依次存放两个线性表(a1, a2, a.... am)和(b1, b2, b..-.bn).试编写一个函数，将数组中两个顺序表的位置互换，即将(b1, b2, b3,,,,,, bn)放在(a1, a2, a3,,,,,,am)的前面。

``` c
void reverse(int *nums,int i,int j){
    while(i<j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        i++;
        j--;
    }
}
void rotate(int* nums, int numsSize, int k){
    //三次逆转
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
    reverse(nums,0,numsSize-1);
}
int main(){
    //a:1 2
    //b:3 4 5 6 7 
    int array[]={1,2,3,4,5,6,7};
    int m=2,n=5;
    rotate(array,m+n,m);
    for(int i=0;i<m+n;i++){
        printf("%d ",array[i]);
    }
})
```

## 9.线性表(a1, a2, a.,.. an)中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。

``` c
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
    // printf("%d \n",mid);
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
```

## 10.同第8题

## 11. [2011统考真题]一个长度为L (L≥1)的升序序列S，处在第[L/27个位置的数称为S的中位数。例如，若序列SI=(11, 13,15, 17, 19)，则S的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=(2,4,6, 8,20)，则S和S2的中位数是11。现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求: 
1)给出算法的基本设计思想。
2)根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
3)说明你所设计算法的时间复杂度和空间复杂度。
``` c
int M_Search(int nums1[], int nums2[], int length) {// nums1,nums2长度相同
    //寻找中位数 就等价于寻找第n个数字
    //对于寻找第n大的数字，就是排除nums1和nums2数组中 n-1个较小的数字
    // 本题中两个数组长度相同 中位数就是第length个数,所以排除length-1个数字
    int target = length - 1;
    while (target > 0) {
        //因为两个数组的长度都大于length-1,所以不用考虑越界问题
        int half = (target + 1) / 2;
        if (nums1[half - 1] < nums2[half - 1]) {
            nums1 += half;
        } else {
            nums2 += half;
        }
        target -= half;
    }
    // 两个数组中较小的就是结果
    return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
}

int main() {
    int nums1[] = {11, 13, 15, 17, 19};
    int nums2[] = {2, 4, 6, 8, 20};
    int ret = M_Search(nums1, nums2, 5);
    printf("%d", ret);
}
```

### 第12题

 ![](../../pics/ch2-2/pic12.png)
### 第13题
 ![](../../pics/ch2-2/pic13.png)