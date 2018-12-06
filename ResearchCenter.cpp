#include <iostream>
using namespace std;
int rareElements[4][2];
int region[20][20];
int c,n,longestDist;
int shortestLongestDist=2000000;

struct node{
	int x;
	int y;
	int level;
	struct node *next; 
};

class queue{
	node *front;
	node *rear;
	
	public:
		queue(){
			front=rear=NULL;
		}
		void push(int a, int b, int level){
			node *p = new node;
			if(front == NULL){
				front=p;
				rear=p;
			}
			else{
				node *q=front;
				while(q->next!= NULL){
					q=q->next;
				}
				q->next=p;
			}
			p->x=a;
			p->y=b;
			p->l=level;
			p->next=NULL;
		}
		
		void pop(int &x,int &y, int &l){
			if(front == NULL)
				cout<<"Empty Queue";
			node *p;
			x=p->x;
			y=p->y;
			l=p->l;
			front=p->next;
			delete p;
		}
		
		bool isEmpty(){
			if(front == NULL)
				return true;
			return false;
		}
};

void findDist(int a, int b, int x, bool visited[20][20]){
	queue q;
	int d=0;
	q.push(a,b,d);
	visited[a][b]=true;
	
	while(!q.empty()){
		int s,t,level;
		q.pop(s,t,level);
		
		if(s == x && t == y){
			if(level>longestDist)
				longestDist=level;
			return;
		}
		
		if(region[s+1][t] != 0 && (s+1) < n && visited[s+1][t] == false){
			q.push(s+1,t,level+1);
			visited[s+1][t]=true;
		}
		if(region[s-1][t] != 0 && (s-1) >= 0 && visited[s-1][t] == false){
			q.push(s-1,t,level+1);
			visited[s-1][t]=true;
		}
		if(region[s][t+1] != 0 && (t+1) < n && visited[s][t+1] == false){
			q.push(s,t+1,level+1);
			visited[s][t+1]=true;
		}
		if(region[s][t-1] != 0 && (t-1) >= 0 && visited[s][t-1] == false){
			q.push(s,t-1,level+1);
			visited[s][t-1]=true;
		}
	}
}

int main(){
	int t;
	cin>>t;
	int testcase=1;
	while(t--){
		shortestLongestDist=2000000;
		int a,b;
		cin>>n;
		cin>>c;
		for(int i=0;i<c;i++){
			cin>>a;
			cin>>b;
			rareElements[i][0]=a-1;
			rareElements[i][1]=b-1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>region[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				longestDist=0;
				for(int k=0;k<c;k++){
					bool visited[20][20]={false};
					if(region[i][j]!=0){
						findDist(i,j,rareElements[k][0],rareElements[k][1],visited);
					}
				}
				if(longestDist<shortestLongestDist && longestDist != 0){
					shortestLongestDist = longestDist;
				}
			}
		}
		cout<<"#"<<testcase++<<" "<<shortestLongestDist<,endl;
	}
	return 0;
}