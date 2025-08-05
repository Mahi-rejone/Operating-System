#include <stdio.h>

void SJF(int pid[], int n, int Bt[]) {
    int Ct[n], Wt[n], TAT[n];
    float totalCt = 0, totalWt = 0, totalTat = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(Bt[j] > Bt[j+1]) {

                int temp = Bt[j];
                Bt[j] = Bt[j+1];
                Bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }
    Ct[0] = Bt[0];
    for (int i = 1; i < n; i++) {
        Ct[i] = Ct[i-1] + Bt[i];
    }

    for(int i = 0; i < n; i++){
        TAT[i] = Ct[i];
        Wt[i] = Ct[i] - Bt[i];

        totalCt  += Ct[i];
        totalTat += TAT[i];
        totalWt  += Wt[i];
    }

    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],Bt[i],Ct[i],Wt[i],TAT[i]);
    }

    printf("\nAverage Completion Time = %.2f(ms)\n", totalCt/n);
    printf("Average Waiting Time    = %.2f(ms)\n", totalWt/n);
    printf("Average Turnaround Time = %.2f(ms)\n", totalTat/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], Bt[n];

    for(int i = 0; i < n; i++){
        pid[i]=i+1;
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d",&Bt[i]);
    }

    SJF(pid,n,Bt);

    return 0;
}
