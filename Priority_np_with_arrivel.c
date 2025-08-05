#include <stdio.h>
#define MAX 100

void priorityScheduling(int n, int pid[], int At[], int Bt[], int Pr[]) {
    int Ct[MAX], Wt[MAX], TAT[MAX], completed[MAX]={0};
    int current = 0, completedCount = 0;
    float totalWt = 0, totalTat = 0, totalCt=0 ;

    printf("\nProcess Arrival Burst Priority Completion Waiting Turnaround\n");

    while(completedCount < n){
        int idx = -1;
        int bestPriority = 9999;

        for(int i = 0; i < n; i++){
            if(At[i] <= current && !completed[i]){
                if(Pr[i] < bestPriority){
                    bestPriority = Pr[i];
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

            printf("P%d\t%d\t%d\t%d\t%d\t  %d\t  %d\n",
                   pid[idx], At[idx], Bt[idx], Pr[idx], Ct[idx], Wt[idx], TAT[idx]);

            totalWt += Wt[idx];
            totalTat += TAT[idx];
            totalCt += Ct[idx];
        }
    }

    printf("\nAverage Waiting Time    = %.2f\n", totalWt/n);
    printf("Average Turnaround Time = %.2f\n", totalTat/n);
    printf("Average Complition Time = %.2f\n", totalCt/n);
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

    priorityScheduling(n, pid, At, Bt, Pr);
    return 0;
}
