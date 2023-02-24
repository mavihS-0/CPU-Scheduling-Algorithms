#include<stdio.h>
#include<stdlib.h>

struct process{
    char pid[5];
    int at,bt,ct,wt,tat,rt;
};

int main(){
    int n,i,j,curr=0;
    printf("no of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(i=0;i<n;i++){
        printf("Enter process id (int), arrival time and burst time of process[%d] ", i + 1);
        scanf("%s %d %d",&p[i].pid,&p[i].at,&p[i].bt);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[j].at<p[i].at){
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(p[i].at>curr){
            curr+=(p[i].at-curr);
        }
        curr+=p[i].bt;
        p[i].ct=curr;
    }
    int twt=0,ttat=0;
    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        twt+=p[i].wt;
        ttat+=p[i].tat;
    }
    printf("pid\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("average waiting time: %f\n",(float)twt/(float)n);
    printf("average turn around time: %f\n",(float)ttat/(float)n);
    return 0;
}

//Contributed by @mavihS-0