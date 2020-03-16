//NI JIA YEE PUNYA

#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	const int size=15;
	const int size2=10;
	char answerScheme[size];
	char studentAnswers[size2][size];
	string studentName[size2];
	int mark;
	int markingResult[size2];
	int highest=0,lowest=15;
	float totalmark=0;
	float average;
	
	ifstream infile;     //ni declare open file
	ofstream outfile;
	infile.open("answer_scheme.txt");  //ni open file
	outfile.open("output.txt");  //ni dia keluar dekat output
	
	for(int i=0;i<size;i++)
	{
		infile>>answerScheme[i];    //ni dia masukkan dalam array
	}
	
	infile.close();                //dia tutup file
	infile.open("student_answers.txt");  //ni bukak file studentanswers pulak
	outfile<<endl;                                                                        //kenapa yang ni takde buat outfile?
	
	for(int i=0;i<size2;i++)  //ni dia nak masukkan dalam array,i=name
	{
		getline(infile,studentName[i]);//ni nak masukkan array yang nama student shj (1D)
		
		for(int j=0;j<size;j++) //ni dia nak masukkan dalam array,j=answers
		{
			infile>>studentAnswers[i][j];//ni masukkan array yg answers je,tapi ada dua en,so 2D,dia ada row & column.
		}
		infile.ignore();  //untuk ignore yang name tu
	}
	
    //compare the answer
	cout<<left<<setw(16)<<"Students"<<left<<setw(5)<<"Mark"<<endl;  //cout apa yang patut
	cout<<left<<setw(16)<<"--------"<<left<<setw(5)<<"----"<<endl;

	for(int i=0;i<size2;i++)    //ni dia nak compare antara students answers dengan answer scheme,loop ini untuk name
	{
		markingResult[i]=0;   //set kepada 0 supaya next student dia akan kira dari 0,masuk name 1,mark jadi 0,next name,mark jadi 0 balik.
		
		for(int j=0;j<size;j++) //ni untuk answers untuk each student,tengah compare lah ni
		{
			if(answerScheme[j]==studentAnswers[i][j]) //kalau answer sama dengan scheme
			{
				mark=1;   //mark jadi 1
			}
			else
			{
				mark=0;   //atau mark jadi 0
			}
			markingResult[i]=markingResult[i]+mark;	//ni still dalam loop untuk answers tu
		}
		cout<<left<<setw(16)<<studentName[i]<<left<<setw(5)<<markingResult[i]<<endl;
	}
	
	
	for(int i=0;i<size2;i++)// nak keluarkan yang tinggi dengan yg low
	{	
		if(markingResult[i]>highest)
		{
			highest=markingResult[i];
		}
		if(markingResult[i]<lowest)
		{
			lowest=markingResult[i];
		}
		
	}
	cout<<"Highest mark: "<<highest<<endl;
	cout<<"Lowest mark: "<<lowest<<endl;

	//average
	for(int i=0;i<size2;i++)
	{
		totalmark=totalmark+markingResult[i];
	}
	
	average=totalmark/10;
	cout<<"Average mark: "<<average;
	
	outfile.close();
		
	return 0;
}
