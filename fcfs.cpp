#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void WaitingTime1(int P[],int n,int B_time[],int W_time[],int quantum)
{
	int RB_time[n];
	for(int i=0;i<n;i++)
	{
		RB_time[i]=B_time[i];
	}
	int t=0;
	while(1)
	{
		bool done=true;
		for(int i=0;i<n;i++)
		{
			if(RB_time[i]>0)
			{
				done=false;
				if(RB_time[i]>quantum)
				{
					t+=quantum;
					RB_time[i]-=quantum;
				}
				else
				{
					t=t+RB_time[i];
					W_time[i]=t-B_time[i];
					RB_time[i]=0;
				}
			}
		}
		if(done==true)
		{
			break;
		}
	}
}
void TurnArroundTime1(int P[],int n,int B_time[],int W_time[],int Ta_time[])
{
	for(int i=0;i<n;i++)
	{
		Ta_time[i]=B_time[i]+W_time[i];
	}
}
int main()
{
	
	int Priority;
    cout<<"\nEnter Priority of Process :";
	cin>>Priority;
	int n;
	cout<<"Enter the Number of Processes:-";
	cin>>n;
	//Process
	int P1[n],P2[n],P3[n];
	int B_time1[n],B_time2[n],B_time3[n],k,l,Ta_time2[n],W_time2[n],PP[n];
	
    int W_time1[n],W_time3[n],Ta_time1[n],Ta_time[n],Tw_time1=0,i,Pos,j,temp;
    int quantum1=4;
	
	if(Priority>=1&&Priority<4)
{
	cout<<"\t\t\t\t\tROUND ROBIN"<<"\n\n";
	for(int i=0;i<n;i++)
	{
		int o=i+1;
		cout<<"Enter RR_  Priority and Brust Time of Process ["<<o<<"]\n";
		cin>>P1[i];
		cin>>B_time1[i];
		o=0;
	}
	WaitingTime1(P1,n,B_time1,W_time1,quantum1);
    TurnArroundTime1(P1,n,B_time1,W_time1,Ta_time1);
    cout<<"\n "<<"PROCESS"<<"\t"<<"BRUST TIME"<<"\t"<<"WAITING TIME"<<"\t"<<"TURN ARROUND TIME"<<endl;
    for(int i=0;i<n;i++)
    { int y=i+1;
    	cout<<" ["<<y<<"]\t\t"<<B_time1[i]<<"\t\t"<<W_time1[i]<<"\t\t"<<Ta_time1[i]<<endl;
    	y=0;
	}
     
	
}
else if(Priority>=4&&Priority<7)
	{
		cout<<"\t\t\t\t\tFIRST COME FIRST SERVE"<<"\n\n";
		for(int i=0;i<n;i++)
		{
		int o1=i+1;
		cout<<"Enter Burst Time of Process ["<<o1<<"]\n";
		//cin>>P2[i];
		cin>>B_time2[i];
		o1=0;
	    }
	    W_time2[0]=0;
	    for(k=1;k<n;k++)
	    {
	    	W_time2[k]=0;
	    	for(l=0;l<k;l++)
	    	{
	    		W_time2[k]+=B_time2[l];
			}
		}
		cout<<"\nPROCESS"<<"\t\t"<<"BRUST TIME"<<"\t\t"<<"WAITING TIME"<<"\t\t"<<"TURN ARROUND TIME"<<endl;
		for(int i=0;i<n;i++)
		{
			Ta_time2[i]=B_time2[i]+W_time2[i];
			cout<<"\nP["<<i+1<<"]"<<"\t\t"<<B_time2[i]<<"\t\t\t"<<W_time2[i]<<"\t\t\t"<<Ta_time2[i]<<endl;
		}
	}
	else if(Priority>=7&&Priority<=10)
	{
		cout<<"\t\t\t\t\tPRIORITY SCHEDULING ALGORITHM"<<"\n\n";
		for(int i=0;i<n;i++)
		{
		int o2=i+1;
		cout<<"Enter PSA_Priority and Brust Time of Process ["<<o2<<"]\n";
		cin>>P3[i];
		cin>>B_time3[i];
		o2=0;
		PP[i]=i+1;
	    }
	    for(int i=0;i<n;i++)
	    {
	    	Pos=i;
	    	for(j=i+1;j<n;j++)
	    	{
	    		if(P3[j]<P3[Pos])
	    		{
	    			Pos=j;
				}
			}
			temp=P3[i];
			P3[i]=P3[Pos];
			P3[Pos]=temp;
			temp=B_time3[i];
			B_time3[i]=B_time3[i];
			B_time3[i]=temp;
			temp=PP[i];
			PP[i]=PP[Pos];
			PP[Pos]=temp;
		}
		W_time3[0]=0;
		for(int i=0;i<n;i++)
		{
			W_time3[i]=0;
			for(j=0;j<i;j++)
			{
				W_time3[i]+=B_time3[i];
			}
		}
		cout<<"\n"<<"PROCESS"<<"\t\t"<<"BRUST TIME"<<"\t\t"<<"WAITING TIME"<<"\t\t"<<"TURN ARROUND TIME"<<endl;
		for(int i=0;i<n;i++)
		{int a=i+1;
		
	       Ta_time[i]=B_time3[i]+W_time3[i];
		   cout<<"\nP["<<PP[a]<<"]"<<"\t\t"<<B_time3[i]<<"\t\t\t"<<W_time3[i]<<"\t\t\t"<<Ta_time[i]<<endl;		
		}	    
	}
}
