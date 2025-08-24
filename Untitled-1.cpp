#include<bits/stdc++.h>
using namespace std;
class process{
    public:
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
};
void SRTF(process p[],int n){
    int c=0,s=0,t=0;
    int s_rt=INT_MAX,ft;
    bool cheak=false;

    for(int i=0; i<n; i++){
        p[i].rt=p[i].bt;
    }
    while(c<n){
        for (int i=0; i<n; i++){
            if ((p[i].at<=t)&&(p[i].rt<s_rt)&&(p[i].rt>0)){
                cheak=true;
                s=i;
                s_rt=p[i].rt;
            }
        }
        if(cheak==false){
            t++;
            continue;
        }
        p[s].rt--;
        s_rt = p[s].rt;
        t++;

        if (s_rt==0){
            s_rt=INT_MAX;
        }
        if (p[s].rt==0){
            c++;
            cheak=false;
            p[s].ct=t;
            p[s].tat=p[s].ct-p[s].at;
            p[s].wt=p[s].tat-p[s].bt;

        }
    }
}
void print(process p[],int n){
    int avgct=0,avgtat=0,avgwt=0;
    cout<<"Process\tA.T\tB.T\tW.T\tC.T\tT.A.T"<<endl;
    for(int i=0; i<n; i++){
        cout<<"P"<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<endl;
        avgct+=p[i].ct;
        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }
    avgct/=n;
    avgwt/=n;
    avgtat/=n;
    cout<<"Average C.T= "<<avgct<<"ms"<<endl;
    cout<<"Average W.T= "<<avgwt<<"ms"<<endl;
    cout<<"Average T.A.T= "<<avgtat<<"ms"<<endl;

}

int main(){
    int n;
    cout<<"enter numbe of process: ";
    cin>>n;
    process p[n];
    for (int i=0; i<n; i++){
        cout<<"Enter Arrival time and Burst time for p"<<i+1<<": ";
        cin>> p[i].at>> p[i].bt; 
        p[i].pid=i+1;    
    }
    SRTF(p,n);
    print(p,n);
}
