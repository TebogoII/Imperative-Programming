#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{	
	string line;
	int y=0;
	ifstream datafile ("data.txt");
	ifstream rowCount ("data.txt");

	//count rows
	if (rowCount.is_open())
	{
		while(rowCount.good())
		{
			y++;
			getline(rowCount,line);
		}
	}
	rowCount.close();

	//Allocation
	string** a= new string*[y];	
	int *arrCol= new int[y];
	//cout<< "there is "<< y << " lists" << endl<<endl;
	y=0;
	if (datafile.is_open())
	{
		while(datafile.good())
		{
			getline(datafile,line);
			stringstream ss(line);
			int x=0;
			string sub;
			while(ss.good())
			{
				x++;
				getline(ss,sub,',');
				if (x==1)
				{
					//cout<< sub<< " is the ID" << endl;
				}
				//cout<< sub << endl;
			}
			arrCol[y]=x;
			//cout<< "there is "<< x << " elements" << endl;
			
			//cout<< line << endl<<endl;

			a[y]=new string[x];
			int col=0;
			stringstream sss(line);
			while(sss.good())
			{
				getline(sss,sub,',');
				a[y][col]=sub;
				col++;
			}
			y++;
		}
		datafile.close();
	}
	else cout << "can't open"<<endl;

	int ro, co=0;
	//cout << "enter row"<<endl;
	//cin>>ro;
	//cout << "enter col"<<endl;
	//cin>>co;
	//cout << a[ro][co]<< " is your element"<<endl;
	int max=0;
	//cout <<a[i][0]<<endl; 
	for (int v = 0; v < y; ++v)
	{
		if (max<stoi(a[v][0]))
		{
			max=stoi(a[v][0]);
		}
	}
	//cout<<max<<endl;

	for (int i = 0; i < max+1; ++i)
	{
		for (int b = 0; b < y; ++b)
		{
			if (stoi(a[b][0])==i)
			{
				//cout<<a[b][0]<<"  "<<arrCol[b]<<endl;
				for (int v = 0; v < arrCol[b]; ++v)
				{
					if (v==0)
					{

					}
					else
					{
						cout<<",";
					}
					cout<<a[b][v];
				}
				cout<<endl;
			}	
		}
	}


	//deallocation
	for(int row=0;row<y;row++)
	{
		delete [] a[row];
	}
	delete [] a;
	delete [] arrCol;
	return 0;


}
