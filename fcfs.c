#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    int at[n], bt[n], ct[n], tat[n], wt[n], pid[n];
    
    for(int i=0; i<n; i++){
        printf("Enter the arrival time and burst time:");
        scanf("%d %d",&at[i],&bt[i]);
        pid[i] = i + 1;
    }

    // sorting

    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if (at[j] > at[j+1]){
                int temp=at[j];
                at[j]=at[j+1];
                at[j+1]= temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;

                temp = bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }

    // calculating completion time

    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++){
        if (ct[i-1] < at[i]){
            ct[i] = at[i]+ bt[i];
        } else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    // calulating the tat and ct

    for (int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i]; 
    }

    int total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }

    int avg_tat = total_tat/n;
    int avg_wt = total_wt/n;

    // print

    printf("PID\tAT\tBT\tCT\tTAT\tWT\t");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf ("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT: %d\n", avg_tat);
    printf("Average WT: %d\n", avg_wt);

    // Grantt chart

    printf("Grantt Chart:\n ");

    for (int i = 0; i < n; i++){
        printf("\t%d\t|",pid[i]);
    }
    printf("\n");
    printf("0\t");

    for (int i = 0; i < n; i++){
        printf("\t%d\t",ct[i]);
    }

    return 0;
}