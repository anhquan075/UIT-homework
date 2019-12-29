#include <iostream>
#include <vector>


using namespace std;



void Import_Matrix(vector< vector <int> > &vec,int n,int m)
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			cin>>vec.at(i).at(j);
		}
	}
}


void Export_Matrix(vector< vector <int> > &vec,int n,int m)
{
	int rows = vec.size();
	int columns = vec.at(0).size();
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << vec.at(i).at(j);
		}
		cout << endl;
	}
}


int main()
{
	vector<vector<int> >vec;
	int n,m;
	cin>>n>>m;
	Import_Matrix(vec,n,m);
	Export_Matrix(vec,n,m);
	return 0;
}
