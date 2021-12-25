/* This is the First-In-First-Out Page Replacement Algorithm.
   In this simple implementation, Input takes the Size of the 
   reference string and the reference string and the number of 
   frames. Output shows the hit and miss ratio.*/
#include<stdio.h>
#define SIZE 25
int main(void) {
    int reference_string[SIZE],Size=0;
    int number_of_frames=0,miss_count=0,hit_count=0,s;
    float miss_ratio=0.0, hit_ratio=0.0;
    printf("Enter the pre-determined size of the Reference String: ");
    scanf("%d",&Size);
    printf("Enter the Reference String: ");
    for(int i=0;i<Size;i++) {
        printf("Value (%d) - ",i+1);
        scanf("%d",&reference_string[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d",&number_of_frames);
    int temp_values[number_of_frames];
    for(int i=0;i<number_of_frames;i++) {
        temp_values[i]=-1;
    }
    printf("The reference string - ");
    for(int i=0;i<Size;i++) {
        printf("%d ",reference_string[i]);
    }
    printf("\nThe page replacing algorithm follows -- \n");
    for(int i=0;i<Size;i++) {
        s=0;
        for(int j=0;j<number_of_frames;j++) {
            if(reference_string[i]==temp_values[j]) {
                s++;
                miss_count--;
            }
        }
        miss_count++;
        if(miss_count<=number_of_frames && (s==0)) {
            temp_values[i]=reference_string[i];
        }
        else if(s==0) {
            temp_values[(miss_count-1)%number_of_frames]=reference_string[i];
        }
        printf("\n");
        for(int j=0;j<number_of_frames;j++) {
            printf("%d\t",temp_values[j]);
        }
    }
    hit_count=Size-miss_count;
    miss_ratio=(float)((float)miss_count/(float)Size);
    hit_ratio=(float)((float)hit_count/(float)Size);
    printf("\nTotal number of Miss Counts - %d",miss_count);
    printf("\nThe Miss Ratio - (%d / %d) = %.2f",miss_count,Size,miss_ratio);
    printf("\nTotal number of Hit Counts - %d",hit_count);
    printf("\nThe Hit Ratio - (%d / %d) = %.2f",hit_count,Size,hit_ratio);
    return 0;
}