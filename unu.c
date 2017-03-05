#include <stdio.h>

int main(){
    int num[3][4]={
        {6,7,8,9},
        {5,10,12,13,14},
        {1,2,3,4,11}

    };

    printf("%d",*(*(num+2)+3));
    return 0;
}
