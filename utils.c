#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int random(int min, int max){
    srand(time(0));
    if (max-min > 1){
    return (rand() % (max-min) + min);}
    else {return (rand() % 2 + min);}
}

void bar(int b, int maxbar){
    int progress = b*40/maxbar;
    int nprogress = 40-progress;
    int i;
    for(i=0;i<progress;i++){
        printf("*");
    }
    for(i=0;i<nprogress;i++){
        printf(" ");
    }
}
