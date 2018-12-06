#include<iostream>
using namespace std;
int* balloon;
int n;
int getSum(int left, int right)
{
	int maxScore=0;
	for(int i=left+1;i<=right-1;i++)
	{
		int sum=0;
		sum=getSum(left,i)+getSum(i,right);
		if(left==0&&right==n+1)
		{
			sum+=balloon[i];
		}
		else
		{
			sum+=balloon[left]*balloon[right];
		}
		if(sum>maxScore)
		{
			maxScore=sum;
		}
	}
	return maxScore;
}
int main()
{
	int tc,count=1;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		balloon=new int[n+2];
		balloon[0]=balloon[n+1]=1;
		for(int i=1;i<=n;i++)
		{
			cin>>balloon[i];
		}
		cout<<"#"<<count++<<" "<<getSum(0,n+1)<<endl;
	}
	system("pause");
	return0;
}