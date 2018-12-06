#include <iostream>
using namespace std;
int** matrix;
bool** visited;
int min_jump=2000000000;
int M;
int N;

bool isSafe(int x,int y){
	if(x>=0 && x<M && y>=0 && y<N)
		return true;
	return false;
}

void solve_util(int x, int y, bool** visited, int jump_size){
	visited[x][y]=true;
	if(matrix[x][y]=3){
		if(jump_size < min_jump){
			min_jump = jump_size;
		}
	}
	else{
		if(isSafe(x,y+1) && matrix[x][y+1] == 1 || matrix[x][y+1] == 3 && !visited[x][y+1]){
			solve_util(x,y+1,visited,jump_size);
		}
		if(isSafe(x,y-1) && matrix[x][y-1] == 1 || matrix[x][y-1] == 3 && !visited[x][y-1]){
			solve_util(x,y-1,visited,jump_size);
		}
		
		int nearest_vert_jump = -1;
		for(int i=x-1;i>=0;i--){
			if(matrix[i][y] == 1 || matrix[i][y] == 3){
				nearest_vert_jump=i;
				break;
			}
		}
		if(nearest_vert_jump != -1 && !visited[nearest_vert_jump][y]){
			int jump_size_current=(x-nearest_vert_jump);
			if(jump_size_current > jump_size){
				solve_util(nearest_vert_jump,y,visited,jump_size_current);
			}
			else{
				solve_util(nearest_vert_jump,y,visited,jump_size);
			}
		}
		
		int nearest_down_jump = -1;
		for(int i=x+1;i<M;i++){
			if(matrix[i][y] == 1 || matrix[i][y] == 3){
				nearest_down_jump=i;
				break;
			}
		}
		if(nearest_down_jump != -1 && !visited[nearest_down_jump][y]){
			int jump_size_current=(nearest_down_jump-x);
			if(jump_size_current > jump_size){
				solve_util(nearest_down_jump,y,visited,jump_size_current);
			}
			else{
				solve_util(nearest_down_jump,y,visited,jump_size);
			}
		}
	}
	visited[x][y]=false;
}

void solve(int x, int y, int jump_size_min){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=false;
		}
	}
	solve_util(x.y.visited,jump_size_min);
}

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T;i++){
		cin>>M;
		cin>>N;
		matrix = new int* M;
		visited = new bool* [M];
		
		for(int i=0;i<M;i++){
			matrix[i] = new int[N];
			viisted[i] = new bool[N];			
		}
		
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>matrix[i][j];
			}
		}
		
		solve(M-1,0,-1);
		cout<<"#"<<i<<min_jump<<endl;
		min_jump=2000000000;
	}
	system("pause");
	return 0;
}