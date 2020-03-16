#include<iostream>
#include<cmath>
using namespace std;
double distanceBetweenTwoPoint(double x1, double y1, double x2, double y2);

int main ()
{
	double x1, y1, x2, y2;
	double answer;

cout<<"Enter x1 and y1: \n";
cin>>x1>>y1;
cout<<endl;
cout<<"Enter x2 and y2: \n";
cin>>x2>>y2;
cout<<endl;
answer=distanceBetweenTwoPoint(x1, y1, x2, y2);
cout<<"The answer is: \n"<<answer;

}

double distanceBetweenTwoPoint(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
