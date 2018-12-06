#include<iostream>
using namespace std;
int abs(int x)
{
	if(x>=0)
		return x;
	else
		return (-1*x);
}
int dist(int x1,int y1, int x2, int y2)
{
	return (abs(x1-x2)+abs(y1-y2));
}
class Point{
public:
	int x;
	int y;
	bool isWormhole;
	int end_x;
	int end_y;
	Point(){}

	Point(int x,int y, bool	isWormhole,int end_x,int end_y)
	{
		this->x=x;
		this->y=y;
		this->isWormhole=isWormhole;
		if(isWormhole)
		{
			this->end_x=end_x;
			this->end_y=end_y;
		}
	}
	void print()
	{
		cout<<"X is :"<<x<<endl;
		cout<<"Y is :"<<y<<endl;
		if(isWormhole)
		{
			cout<<"EndX is:"<<end_x<<endl;
			cout<<"Endy is: "<<end_y<<endl;
		}
	}
};
int** matrix;
int M;
int N;
int W;
Point* points;
int matrix_size;
int get_min(int* dist_set,bool* visited_set)
{
	int min_val=2000000000;
	int min_index=-1;
	for(int i=0;i<matrix_size;i++)
	{
		if(!visited_set[i]&&dist_set[i]<min_val)
		{
			min_val=dist_set[i];
			min_index=i;
		}
	}
	return min_index;
}
int dijkstra(int source,int dest)
{
	bool* visited=new bool[matrix_size];
	for(int i=0;i<matrix_size;i++)
	{
		visited[i]=false;
	}
	int* dist_set=new int[matrix_size];
	for(int i=0;i<matrix_size;i++)
		{
			dist_set[i]=2000000000;
		}
		dist_set[source]=0;
		while(!visited[dest])
		{
			int index=get_min(dist_set,visited);
			visited[index]=true;
			for(int i=0;i<matrix_size;i++)
			{
				if(!visited[i]&&(dist_set[i]>(dist_set[index]+matrix[index][i])))
				{
					dist_set[i]=dist_set[index]+matrix[index][i];
				}
			}
		}
		return dist_set[dest];
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>M;
		cin>>N;
		cin>>W;
		points=new Point[W+2];
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		points[0]=Point(a,b,false,0,0);
		points[1]=Point(c,d,false,0,0);
		for(int i=2;i<(W+2);i++)
		{
			cin>>a>>b>>c>>d;
			points[i]=Point(a,b,true,c,d);
		}
		matrix_size=(2*W)+2;
		matrix=new int*[matrix_size];
		for(int i=0;i<matrix_size;i++)
		{
			matrix[i]=new int[matrix_size];
		}
		for(int i=0;i<matrix_size;i++)
		{
			for(int j=0;j<matrix_size;j++)
			{
				matrix[i][j]=INT_MAX;
			}
		}
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<matrix_size;j++)
			{
				if(j==0 || j==1)
				{
					matrix[i][j]=dist(points[j].x,points[j].y,points[i].x,points[i].y);
				}
				else
				{
					if(j%2==0)
					{
						matrix[i][j]=dist(points[(j+2)/2].x,points[(j+2)/2].y,points[i].x,points[i].y);
					}
					else
					{
						matrix[i][j]=dist(points[(j+1)/2].end_x,points[(j+1)/2].end_y,points[i].x,points[i].y)
					}
				}
			}
		}
		for(int i=2;i<W+2;i++)
		{
			for(int j=0;j<matrix_size;j++)
			{
				if(j==0||j==1)
				{
					matrix[(2*i)-2][j]=dist(points[j].x,points[j].y,points[i].x,points[i].y);
				}
				else
				{

					if(j%2==0)
					{
						matrix[(2*i)-2][j]=dist(points[(j+2)/2].x,points[(j+2)/2].y,points[i].x,points[i].y);
					}
					else
					{
						matrix[(2*i)-2][j]=dist(points[(j+1)/2].end_x,points[(j+1)/2].end_y,points[i].x,points[i].y)
					}
				}
			}
			for(int j=0;j<matrix_size;j++)
			{
				if(j==0||j==1)
				{
					matrix[(2*i)-1][j]=dist(points[j].x,points[j].y,points[i].x,points[i].y);
				}
				else
				{

					if(j%2==0)
					{
						matrix[(2*i)-1][j]=dist(points[(j+2)/2].x,points[(j+2)/2].y,points[i].x,points[i].y);
					}
					else
					{
						matrix[(2*i)-1][j]=dist(points[(j+1)/2].end_x,points[(j+1)/2].end_y,points[i].x,points[i].y)
					}
				}
			
			}
		}
		for(int i=2;i<W+2;i++)
		{
			int row_start=(2*i)-2;
			int row_end=(2*i)-1;
			int col_start=row_start;
			int col_end=row_end;
			matrix[row_start][col_end]=0;
		}
		cout<<dijkstra(0,1);
	}
	system("pause");
	return 0;
}