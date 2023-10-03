#include<iostream>
using namespace std;
int choice;
bool draw =  false;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;

void Display_Board()
{
	
system("cls");
cout<<endl<<endl;
cout<<"\t\t******************************************************************************************\n\n";
cout<<"\t\t =======  =======   =======  =======     ==        =======   =======    ======     ======="<<endl;
cout<<"\t\t    =        =     =            =       =  =      =             =      =      =    ="<<endl;     
cout<<"\t\t    =        =    =             =      =    =    =              =     =        =   ="<<endl;      
cout<<"\t\t    =        =    =             =     ========   =              =     =        =   ======="<<endl;
cout<<"\t\t    =        =    =             =    =        =  =              =     =        =   ="<<endl;
cout<<"\t\t    =        =     =            =   =          =  =             =      =      =    ="<<endl;
cout<<"\t\t    =     =======   =======     =  =            =  =======      =       ======     ======="<<endl;
cout<<"\n\n\t\t*******************************************************************************************";
cout<<"\n\n\t\t\t\tPLAYER1 [X]\n";
cout<<"\n\t\t\t\tPLAYER2 [O]\n\n\n";
 
 cout<<"\t\t\t     |     |     "<<endl;
 cout<<"\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
 cout<<"\t\t\t_____|_____|_____"<<endl;
 cout<<"\t\t\t     |     |     "<<endl;
 cout<<"\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
 cout<<"\t\t\t_____|_____|_____"<<endl;
 cout<<"\t\t\t     |     |     "<<endl;
 cout<<"\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
 cout<<"\t\t\t     |     |     "<<endl;
}
void Player_Turn()
{
	if(turn=='X')
cout<<"\n\tPLAYER1 [x] Turn :  ";
if(turn=='O')
cout<<"\n\tPLAYER2 [O] Turn :  ";
 cin>>choice;
 switch(choice){
		case 1:	row=0; column=0;break;
		case 2:	row=0; column=1;break;
		case 3: row=0; column=2;break;
		case 4: row=1; column=0;break;
		case 5: row=1; column=1;break;
		case 6: row=1; column=2;break;
		case 7: row=2; column=0;break;
		case 8:	row=2; column=1;break;
		case 9: row=2; column=2;break;
		default :cout<<"\nInvalid choice\n ";break;
	}
	if(turn=='X' && board[row][column]!='X' && board[row][column]!='O' )
	{
		board[row][column]='X';
		turn='O';
	}
	else if(turn=='O'&& board[row][column] !='X' && board[row][column] !='O')
	{
		board[row][column]='O';
		turn='X';
	}
	else 
	{
	cout<<"BOX IS ALREADY FILL PLEASE TRY AGAIN ";
	Player_Turn();
	}
	Display_Board();
}  
bool Game_Over()
{ 
	//if check win 
	
  for(int i=0; i<3; i++)
	if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
	return false; 
	
	 if(board[0][0]==board[1][1] && board[0][0]==board[2][2] ||  board[0][2]==board[1][1] && board[0][2]==board[2][0])
	return false;
    
	//if there is only box not filled
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
	if(board[i][j] != 'X'&& board[i][j]!='O')
	return true;
	
	//draw
	draw=true;
	return false;
	
	
}

int main()
{

while(Game_Over())
{
Display_Board();
Player_Turn();
Game_Over();
}

if(turn =='X' && draw==false)
{
cout<<"PLAYER2 [O] WINS !! congratulations \n";
}
else if(turn =='O' && draw==false)
{
cout<<"PLAYER1 [x] WINS !! congratulations \n";

}
else
{
cout<<"GAME DRAW !! \n";
}


	return 0;
}

