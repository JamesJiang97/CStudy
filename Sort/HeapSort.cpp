#include <cstdio>
#include <iostream>

using namespace std;

void downheap(int* arr, int start, int end);

void swap(int* arr, int p, int q){
    int tmp = arr[p];
    arr[p] = arr[q];
    arr[q] = tmp;
}

void initHeap(int* arr, int len){
    int start = len / 2 - 1;
    for(int i = start; i >= 0; i--){
        downheap(arr, i, len-1);
    }
}

void downheap(int* arr, int start, int end){
    int  parent = start, son;
    while(2*parent + 1 <= end){
        son = 2*parent + 1;
        if(son+1 <= end && arr[son] < arr[son+1])son++;
        if(arr[parent] < arr[son]){
            swap(arr, parent, son);
            parent = son;
        }else{
            break;
        }
    }
}

int main(){
    int arr[] = {5, 2, 10, 9, 19, 1, 0, 16};
    int len = (int) sizeof(arr) / sizeof(*arr);
    initHeap(arr, len);
    for(int i = len-1; i > 0; i--){
        swap(arr, 0, i);
        downheap(arr, 0, i-1);
    }
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
}