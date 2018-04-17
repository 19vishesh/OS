#include<stdio.h>
double change(double x)
{
	x=x*1000000;		//Converting from millisecond to nanosecond
	return x;		//returning the value in nanosec
}

int main()
{
	double a,b,p,SPF,RPNM,MAT,EAT;


	/* 	SPF=Service Page-Fault
		RPNM=Replace Page Not Modified
		MAT=Memory Access Time
		EAT=Effective Address Time 
	*/


	printf("Enter for the Replace Page Not Modified in millisecond:\n");	//Taking the value from user
	scanf("%lf",&RPNM);
	RPNM=change(RPNM);		//Changing the value from millisec to nanosecond

	printf("Enter for the Service Page Fault in millisecond:\n");		//Taking the value from user
	scanf("%lf",&SPF);
	SPF=change(SPF);		//Changing the value from millisec to nanosecond

	printf("Enter the Percentage of Page Replaced Modified TIME :\n");	//Taking the value from user
	scanf("%le",&a);
	a=a*0.01;			//converting the value in percentage in integer form
	SPF=a*SPF;

	b=1-a;				
	RPNM=b*RPNM;

	printf("Enter for the Memory Access Timein nanosecond:\n");		//Taking the value from user
	scanf("%lf",&MAT);

	printf("Enter for the Effective Address Time in nanosecond:\n");	//Taking the value from user
	printf("Effective Address Time Should not be more than 200ns\n");
	scanf("%lf",&EAT);


	if(EAT>200)
	{
		printf("\tSorry\nThe Value of Effective Access Time is more than 200\n");
	}
	else
	{
		p=(EAT-MAT)/(RPNM+SPF-MAT);			//using the formula for finding Page-Fault
		p=p*100;
		printf("The Maximum Acceptable Page-fault rate is: %lf%\n",p);		//returning the Page-fault after calculation
		return 0;
	}



}			//End of scope of the programm
