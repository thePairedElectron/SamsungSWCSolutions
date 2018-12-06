#include <iostream>
using namespace std;
int N;
int *matrix;
int min_cost=2000000000;

int abs(int x){
	if(x>=0)
		return x;
	return(-1*x);
}

bool isAllVisited(bool* visited){
	for(int i=0;i<=N;i++){
		if(!visited[i])
			return false;
		return true;
	}
}

bool isLeftType1(bool* visited){
	for(int i=1;i<=N;i++){
		if(matrix[i] == 1 && !visited[i])
			return true;
		return false;
	}
}

bool isLeftType2(bool* visited){
	for(int i=1;i<=N;i++){
		if(matrix[i] == 2 && !visited[i])
			return true;
		return false;
	}
}

void solve(int curr_pos, int curr_cost, bool* visited, int fuel_qty, int type_of_fuel){
	if(curr_pos != 0 && curr_pos != (N+1))
		visited[curr_pos]=true;
	
	if(isAllVisited(visited)){
		if(min_cost>curr_cost)
			min_cost=curr_cost;
	}
	else if(curr_cost>min_cost){
	}
	else{
		if(fuel_qty>0){
			for(int i=1;i<=N;i++){
				if(!visited[i] && matrix[i] == type_of_fuel)
					solve(i,curr_cost+(abs(curr_pos-i)),visited,fuel_qty-1,type_of_fuel);
			}
		}
		if((curr_pos != 0 && curr_pos != (N+1))){
			if(isLeftType1(visited)){
				solve(0,curr_cost+(abs(curr_pos-0)),visited,2,1);
			}
			if(isLeftType2(visited)){
				solve((N+1),curr_cost+(abs(curr_pos-(N+1))),visited,2,2);
			}
		}
		if(curr_pos == (N+1)){
			solve(0,curr_cost+(abs(curr_pos-0)),visited,2,1);
		}
		if(curr_pos == 0){
			solve((N+1),curr_cost+(abs(curr_pos-(N+1))),visited,2,2);
		}
	}
	if(curr_pos != 0 && curr_pos != (N+1)){
		visited[curr_pos]=false;
}

int main(){
	int T;
	cin >>T;
	for(int i= 1;i<=T;i++){
		cin>>N;
		matrix=new int[N+2];
		matrix[0]=3;
		matrix[N+1]=4;
		
		for(int j=1;j<=N;j++)
			cin>>matrix[j];
		
		bool* visited = new bool[N+2];
		
		for(int i=1;i<=N;i++){
			visited[i]=false;
		}
		
		solve(0,0,visited,2,1);
		
		cout<<"Min cost is :"<<min_cost<<endl;
		min_cost=2000000000;
	}
	system("pause");
	return 0;
}