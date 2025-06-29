#include<iostream>
#include<sys/time.h>
//Time:  0.001085 0.004125 0.002579  0.00312 0.000997 0.001423

using namespace std;

int main(){
	struct timeval begin, end;
    gettimeofday(&begin, 0);

    char chararr[10][10] = {{'p','C','a', 'P'},{'E','x','A','m'}}, pattern[1000];
	int intarr[10][10] = {{1,2,4,3},{2,3,4,2}}, r=2, c=4, patidx =0;
	cout<<"The Character matrix:\n";
	for(int i =0; i<r; i++){
		for(int j = 0; j<c; j++){
			cout<<chararr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"The integer matrix:\n";
	for(int i =0; i<r; i++){
		for(int j = 0; j<c; j++){
			cout<<intarr[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i =0; i<r; i++){
		for(int j = 0; j<c; j++){
			for(int k =0; k<intarr[i][j]; k++){
				pattern[patidx++] = chararr[i][j];
			}
		}
	}
	pattern[patidx] = '\0';
	cout<<"the final pattern is: "<<pattern;
	gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    cout<<"\nTime measured: "<<elapsed<<" seconds.\n";
	return 0;
}
