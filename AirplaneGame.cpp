#include <iostream>
using namespace std;
int n;
int airplane[12][12];
int detonate=0;
int maxPoints=0;

void findPoints(int i, int j, int points, int rowcount){
	if(i == -1){
		if(points>maxPoints)
			maxPoints=points;
		return;
	}
	
	if(j<=0 || j>=5)
		return;
	
	if(airplane[i][j] == 0){
		if(points>maxPoints)
			maxPoints=points;
		return;
	}
	
	if(airplane[i][j] == 1){
		if(rowcount !=0){
			findPoints(i-1,j,points+1,rowcount-1);
			findPoints(i-1,j-1,points+1,rowcount-1);
			findPoints(i-1,j+1,points+1,rowcount-1);
		}
		else{
			findPoints(i-1,j,points+1,rowcount);
			findPoints(i-1,j-1,points+1,rowcount);
			findPoints(i-1,j+1,points+1,rowcount);		
		}
	}
	
	if(airplane[i][j] == 2){
		if(detonate == 0){
			detonate=1;
			findPoints(i-1,j,points,4);
			findPoints(i-1,j-1,points,4);
			findPoints(i-1,j+1,points,4);
			detonate=0;
		}
		if(rowcount !=0){
			findPoints(i-1,j,points,rowcount-1);
			findPoints(i-1,j-1,points,rowcount-1);
			findPoints(i-1,j+1,points,rowcount-1);
		}
		else{
			findPoints(i-1,j,points-1,rowcount);
			findPoints(i-1,j-1,points-1,rowcount);
			findPoints(i-1,j+1,points-1,rowcount);		
		}
	}
	
}

int main(){
	int t;
	cin>>t;
	int testcase=1;
	while(t--){
		int points=0;
		maxPoints=0;
		cin>>n;
		for(int i=o;i<n;i++){
			for(int j=0;j<5;j++){
				cin>>airplane[i][j];
			}
		}
		
		findPoints(n-1,2,points,0);
		findPoints(n-1,1,points,0);
		findPoints(n-1,3,points,0);

		if(maxPoints <= 0){
			maxPoints = -1;		
		}
		cout<<"#"<<testcase++<<" "<<maxPoints<<endl;
	}
	system("pause");
	return 0;
}