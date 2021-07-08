#include<stdio.h>
struct priority_process
{
       int bt,at,ct,wt,st,pno,tt,cbt,pr;
};

int get(struct priority_process arr[],int t,int n)
{
       int imin,min=9999,i;
       for(i=0;i<n;i++)
       {
              if(arr[i].at<=t&&arr[i].st==0)
                     if(min>arr[i].pr)
                     {
                           min=arr[i].pr;
                           imin=i;
                     }
       }
       return imin;
}

void final_output(struct priority_process arr[],int p[],int n,int nop)
{
       int i,a[100],s=0;
       float avgtat=0,avgwt=0;
       for(i=0;i<n;i++)
       {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }
              s++;
              arr[p[i]].wt=s-arr[p[i]].at-arr[p[i]].tt;
       }
       for(i=0;i<nop;i++)
       {
              arr[i].tt+=arr[i].wt;
              avgwt+=arr[i].wt;
              avgtat+=arr[i].tt;
       }
       printf("\n\n");
       printf("Process\t|Priority\t|Arrival Time\t|Burst Time\t|Completion Time|Turnaround Time|Waiting Time\n");
       for(i=0;i<nop;i++)
       {
              printf("[P%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",arr[i].pno,arr[i].pr,arr[i].at,
                          arr[i].cbt,arr[i].ct,arr[i].tt,arr[i].wt);
       }
       printf("\n");
       printf("Total wait time: %.2f\n",avgwt);
       printf("Total turnaround time: %.2f\n",avgtat);
       avgwt = avgwt/nop;
       avgtat = avgtat/nop;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtat);
       return;
}

int iscomplete(struct priority_process arr[],int n)
{
       int i;
       for(i=0;i<n;i++)
              if(arr[i].st==0)
                     return 0;
       return 1;
}
void ppriority()
{
       int n,i,a,t=0,j;
       int p[100];
       float avgwt=0,avgtat=0;
       struct priority_process arr[100];
       printf("Enter Number of Processes\n");
       scanf("%d",&n);

     for(i=0;i<n;i++)
       {
              printf("Enter Arrival Time, priority & Burst Time for Process [P%d]\n",i);
              scanf("%d%d%d",&arr[i].at,&arr[i].pr,&arr[i].bt);
              arr[i].pno = i;
              arr[i].cbt = arr[i].bt;
              arr[i].st=0;
              arr[i].tt=arr[i].bt;
              arr[i].wt=0;
       }
       i=0;
       while(1)
       {
              if(iscomplete(arr,n))
                     break;
              a=get(arr,t,n);
              p[i]=a;
              arr[a].bt-=1;
              if(arr[a].bt==0)
              {
                  arr[a].st=1;
                  arr[a].ct = t+1;
              }
              t=t+1;
              i++;
       }
       final_output(arr,p,i,n);
}
