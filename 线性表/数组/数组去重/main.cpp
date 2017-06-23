//
//  main.cpp
//  数组去重
//
//  Created by Bruce on 2017/6/23.
//  Copyright © 2017年 Bruce. All rights reserved.
//

#include <iostream>
#include <iterator>
using namespace std;


//2.1.1 Remove Duplicates from Sorted Array
//描述
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant mem- ory.
//For example, Given input array A = [1,1,2],
//Your function should return length = 2, and A is now [1,2].


int removeDuplicates (int a[],int n){
    if (n == 0) return 0;
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[index] != a[i]) {
            a[++index] = a[i];
        }
    }
    return index + 1;
}



int removeDuplicates_01(int A[] ,int n) {
    if (n == 0) return 0;
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (A[index] != A[i])
            A[++index] = A[i];
    }
    return index + 1;
}

long removeDuplicates_02(int A[], int n) {
    return distance(A, unique(A, A + n));
}


template<typename InIt, typename OutIt>
OutIt removeDuplicates_03(InIt first, InIt last, OutIt output) {
    while (first != last) {
        *output++ = *first;
        first = upper_bound(first, last, *first);
    }
    return output;
}

long removeDuplicates_03(int A[], int n) {
    return removeDuplicates_03(A, A + n, A) - A;
}

/*
2.1.2 Remove Duplicates from Sorted Array II
描述
Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice? For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
*/

int removeDuplicatesAllowTwice(int a[],int n){
    if(n <= 2) return n;
    
    int index = 2;
    for (int i = 2; i < n ; i++) {
        if (a[i] != a[index - 2]) {
            a[index ++] = a[i];
        }
    }
    return index;
}


int removeDuplicatesAllowTwice_01(int a[],int n){
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && i< n - 1 && a[i] == a[i+1] && a[i] == a[i-1]) {
            continue;
        }
        a[index++] = a[i];
    }
    return index;
}

/* 旋转数组
2.1.3 Search in Rotated Sorted Array
描述
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.、
 
 旋转数组:把一个数组最开始的若干元素搬到数组的末尾,我们称之为旋转
 
 0　　1　　2　　 4　　5　　6　　7
 
 7　　0　　1　　 2　　4　　5　　6
 
 6　　7　　0　　 1　　2　　4　　5
 
 5　　6　　7　　 0　　1　　2　　4
 
 4　　5　　6　　 7　　0　　1　　2
 
 2　　4　　5　　 6　　7　　0　　1
 
 1　　2　　4　　 5　　6　　7　　0
 
 二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，我们观察上面红色的数字都是升序的，由此我们可以观察出规律，如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了，代码如下
 
*/


int roleSearch(int a[],int n,int target) {
    if (n == 0) return -1;
    int first = 0,last = n;
    
    while (first != last) {
        const int mid = (first + last) / 2;
        if (a[mid] == target)
            return mid;
        if (a[first] <= a[mid]) {
            if (a[first] <= target && target < a[mid]) {
                last = mid;
            }else{
                first = mid + 1;
            }
        }else{
            if (a[mid] < target && target <= a[last -1]) {
                first = mid + 1;
            }else{
                last = mid;
            }
        }

    }
    return -1;
}



int main(int argc, const char * argv[]) {
   
    /*
    int A[] = {1,1,1,2,3,4,5,5,5,9};
    int length = sizeof(A) / sizeof(A[0]);
    int thinLength =  removeDuplicatesAllowTwice_01(A, length);

    printf("长度为 = %d\n",thinLength);
    for (int i = 0; i < thinLength; i++) {
        printf("%d\n",A[i]);
    }
     */
    
    
    int b[] = {4,5,6,7,0,1,2,3};
    
    int target =  roleSearch(b, 8, 2);
    
    printf("%d   %d\n ",target,b[target]);
    
    return 0;
}
