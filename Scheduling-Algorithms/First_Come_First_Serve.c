/* This is a very basic C Program implementing the basic 'First-Come-First-Serve' type scheduling
   Constraints taken - Arrival Time, Burst Time and the Number of Processes.
   Values displayed - Average Turn Around Time and Average Wait Time. 
   It is assumed all processes are entered in ascending order and rightly.*/
#include<stdio.h>
int main(void) {
    int n=0,i=0,compl_time=0; /* The number of processes */
    float TAT=0.0, WT=0.0; /* The Average TAT and WT */
    printf("Enter the number of processes in the queue: ");
    scanf("%d",&n);
    int processes[n+1],at[n+1],bt[n+1],ct[n+1],tat[n+1],wt[n+1];
    for(i=0;i<n;i++) {
        processes[i]=0;
        at[i]=0;
        bt[i]=0;
        ct[i]=0;
        tat[i]=0;
        wt[i]=0;
    }
    printf("For every process, Enter the Arrival and Burst Time:\n");
    for(i=0;i<n;i++) {
        processes[i]=i+1;
        scanf("%d %d",&at[i],&bt[i]);
    }
    for(i=0;i<n;i++) {
        compl_time+=bt[i];
        ct[i]=compl_time;
        tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt[i];
    }
    printf("The Complete details are -- \n");
    printf("P     AT      BT     CT        TAT       WT\n");
    for(i=0;i<n;i++) {
        printf("%d      %d      %d      %d          %d          %d\n",processes[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        TAT+=tat[i];
        WT+=wt[i];
    }
    TAT/=n;
    WT/=n;
    printf("The Average Turn Around Time is - %.2fms\nThe Average Wait Time is - %.2fms",TAT,WT);
    return 0;
}