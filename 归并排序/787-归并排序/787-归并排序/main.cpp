//
//  main.cpp
//  787-归并排序
//
//  Created by MacBook Pro on 2023/8/19.
//

#include <iostream>
using namespace std;

const int N = 100010;

int a[N],tmp[N];

/*
 归并排序 - 模版
 */
void merge_sort(int l,int r,int q[]){
    if(l>=r) return;
    //递归
    int mid = (l+r)>>1;
    merge_sort(l, mid, q);
    merge_sort(mid+1, r, q);
    //合并
    int k = 0, i = l, j = mid+1;
    while(i<=mid && j<=r){
        if(q[i]<q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i<=mid) tmp[k++] = q[i++];
    while(j<=r) tmp[k++] = q[j++];
    //放回
    for(i=0,j=l;j<=r;i++,j++){
        q[j] = tmp[i];
    }
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(0, n-1, a);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
