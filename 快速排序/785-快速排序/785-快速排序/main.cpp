//
//  main.cpp
//  785-快速排序
//
//  Created by MacBook Pro on 2023/8/7.
//

#include <iostream>
using namespace std;

const int N = 1e6+10;

int s[N],n;

/*******************************************************************
 快速排序模版主要分为
 - 设置标志位
 - 按照标志位进行左右划分
 - 递归
 需要注意的是选用的标志位不同，递归边界不同
 （边界问题，标志位为左端点为一种情况，标志位为右端点/中点为另一种情况）
 *******************************************************************/

//快速排序函数模版1 - 区间左端点作为标志点
void quick_sort_left(int l,int r,int a[]){
    if(l>=r) return;
    int flag = a[l];    //设置flag - 左端点为分界点
    int i = l-1, j = r+1;
    //分离
    while(i<j){
        do i++; while(a[i]<flag);
        do j--; while(a[j]>flag);
        if(i<j) swap(a[i],a[j]);
    }
    //递归
    quick_sort_left(l, j, a);
    quick_sort_left(j+1, r, a);
}

//快速排序函数模版2 - 区间右端点作为标志点
void quick_sort_right(int l,int r,int a[]){
    if(l>=r) return;
    int flag = a[r];    //设置flag - 右端点为分界点
    int i = l-1, j = r+1;
    //分离
    while(i<j){
        do i++; while(a[i]<flag);
        do j--; while(a[j]>flag);
        if(i<j) swap(a[i],a[j]);
    }
    //递归
    quick_sort_right(l, i-1, a);
    quick_sort_right(i, r, a);
}

//快速排序函数模版3 - 区间中间点作为标志点
void quick_sort_middle(int l,int r,int a[]){
    if(l>=r) return;
    int flag = a[(l+r+1)/2];    //设置flag - 右端点为分界点
    int i = l-1, j = r+1;
    //分离
    while(i<j){
        do i++; while(a[i]<flag);
        do j--; while(a[j]>flag);
        if(i<j) swap(a[i],a[j]);
    }
    //递归
    quick_sort_middle(l, i-1, a);
    quick_sort_middle(i, r, a);
}

/* ****************************************************************** */

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
//    quick_sort_left(0, n-1, s);
//    quick_sort_right(0, n-1, s);
    quick_sort_middle(0, n-1, s);
    
    for(int i=0;i<n;i++){
        printf("%d ",s[i]);
    }
    return 0;
}
