#include <iostream>
using namespace std;

class Move{
	public:
	int dir;
	int dist;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	
	Move(){}
	
	Move(int start_x, int start_y, int dir, int dist){
		this.start_x=start_x;
		this.start_y=start_y;
		this.dir=dir;
		this.dist=dist;
			
		int movement_x=0;
		int movement_y=0;
			
		if(dir == 1)
			movement_y += dist;
		else if(dir == 2)
			movement_y -= dist;
		else if(dir == 3)
			movement_x += dist;
		else 
			movement_x -= dist;
		
		this.end_x = start_x + movement_x;
		this.end_y = start_y + movement_y;
	}
	
	void print(){
		cout<<"start:"<<start_x<<" "<<start_y<<endl;
		cout<<"end :"<<end_x<<" "<<end_y<<endl;
	}
};

Move* moves;
int N;

int abs(int x){
	if(x>=0)
		return x;
	return(-1*x);
}

bool isIntersecting(Move i, Move j){
	if(i.dir == 1 || i.dir == 2 ){
		if(j.dir == 3 || j.dir == 4 ){
			if(((i.start_x > j.start_x && i.start_x < j.end_x) || (i.start_x > j.end_x && i.start_x < j.start_x)) && 
			   ((j.start_y > i.start_y && j.start_y < i.end_y )|| (j.start_y > i.end_y && j.start_y < i.start_y)))
			{
				return true;
			}
			return false;
		}
		else{
			if(i.start_x == j.start_x){
				if((i.start_y>j.start_y && i.start_y<j.end_y)||
				   (i.start_y>j.end_y && i.start_y<j.start_y)||
				   (i.end_y>j.start_y && i.end_y<j.end_y)||
				   (i.end_y>j.end_y && i.end_y<j.start_y)||
				   (j.start_y>i.start_y && j.start_y<i.end_y)||
				   (j.start_y>i.end_y && j.start_y<i.start_y)||
				   (j.end_y>i.start_y && j.end_y<i.end_y)||
				   (j.end_y>i.end_y && j.end_y<i.start_y)){
					return true;
				}
			}
			return false;
		}	
	}
	else {
		if(j.dir == 1 || j.dir  2){
			if(((j.start_x > i.start_x && j.start_x < i.end_x) || (j.start_x > i.end_x && j.start_x < i.start_x)) && 
		       ((i.start_y > j.start_y && i.start_y < j.end_y )|| (i.start_y > j.end_y && i.start_y < j.start_y)))
			{
				return true;
			}
			return false;
		}
		else{
			if(i.start_y == j.start_y){
				if((i.start_x>j.start_x && i.start_x<j.end_x)||
				   (i.start_x>j.end_x && i.start_x<j.start_x)||
				   (i.end_x>j.start_x && i.end_x<j.end_x)||
				   (i.end_x>j.end_x && i.end_x<j.start_x)||
				   (j.start_x>i.start_x && j.start_x<i.end_x)||
				   (j.start_x>i.end_x && j.start_x<i.start_x)||
				   (j.end_x>i.start_x && j.end_x<i.end_x)||
				   (j.end_x>i.end_x && j.end_x<i.start_x)){
					return true;
				}
			}
			return false;
		}
	}
	
}

int main(){
	int T;
	cin>>T;
	for(int i=0;i<t;i++){
		cin>>N;
		moves = new Move[N];
		int dir;
		int dist;
		for(int i=0;i<N;i++){
			cin>>dir;
			cin>>dist;
			if(i==0){
				moves[i]=Move(0,0,dir,dist);
			}
			else{
				moves[i]=Move(moves[i-1].end_x,moves[i-1].end_y,dir,dist);
			}
		}
		for(int i=0;i<N;i++){
			moves[i],print();
		}
		
		int mov_no = 1;
		for(int i=1;i<N;i++){
			for(int j=i-1;j>=0;j--){
				if(isIntersecting(moves[i],moves[j])){
					mov_no=i;
					break;
				}
			}
			if(mov_no != -1){
				break;
			}
		}
		if(mov_no != -1)
			cout<<mov_no+1<<endl;
		else
			cout<<mov_no<<endl;
	}
	system("pause");
	return 0;
}