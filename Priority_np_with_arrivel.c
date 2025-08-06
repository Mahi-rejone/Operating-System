#include <stdio.h>

void priority(int pid[], int n, int At[] ,int Bt[], int pr[]) {
    int Ct[n], Wt[n], TAT[n];
    float totalCt = 0, totalWt = 0, totalTat = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(At[j] > At[j+1]) {
                int temp = At[j];
                At[j] = At[j+1];
                At[j+1] = temp;
                
                temp = pr[j];
                pr[j] = pr[j+1];
                pr[j+1] = temp;

                temp = Bt[j];
                Bt[j] = Bt[j+1];
                Bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < n-i; j++) {
            if(pr[j] > pr[j+1]|| pr[j]==pr[j+1]&&At[j]>At[j+1] ) {
                int temp = At[j];
                At[j] = At[j+1];
                At[j+1] = temp;
                
                temp = pr[j];
                pr[j] = pr[j+1];
                pr[j+1] = temp;

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

    printf("Process\tPriority\tA.T\tB.T\tC.T\tW.T\tT.A.T\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t\t%d\t\t\t%d\t%d\t%d\t%d\t%d\n",pid[i],pr[i],At[i],Bt[i],Ct[i],Wt[i],TAT[i]);
    }

    printf("\nAverage Completion Time = %.2f(ms)\n", totalCt/n);
    printf("Average Waiting Time    = %.2f(ms)\n", totalWt/n);
    printf("Average Turnaround Time = %.2f(ms)\n", totalTat/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], At[n], Bt[n], pr[n];


    for(int i = 0; i < n; i++){
        pid[i]=i+1;
        printf("Enter priority ,arrivel time & burst time for P%d: ", i+1);
        scanf("%d %d %d",&pr[i],&At[i],&Bt[i]);
    }

    priority(pid,n,At,Bt,pr);

    return 0;
}