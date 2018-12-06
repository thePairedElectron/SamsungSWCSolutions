#include<iostream>
using namespace std;
int MEM;
int CPU;
int BOARD;
int CPU_SP;
int MEM_SP;
int N;
int max_profit =-1;
class Product{
	public:
	    
		 int cpus;
		 int mem;
		 int boards;
		 int sp;
		 
		 Product(){}
		 
		 Product(int a,int b,int c,int d)
		 {
			 cpus=a;
			 mem=b;
			 boards=c;
			 sp=d;
		 }
};
Product* model;

int* max_production;

int get_max(Product p)
{
	int count =0;
	int memory = MEM;
	int cpus = CPU;
	int boards = BOARD;
	
	while(p.mem <= memory && p.cpus <= cpuss && p.boards <= boardss)
	{
		memory = memory - p.mem;
		cpuss = cpuss - p.cpus;
		boardss = boardss - p.boards;
		
		count++;
	}
	return count;
}

void getCost(int* product_array,int* max_array,int size)
{
	if(size == 1)
	{
		Product p = model[product_array[0]];
		
		for(int i = 1;i<=max_array[0];i++)
		{
			int profit = 0;
			int temp1 = CPU;
			int temp2 = MEM;
			
			profit = profit + (i*(p.sp));
			temp1 = temp1 - (i*(p.cpus));
			temp2 = temp2 - (i*(p.mem));
			
			profit = profit + ((CPU_SP)*temp1) + ((MEM_SP)*temp2);
			
			if(profit>max_profit)
			{
				
				max_profit = profit;
				
			}
			
		}
	}
	
	else if(size == 2)
	{
		for(int i = 1;i<= max_array[0];i++)
		{
			Product p = model[product_array[0]];
			
			for(int j=1;j<=max_array[1];j++)
			{
				Product q = model[product_array[1]];
				
				int profit = 0;
				int temp1 =CPU;
				int temp2 = MEM;
				int temp3 =BOARD;
				
				temp1 = temp1 - (i*(p.cpus)) - (j*(q.cpus));
				temp2 = temp2 - (i*(p.mem)) - (q.mem));
				temp3 = temp3 - (i*(p.boards)) - (j*(q.boards));
				
				if(temp1 >= 0 && temp2 >= 0 && temp3 >=0)
				{
					profit = profit + (i*(p.sp)) + (j*(q.sp));
					
					profit = profit + ((CPU_SP)*temp1) + ((MEM_SP)*temp2);
					
					if(profit > max_profit)
					{
						max_profit = profit;
						
					}
				}
			}
		}
	}
	
	else if(size == 3)
	{
		for(int i = 1;i<= max_array[0];i++)
		{
			Product p = model[product_array[0]];
			
			for(int j=1;j<=max_array[1];j++)
			{
				Product q = model[product_array[1]];
				for(int k=1;k<max_array[2];k++)
				{
					Product r = model[product_array[2]];
					
					int profit = 0;
					int temp1 = CPU;
					int temp2 = MEM;
				    int temp3 =BOARD;
					
					temp1 = temp1 - (i*(p.cpus)) - (j*(q.cpus)) - (k*(r.cpus));
					temp2 = temp2 - (i*(p.mem)) - (j*(q.mem)) - (k*(r.mem));
					temp3 = temp3 - (i*(p.boards)) - (j*(q.boards))- (k*(r.boards));
					
					if(temp1 >= 0 && temp2 >= 0 && temp3 >=0)
					{
						
						profit = profit + (i*(p.sp))+(j*(q.sp))+(k*(r.sp));
						
						profit = profit + ((CPU_SP)*temp1) + ((MEM_SP)*temp2);
						
						if(profit > max_profit)
						{
							
							max_profit = profit;
						}
					}
				
				}
		}
		}
	}
}


void choose_util(int product_no,int count,bool* visited,int nos)
{
	visited[product_no] = true;
	
	if(count == 0)
	{
		
		int product_array[3];
		int max_array[3];
		
		for(int i=0; i<3 ;i++)
		{
			max_array[i] = -1;
			product_array[i] = -1;
		}
		
		int product_array_size =0;
		
		for(int i=0; i< N ;i++)
		{
			if(visited[i])
			{
				product_array[product_array_size] = i;
				product_array_size++;
			}
		}
		
		for(int i =0 ; i < product_array_size;i++)
		{
			max_array[i] = max_production[product_array[i]];
		}
		
		getCost(product_array , max_array , product_array_size);
		
		
		
		
		
		
		
	}
	
	else
	{
		for(int i = product_no + 1; i< N ;i++)
		{
			if(!visited[i])
			{
				choose_util(i,count - 1, visited,nos);
			}
			
		}
		
	}
	visited[product_no] = false;
}

void choose(int no_of_products)
{
	bool* visited = new bool[N];
	for(int i = 0;i < N;i++)
	{
		visited[i] = false;
	}
	
	if(no_of_products == 0)
	{
		int profit = 0;
		profit= profit + (CPU)*(CPU_SP)+(MEM)*(MEM_SP);
		
		if(profit > max_profit)
		{
			max_profit = profit;
		}
		return;
	}
	if(no_of_products <= N)
		
		{
			
			for(int i=0; i< N;i++)
			{
				if(!visited[i])
				{
					choose_util(i,no_of_products - 1,visited ,no_of_products);
				}
			}
		}
}

int main()
{
	int T;
	cin>> T;
	for(int i=1;i <= T;i++)
	{
		cin>>CPU;
		cin>>MEM:
		cin>>BOARD;
		cin>>CPU_SP;
		cin>>MEM_SP;
		cin>>N;
		
		model = new Product[N];
		
		int a,b,c,d;
		
		for(int i=0;i<N;i++)
		{
			cin>>a;
			cin>>b;
			cin>>c;
			cin>>d;
			model[i] = Product(a,b,c,d);
		}
		max_production = new int[N];
		for(int i=0;i < N;i++)
		{
			max_production[i] = get_max(model[i]);
		}
		for(int i=0; i<=3 ;i++)
		{
			choose(i);
		}
		 cout<<"#"<<i<<" "<<max_profit <<endl;
		 max_profit = -1;
	}
	system("pause");
	return 0;
}
		
		
						

	
	