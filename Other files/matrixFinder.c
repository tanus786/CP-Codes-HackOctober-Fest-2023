#include <stdio.h>
void run(int r1,int c1,int r2, int c2);
int main()
{
	int r1,r2,c1,c2;
	printf("1st size of matrix\nr1=");
	scanf("%d",&r1);
	printf("c1=");
	scanf("%d",&c1);
    printf("2nd size of matrix\n");
	printf("r2=");
	scanf("%d",&r2);
	printf("c2=");
	scanf("%d",&c2);
	
	if(c1== r2 ){
		run(r1,c1,r2,c2);
	}else{
		printf("invalid size: In multiplication of matrix c1 and r2 must be equal...");
	}
	
	
	return 0;
}
	
void run(int r1,int c1,int r2, int c2){
		
		
	int a[r1][c1],b[r2][c2];
	int mul[r1][c2];
	printf("\n1st matrix\n\n");
	for(int i=0;i<r1;i++){
		
		for(int j=0;j<c1;j++){
			printf("(%d, %d)= ",i+1,j+1);
			scanf("%d",&a[i][j]);	
		}	
		printf("\n");
	}
	
	printf("\n2nd matrix\n\n");
	for(int i=0;i<r2;i++){
		
		for(int j=0;j<c2;j++){
			printf("(%d, %d)= ",i+1,j+1);
			scanf("%d",&b[i][j]);	
		}	
		printf("\n");
	}
	
	
	for(int i=0; i<r1;i++){
		
		for(int j=0;j<c2;j++){
			mul[i][j]=0;
			for(int k=0;k<c1;k++){
			mul[i][j]+=a[i][k]*b[k][j];
			}
		}
		
	}
	printf("Result is in %d*%d matrix\n\n\n",r1,c2);
	
	for(int i=0; i<r1;i++){
		
		for(int j=0;j<c2;j++){
			printf("\t%d\t",mul[i][j]);
		}
		printf("\n");
	}

}
