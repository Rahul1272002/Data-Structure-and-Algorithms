#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n,exetime[10],wtime=0,tAT,tot_wtime=0;//Burst time is similar to execute time
	int i;
	float avgwaitingTime; 
	
	printf("\nEnter how many  number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter exe time for process %d: ",i+1);
		scanf("%d",&exetime[i]);
	}
	
	printf("\nPID \t\t Burst Time\n");
	for(i=0;i<n;i++)
	{
			printf("P%d\t\t\t%d\n",i+1,exetime[i]);
	}
	

printf("\nPID\t\tWaiting Time\t\tBurst(EXE) Time\t\t Turn Around Time ");
	for(i=0;i<n;i++)
	{
		tAT=exetime[i]+wtime;    // Turn around tiem=Burst time + wait time
				printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,wtime,exetime[i],tAT);
		tot_wtime=tot_wtime+wtime;
		
		wtime=wtime+exetime[i];
		
	}
	avgwaitingTime=(float)tot_wtime/n;
	printf("\nTotal Waiting Time : %d \nAverage waiting Time: %.2f ",tot_wtime,avgwaitingTime);
return 0;
}