#include<stdio.h>			//Initialization of header files
#include<pthread.h>
int arr[1000];


void *fibo(); 		//creating Function for Parent thread 
void *sequence();   	 //creating fucntion for child thread 

void *sequence(int n)
{
	int i,a=0,b=1,nextterm=0;			//intialization of arguments
	
	arr[n];
	arr[1]=a;
	arr[2]=b;
	for(i=3;i<n;i++)     //for loop for the child thread
	{	
		nextterm=a+b;		//using the fibonnaci formula
		arr[i]=nextterm;
		a=b;
		b=nextterm;
		nextterm=0;
	}sleep(1);
							//using sleep command	
}		

void *fibo()
{
	int n,j;
		
	scanf("%d",&n);    				//Child thread created
	printf("child process created\n");
	sequence(n);
	printf("child process ended\n");
	printf("Fibonacci Series is:\n");
	for(j=0;j<n;j++)
	{                       			//for the iteration of the process
	printf("%d\n",arr[j]);
	}
	
	
}



int main()
{
	pthread_t p1,p2;      							// initilization of Thread p1 and p2
	pthread_create(&p1,NULL,fibo,NULL);  					 //parent thread created
	printf("Enter the number for fibonacci series \n ");			//taking the input from user
	pthread_create(&p2,NULL,sequence,NULL);					//child thread created	
	pthread_join(p1,NULL);				//parent thread joined
	pthread_join(p2,NULL);				//child thread joined
	//pthread_exit(NULL);
}								//End of scope of the program
