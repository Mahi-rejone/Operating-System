#include <stdio.h>

void fcfs(int pid[], int n, int Bt[]) {
    int Ct[n], Wt[n], TAT[n];
    float avgCt=0, avgWT=0, avgTAT=0;
    Ct[0] = Bt[0];

    for (int i = 1; i < n; i++) {
        Ct[i] = Ct[i-1] + Bt[i];
        avgCt+=Ct[i];
    }
    for (int i = 0; i < n; i++) {
        TAT[i] = Ct[i];
        Wt[i] = TAT[i] - Bt[i];
        avgWT+=Wt[i];
        avgTAT+=TAT[i];
    }
    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], Bt[i], Ct[i], Wt[i], TAT[i]);
    }
    avgCt=avgCt/n;
    avgWT=avgWT/n;
    avgTAT=avgTAT/n;
    printf("Average Complition Time: %f\n",avgCt);
    printf("Average Waiting Time: %f\n",avgWT);
    printf("Average Turnaround Time: %f\n",avgTAT);
}
int main() {
    int n;
    printf("Enter number of process :");
    scanf("%d",&n);
    int Pid[n];
    int Bt[n];
    printf("Enter burst time number : ");
    for(int i= 0;i<n;i++){
        Pid[i] = i+1;
        scanf("%d",&Bt[i]);
    }
    fcfs(Pid, n, Bt);
    return 0;
}
