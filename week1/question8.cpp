#include<iostream>
#include<sys/time.h>
//Time:  0.001085 0.004125 0.002579  0.00312 0.000997 0.001423

using namespace std;

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
	struct timeval begin, end;
    gettimeofday(&begin, 0);

    int a[10][10] = {{1,2,3,4},{6,5,8,3},{2,4,10,1},{9,1,2,5}};
	int r = 4, c = 4, b[10][10], d[10][10];
	cout<<"The original matrix A:\n";
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			if(i==0 || j == 0|| i == r-1 || j == c-1){
				b[i][j] = a[i][j];
				d[i][j] = a[i][j];
			}
			else{
				b[i][j] = onecomplement(a[i][j]);
				d[i][j] = complementtonum(b[i][j]);
			}
		}
	}
	cout<<"The matrix B is:\n";
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"The matrix D is:\n";
	for(int i = 0; i<r; i++){
		for(int j =0; j<c; j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    cout<<"\nTime measured: "<<elapsed<<" seconds.\n";
	return 0;
}
