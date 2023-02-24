#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct process{
    char pid[5];
    int at,atf,bt,btf,pr,ct,wt,tat,rt;
};

int main()
{
    int n,i,j,curr=0;
    printf("no of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(i=0;i<n;i++){
        printf("Enter process id , arrival time, burst time and priority of process[%d] ", i + 1);
        scanf("%s %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].atf=p[i].at;
        p[i].btf=p[i].bt;
        p[i].ct=0;
        p[i].rt=-1;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[j].pr<p[i].pr){
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    i=0;
    int count=0,c2;
    while(i<n){
        if(p[i].at<=curr){
            if(p[i].rt==-1){
                p[i].rt=curr-p[i].at;
            }
            curr+=1;
            p[i].bt-=1;
            if(p[i].bt==0){
                p[i].ct=curr;
                p[i].at=INT_MAX;
            }
            i=-1;
            count=0;
        }
        else count+=1;
        if (count == n){
            c2=0;
            for(j=0;j<n;j++) if(p[j].ct==0) c2=1;
            if(c2==1) {
                curr+=1;
                i=-1;
                count=0;
            }
            else break;
        }
        i+=1;
    }

    int ttat=0,twt=0,trt=0;
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].atf;
        p[i].wt = p[i].tat - p[i].btf;
        ttat+=p[i].tat;
        twt+=p[i].wt;
        trt+=p[i].rt;
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
    printf("pid\t\tAT\t\tBT\t\tPrior\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].atf, p[i].btf,p[i].pr, p[i].ct, p[i].tat, p[i].wt,p[i].rt);
    }
    printf("average waiting time: %f\n",(float)twt/(float)n);
    printf("average turn around time: %f\n",(float)ttat/(float)n);
    printf("average response time: %f\n",(float)trt/(float)n);
    return 0;
}

//Contributed by @mavihS-0
