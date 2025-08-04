#include <stdio.h>

void fcfs(int pid[], int n, int Bt[], int At[]) {
    int Ct[n], Wt[n], TAT[n],;
    // Sort by Arrival Time
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(at[j] > at[j+1]) {
                int temp = at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = pid[j]; pid[j] = pid[j+1]; pid[j+1] = temp;
            }
        }
    }

    Ct[0] = Bt[0];

    for (int i = 1; i < n; i++) {
        Ct[i] = Ct[i-1] + Bt[i];
    }
    for (int i = 0; i < n; i++) {
        TAT[i] = Ct[i];
        Wt[i] = TAT[i] - Bt[i];
    }
    printf("Process\t Arrival Time \tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i],At[i], Bt[i], Ct[i], Wt[i], TAT[i]);
    }
}
int main() {
    int n;
    printf("Enter number of process :");
    scanf("%d",&n);
    int pid[n];
    int Bt[n];
    int At[n];
    for(int i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &At[i]);
    }
    for(int i= 0; i<n; i++){
        printf("Enter burst time for P%d: ",i+1);
        scanf("%d", &Bt[i]);
    }
    fcfs(pid, n, Bt, At);
    return 0;
}

