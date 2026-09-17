#include "Selection.h"

void test(){
    int arr [] = {23,7,86,0,3};
    sort(arr,5);
    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    test();
    return 0;
}


