#include <stdio.h>

int main()
{
    printf("Name : Urchintla Muhammed Muzammil Shaik\n");
    printf("USN : 1BF24CS324\n\n");
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++)
    {
        printf("P%d AT BT: ",i+1);
        pid[i]=i+1;
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    int queue[100], front=0, rear=0;
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;

    int time=0, completed=0;
    float total_wt=0,total_tat=0;

    while(completed<n)
    {
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && visited[i]==0)
            {
                queue[rear++]=i;
                visited[i]=1;
            }
        }

        if(front==rear)
        {
            time++;
            continue;
        }

        int p = queue[front++];

        if(rt[p] > tq)
        {
            time += tq;
            rt[p] -= tq;

            for(int i=0;i<n;i++)
            {
                if(at[i]<=time && visited[i]==0)
                {
                    queue[rear++]=i;
                    visited[i]=1;
                }
            }

            queue[rear++] = p;
        }
        else
        {
            time += rt[p];
            rt[p] = 0;

            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            total_tat += tat[p];
            total_wt += wt[p];

            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",total_tat/n);

    return 0;
}
