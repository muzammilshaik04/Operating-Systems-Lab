#include <stdio.h>

int main() {
    printf("Name : Urchintla Muhammed Muzammil Shaik\n");
    printf("USN : 1BF24CS324\n\n");
    int n,i;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],pr[n],ct[n],tat[n],wt[n],completed[n];

    printf("\nEnter AT BT Priority for each process\n");
    for(i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        completed[i]=0;
    }

    int time=0,done=0;
    float total_wt=0,total_tat=0;

    while(done<n){
        int hp=9999,sel=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && completed[i]==0){
                if(pr[i]<hp){
                    hp=pr[i];
                    sel=i;
                }
            }
        }

        if(sel==-1){
            time++;
        }
        else{
            ct[sel]=time+bt[sel];
            tat[sel]=ct[sel]-at[sel];
            wt[sel]=tat[sel]-bt[sel];

            time=ct[sel];
            completed[sel]=1;
            done++;

            total_wt+=wt[sel];
            total_tat+=tat[sel];
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    }

    printf("\nAverage WT = %.2f",total_wt/n);
    printf("\nAverage TAT = %.2f\n",total_tat/n);

    return 0;
}
