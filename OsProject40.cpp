#include<bits/stdc++.h>
using namespace std;
struct Process
{
	int P_id;
	int B_time;
};
bool comparison(Process a,Process b)
{
	return(a.B_time<b.B_time);
}

void WaitingTime(Process Pro[],int n,int W_time[])
{
	W_time[0]=0;
	for(int i=1;i<n;i++)
	{
		W_time[i]=Pro[i-1].B_time+W_time[i-1];
	}
}
void TurnArroundTime(Process Pro[],int n,int W_time[],int Ta_time[])
{
	for(int i=0;i<n;i++)
	{
		Ta_time[i]=Pro[i].B_time+W_time[i];
	}
}



int main()
{
	cout<<"\t\t\t\t\tSHORTEST JOB FRIST\n"<<endl;
	Process Pro[]={{1,10},{2,1},{3,2},{4,1},{5,5}};//Process Number And Brust Time
	int n=sizeof(Pro)/sizeof(Pro[0]);
	sort(Pro,Pro+n,comparison);
	cout<<"\n Order in which Process Gets Executed:- ";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<Pro[i].P_id<<" ";
	}
	
	int W_time[n],Ta_time[n],Total_Wt=0;
	WaitingTime(Pro,n,W_time);
	TurnArroundTime(Pro,n,W_time,Ta_time);
	cout<<"\n\n"<<"PROCESS"<<"\t "<<"BRUST TIME"<<"\t "<<"WAITING TIME"<<"\t "<<"TURNARROUND TIME"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<Pro[i].P_id<<"\t\t "<<Pro[i].B_time<<"\t\t "<<W_time[i]<<"\t\t "<<Ta_time[i]<<endl;
	}
	
}

