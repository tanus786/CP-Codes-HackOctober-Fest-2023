#include <iostream>
using namespace std;

void merged_array(int a[], int m, int n, int b[])
{
    int i,j,k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
        // else
        // {
        //     c[k] = a[i];
        //     i++;
        //     j++;
        //     k++;
        // }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    // print

    cout<<"Merged Array : ";
    for (int i = 0; i < k; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}
void union_array (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (b[j] < a[i])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else
        {   c[k]=a[i];
            i++;
            j++;
            k++;  
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    // print

    cout<<"Union : ";
    for (int i = 0; i < k; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}
void intersection (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            
            j++;
            
        }
        else
        {   c[k]=a[i];
            i++;
            j++;
            k++;  
        }
    }

    

    // print

    cout<<"Intersection : ";
    for (int i = 0; i < k; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}
void difference (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (b[j] < a[i])
        {
            
            j++;
            
        }
        else
        {   
            i++;
            j++;
             
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    

    // print

    cout<<"Difference : ";
    for (int i = 0; i < k; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}
void symmentric_difference (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (b[j] < a[i])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else
        {   
            i++;
            j++;
            
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    // print

    cout<<"Symmetric Difference : ";
    for (int i = 0; i < k; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    // program for union of two sets
    int a[] = {1, 3, 4, 5, 9}, b[] = {3, 4, 5, 6, 7, 8, 9, 10}, m = 5, n = 8;

    printf("\nArray 1 : \n");
    for (int i = 0; i < m; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nArray 2 : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;

    merged_array(a, m, n, b);
    union_array(a,m,n,b);
    intersection(a, m, n, b);
    difference(a,m,n,b);
    symmentric_difference(a,m,n,b);

    return 0;
}