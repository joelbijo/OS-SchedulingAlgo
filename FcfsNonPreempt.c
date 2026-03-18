#include <stdio.h>
int main(){
    int n;
    printf("\nEnter no. of processes: ");
    scanf("%d",&n);
    int at[n],bt[n],wt[n],tat[n],ct[n];
    
    for(int i=0;i<n;i++){
        printf("Enter AT, BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }
    //Bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                int temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(int i=1;i<n;i++){
        ct[i]=(ct[i-1]<at[i]) ? at[i]+bt[i] : ct[i-1]+bt[i];   
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    printf("------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }


    //Gantt Chart
    printf("\n\nGantt Chart:\n");

    //Top bar
    printf(" ");
    for(int i=0;i<n;i++){
        int len=bt[i];
        for(int j=0;j<len;j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    //Process
    for(int i=0;i<n;i++){
        int len=bt[i];
        int left=len-1;
        for(int j=0;j<left;j++) printf(" ");
        printf("P%d",i+1);
        for(int j=0;j<left;j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    //Bottom bar
    for(int i=0;i<n;i++){
        int len=bt[i];
        for(int j=0;j<len;j++) printf("--");
        printf(" ");
    }
    printf("\n");

    //Timeline
    printf("%d",at[0]);
    for(int i=0;i<n;i++){
        int gap=bt[i]*2;
        for(int j=0;j<gap;j++) printf(" ");
        printf("%d", ct[i]);
    }
    printf("\n\n");
    return 0;
}