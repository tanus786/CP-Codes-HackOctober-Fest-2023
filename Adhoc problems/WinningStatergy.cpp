// Winning Strategy
// Send Feedback
// The college team, along with their coach, is going to the sports fest to play a football match.
// There are n players in the team, numbered from 1 to n.
// Someone gives a paper to the coach. The paper elaborates on the positions and strategies of the opponent team.
// Based on it, the coach creates a winning strategy. In that strategy,
// he decides and gives a particular position to every player.
// After this, the coach starts swapping two players at a time to make them stand according to new positions
// decided on paper.
    
// He swaps players by applying following rules:
// 1. Any player can swap with the player standing next to him. 
// 2. One player can swap with at most two other players.
// Given that initially all the players are standing linearly, numbered from 1 to n,
// you have to tell whether it is possible for
// the coach to create new positions by swapping within the constraints defined in the task.
    
// Input Format
// The first line of input will contain an integer, that denotes the value of the number of test cases.
//     Let us denote the number of test cases by the symbol T.
// Each of the following T test cases consists of two lines. The first line of each test case contains an integer n, 
// that denotes the number of players in the team. The following line contains n space separated integers,
// denoting the specific position of players in winning strategy.  
    
// Output Format
// For each test case, if it is possible to create winning strategy positions, then print "YES" (without quotes)
// and in the next line, print the minimum numbers of swaps required to form the winning strategy order, 
// otherwise print "NO"(without quotes) in a new line.
    
// Constraints
// 1 <= T <= 50
// 1 =< N <= 10^5 
// 1 <= A[i] <= n
// Time Limit: 1 second

// Sample Input 1:
// 1
// 5
// 2 1 5 3 4
    
// Sample Output 1:
// YES
// 3

// Explanation
// In this case, we can achieve winning strategy positions in 3 swaps. Initial state of positions: 1 2 3 4 5
// Three moves required to form winning strategy positions:
// 1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
// Sample Input 2:
// 1
// 5
// 2 5 1 3 4
// Sample Output 2:
// NO   
// Explanation:
// In the second case, there is no way to form the specific winning strategy positions by swapping 
// within the constraints mentioned in the task.

#include<iostream>
using namespace std;
void printer(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
      int t;
    cin>>t;
    while(t--){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
        int tt=0;
        for(int i=0;i<n;i++){
            
            if(abs(arr[i]-i-1)>2){
                cout<<"NO"<<endl;
                tt=1;
                break;
            }
            
        }
        if(tt==1){
            continue;
        }
	for(int i=n-1; i>=2; i--)
	{
		if(arr[i]==i+1)
		{
			continue;
		}
		else
		{
			if(arr[i-1]==i+1)
			{
				count += 1;
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
			else if(arr[i-2]==i+1)
			{
				count += 2;
				arr[i - 2] = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = i + 1;
			}
			else
			{
				cout << "NO"<<endl;
                    tt=1;
				break;
            
                
			}
		}
	}
        if(tt==1){
            continue;
        }
	else if(arr[0]==2 && arr[1]==1)
	{
		arr[0] = 1;
		arr[1] = 2;
		count += 1;
		cout << "YES" << endl << count<<endl;
	}
	else if(arr[0]==1 && arr[1]==2)
	{
		cout << "YES" << endl << count<<endl;
	}
	else
	{
		cout << "NO";
	}
    }
}
