#include<stdio.h>
#include<omp.h>
#include<time.h>

int main(){
	clock_t start,end;
	int a[5][5];
	printf("Enter the values of matrix a: \n");
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int b[5][5];
	start = clock();
	#pragma omp parallel for
	for (int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if (i==j){
				b[i][j] = 0;
			}else if(i<j){
				//int min;
				//for(int k=0;k<5;k++){
				int min = a[i][0];//j=0
				for(int l=0;l<5;l++){
					if (a[i][l]<min){
						min = a[i][l];
					}
				}
				//}
				b[i][j] = min;
				printf("thread number %d \n",omp_get_thread_num());
			}else if(i>j){
				//int max;
				//for(int k=0;k<5;k++){
				int max = a[i][0];//j=0
				for(int l=0;l<5;l++){
					if (a[i][l]>max){
						max = a[i][l];
					}
				}
			b[i][j] = max;
			printf("thread number %d \n",omp_get_thread_num());
			//}
		}
	}
}
end = clock();
for (int i = 0; i < 5; i++)
{
   for (int j = 0; j < 5; j++)
   {
      printf("%d ",b[i][j]);
   }
   printf("\n");
}
printf("\n time taken for execution of parallel code is: %f",end-start);
return 0;
}

