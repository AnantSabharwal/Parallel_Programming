#include<stdio.h>
#include<omp.h>
float adds(float a, float b){
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
float print(float arr[]){
	for(int i=0;i<4;i++){
		printf("%f ",arr[i]);
	}
}
int main(){
	float a[4],b[4],add[4],sub[4],mul[4],div[4];
	//enter the numbers of the array
	printf("Enter values for a: \n");
	for(int i=0;i<4;i++){
		scanf("%f",&a[i]);
	}
	printf("Enter values for b: \n");
	for(int i=0;i<4;i++){
		scanf("%f",&b[i]);
	}
	#pragma omp parallel for
	for (int i = 0;i<4;i++ )
	{
		add[i] = adds(a[i],b[i]);
		//printf("Addition: %f \n",add(a,b));
		sub[i] = subtract(a[i],b[i]);
		//printf("Subtraction: %f \n",subtract(a,b));
		mul[i] = multiply(a[i],b[i]);
		//printf("Multiplication: %f \n",multiply(a,b));
		div[i] = divide(a[i],b[i]);
		//printf("Division: %f \n",divide(a,b));			
	}
	printf("Add ");
	print(add);
	printf("\n");
	printf("Subtract ");
	print(sub);
	printf("\n");
	printf("Multiply ");
	print(mul);
	printf("\n");
	printf("Divide: ");
	print(div);
	printf("\n");
}
