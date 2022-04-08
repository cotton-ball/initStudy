//
//  Q2750.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/04/08.
//

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_SIZE 1000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;
    low = left +1;
    high = right;
    pivot = list[left];
    while(low <= high){
        //while ( list[low] <= pivot) low++;
        while (low<= right && list[low] <= pivot) low++;
        while (high >= left && list[high] > pivot) high--;
        if(low<high) SWAP(list[low],list[high],temp);
        else SWAP(list[left], list[high], temp);
    }
    return high;
}


void quick_sort(int list[], int left, int right)
{
    if (left < right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);

    }
}

void print_list(int list[], int size){
    for(int i = 0; i<size; i++)
        cout<< list[i]<<endl;
}


int main(void){
    int num;
    int list1[MAX_SIZE];
    
    cin >> num;
    for(int i = 0; i < num; i++)
        cin >> list1[i];
    
    quick_sort(list1, 0, num-1); // 퀵정렬 호출
    print_list(list1, num);
        
    return 0;
}
