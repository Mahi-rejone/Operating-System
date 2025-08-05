#include <stdio.h>

void SJF(int pid[], int n, int At[], int Bt[]) {
    int Ct[n], Wt[n], TAT[n], completed[n];
    float totalCt = 0, totalWt = 0, totalTat = 0;
    int current = 0, completedCount = 0;

    for(int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    while(completedCount < n){
        int idx = -1;
        int minBT = 9999;

        for(int i = 0; i < n; i++){
            if(At[i] <= current && !completed[i]){
                if(Bt[i] < minBT){
                    minBT = Bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1){
            current++; 
        }
        else{
            current += Bt[idx];
            Ct[idx] = current;
            TAT[idx] = Ct[idx] - At[idx];
            Wt[idx] = TAT[idx] - Bt[idx];
            completed[idx] = 1;
            completedCount++;

            totalCt  += Ct[idx];
            totalTat += TAT[idx];
            totalWt  += Wt[idx];

            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[idx], At[idx], Bt[idx], Ct[idx], Wt[idx], TAT[idx]);
        }
    }

    printf("\nAverage Completion Time = %.2f\n", totalCt/n);
    printf("Average Waiting Time    = %.2f\n", totalWt/n);
    printf("Average Turnaround Time = %.2f\n", totalTat/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], At[n], Bt[n];
    for(int i = 0; i < n; i++){
        pid[i] = i+1;
        printf("Enter Arrival time & Burst time for P%d: ", pid[i]);
        scanf("%d %d", &At[i], &Bt[i]);
    }

    SJF(pid, n, At, Bt);

    return 0;
}
