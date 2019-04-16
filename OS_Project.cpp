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
	int n;
	cout<<"Enter the Number of Processes:-";
	cin>>n;
	int P[n],P2[n],P3[n];
	int B_time[n],B_time2[n],B_time3[n],k,l,Ta_time2[n],W_time2[n],PP[n];
    int W_time1[n],W_time3[n],Ta_time1[n],Ta_time[n],Tw_time1=0,i,Pos,j,temp;
    int quantum1=4;
	
	cout<<"\nEnter Priority and Burst Time :";
	for(i=0;i<n;i++)
	{
		cout<<"\nPROCESS ["<<i+1<<"] :\t";
		cout<<"\nBurst_Time :";
		cin>>B_time[i];
		cout<<"\nPriority :";
		cin>>P[i];	
	}
	for(i=0;i<n;i++)
	{
	    if(1<=P[i]&&P[i]<=3)
	    {
			cout<<"\t\t\t\t\tROUND ROBIN"<<"\n\n";
			WaitingTime1(P,n,B_time,W_time1,quantum1);
            TurnArroundTime1(P,n,B_time,W_time1,Ta_time1);
            cout<<"\n "<<"PROCESS"<<"\t"<<"BRUST TIME"<<"\t"<<"WAITING TIME"<<"\t"<<"TURN ARROUND TIME"<<endl;
            for(int i=0;i<n;i++)
            { 
			  int y=i+1;
    	      cout<<" ["<<y<<"]\t\t"<<B_time[i]<<"\t\t"<<W_time1[i]<<"\t\t"<<Ta_time1[i]<<endl;
    	      y=0;
         	}
 	    }
 	    else if(4<=P[i]&&P[i]<=6)
 	    {
 	    	
 	    	cout<<"\t\t\t\t\tFIRST COME FIRST SERVE"<<"\n\n";
 	    	W_time2[0]=0;
	        for(k=1;k<n;k++)
	        {
	    	 W_time2[k]=0;
	    	 for(l=0;l<k;l++)
	    	 {
	    		W_time2[k]+=B_time[l];
			 }
		    }
		   cout<<"\nPROCESS"<<"\t\t"<<"BRUST TIME"<<"\t\t"<<"WAITING TIME"<<"\t\t"<<"TURN ARROUND TIME"<<endl;
		   for(int i=0;i<n;i++)
		     {
		    	Ta_time2[i]=B_time[i]+W_time2[i];
			    cout<<"\nP["<<i+1<<"]"<<"\t\t"<<B_time[i]<<"\t\t\t"<<W_time2[i]<<"\t\t\t"<<Ta_time2[i]<<endl;
		     }
		    // break;
	     } 
		 else if(7<=P[i]&&P[i]<=9)
		 {
		 	
		 	
		cout<<"\t\t\t\t\tPRIORITY SCHEDULING ALGORITHM"<<"\n\n";
		
	    for(int i=0;i<n;i++)
	    {
	    	Pos=i;
	    	for(j=i+1;j<n;j++)
	    	{
	    		if(P[j]<P[Pos])
	    		{
	    			Pos=j;
				}
			}
			temp=P[i];
			P[i]=P[Pos];
			P[Pos]=temp;
			temp=B_time[i];
			B_time[i]=B_time[i];
			B_time[i]=temp;
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
				W_time3[i]+=B_time[i];
			}
		}
		cout<<"\n"<<"PROCESS"<<"\t\t"<<"BRUST TIME"<<"\t\t"<<"WAITING TIME"<<"\t\t"<<"TURN ARROUND TIME"<<endl;
		for(int i=0;i<n;i++)
		{int a=i+1;
	       Ta_time[i]=B_time[i]+W_time3[i];
		   cout<<"\nP["<<PP[a]<<"]"<<"\t\t"<<B_time[i]<<"\t\t\t"<<W_time3[i]<<"\t\t\t"<<Ta_time[i]<<endl;		
		}
		 }   	
	}
}
