//ATIKAH BINTI DAUD(A17CS0272)
//NURAINNA FATIHA IZZUWAN (A17CS0296)
//ASSIGNMENT 2

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void getFileData(int [][12], int ,int);
float calTotalSales(int[][12], int,int);
float calBranchSales(int [][12],int ,int, float []);
float calMonthlySales(int [][12],int,int, float []);
float findHighest(float [],int );
float findLowest(float [], int);

int main()
{
	ifstream inputFile;
	inputFile.open("sales.txt");
	ofstream outputFile;
	outputFile.open("sales_report.txt",ios::app);
	
	const int row=5;
	const int col=12;
	float total,ave,sum,ave1,sum1;
	int salesData[row][col];
	float branchSales[row];
	float monthlySales[col];
	int h,h2,l,l2;
	
	getFileData(salesData,row,col);
	total=calTotalSales(salesData,row,col );
	sum=calBranchSales(salesData,row,col, branchSales);
	sum1=calMonthlySales(salesData,row,col, monthlySales);	
	h=findHighest(branchSales,row);
    l=findLowest(branchSales,row );
	h2=findHighest(monthlySales,col);
    l2=findLowest(monthlySales, col );
	outputFile<<fixed<<setprecision(2);
	
	outputFile<<"Total sales of the company throughout the year: "<<total<<endl;;
	outputFile<<"---------------------------------------------------"<<endl;
	outputFile<<"Branch Sales:"<<endl;
	outputFile<<"============="<<endl;
	
	for(int i=0;i<row;i++)
	{
		outputFile<<"Branch "<<i+1<< ": RM"<<branchSales[i]<<endl;
	}
	
	ave=sum/row;
	ave1=sum1/col;
	
	outputFile<<"Average Sales per branch: RM"<<ave<<endl;
	outputFile<<"Highest sales branch: Branch "<<h+1<<endl;
	outputFile<<"Lowest sales branch: Branch "<<l+1<<endl;
	
	outputFile<<"---------------------------------------------------"<<endl;
	outputFile<<"Monthly Sales:"<<endl;
	outputFile<<"=============="<<endl;
	
	int n=1;
	int j=0;
	
	for(int i=0;i<4;i++)
	{
			for(int k=0;k<3;k++)
			{
				outputFile<<n<< " :RM"<<monthlySales[j]<<"   " ;
	            n++;
	            j++;
			}
			outputFile<<endl;
	}
	
	outputFile<<"Average Sales per month: RM "<<ave1<<endl;
	outputFile<<"Highest sales month: Month "<<h2+1<<endl;
	outputFile<<"Lowest sales month: Month "<<l2+1<<endl;
	outputFile<<"---------------------------------------------------";
	
    cout<<"Done process data. Output file generated!";

    inputFile.close();
    outputFile.close();
}


void getFileData(int salesData[][12], int row, int col)
{
	ifstream inputFile;
	inputFile.open("sales.txt");
	ofstream outputFile;
	outputFile.open("sales_report.txt");
	
	int branch,months;
	
	if(!inputFile)
	{
		cout<<"Error!";
		exit(1);
	}
	
	for(int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			inputFile>>salesData[i][j];
		}
		inputFile.ignore();
	}
}


float calTotalSales(int salesData[][12], int row,int col )
{
	float sum=0,total;
	
	for(int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			sum=sum+salesData[i][j];
			total=sum;
		}	
	}
	return total;
}

float calBranchSales(int salesData[][12],int row,int col, float branchSales[])
{
	ofstream outputFile;
	float sum=0;
	for(int i=0;i<row;i++)
	{
		branchSales[i]=0;
		
		for (int j=0;j<col;j++)
		{
			branchSales[i]=branchSales[i]+ salesData[i][j];
		}
		sum=sum+branchSales[i];
	}
	return sum;
}
	
float calMonthlySales(int salesData[][12],int row,int col, float monthlySales[])	
    {
		ofstream outputFile;
		float sum1=0;
		for (int j=0; j<col;j++)
		{
			monthlySales[j]=0;
			
			for (int i=0;i<row;i++)
			{
				monthlySales[j]=monthlySales[j]+ salesData[i][j];
			}
			sum1=sum1+monthlySales[j];
	    }
	    return sum1;
    }


float findHighest(float sales[], int x)
{
	int high=0,h;
	
	for (int i=0;i<x;i++)
	{
		if (sales[i]>high)
		{
			high= sales[i];
			h=i;
		}
	}
	return h;
}

float findLowest(float sales1[],int x )
{
	int low=400000,l,lowest;
	
	for (int i=0;i<x;i++)
	{
		if (sales1[i]<low)
		{
			low= sales1[i];
			l=i;
		}
	}
	return l;
}


