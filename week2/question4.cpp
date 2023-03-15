#include<math.h>
#include<stdio.h>
#include<omp.h>
float add(float a, float b){
	return a+b;
}
float subtract(float a, float b){
	return a-b;
}
float multiply(float a, float b){
	return a*b;
}
float divide(float a, float b){
	return a/b;
}
int main(void){
	float a,b;
	scanf("%f",&a);
	scanf("%f",&b);
	#pragma omp parallel
	{
			#pragma omp sections
			{
				#pragma omp section
				{
					printf("Addition: %f \n",add(a,b));
				}
				#pragma omp section
				{
					printf("Subtraction: %f \n",subtract(a,b));
				}
				#pragma omp section
				{
					printf("Multiplication: %f \n",multiply(a,b));
				}
				#pragma omp section
				{
					printf("Division: %f \n",divide(a,b));
				}
			}			
	}		
}
