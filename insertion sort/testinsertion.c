#include "Insertion.h"

void test(){
    int arr [] = {5, 2, 9, 1, 5};
    sort(arr,5);
    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    test();
    return 0;
}

