#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct SJF
{
	int exetime;
	char pid[3];
};

int main()
{
	struct SJF P[10];
	int n,wtime=0,tAT,tot_wtime=0; //Burst time is similar to execute time
	int i,j,temp;
	char t[3];
	float avgwaitingTime;
	
	printf("\nEnter how many number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter PID and Burst Time   : ");
		scanf("%s %d",P[i].pid,&P[i].exetime);
	}
printf("\nPID \t\t Burst Time\n");
	for(i=0;i<n;i++)
	{
			printf("%s\t\t\t%d\n",P[i].pid , P[i].exetime);
	}
	printf("\n\n");
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(P[j].exetime>P[j+1].exetime)
             {
             	temp=P[j].exetime;
             	P[j].exetime=P[j+1].exetime;
             	P[j+1].exetime=temp;
             	
             	
             	strcpy(t,P[j].pid);
             	strcpy(P[j].pid,P[j+1].pid );
             	strcpy(P[j+1].pid,t);
				 
				 
			}
		 }

}	
		
	printf("\nPID \t\t Burst Time\n");
	for(i=0;i<n;i++)
	{
			printf("%s\t\t\t%d\n",P[i].pid,P[i].exetime);
	}
	printf("\n\n");
	
	printf("\nPID\t\tWaiting Time\t\tBurst(EXE) Time\t\t Turn Around Time ");
	for(i=0;i<n;i++)
	{
		tAT=P[i].exetime+wtime;    // Turn around tiem=Burst time + wait time
				printf("\n%s\t\t\t%d\t\t\t%d\t\t\t%d\n",P[i].pid,wtime,P[i].exetime,tAT);
		tot_wtime=tot_wtime+wtime;
		
		wtime=wtime+P[i].exetime;
		
	}
	avgwaitingTime=(float)tot_wtime/n;

printf("\nTotal Waiting Time : %d \nAverage waiting Time: %.2f ",tot_wtime,avgwaitingTime);
return 0;
}