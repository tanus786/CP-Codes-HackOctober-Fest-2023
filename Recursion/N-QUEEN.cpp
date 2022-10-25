#include<bits/stdc++.h>
using namespace std;
bool issafe(int row, int col, vector<vector<char>> &pos, int n)
{
	  for(int i=row, j=col; i>=0  && j>=0;j--) if(pos[i][j]==1) return false;
    for(int i=row, j=col; i>=0 && j>=0;i--,j--) if(pos[i][j]==1) return false; 
    for(int i=row, j=col; i<n && j>=0;i++,j--) if(pos[i][j]==1) return false;

    return true;	
}

bool issafe2(int row, int col, vector<vector<char>> &pos, int n, vector<int> &rowhash, 
	vector<int> &thirdhash, vector<int> &firsthash)
{

  if(rowhash[row]==1 || thirdhash[row + col] ==1|| firsthash[n-1-row+col]==1) 
  	return false;
 
  return true;
}



bool findpos(int col, vector<vector<char>> &pos,int n, vector<int> &rowhash,
	vector<int> &thirdhash, vector<int> &firsthash)
{
	if(col==n)
	{
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++)
        		cout<<pos[i][j]<<" ";
        	cout<<endl;
        }
        cout<<endl<<endl;

        return true;	
	}

   for(int row=0;row<n;row++)
   {
   	
   	 if(issafe2(row,col,pos,n,rowhash,thirdhash,firsthash)){

   	    pos[row][col]='Q';
   	    rowhash[row]=1;
   	    thirdhash[row+col]=1;
   	    firsthash[n-1-row+col]=1;
   	    if(findpos(col+1,pos,n,rowhash,thirdhash,firsthash)==true) return true;
   	    pos[row][col]='.';
   	    rowhash[row]=0;
   	    thirdhash[row+col]=0;
   	    firsthash[n-1-row+col]=0;
   	 }

   }
  return false;

}

int main()
{
	int n;
	cin>>n;
	vector<vector<char>> pos(n, vector<char>(n,'.'));
	vector<int> rowhash(n,0);
	vector<int> thirdhash(2*n-1,0);
	vector<int> firsthash(2*n-1,0);
	findpos(0,pos,n,rowhash,thirdhash,firsthash);
	
}