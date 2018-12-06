#include <iostream>
using namespace std;
int matrix[30][128];
int m;
int n;
int k;
bool* isAvailable;
int count_of_rows = -1;

ina main(){
	int T;
	cin>>T;
	for(int i=1;i<=t;i++){
		cin>>n;
		cin>>m;
		cin>>k;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>matrix[i][j];
			}
		}
		isAvailable = new bool[M];
		
		for(int i=0;i<m;i++){
			isAvailable[i]=true;
		}
		
		for(int i=0;i<m;i++){
			int no_of_zeroes=0;
			for(int j=0;j<n;j++){
				if(matrix[i][j] == 0){
					no_of_zeroes++;
				}
			}
			if(no_of_zeroes > k){
				isAvailable[i]=false;
			}
			else{
				int a1=k%2;
				int a2=k/2;
				if(a1 != a2){
					isAvailable[i]=false;
				}
			}
		}
		cout<<"Is available array:"<<endl;
		for(int i=0;i<m;i++){
			cout<<isAvailable[i]<<"/t";
		}
		cout<<"Ends....\n";
		
		for(int i=0;i<m;i++){
			if(isAvailable[i]){
				int similar=0;
				for(int j=0;j<m;j++){
					if(isAvailable[j]){
						cout<<"In following two rows"<<i<<" "<<j<<endl;
						bool flag = true;
						for(int k=0;k<n;k++){
							if(matrix[i][k] != matrix[j][k]){
								flag=false;
							}
						}
						if(flag){
							similar++;
						}
					}
				}
				cout<<"Similar count is :"<,similar<,endl;
				if(similar > count_of_rows){
					count_of_rows=similar;
				}
			}
			
		}
		cout<<"#"<<i<<" "<<count_of_rows<,endl;
	}
	system("pause");
	return 0;
}