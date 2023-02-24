#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct process{
    int pid,at,atf,bt,btf,ct,wt,tat,rt;
};

int main(){
    int n,i,j,k,l,curr=0,q,count=0;
    printf("no of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(i=0;i<n;i++){
        printf("Enter process id (int), arrival time and burst time of process[%d] ", i + 1);
        scanf("%d %d %d",&p[i].pid,&p[i].at,&p[i].bt);
        p[i].atf=p[i].at;
        p[i].btf=p[i].bt;
        p[i].ct=0;
        p[i].rt=-1;
    }
    printf("Enter time quantum: ");
    scanf("%d",&q);
    int pq[100];
    for(i=0;i<n;i++){
        pq[i]=-1;
    }
    j=0;
    for(i=0;i<n;i++){
        if(p[i].at==0) pq[j++]=p[i].pid;
    }
    k=0;
    while(1){
        for(i=0;i<n;i++){
            if(p[i].pid==pq[k]){
                if(p[i].rt==-1) p[i].rt=curr-p[i].atf;
                if(p[i].at!=INT_MAX) p[i].at=INT_MAX;
                if(p[i].bt<=q){
                    p[i].ct=curr+p[i].bt;
                    p[i].bt=0;
                    curr=p[i].ct;
                    count++;
                }
                else{
                    p[i].bt-=q;
                    curr+=q;
                }
                for(l=0;l<n;l++){
                    if(p[l].at<=curr && p[l].at!=INT_MAX && p[l].pid!=pq[k]){
                        pq[j++]=p[l].pid;
                        p[l].at=INT_MAX;
                    }
                }
                if(p[i].bt!=0) pq[j++]=p[i].pid;
                k++;
                break;
            }
        }
        if(count==n) break;
    }
    int sumwt=0,sumtat=0,sumrt=0;
    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].atf;
        p[i].wt=p[i].tat-p[i].btf;
        sumwt+=p[i].wt;
        sumtat+=p[i].tat;
        sumrt+=p[i].rt;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[j].ct<p[i].ct){
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    printf("pid\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].atf, p[i].btf, p[i].ct, p[i].tat, p[i].wt,p[i].rt);
    }
    printf("average waiting time: %f\n",(float)sumwt/(float)n);
    printf("average turn around time: %f\n",(float)sumtat/(float)n);
    printf("average response time: %f\n",(float)sumrt/(float)n);
    return 0;
}
