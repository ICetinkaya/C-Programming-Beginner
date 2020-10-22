/*#####################################################################*/
/*HW00_121044072_part1.c														*/
/*__________________________________													*/
/*Written by İbrahim Çetinkaya on February  13,2014									*/
/*											   								*/
/*Description:																	*/
/*____________________																*/
/*Evaluates a  given 2nd Degree polynomial											*/
/*Inputs:																		*/
/*	Coefficients of the Poly 														*/
/*	Number for which the Poly will be evaluated										*/
/*Outputs:																	*/
/*	Result																	*/
/*#####################################################################*/

#include<stdio.h>

int main()
{
/*#####################################################################*/
/*																			*/
/*								START_OF_MAIN								*/
/*																			*/
/*#####################################################################*/	
	
	double  c1,c2,c3;  /*coefficients of the poly*/
	double x;		  /*variable of poly*/
	double result;	/*evaluation value*/

/*#####################################################################*/
/*																			*/
/*								END_OF_VARIABLES								*/
/*																			*/
/*#####################################################################*/	
	
/*Get the poly*/
printf("Enter the coefficients of the poly  (from higher to lower order):  \n");
scanf("%lf %lf %lf", &c1, &c2, &c3); 

/*Get the value of the variable */
printf("Enter the value of x: \n");
scanf("%lf",&x);

/*Calculate the evaluation value*/
result = c1*x*x + c2*x + x;

/*Print  the result*/
printf("The result is %5.3f \n",result);

/*#####################################################################*/
/*																			*/
/*								END_OF_MAIN									*/
/*																			*/
/*#####################################################################*/
return 0;
}

