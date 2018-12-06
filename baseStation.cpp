#include<iostream>
using namespace std;
int final_ans=-1;
int ROWS;
int COLS;
int** matrix;
bool** visited;
int* ans_array; 
int* final_ans_array;
bool isSafe(int x, int y)
{
	if(x>=0 && x<ROWS && y>=0 && y<COLS)
	{
		return true;
	}
	return false;
}
void solve_helper(int x, int y, int left_to_see, int ans, bool** visited)
{
	visited[x][y]=true;
	ans_array[3-(left_to_see)]=matrix[x][y];
	if(left_to_see==0)
	{
		if(ans>final_ans)
		{
			final_ans=ans;
			for(int i=0;i<4;i++)
			{
				final_ans_array[i]=ans_array[i];
			}
		}
	}
	else
	{
		int xmoves_odd[6]={1,-1,0,0,1,1};
		int ymoves_odd[6]={0,0,1,-1,-1,1};
		int xmoves_even[6]={1,-1,0,0,-1,-1};
		int ymoves_even[6]={0,0,1,-1,-1,1};
		if(y%2==0)
		{
			if(left_to_see==2)
			{
				for(int i=0;i<6;i++)
				{
					for(int j=i+1;j<6;j++)
					{
						int n1x=x+xmoves_even[i];
						int n1y=y+ymoves_even[i];
						int n2x=x+xmoves_even[j];
						int n2y=y+ymoves_even[j];
						if(isSafe(n1x,n1y) && isSafe(n2x,n2y)&&!visited[n1x][n1y]&&!visited[n2x][n2y])
						{
							int ans2=matrix[n1x][n1y]+matrix[n2x][n2y]+ans;
							if(ans2>final_ans)
							{
								final_ans=ans2;
							}
						}
					}
				}
			}
			for(int k=0;k<6;k++)
			{
				int next_x=x+xmoves_even[k];
				int next_y=y+ymoves_even[k];
				if(next_x>=0 && next_x<ROWS && next_y>=0 && next_y<COLS && !visited[next_x][next_y])
				{
					solve_helper(next_x,next_y,left_to_see-1,ans+(matrix[next_x][next_y]),visited);
				}
			}
		}
		else 
		{
			if(left_to_see==2)
			{
				for(int i=0;i<6;i++)
				{
					for(int j=i+1;j<6;j++)
					{
						int n1x=x+xmoves_odd[i];
						int n1y=y+ymoves_odd[i];
						int n2x=x+xmoves_odd[j];
						int n2y=y+ymoves_odd[j];
						if(isSafe(n1x,n1y) && isSafe(n2x,n2y)&&!visited[n1x][n1y]&&!visited[n2x][n2y])
						{
							int ans2=matrix[n1x][n1y]+matrix[n2x][n2y]+ans;
							if(ans2>final_ans)
							{
								final_ans=ans2;
							}
						}
					}
				}
			}
			for(int k=0;k<8;k++)
			{
				int next_x=x+xmoves_odd[k];
				int next_y=y+ymoves_odd[k];
				if(next_x>=0 && next_x<ROWS && next_y>=0 && next_y<COLS && !visited[next_x][next_y])
				{
					solve_helper(next_x,next_y,left_to_see-1,ans+(matrix[next_x][next_y]),visited);
				}
			}
		}
	}
	visited[x][y]=false;
}
void solve(int x, int y, int left_to_see, int ans)
{
	for(int i=0;i<ROWS;i++)
	{
		for(int j=0;j<COLS;j++)
		{
			visited[i][j]=false;
		}
	}
	solve_helper(x,y,left_to_see,ans,visited);
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>ROWS;
		cin>>COLS;
		matrix=new int*[ROWS];
		for(int i=0;i<ROWS;i++)
		{
			matrix[i]=new int[COLS];
		}
		for(int i=0;i<ROWS;i++)
		{
			for(int j=0;j<COLS;j++)
			{
				cin>>matrix[i][j];
			}
		}
		visited=new bool*[ROWS];
		for(int i=0;i<ROWS;i++)
		{
			visited[i]=new bool[COLS];
		}
		ans_array=new int[4];
		final_ans_array=new int[4];
		for(int i=0;i<ROWS;i++)
		{
			for(int j=0;j<COLS;j++)
			{
				solve(i,j,3,matrix[i][j]);
			}
		}
		cout<<"Answer array is "<<endl;
		for(int i=0;i<4;i++)
		{
			cout<<final_ans_array[i]<<"\t"<<endl;
		}
		cout<<"#"<<i<<final_ans<<endl;
		final_ans=-1;
	}
	system("pause");
	return 0;
}	