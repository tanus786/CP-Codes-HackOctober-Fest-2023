// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     int num=1;
//     for (int i=1;i<=t;i++){
//         for (int j=1;j<=i;j++){
//             cout<<num;
//             num++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



//Alphabetical Triangle
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     char ch='A';
//     for (int i=1;i<=t;i++){
//         for (int j=1;j<=i;j++){
//             cout<<ch;
//             ch++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//Yet another Alphabetical Triangle
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     char ch='A';
//     for (int i=1;i<=t;i++){
//         for (int j=1;j<=i;j++){
//             cout<<ch;
//         }
//         ch++;
//         cout<<endl;
//     }
//     return 0;
// }

//Yet another Alphabetical Triangle
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     char ch='A';
//     for (int i=0;i<=t;i++){
//         for(char ch='A';ch<='A'+i;ch++){
//             cout<<ch;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//reverse Alphabetical Triangle
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     char ch='A';
//     for (int i=0;i<=t;i++){
//         for (char ch='A';ch<='A'+(t-i-1);ch++){
//             cout<<ch;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// //equilateral alphabetical triangle
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     for (int i=0;i<t;i++){
//         //space
//         for (int j=0;j<=t-i-1;j++){
//             cout<<" ";
//         }
//         //characters
//         char ch='A';
//         int breakpoint=(2*i+1)/2;
//         for (int j=1;j<=2*i+1;j++){
//             cout<<ch;
//             if(j<=breakpoint) ch++;
//             else ch--;
//         }
//         //space 
//         for (int j=0;j<=t-i-1;j++){
//             cout<<" ";
//         }
//         cout<<endl;

//     }
//     return 0;
// }

//alphabetical right angle triangle but in reverse order
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     char ch='A';
//     for (int i=0;i<=t;i++){
//         for(char ch='E'-i;ch<='E';ch++){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int space=0;
    for (int i=0;i<t;i++){
        for (int j=1;j<=t-i;j++){
            cout<<"*";
        }
        for (int j=0;j<space;j++){
            cout<<" ";
        }
        for (int j=1;j<=t-i;j++){
            cout<<"*";
        }
        space+=2;
        cout<<endl;

    }
    int space2=8;
    for (int i=1;i<=t;i++){
        for (int j=1;j<=i;j++){
            cout<<"*";
        }
        for (int j=0;j<space2;j++){
            cout<<" ";
        }
        for (int j=1;j<=i;j++){
            cout<<"*";
        }
        space-=2;
        cout<<endl;

    }
    return 0;
}