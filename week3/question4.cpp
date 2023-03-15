#include<stdio.h>
#include<time.h>
#include<omp.h>

int onecomplement(int num){
	int complement = 0, power = 1;
	while(num > 0){
		int rem = num%2 == 1?0:1;
		complement = complement + power*rem;
		power = 10*power;
		num /= 2;
	}
	return complement;
}

int complementtonum(int num){
	int sum =0, power = 1;
	while(num >0){
		sum = sum + (num%10)*power;
		power *=2;
		num /=10;
	}
	return sum;
}

int main(){
	clock_t start,end;

    int a[10][10] = {{1,2,3,4},{6,5,8,3},{2,4,10,1},{9,1,2,5}};
	int r = 4, c = 4, b[10][10], d[10][10];
	printf("The original matrix A:\n");
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	start = clock();
	#pragma omp parallel for
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			if(i==0 || j == 0|| i == r-1 || j == c-1){
				printf("thread number %d \n",omp_get_thread_num());
				b[i][j] = a[i][j];
				printf("thread number %d \n",omp_get_thread_num());
				d[i][j] = a[i][j];
			}
			else{
				printf("thread number %d \n",omp_get_thread_num());
				b[i][j] = onecomplement(a[i][j]);
				printf("thread number %d \n",omp_get_thread_num());
				d[i][j] = complementtonum(b[i][j]);
			}
		}
	}
	end = clock();
	printf("The matrix B:\n");
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}

	printf("The matrix D:\n");
	for(int i = 0; i<r; i++){
		for(int j =0; j<c; j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
    printf("\nTime measured: %f",end-start);
	return 0;
}

