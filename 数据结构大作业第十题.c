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
	printf("����ʮ��������");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
//	sheer(A);
	quick(B,0,N-1);
	for(i=0;i<N;i++){
		printf("%d ",B[i]);
	}
	printf("\n��������\n�Ƚϴ�����%d\n�ƶ�������%d\n",count_1,count_2);
	return 0;
}
void sheer(int *A){
	int d = N,i = 0,count1 = 0,count2 = 0;
	while(d>1){
		d/=2;
		for(i = d;i<N;i++){
			int temp = A[i];
			int j = i - d;
			while(j>=0&&temp>A[j]){      //�����в������� 
				A[j+d] = A[j];
				count2++;
				count1++;
				j-=d;
				
			}
			A[j+d] = temp;
			count2++;
		}
	}
	//��ӡ��� 
	for(i=0;i<N;i++){
		printf("%d ",A[i]);
	}
	printf("\nϣ������\n�Ƚϴ�����%d\n�ƶ�������%d\n",count1,count2);
}

void quick(int *A,int low,int high){
	if(low<high){
	int i=low,j = high;
	int temp = A[i];
	while(i<j)
	{
		while(i<j&&temp>=A[j]){        //�Ӻ���ǰ�ұȻ��ؼ���С�ģ�Ȼ�󽻻�����λ�� 
			j--;
			count_1++;
		}
		if(i<j){
			A[i] = A[j];
			count_2++;
			i++;
		}
		int q;
		
	
		while(i<j&&A[i]>=temp){       //�ٴ�ǰ�����ұȻ��ؼ��ִ�ģ��������� 
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
	A[i] = temp;       //һ��������ɣ��ڻ��ؼ������Ҽ��� 
	count_2++;	
	quick(A,low,i-1);
	quick(A,i+1,high);
	}
}
