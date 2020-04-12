#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
 
class sched{
public:
    int n,bt[10],at[10],tat[10],wt[10],rt[10],finish[10],tw,tt,tot;
    void EnterData();
    void SRTF();
    void Init();
    void dispTime();
    int NextProcess(int);
    
};
 
void sched::EnterData()
{
    cout<<"Enter no. of processes\n";
    cin>>n;
    cout<<"Enter the burst times in order :\n";
    for(int i=0;i<n;i++)
    cin>>bt[i];
    cout<<"Enter the arrival times in order:\n";
    for(int i=0;i<n;i++)
    cin>>at[i];
}
 
void sched::Init(){
    tot=0;
    tw=0;
    tt=0;
    for(int i=0; i<n; i++){
        rt[i]=bt[i];
        finish[i]=0;
        wt[i]=0;
        tat[i]=0;
        tot+=bt[i];
        }
}
 
void sched::SRTF(){
    EnterData();
    Init();
    int time,next=0,old,i=0,tq;
	cout<<"Gantt Chart\n ";
    for(time=0;time<tot;time++)
    {
     	
			old=next;
        	next=NextProcess(time);
        	if(old!=next || time==0) cout<<"("<<time<<")|==P"<<next+1<<"==|";
        	rt[next]=rt[next]-1;
        	if(rt[next]==0) finish[next]=1;
        	for(i=0;i<n;i++)
            if(i!=next && finish[i]==0 && at[i]<=time)
                wt[i]++;
	 
    }
    cout<<"("<<tot<<")"<<endl;
 
    for(i=0;i<n;i++)
        if(!finish[i]) {cout<<"Scheduling failed, cannot continue\n"; return;
		}
 
    dispTime();
 
}
 
void sched::dispTime()
{	
    for(int i=0;i<n;i++)
    {
 
        tw+=wt[i];
        tat[i]=wt[i]+bt[i];
        tt+=tat[i];
        cout<<"Waiting time for P"<<(i+1)<<" = "<<wt[i]<<", Turnaround time = "<<tat[i]<<endl;
 
    }
 
    cout<<"Avg Waiting time = "<<(double)tw/n<<" and Avg Turnaround time = "<<(double)tt/n<<endl;
    cout<<"Scheduling complete\n";
}
int sched::NextProcess(int time){
 
        int i,low;
        for(i=0;i<n;i++)
            if(finish[i]==0){low=i; break; }
        for(i=0;i<n;i++)
            if(finish[i]!=1)
                if(rt[i]<rt[low] && at[i]<=time)
                        low=i;
        return low;}

int main()
{
    sched s;
    int ch;
 
    while(ch!=2)
    {
        cout<<"1.Shortest Remaining time\n2. Exit\nEnter choice: ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
            case 1: s.SRTF();
            		break;
			
            default: cout<<"Invalid Option\n";
            		ch=2;
 
        }
    }
 return 0;
}

