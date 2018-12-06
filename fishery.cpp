#include<iostream>
using namespace std;
int N;
int final_ans=2000000000;
int get_closet_left(int* ans_array, int pos)
{
	for(int i=pos-1;i>=1;i--)
	{
	if(ans_array[i] == 0)
		return i;
	}
	return -1;
}
int get_closet_right(int* ans_array, int pos)
{
	for(int i=pos+1;i<=N)
	{
	if(ans_array[i] == 0)
		return i;
	}
	return -1;
}
class Gate{
	public:
	int pos;
	int nos;
	Gate() {}
	Gate (int pos, int nos)
	{
	this->pos=pos;
	this-nos=nos;
	}
	void print()
	{
	cout<<pos<<" "<<nos<<endl;
	}
};
Gate* gates;
void solve_util(int gate1, int gate2, int gate3, int count1, int count2,int count3, int* visited, int cost)
{
	int assigned=-1;
	if((count1+count2+count3)==0)
	{
		if(cost<final_ans)
		{
			final_ans=cost;
		}
	}
	else if(cost>final_ans)
	{

	}
	else 
	{
		int curr_gate;
		int curr_count;
		if(count1>0)
		{
			curr_gate=gate1;
			curr_count=count1;
			count1--;
		}
		else if(count2>0)
		{
			curr_gate=gate2;
			curr_count=count2;
			count2--;
		}
		else if(count3>0)
		{
			curr_gate=gate3;
			curr_count=count3;
			count3--;
		}
		int curr_pos=gates[curr_gate].pos;

		if(visited[curr_pos]==0)
		{
			visited[curr_pos]=1;
			assigned=curr_pos;
			solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+1);
		}
		else
		{
			int left=get_closet_left(visited,curr_pos);
			int right=get_closet_right(visited,curr_pos);
			if(left==-1 && right==-1)
			{

			}
			else if(left==-1)
			{
				assigned=right;
				int dist=((right-curr_pos)+1);
				visited[right]=dist;
				solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist);
			}
			else if(right==-1)
			{
				assigned=left;
				int dist=((curr_pos-left)+1);
				visited[left]=dist;
				solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist);
			}
			else
			{
				int dist_right=((right-curr_pos)+1);
				int dist_left=((curr_pos-left)+1);
				if(dist_right>dist_left)
				{
					assigned=left;
					visited[left]=dist_left;
				solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_left);
				}
				else if(dist_left>dist_right)
				{
					assigned=right;
					visited[right]=dist_right;
				solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_right);	
				}
				else
				{
					if(curr_count==1)
					{
						if(curr_gate == 0)
						{
							assigned=left;
							visited[left]=dist_left;
							solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_left);
						}
						else if(curr_gate == 2)
						{
							assigned=right;
							visited[right]=dist_right;
							solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_right);
						}
						else 
						{
							visited[left]=dist_left;
							assigned=left;
							solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_left);
							visited[left]=0;
							visited[right]=dist_right;
							assigned=right;
							solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_right);
						}
					}
					else
					{
							assigned=left;
							visited[left]=dist_left;
							solve_util(gate1,gate2,gate3,count1,count2,count3,visited,cost+dist_left);	
					}
				}
			}
		}

	}
	if(assigned!=-1)
	{
		visited[assigned]=0;
	}
}
void solve(int gate1,int gate2,int gate3)
{
	int c1=gates[gate1].nos;
	int c2=gates[gate2].nos;
	int c3=gates[gate3].nos;

	int* visited=new int[N+1];
	for(int i=1;i<=N;i++)
	{
		visited[i]=0;
	}
	solve_util(gate1,gate2,gate3,c1,c2,c3,visited,0);
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>N;
		gates=new Gate[3];

		int a,b;
		for(int j=0;j<3;j++)
		{
			cin>>a;
			cin>>b;
			gates[j]=Gate(a,b);
		}
		solve(0,1,2);
		solve(0,2,1);
		solve(1,0,2);
		solve(1,2,0);
		solve(2,1,0);
		solve(2,0,1);
		cout<<"#"<<i<<" "<<final_ans<<endl;
		final_ans=2000000000;
	}
	system("pause");
	return 0;
}