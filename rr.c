#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], rem_bt[n], pid[n];

    for (int i = 0; i < n; i++){
        printf("Enter the arrival time and burst time:");
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
        pid[i] = i + 1;
    }

    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    // round robin

    int count = 0, time = 0;

    while (count<n){
        for(int i =0; i< n; i++){
            if (rem_bt[i]>0){
                if (rem_bt[i] > time_quantum){
                    time += time_quantum;
                    rem_bt[i] -= time_quantum;
                } else{
                    time+= rem_bt[i];
                    ct[i] = time;
                    rem_bt[i] = 0;
                    count++;
                }
            }
        }
    }
    // calculating tat and wt
    for (int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    // printing the results
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // averaging tat and wt
    int total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt/n);

    // Grantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++){
        printf("| P%d ", pid[i]);
    }
    printf("|\n");
    for (int i = 0; i < n; i++){
        printf("%d\t", at[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++){
        printf("%d\t", ct[i]);
    }
    printf("\n");

    return 0;
}