/****************************************************************
 * 	Written by İbrahim Çetinkaya  Date:17 March 2014			*
 *		HW04_İbrahim_Çetinkaya_121044072.c						*
 *  	 _____________________________________________________	*
 *Description:													*
 * ______________________________								*
 *																*
 *	In this C program  which an automation program for a market *
 *	house.It will contain records of existing products			*
 *		Types will be:											*
 *________________________										*
 *		 f = food stuff 										*
 *       c = cleaning product 									*
 *		 p = personal care product								* 
 *	İnputs:														*		
 *		Selection(c,C,u,U)										*
 *		Choice(2,3,4,5,6)			 							*
 *		Code of product											*
 *		Type of product											*
 *		Buying price of product									*
 *		Sale price of product									*
 *		Quantity of product										*				
 *																*
 *																*		
 *																*
 ****************************************************************
 */

#include <stdio.h>
/****************************************************************
 *																*
 *					START_OF_FUNCTION_PROTOTYPES				*
 *																*
 ****************************************************************
 */

 /***************************************************************
 *		In this function >>> 									*
 *	Write products in products.txt								*
 *	Input:														*
 * -------------												*
 *  code_product,type_product ,buyprice_product,sale_product	*
 *	,quantity_product											*
 ****************************************************************
 */	
int enter_products(int code_product,char type_product ,double buyprice_product
					,double sale_product,int quantity_product);
/****************************************************************
 *		In this function >>> 									*
 *	According to Code and Type:									*
 * Searches the product records with the given code and type 	*
 * from the “products.txt” file and reports the current			*
 * information of this product. 								*
 *	Input:														*
 * -------------												*
 *  get_code ,get_type											*
 ****************************************************************
 */	
int search_by_type_code(int get_code ,char get_type);
/****************************************************************
 *		In this function >>> 									*
 *	List all products with their information					*

 ****************************************************************
 */
int list_all_products();
/****************************************************************
 *		In this function >>> 									*
 *  Print the console sub menu									*
 ****************************************************************
 */
int sub_menu();


/****************************************************************
 *		In this function >>> 									*
 *	According to Quantity:										*
 * Searches and lists the product reports which are lower or 	*
 * higher than the given quantity.								*
 *	Input:														*
 * -------------												*
 *  choice_quantity, get_quantity								*
 ****************************************************************
 */	

int filter_by_quantity(char choice_quantity, int get_quantity);

/****************************************************************
 *		In this function >>> 									*
 *	According to a Type:										*
 * Searches the product records with the given type from the 	*
 * “products.txt” file 											*
 *	Input:														*
 * -------------												*
 *  get_type											  		*
 ****************************************************************
 */	
