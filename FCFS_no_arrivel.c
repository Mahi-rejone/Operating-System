#include <stdio.h>

void fcfs(int pid[], int n, int Bt[]) {
    int Ct[n], Wt[n], TAT[n];

    Ct[0] = Bt[0];

    for (int i = 1; i < n; i++) {
        Ct[i] = Ct[i-1] + Bt[i];
    }
    for (int i = 0; i < n; i++) {
        TAT[i] = Ct[i];
        Wt[i] = TAT[i] - Bt[i];
    }
    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], Bt[i], Ct[i], Wt[i], TAT[i]);
    }
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
