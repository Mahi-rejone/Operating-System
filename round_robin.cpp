#include<iostream>
#include<queue>
using namespace std;
class process{
    public:
    int pid;
    int bt;
    int rt;
    int wt;
    int ct;
    int tat;

};
int main(){
    int n,quantum;
    cout<<"Enter the number of process: ";
    cin>>n;
    process p[n];
    for (int i =0; i<n; i++){
        cout<<"Enter Burst time for process p"<<i+1<<": ";
        cin>>p[i].bt;
    }
    for (int i =0; i<n; i++){
        p[i].pid=i+1;
        p[i].rt=p[i].bt;
        p[i].wt=0;
        p[i].ct=0;
        p[i].tat=0;
    }
    cout<<"Enter the quantum time: ";
    cin>>quantum;
    int time =0;
    queue<int>q;
    for (int i=0; i<n; i++){
        q.push(i);
    }
    while(!q.empty()){
        int i=q.front();
        q.pop();
        if(p[i].rt>quantum){
            time=time+quantum;
            p[i].rt=p[i].rt -quantum;
            q.push(i);
        }
        else{
            time = time+ p[i].rt;
            p[i].rt=0;
            p[i].ct=time;
            p[i].tat=p[i].ct;
            p[i].wt= p[i].tat-p[i].bt;
        }
    }
    cout<<"\n";
    cout<<"Process\tB.T\tC.T\tW.T\tT.A.T"<<"\n";
    for(int i=0;i<n; i++){
        cout<<"P"<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<"\n";
    }
    float avgct=0,avgwt=0,avgtat=0;
    for(int i=0; i<n; i++){
        avgct=avgct+p[i].ct;
        avgwt=avgwt+p[i].wt;
        avgtat=avgtat+p[i].tat;
    }
    avgct=avgct/n;
    avgwt=avgwt/n;
    avgtat=avgtat/n;
    cout<<"The average Completion Time: "<<avgct<<"ms\n";
    cout<<"The average Waiting Time: "<<avgwt<<"ms\n";
    cout<<"The average Turn Around Time: "<<avgtat<<"ms\n";

    return 0;
}
