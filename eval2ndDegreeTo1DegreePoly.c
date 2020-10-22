/****************************************************************
 *Written by İbrahim Çetinkaya	Date:12 February  2014		*
 *	________________________________________________________*
 *Description:							*
 *________________________________				*
 *								*
 *2.dereceden verilen bir polinomun 1.derece polinoma çevrilmesi*
 *Input:							*
 *	Polinomun katsayıları(c1,c2,c3)				*	
 *Output:					                *                                                                            
 *       Sonuç(total)						*                                                  
 *		HW00_İbrahim_Çetinkaya_121044072_part2.c  	*
 ****************************************************************
 */
#include<stdio.h>
/****************************************************************
 *								*  					
 *			START_OF_MAIN				*
 *								*
 ****************************************************************
 */
int main(void)
{

	double c1,c2,c3;	 /*Polinomun katsayıları*/
	double  total; 		 /*sonuç*/
/****************************************************************
 *			END_OF_VARIABLES			*
 *								*
 ****************************************************************
 */ 

/*Polinomun başkatsayıları alınması için aşağıdaki kod uygulanmıştır.*/
printf("Enter the coefficients of the poly  (from higher to lower order):  \n");
scanf("%lf %lf %lf",&c1,&c2,&c3);

/*Polinomu indirgemek  için 2 ile çarpılır */
total = c1*2;

/*Virgülden sonra sayı gözükmesin diye 0 yazılmıştır.*/
printf("1st degree polynomial:	%.0fx+%.0f \n",total,c2);  

/****************************************************************
 *								*
 *			END_OF_MAIN				*
 *								*
 ****************************************************************
 */
return 0;
}
