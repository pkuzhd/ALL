//****************************
//*例程：距离排序           **
//*作者：pkuzhd             **
//*时间：2017.10.15         **
//****************************

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 结构体点
struct point
{
	int x, y, z;
};

// 结构体 储存点和距离
struct pDistance
{
	point point1, point2;
	double ds;
};

double calcDis(const point &point1, const point &point2)
{
	double _=(point1.x-point2.x)*(point1.x-point2.x)
	       +(point1.y-point2.y)*(point1.y-point2.y)
	       +(point1.z-point2.z)*(point1.z-point2.z);
	return sqrt(_);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	point *szP = new point[n];
	// 输入n个点
	for (int i = 0; i < n; ++i)
	{
		cin >> szP[i].x >> szP[i].y >> szP[i].z;
	}
	pDistance *szD = new pDistance[(n-1)*n/2];
	int num=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			szD[num].point1 = szP[i];
			szD[num].point2 = szP[j];
			szD[num].ds = calcDis(szP[i], szP[j]);
			++num;
		}
	}
	for (int i = 0; i < (n-1)*n/2; ++i)
	{
		for (int j = 0; j < (n-1)*n/2-i-1; ++j)
		{
			if (szD[j].ds < szD[j+1].ds)
			{
				pDistance temp = szD[j];
				szD[j] = szD[j+1];
				szD[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < (n-1)*n/2; ++i)
	{
		cout << "(" << szD[i].point1.x
		     << "," << szD[i].point1.y
		     << "," << szD[i].point1.z
		     << ")-"
		     << "(" << szD[i].point2.x
		     << "," << szD[i].point2.y
		     << "," << szD[i].point2.z
		     << ")=" 
		     << setiosflags(ios::fixed)
		     << setprecision(2)
		     << szD[i].ds << endl;
	}

	delete [] szP;
	delete [] szD;
	return 0;
}
