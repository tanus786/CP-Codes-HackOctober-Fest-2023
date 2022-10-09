#include <iostream>
#include<iomanip>
using namespace std;

void input( int a[][4],int row,int col){
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++)
    cin>>a[i][j];
    }
}
void display (int a[][4],int row3,int col3){
for(int i=0;i<row3;i++){
    for(int j=0;j<col3;j++)
    cout<<setw(5)<<a[i][j]<<endl;}
cout<<endl;
}
void add(int a[][4],int b[][4],int c[][4],int row1,int row2,int& row3,int col1,int col2,int& col3){
if(row1==row2 && col1==col2){
        for(int i=0;i<row1;i++){
            for( int j=0;j<col1;j++)
             c[i][j]=a[i][j]+b[i][j];}
        }
        else
            cout<<"invalid matrix"<<endl;}
void subtract(int a[][4], int b[][4], int c[][4], int row1,int row2,int&row3,int col1,int col2,int&col3){
 if(row1==row2 && col1==col2){
    for(int i=0;i<row1;i++){
        for( int j=0;j<col1;j++)
             c[i][j]=a[i][j]-b[i][j];
        }
    }
    else
        cout<<"invalid matrix"<<endl;}
void multiply (int a[][4],int b[][4],int c[][4],int row1,int row2,int &row3,int col1,int col2,int &col3){
    if(col1=row2){
        row3=row1;
        col3=col2;
        for(int i=0;i<row2;i++){
            for(int j=0;j<col1;j++)
                c[i][j] +=a[i][j]*b[i][j];
            cout<<endl;}
    }
        else cout<<"invalid number"<<endl;
    }
int main(){
 int a[5][4],b[5][4],c[5][4];
 int row,col,row1,row2,row3,col1,col2,col3,x;
 char ch='y';
while(ch=='y'){
    cout<<"1=input the matrix"<<endl;
    cout<<"2=output the matrix"<<endl;
    cout<<"3-add the matrix"<<endl;
    cout<<"4-subtract the matrix"<<endl;
    cout<<"5-multiply the matrix"<<endl;
    cin>>x;
    switch(x){
        case 1:cout<<"enter the number of row and colume of matrix A"<<endl;
             cin>>row1>>col1;
             cout<<"enter the elements for matrix A";
             input(a,row1,col1);
             ch = 'z';
             break;
        case 2:cout<<"enter the number of row and colume 0f matrix B"<<endl;
             cin>>row1>>col1;
             cout<<"matrix B";
             input(b,row1,col1);
             break;
        case 3:cout<<"matrix A"<<endl;
             display (a,row1,col1);
           cout<<"matrix B"<<endl;
           display(b,row2,col2);
           cout<<"matrix C"<<endl;
           display(c,row3,col3);
           break;
        case 4:add( a,b,c,row1,row2,row3,col1,col2,col3);
           break;
        case 5: subtract( a,b,c,row1,row2,row3,col1,col2,col3);
           break;
           case 6:multiply ( a,b,c,row1,row2,row3,col1,col2,col3);
           break;
    }
cout<<"do you want to continue :y/n"<<endl;
cin>>ch;
}


    return 0;
}