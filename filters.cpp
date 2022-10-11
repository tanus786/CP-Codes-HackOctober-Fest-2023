#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

//Bloom Filter Functions

int h1(string s, int arrSize)
{
    int hash = 0;
    
    for(int i=0;i<s.size();i++)
    {
        hash = hash + (int(s[i]));
        hash = hash % arrSize;
    }
    
    return hash;
}

int h2(string s, int arrSize)
{
    int hash = 1;
    
    for(int i=0;i<s.size();i++)
    {
        hash = hash + (i*int(s[i]));
        hash = hash % arrSize;
    }
    
    return hash;
}

int h3(string s, int arrSize)
{
    int hash = 2;
    for(int i=0;i<s.size();i++)
    {
        hash = hash + pow(19,i);
        hash = hash % arrSize;
    }
    
    return hash;
}

void insert(int bfilter[10], string name, int arrSize)
{
    int a = h1(name,arrSize);
    int b = h2(name,arrSize);
    int c = h3(name,arrSize);
 
    if(bfilter[a]==1 && bfilter[b]==1 && bfilter[c]==1)
    {
        cout<<"\nThe Name is Probably Present !!";
    }
    
    else
    {
        bfilter[a] = 1;
		bfilter[b] = 1;
		bfilter[c] = 1;
		
		cout<<name<<" is inserted !!"; 
    }
}

//Cuckoo Filter Functions

int hash1(int num, int arrSize)
{
    int h1=0;
    h1 = num%arrSize;
    
    return h1;
}

int hash2(int num, int arrSize)
{
    int h2 = 0;
    h2 = ((num/arrSize)%arrSize);
    
    return h2;
}

void printHash(int cfilter1[10],int cfilter2[10],int arrSize)
{
    cout<<endl<<"\nHashtable 1 : ";
    
    for(int i = 0;i<arrSize;i++)
    {
        cout<<cfilter1[i]<<" | ";
    } 
	 
    cout<<endl<<"\nHashtable 2 : ";
    
	for(int i = 0;i<arrSize;i++)
    {
        cout<<cfilter2[i]<<" | ";
    }
    cout<<endl;
}

void insertC(int cfilter1[10],int cfilter2[10],int num, int arrSize)
{
    int a = hash1(num,arrSize);
    
    if(cfilter1[a] == -1)
    {
       cfilter1[a] = num;
    }
    
    else
    {
        int temp;
        temp = cfilter1[a];
        cfilter1[a] = num;
        int b = hash2(temp,arrSize);
        
        if(cfilter2[b] == -1)
        {
            cfilter2[b] = temp;
        }
        
        else
        {
            insertC(cfilter1,cfilter2,temp,arrSize);
        }
    }
    
    printHash(cfilter1,cfilter2,arrSize);
}

int main()
{
    int opt;
    
    do
    {
        cout<<"\nWhich Filter Do You Want To Choose\n(1)Bloom Filter\n(2)Cuckoo Filter\n(0)Exit\nEnter Your Choice --> ";
        cin>>opt;
        
		if(opt==1)
        {
            int bfilter[10],choice;
            string name;
            
			for(int i=0;i<10;i++)
            { 
                bfilter[i]=0;
            }
            
            do
            {
                cout<<"\nEnter The name you Want To Insert : ";
                cin>>name;
                insert(bfilter,name,10);
                cout<<"\nDo You Want to insert another name(1/0) : ";
                cin>>choice;
                
            } while(choice!=0);
        }
        
        else if(opt==2)
        {
            int cfilter1[10],cfilter2[10],num,choice;
            
			for(int i=0;i<11;i++)
            {
                cfilter1[i] = cfilter2[i] = -1;
            }
            
            do
            {
                cout<<"\nEnter A number to be inserted : ";
                cin>>num;
                insertC(cfilter1,cfilter2,num,11);
                
                cout<<"\nDo you want to insert more numbers(1/0) : ";
                cin>>choice;
                
            } while(choice!=0);
        }
        
		else if(opt==0)
        {
            break;
        }
        
        else
        {
            cout<<"Invalid Input!!!";
        }
        
    } while(opt!=0);
    
    return 0;
}


/*


Which Filter Do You Want To Choose
(1)Bloom Filter
(2)Cuckoo Filter
(0)Exit
Enter Your Choice --> 1

Enter The name you Want To Insert : sathak
sathak is inserted !!
Do You Want to insert another name(1/0) : 1

Enter The name you Want To Insert : sarthak
sarthak is inserted !!
Do You Want to insert another name(1/0) : 1

Enter The name you Want To Insert : sarthak

The Name is Probably Present !!
Do You Want to insert another name(1/0) :





Which Filter Do You Want To Choose
(1)Bloom Filter
(2)Cuckoo Filter
(0)Exit
Enter Your Choice --> 2

Enter A number to be inserted : 20


Hashtable 1 : -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 20 | -1 |

Hashtable 2 : -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |

Do you want to insert more numbers(1/0) : 1

Enter A number to be inserted : 50


Hashtable 1 : -1 | -1 | -1 | -1 | -1 | -1 | 50 | -1 | -1 | 20 | -1 |

Hashtable 2 : -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 1 |

Do you want to insert more numbers(1/0) : 1

Enter A number to be inserted : 53


Hashtable 1 : -1 | -1 | -1 | -1 | -1 | -1 | 50 | -1 | -1 | 53 | -1 |

Hashtable 2 : -1 | 20 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 1 |

Do you want to insert more numbers(1/0) : 1

Enter A number to be inserted : 75


Hashtable 1 : -1 | -1 | -1 | -1 | -1 | -1 | 50 | -1 | -1 | 75 | -1 |

Hashtable 2 : -1 | 20 | -1 | -1 | 53 | -1 | -1 | -1 | -1 | -1 | 1 |

*/