int search_by_type(char get_type);
/****************************************************************
 *																*
 *						START_OF_MAIN							*
 *																*
 ****************************************************************
 */	
 int main(void)
{

	
	int code_product,get_code;
	double buyprice_product,sale_product ;
	int quantity_product,get_quantity;
	char choice_quantity;
	int doWrite,temporary;
	char type_product;
	int choice;
	char selection;
	char get_type;
	int error = 1;
	char temporary_1,temporary_2,temporary_3,temporary_4;
/****************************************************************
 *						END_OF_VARIABLES						*
 ****************************************************************
 */		
								/*MENU*/
	printf("\t##################################################### \n");
	printf("\t#           --------WELCOME!!!--------              # \n");
	printf("\t#   An automation program for a market warehouse    # \n");
	printf("\t#           f = food stuff                          # \n");
	printf("\t#           c = cleaning product                    # \n");
	printf("\t#           p = personal care product               # \n");
	printf("\t#           o = other product                       # \n");
    printf("\t##################################################### \n");
	printf("\t#           Select to make operations               # \n");
    printf("\t#                                                   # \n");
    printf("\t#   (c or C) ==> Create New File                    # \n");
    printf("\t#   (u or U) ==> Use the existing products file     # \n");
    printf("\t##################################################### \n");
    printf("Please enter the selection:\n");
	scanf(" %c",&selection);
    
    
    while(selection != 'c' || selection != 'C' || selection != 'u' ||
    			selection != 'U')
    {	
		switch(selection)
		{
		case 'C':
		case 'c':
			/*create new file and write information of products*/
		enter_products(code_product,type_product ,buyprice_product,
						sale_product,quantity_product);
		printf("-------Thank you for using an automation program-------\n");
		printf("                << END OF PROGRAM >>                  \n");
		break;
		case 'U':
		case 'u':
		while( !(choice >= 2 && choice <= 6 ) )
			{
				choice = sub_menu();
				switch(choice)
				{

					case 2:
						/*Print console all information of products*/
					list_all_products();
					sub_menu();
									
					break;

					case 3:

						printf("please enter type of the product you want to search\n");
						scanf(" %c",&get_type);
						search_by_type(get_type);
						sub_menu();
						
					break;

					case 4:
					printf("please enter code of the product you want to search\n"); 
					scanf("%d",&get_code);
					while(get_code < 0)
					{
						printf("Incorrcet data \n");
						scanf("%d",&get_code);
					}
					printf("please enter type of the product you want to search\n"); 
					scanf(" %c",&get_type);

					search_by_type_code(get_code ,get_type);
					sub_menu();
					
					break;
						
					case 5:
					printf("please enter lower(l) or higher(h) quantity of the product you want to search\n");
					scanf(" %c",&choice_quantity);
					if (choice_quantity == 'l')
					{
						printf("please enter quantity of the product you want to search\n");	
						scanf("%d",&get_quantity);
						printf("The products which are %d lower quantity\n",get_quantity);
						filter_by_quantity(choice_quantity,get_quantity);
					}
					else if  (choice_quantity == 'h')
					{
						printf("please enter quantity of the productyou want to search\n");
						scanf("%d",&get_quantity);
						printf("The products which are %d higher quantity\n",get_quantity);
						filter_by_quantity(choice_quantity,get_quantity);
						
					}
					sub_menu();
					break;
					
					case 6:
					sub_menu();
					printf("-----Thank you for using an automation program-----\n");
					printf("                << END OF PROGRAM >>           \n");
					return 0;
					break; 
					default:
					if (  !(choice >= 2 && choice <= 6 ) )
					{
						printf("Incorrcet Data\n");
						printf("Try again!!!\n");
						sub_menu();
					}
						

				}
			}
			
		break;
		default:
	
			if (error == 1)
			{
				printf("Incorrcet Data\n");
				printf("Try again,Please enter the selection\n");
				printf("Please enter the selection:\n");
				scanf(" %c",&selection);
				
			}	
		}
	
	}	

	return 0;
}
int enter_products(int code_product,char type_product, double buyprice_product
				     ,double sale_product,int quantity_product)
{
	FILE *products;
	int doWrite;
	products = fopen("products.txt","w");
	
	while(1)/**/ 
	{
		printf("Please enter the code of product(Exit -1)\n");
		scanf("%d",&code_product);
		if(code_product == -1){
			printf("Your operations has ended\n");
			break;
		}
		
		if(code_product < 0){
			printf("Incorrect Data,please try again\n");
			continue;
		}
		printf("Please enter the type of product(Exit -1)\n");
		scanf(" %c",&type_product );
		 /*eğer kullanıcı yanlış input girmişse tekrar girmesini sağla.Dosyaya yazdırmaz */ 

		while( !( ('z'>=type_product) && ('a'<=type_product)) || 
								!(( 'Z'>=type_product) && ('A'<=type_product)) )
					{
						printf("Incorrcet İnput type\n");
						scanf(" %c",&type_product);	
					
					}

		printf("Please enter buying price of product(Exit -1)\n");
		scanf("%lf",&buyprice_product);
		printf("Please enter sale of product(Exit -1)\n");
		scanf("%lf", &sale_product );
		doWrite = 1;
		if(sale_product <= buyprice_product){
			printf("Incorrect input, buy price of product is not higher\n");
			doWrite = 0;
			continue;

		}
		doWrite = 1;
		printf("Please enter quantity of product(Exit -1)\n");
		scanf(" %d",&quantity_product);
		if(quantity_product < 0)
		{
			printf("There isn't product in the market\n");
			doWrite = 0 ;
			continue;
		}
		if(doWrite)
			fprintf(products,"%d %c %.2f %.2f %d\n",code_product,type_product ,
				buyprice_product,sale_product ,quantity_product);
	}
fclose(products);
}

