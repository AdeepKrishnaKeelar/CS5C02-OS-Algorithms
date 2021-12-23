#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
int main(void) {
    int *reference_string=(int *)malloc(sizeof(int)*SIZE);
    int number_of_frames=0,size=0,i=0;
    char c[5];
    do {
        scanf("%d",&reference_string[i]);
        i+=1;
        printf("Do you want to add more numbers?");
        scanf("%s",c);
    }while(!strcmp(c,"yes"));
    size=i;
    printf("The size is -- %d\n",size);
    for(int j=0;j<size;j++) {
        printf("%d ",reference_string[j]);
    }
    free(reference_string);
    return 0;
}