#include <iostream>
using namespace std;
int N;
int H;
int V;
int ** matrix;
int * tunnel_cost;
int C!,R1,C2,R2,M1,M2;
int min_cost=2000000000;

void getMinTunnelCost(int tunnel){
	for(int i=0;i<H;i++){
		int working_days_M1=i;
		int working_days_M2=H-i;
		
		int cost;
		for(int j=0;j<working_days_M1;j++){
			cost +=matrix[tunnel][j]*C1;
		}
		for(int j=0;j<working_days_M2;j++){
			cost +=matrix[tunnel][H-j-1]*C2;
		}
		
		int add_cost=0;
		if(working_days_M1 > working_days_M2){
			add_cost=(working_days_M1-working_days_M2-1)*R1;
		}
		else(working_days_M2 > working_days_M1){
			add_cost=(working_days_M2-working_days_M1-1)*R2;
		}
		else{
			add_cost=0;
		}
		
		cost=cost+add_cost;
		if(tunnel_cost[tunnel] > cost){
			tunnel_cost[tunnel] = cost;
		}
	}
}

int abs(int x){
	if(x>0)
		return x;
	return(-1*x);
}

void select_tunnel(int tunnel, int cost, int left, bool* visited){
	if(left==0){
		if(cost < min_cost){
			min_cost=cost;
		}
		return;
	}
	
	visited[tunnel]=true;
	
	for(int i=0;i<V;i++){
		if(visited[i] && abs(tunnel-i)>= 2){
			select_tunnel(i,(cost+tunnel_cost[i]+(((M1*M1)+(M2*M2))*(abs(tunnel-i)))),left-1,visited);
		}
	}
}

int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N;
		cin>>H;
		cin>>V;
		
		matrix = new int*[V];
		for(int i=0;i<V;i++){
			matrix[i] = new int[H]; 
		}
		for(int i=0;i<V;i++){
			for(int j=0;j<H;j++){
				cin>>matrix[i][j];
			}
		}
		cin>>C1;
		cin>>R1;
		cin>>M1;
		cin>>C2;
		cin>>R2;
		cin>>M2;
		
		tunnel_cost = new int[V];
		for(int i=0;i<V;i++){
			getMinTunnelCost(i);
		}
		
		bool* visited = new bool[V];
		
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				visited[j]=false;
			}
			select_tunnel(i,tunnel_cost[i],N-1,visited);
		}
		
		cout<<min_cost<<endl;
		min_cost=2000000000;
	}
	system("pause");
	return 0;
}