int list_all_products()
{

	FILE  *products;
	int code_product;
	double buyprice_product,sale_product ;
	int quantity_product, doWrite;
	char type_product;
	int choice,data;
	products = fopen("products.txt","r");
	
	while(data = fscanf(products,"%d %c%lf%lf%d\n", &code_product, &type_product 
				 , &buyprice_product, &sale_product , &quantity_product) != EOF)
		{
			printf("%d %c %.2f %.2f %d\n", code_product, type_product,
				     buyprice_product, sale_product, quantity_product);
		}
	
	
	fclose(products);


}

int search_by_type(char get_type)
{

	FILE  *products;
	int code_product;
	double buyprice_product,sale_product ;
	int quantity_product, doWrite;
	char type_product;
	int choice;
	products = fopen("products.txt","r");
	
	printf("Information of product in %c type\n",get_type);
	while(fscanf(products,"%d %c%lf%lf%d\n", &code_product, &type_product 
				 , &buyprice_product, &sale_product , &quantity_product) != EOF)
		{
			
			if ( get_type == type_product )
			{
				printf("%d %c %.2f %.2f %d\n", code_product, type_product,
				     buyprice_product, sale_product, quantity_product);
			}
			
			
		}
	fclose(products);
return 0;
}

int search_by_type_code(int get_code ,char get_type)
{

	FILE  *products;
	int code_product;
	double buyprice_product,sale_product ;
	int quantity_product, doWrite;
	char type_product;
	int choice;
	products = fopen("products.txt","r");
	
	printf("Information of product in %d code and %c type\n",get_code,get_type);


	while(fscanf(products,"%d %c%lf%lf%d\n", &code_product, &type_product 
				 , &buyprice_product, &sale_product , &quantity_product) != EOF)
		{
			
			if ( get_type == type_product && get_code == code_product )
			{
				printf("%d %c %.2f %.2f %d\n", code_product, type_product,
				     buyprice_product, sale_product, quantity_product);
			}
			
		}
	fclose(products);
}

int filter_by_quantity(char choice_quantity, int get_quantity)
{

	FILE  *products;
	int code_product;
	double buyprice_product,sale_product ;
	int quantity_product, doWrite;
	char type_product;
	int choice;
	products = fopen("products.txt","r");
	
	printf("Information of product in %d quantity\n",get_quantity);
	while(fscanf(products,"%d %c%lf%lf%d\n", &code_product, &type_product 
				 , &buyprice_product, &sale_product , &quantity_product) != EOF)
		{
			if (choice_quantity == 'l')
			{
				if ( get_quantity > quantity_product )
				{
					printf("%d %c %.2f %.2f %d\n", code_product, type_product,
					     buyprice_product, sale_product, quantity_product);
					if(quantity_product < 0)
					{
						printf("There isn't product in the market\n");
					} 
				}
			}
			 if (choice_quantity == 'h')
			{
				if ( get_quantity < quantity_product )
				{
					printf("%d %c %.2f %.2f %d\n", code_product, type_product,
					     buyprice_product, sale_product, quantity_product);
					if(quantity_product < 0)
					{
						printf("There isn't product in the market\n");
					} 
				}
			}
		}
	fclose(products);
}
int sub_menu()
{
	int choice;
	while( !(choice >= 2 && choice <= 6 ) )
	{
	printf("\t######################################################\n");
	printf("\t##    <<<<<Use the existing products file>>>>>      ##\n");	
	printf("\t##                                                  ##\n");
	printf("\t######################################################\n");
	printf("\t##   [2] List all records                           ##\n");
	printf("\t##   [3] Search by Type                             ##\n");
	printf("\t##   [4] Search by Type and Code                    ##\n");	
	printf("\t##   [5] Filter by quantity                         ##\n");
	printf("\t##   [6] Exit                                       ##\n");
	printf("\t######################################################\n");

	
	printf("Please enter the choice\n");
	scanf("%d",&choice);
	if (  !(choice >= 2 && choice <= 6 ) )
		{
			printf("Incorrcet Data\n");
			printf("Try again!!!\n");
			
		}


	}

return choice;
}
/****************************************************************
 *																*
 *						END_OF_MAIN								*
 *																*
 ****************************************************************
 */	