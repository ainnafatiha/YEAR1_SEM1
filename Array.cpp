#include <iostream>
using namespace std;

int N=5;
int N2=10;

int main()
{
    int array1[N2], array2[N], array3[N], i, even=0, odd=0;

    cout <<"Please enter 5 intergers for Array 2"<< endl << endl;
    for (i=0; i<N; i++)
    {
        cout << "Please enter an integer: ";
        cin >> array2[i];
    }
	
	cout<<endl;
	
    cout << "Please enter 5 intergers for Array 3" << endl << endl;
    for (i=0; i<N; i++)
    {
        cout << "Please enter an integer: ";
        cin >> array3[i];
    }

    for(int k=0; k<10; k++)
	{
		if(k%2==0)
		{
			array1[k]=array3[even];
			even++;
		}
		else {
			array1[k]=array2[odd];
			odd++;
		}
		cout<<endl;
		cout<<" "<<array1[k]<<" ";
	}

	
    return 0;
}
