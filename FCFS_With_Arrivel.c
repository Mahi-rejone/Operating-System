#include <stdio.h>

void fcfs(int pid[], int n, int Bt[], int At[]) {
    int Ct[n], Wt[n], TAT[n];
    float totalCt = 0, totalWt = 0, totalTat = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(At[j] > At[j+1]) {
                int temp = At[j];
                At[j] = At[j+1];
                At[j+1] = temp;

                temp = Bt[j];
                Bt[j] = Bt[j+1];
                Bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }

    Ct[0] = At[0] + Bt[0];
    for(int i = 1; i < n; i++) {
        if(Ct[i-1] < At[i]) {
            Ct[i] = At[i] + Bt[i];
        } else {
            Ct[i] = Ct[i-1] + Bt[i];
        }
    }

    for(int i = 0; i < n; i++){
        TAT[i] = Ct[i] - At[i];
        Wt[i]  = TAT[i] - Bt[i];

        totalCt  += Ct[i];
        totalTat += TAT[i];
        totalWt  += Wt[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", pid[i], At[i], Bt[i], Ct[i], Wt[i], TAT[i]);
    }

    printf("\nAverage Completion Time = %.2f\n", totalCt/n);
    printf("Average Waiting Time    = %.2f\n", totalWt/n);
    printf("Average Turnaround Time = %.2f\n", totalTat/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], Bt[n], At[n];

    for(int i = 0; i < n; i++){
        pid[i] = i+1;
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d",&At[i]);
    }
    for(int i = 0; i < n; i++){
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d",&Bt[i]);
    }

    fcfs(pid,n,Bt,At);

    return 0;
}
