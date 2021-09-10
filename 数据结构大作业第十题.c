#include<stdio.h>
#define N 11
void quick(int *,int i,int j);
void sheer(int *);
int count_1=0,count_2=0; 
int main()
{
	int A[N] = {0};
	int B[N] = {0};
	int i ;
	printf("输入十个整数：");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
//	sheer(A);
	quick(B,0,N-1);
	for(i=0;i<N;i++){
		printf("%d ",B[i]);
	}
	printf("\n快速排序\n比较次数：%d\n移动次数：%d\n",count_1,count_2);
	return 0;
}
void sheer(int *A){
	int d = N,i = 0,count1 = 0,count2 = 0;
	while(d>1){
		d/=2;
		for(i = d;i<N;i++){
			int temp = A[i];
			int j = i - d;
			while(j>=0&&temp>A[j]){      //子序列插入排序 
				A[j+d] = A[j];
				count2++;
				count1++;
				j-=d;
				
			}
			A[j+d] = temp;
			count2++;
		}
	}
	//打印结果 
	for(i=0;i<N;i++){
		printf("%d ",A[i]);
	}
	printf("\n希尔排序\n比较次数：%d\n移动次数：%d\n",count1,count2);
}

void quick(int *A,int low,int high){
	if(low<high){
	int i=low,j = high;
	int temp = A[i];
	while(i<j)
	{
		while(i<j&&temp>=A[j]){        //从后往前找比基关键字小的，然后交换两者位置 
			j--;
			count_1++;
		}
		if(i<j){
			A[i] = A[j];
			count_2++;
			i++;
		}
		int q;
		
	
		while(i<j&&A[i]>=temp){       //再从前往后找比基关键字大的，继续交换 
			i++;
			count_1++;
		}
		for(q=0;q<N;q++){
			printf("%d ",A[q]);
		}
		puts("");
		if(i<j){
			A[j] = A[i];
			count_2++;
			j--;
		}	
	}
	A[i] = temp;       //一次排序完成，在基关键字左右继续 
	count_2++;	
	quick(A,low,i-1);
	quick(A,i+1,high);
	}
}
