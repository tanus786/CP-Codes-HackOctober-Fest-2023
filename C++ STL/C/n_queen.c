#include<stdio.h>
#include<math.h>
int board[20], count=0;
int place(int row, int col){
    int i;
    for(i=1; i<=row-1; i++){
        if(board[i] == col){
            return 0;
        }
        else{
            if(abs(board[i]-col) == abs(i-row))
            return 0;
        }
    }
    return 1;
}


void print(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",count++);

for(i=1;i<=n;i++)
  printf("\t%d",i);

for(i=1;i<=n;i++)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;j++) 
  {
  if(board[i]==j)
    printf("\tQ"); 
  else
    printf("\t-"); 
  }
}
}

void nqueen(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
  board[row]=column;
  if(row==n) 
    print(n); 
  else 
    nqueen(row+1,n);
  }
}
}
int main(){
    int n, i, j;
    void nqueen(int row, int n);
    printf("Enter the number of queen to be inserted: \n");
    scanf("%d", &n);
    nqueen(1, n);
    return 0;
}