#include<iostream>
#include"box.h"
using namespace std;
void sortArray(Box* bptr, int size)
{
	Box temp=bptr[0];
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (bptr[i].getvolume() > bptr[j].getvolume())
			{
				temp = bptr[i];
				bptr[i] = bptr[j];
				bptr[j] = temp;
			
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << bptr[i].getvolume();
		cout << "\t";
	}

}
int main()
{
	
	int size;
	cout << "Enter the size of array : ";
	cin >> size;
	Box *bptr = new Box[size];
 for (int i = 0; i < size; i++)
	{
		int le;
		cout << "Enter of length of box " << i + 1 << " : ";
		cin >> le;
		bptr[i].setlength(le);
		int w;
		cout << "Enter the width of box " << i + 1 << " : ";
		cin >> w;
		bptr[i].setwidth(w);
		int h;
		cout << "Enter the height of box " << i + 1 << " : ";
		cin >> h;
		bptr[i].setheight(h);

	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Volume of box " << i + 1 << " : ";
		cout << bptr[i].getvolume() << endl;
		cout << endl;
	}
	cout << endl;
	
	cout << " Sorted array in ascending order :   ";
	sortArray(bptr, size);
	cout << endl;
	delete[]bptr;
	return 0;
	
	
}

	