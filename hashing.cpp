#include<iostream>
using namespace std;


void insert_withoutreplacement(int n)
{
    int arr1[n-1];
    int arr2[n-1];
    int flag[n-1];
    
    for(int i=0;i<n;i++)
    { 
        flag[i]=0;
    }
    
    cout<<"Enter the elements "<<"\n";
    
	for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    
    for (int i=0;i<n;i++)
    {
        arr2[i]=-1;
    }
    
    //actual code
    for(int i=0;i<n;i++)
    {
        int a=arr1[i]%n; //a=hash value
        
        if(arr2[a]==-1)
        {
            arr2[a]=arr1[i];
            flag[a]=1;
        }
        
        else
        {
            int c=a+1; //c is also hash key
            int flag1=0;
            
            while(c!=a && flag1==0)
            {
                if(flag[c]==0 && c<n)
                {
                    arr2[c]=arr1[i];
                    flag[c]=1;flag1=1;
                    break;
                }
 
                else
                {
                    if(c==n)
                    {
                        c=-1;
                    }
                    
                    c++;
                }
            }
        }
 
    }
 
    cout<<" Hashing table is ";
    cout<<"\n";
    
    for(int j=0;j<n;j++)
    {
        cout<<arr2[j]<<" ";
    }
}


void insert_replacement(int n)
{
    int arr1[n-1];
    int arr2[n-1];
    int flag[n-1];
    
    for(int i=0;i<n;i++)
    {
        flag[i]=0;
    }
     
	cout<<"Enter the elements "<<"\n";
	
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    
    for (int i=0;i<n;i++)
    {
        arr2[i]=-1;
    }
    
    for(int i=0;i<n;i++)
    {
        int a=arr1[i]%n;
        
        if(arr2[a]==-1)
        {
            arr2[a]=arr1[i];
            flag[a]=1;
        }
        
		else
        {
            int c=a+1;
            int flag1=0;
            
			while(c!=a && flag1==0)
            {
                if(flag[c]==0 && c<n)
                {
                	arr2[c]=arr1[i];
                    flag[c]=1;flag1=1;
                   
				   //swappping
                    int temp;
                    temp=arr2[a];
                    arr2[a]=arr2[c];
                    arr2[c]=temp;
                    c++;
                    break;
                }
 
                else
                {
                    if(c==n)
                    {
                        c=-1;
                    }
                    c++;
                }
            }
        }
 
    }
 
    cout<<" Hashing table is ";
    cout<<"\n";
    
	for(int j=0;j<n;j++)
    {
        cout<<arr2[j]<<" ";
    }
}

void insert_student(int n)
{
    int arr1[n-1];
    int arr2[n-1];
    int flag[n-1];

    for(int i=0;i<n;i++)
    {
        flag[i]=0;
    }
    
    cout<<"\nEnter the rollno of students "<<"\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    
    for (int i=0;i<n;i++)
    {
        arr2[i]=-1;
    }
    
    //actual code
    for(int i=0;i<n;i++)
    {
        int a=arr1[i]%n;
        
		if(arr2[a]==-1)
        {
            arr2[a]=arr1[i];
            flag[a]=1;
        }
        
        else
        {
            int c=a+1;
            int flag1=0;
 
            while(c!=a && flag1==0)
            {
                if(flag[c]==0 && c<n)
                {
                    arr2[c]=arr1[i];
                    flag[c]=1;flag1=1;
                    break;
                }
 
                else
                {
                    if(c==n)
                    {
                        c=-1;
                    }
                    
					c++;
                }
            }
        }
 
    }
 
    cout<<" Roll No. Of students are ";
    cout<<"\n";
    
	for(int j=0;j<n;j++)
    {
        cout<<arr2[j]<<" ";
    }
 
}


int main()
{
    int choice=1,ch;
    
    do
    {
        cout<<"---------------Hashing--------------\n"<<"\n";
        cout<<"1.Linear probing without replacement"<<"\n";
        cout<<"2.Linear probing with replacement"<<"\n";
        cout<<"3.Hash Table to store the rollno of students "<<"\n";
        cout<<"\nEnter your choice";
        cin>>ch;
 
        switch(ch)
        {
            case 1:
                int n1;
                cout<<"Enter the max length of hashing table: ";
                cin>>n1;
                insert_withoutreplacement(n1);
            break;
          
		    case 2:
                int n2;
                cout<<"Enter the max length of hashing table: ";
                cin>>n2;
                insert_replacement(n2);
            break;
            
			case 3:
                int n3;
                cout<<"Enter the total no. of students in the class: "<<"\n";
                cin>>n3;
                insert_student(n3);
            break;
       }
        
	    cout<<"Press 1 to continue"<<"\n";
        cin>>choice;
   } 
    while(choice==1);

    return 0;
}
