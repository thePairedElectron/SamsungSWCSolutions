#include<iostream>
using namespace std;
int N;
int** matrix;
int count_array[6];
bool** visited;
class Queue{
	public:
		int a[1000];
		int size;
		int front;
		int rear;
		Queue()
		{
			size=0;
			front=-1;
			rear=-1;
		}
		bool isEmpty()
		{
			if(size==0)
			{
				return true;
			}
			return false;
		}
		void push(int val)
		{
			a[++rear]=val;
			size=size+1;
		}
		int pop()
		{
			if(!isEmpty())
			{
				int temp=a[++front];
				if(front==rear)
				{
					front=-1;
					rear=-1;
				}
				size=size-1;
				return temp;
			}
			return -1;
		}
};
bool isSafe(int x, int y)
{
	if(x>=0 && x<N &&y>=0 && y<N)
		return true;
	return false;
}
void call_bfs(int x,int y, bool** visited)
{
	Queue q;
	q.push(x);
	q.push(y);
	while(!q.isEmpty())
	{
		int next_x=q.pop();
		int next_y=q.pop();
		visited[next_x][next_y]=true;
		int key=matrix[next_x][next_y];
		if(key!=0)
		{
			count_array[key]++;
		}
		int xmoves[4]={-1,1,0,0};
		int ymoves[4]={0,0,1,-1};
		for(int i=0;i<4;i++)
		{
			int new_x=next_x+xmoves[i];
			int new_y=next_y+ymoves[i];
			if(isSafe(new_x,new_y)&&(matrix[new_x][new_y]==key || key==0)&&!visited[new_x][new_y])
			{
				q.push(new_x);
				q.push(new_y);
			}
		}
	}
}
void apply_val(int i,int j, int val)
{
	bool** visited=new bool*[N];
	for(int i=0;i<N;i++)
	{
		visited[i]=new bool[N];
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			visited[i][j]=false;
		}
	}
	Queue q;
	q.push(i);
	q.push(j);
	while(!q.isEmpty())
	{
		int next_x=q.pop();
		int next_y=q.pop();
		visited[next_x][next_y]=true;
		matrix[next_x][next_y]=val;
		int xmoves[4]={-1,1,0,0};
		int ymoves[4]={0,0,1,-1};
		for(int i=0;i<4;i++)
		{
			int new_x=next_x+xmoves[i];
			int new_y=next_y+ymoves[i];
			if(isSafe(new_x,new_y)&&(matrix[new_x][new_y]==0)&&!visited[new_x][new_y])
			{
				q.push(new_x);
				q.push(new_y);
			}
		}
	}
}
int get_max()
{
	int max_val=count_array[1];
	int max_index=1;
	for(int i=2;i<6;i++)
	{
		if(count_array[i]>=max_val)
		{
			max_index=i;
			max_val=count_array[i];
		}
	}
	return max_index;
}
void call_fn(int i,int j,bool** visited)
{
	Queue q;
	q.push(i);
	q.push(j);
	while(!q.isEmpty())
	{
		int next_x=q.pop();
		int next_y=q.pop();
		visited[next_x][next_y]=true;
		int key=matrix[next_x][next_y];
		int xmoves[4]={-1,1,0,0};
		int ymoves[4]={0,0,1,-1};
		for(int i=0;i<4;i++)
		{
			int new_x=next_x+xmoves[i];
			int new_y=next_y+ymoves[i];
			if(isSafe(new_x,new_y)&&(matrix[new_x][new_y]==key)&&!visited[new_x][new_y])
			{
				q.push(new_x);
				q.push(new_y);
			}
		}
	}
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>N;
		matrix=new int*[N];
		for(int i=0;i<N;i++)
		{
			matrix[i]=new int[N];
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>matrix[i][j];
			}
		}
		for(int i=0;i<6;i++)
		{
			count_array[i]=0;
		}
		visited=new bool*[N];
		for(int i=0;i<N;i++)
		{
			visited[i]=new bool[N];
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				visited[i][j]=false;
			}
		}
		Queue a;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!visited[i][j]&&matrix[i][j]==0)
				{
					call_bfs(i,j,visited);
					int max_val=get_max();
					a.push(i);
					a.push(j);
					a.push(max_val);

					for(int i=1;i<6;i++)
					{
						count_array[i]=0;
					}
					for(int i=0;i<N;i++)
					{
						for(int j=0;j<N;j++)
						{
							if(visited[i][j]&&matrix[i][j]!=0)
							{
								visited[i][j]=false;
							}
						}
					}
				}
			}
		}
		while(!a.isEmpty())
		{
			int x=a.pop();
			int y=a.pop();
			int z=a.pop();
			apply_val(x,y,z);
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				visited[i][j]=false;
			}
		}
		int count=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!visited[i][j])
				{
					count++;
					call_fn(i,j,visited);
				}
			}
		}
		cout<<"Count is:"<<cout<<endl;
	}
	system("pause");
	return 0;
}
