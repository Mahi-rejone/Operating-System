#include <stdio.h>
#define MAX 100

void preemptivePriority(int n, int pid[], int At[], int Bt[], int Pr[]) {
    int remainingBt[MAX], Ct[MAX], Wt[MAX], TAT[MAX];
    int completed = 0, current = 0;
    float totalTAT = 0, totalWT = 0, totalCT = 0;

    // To build Gantt chart
    int ganttPid[1000];   // stores pid or -1 if idle, per time unit
    int ganttTime = 0;

    for(int i = 0; i < n; i++){
        remainingBt[i] = Bt[i];
    }

    while(completed < n) {
        int idx = -1;
        int bestPriority = 9999;

        for(int i = 0; i < n; i++){
            if(At[i] <= current && remainingBt[i] > 0){
                if(Pr[i] < bestPriority){
                    bestPriority = Pr[i];
                    idx = i;
                }
            }
        }

        if(idx == -1){
            ganttPid[ganttTime++] = -1; // idle
            current++;
        }
        else{
            ganttPid[ganttTime++] = pid[idx];
            remainingBt[idx]--;
            current++;

            if(remainingBt[idx] == 0){
                completed++;
                Ct[idx] = current;
                TAT[idx] = Ct[idx] - At[idx];
                Wt[idx] = TAT[idx] - Bt[idx];

                totalCT += Ct[idx];
                totalWT += Wt[idx];
                totalTAT += TAT[idx];
            }
        }
    }

    // Table
    printf("\nProcess\tA.T\tB.T\tPriorrity\tC.T\tW.T\tTAT\n");
    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", pid[i],At[i],Bt[i],Pr[i], Ct[i], Wt[i], TAT[i]);
    }
    printf("\nAverage Completion Time  = %.2f(ms)", totalCT/n);
    printf("\nAverage Waiting Time     = %.2f(ms)", totalWT/n);
    printf("\nAverage Turnaround Time  = %.2f(ms)\n", totalTAT/n);

    // Gantt chart print
    printf("\nGantt Chart:\n| ");

    for(int i=0; i<ganttTime; ){
        int j=i;
        // grouping same process
        while(j < ganttTime && ganttPid[j] == ganttPid[i]) j++;

        if(ganttPid[i] == -1) printf(" IDLE |");
        else printf("   P%d  |", ganttPid[i]);

        i = j;
    }
    // print timeline
    printf("\n0");
    current = 0;
    for(int i=0; i<ganttTime; ){
        int j=i;
        while(j < ganttTime && ganttPid[j] == ganttPid[i]) j++;

        current += (j-i);
        printf("\t%d", current);
        i = j;
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[MAX], At[MAX], Bt[MAX], Pr[MAX];
    for(int i = 0; i < n; i++){
        pid[i] = i+1;
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", pid[i]);
        scanf("%d %d %d", &At[i], &Bt[i], &Pr[i]);
    }

    preemptivePriority(n, pid, At, Bt, Pr);
    return 0;
}
