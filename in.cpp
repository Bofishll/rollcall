#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include<string.h>

using namespace std;

int All[90][20] = {0}, Poor[8]={0}, Course[16]={0}, Nump;

class rand_poor;
class rand_course;
void rand_absent(int no);
void in(int N);

int main()
{
	int i;
	srand(time(NULL));

	for (i = 0; i < 5; i++)
	{
		in(i);
	}

	return 0;
}

class rand_poor
{//生成5-8名80%缺课学生
private:
	int num;
	int poor[8] = {};

public:
	void rp()
	{
		num = 5 + rand() % (8 - 5 + 1);

		vector<int> temp;
		for (int i = 0; i < 90; ++i)
		{
			temp.push_back(i);
		}
		random_shuffle(temp.begin(), temp.end());

		for (int i = 0; i < num; i++)
			poor[i] = temp[i];
	}

	void out()
	{
		//cout << "80%缺课学生" << endl;
		//cout << "num=" << num << endl;
		for (int i = 0; i < num; i++)
		{
			Poor[i] = poor[i];
			//cout << poor[i] << endl;
		}
		Nump = num;
	}
};

class rand_course
{//生成缺课学生单门缺课情况
private:
	int course[16] = { 0 };	//未缺课置0，缺课置1

public:
	void rc()
	{
		vector<int> temp;
		for (int i = 0; i < 20; ++i)
		{
			temp.push_back(i);
		}
		random_shuffle(temp.begin(), temp.end());

		for (int i = 0; i < 16; i++)
			course[i] = temp[i];
	}

	void out()
	{
		//			cout<<"单门缺课情况"<<endl;
		for (int i = 0; i < 16; i++)
		{
			Course[i] = course[i];
			//				cout<<course[i]<<" ";
		}
		//			cout<<endl;
	}
};

void rand_absent(int no)
{//生成意外缺席学生 
	int num;
	int absent[3] = {};

	num = 0 + rand() % (3 - 0 + 1);
	for (int i = 0; i < num; i++)
	{
		while (1)
		{
			int temp = 0 + rand() % (89 - 0 + 1);

			if (All[temp][no] == 0)
			{
				int flag = 0;
				for (int j = 0; j < Nump; j++)
				{
					if (Poor[j] == temp)
					{
						flag = 1;
						break;
					}
				}
				if (flag) continue;
				All[temp][no] = 1;
				absent[i] = temp;
				break;
			}
		}
	}

	//	cout<<"第"<<no<<"节意外缺席学生"<<num<<"人"<<endl;
	//	for (int i = 0; i < num; i++)
	//	{
	//		cout<<absent[i]<<" ";
	//	}
	//	cout<<endl;
};

void in(int N)
{
	memset(All, 0, sizeof(All));
	memset(Poor, 0, sizeof(Poor));
	memset(Course, 0, sizeof(Course));
	int i, j;

	rand_poor C1;
	C1.rp();
	C1.out();

	for (i = 0; i < Nump; i++)
	{
		//		cout<<"差生"<<"["<<Poor[i]<<"]"; 
		rand_course stu;
		stu.rc();
		stu.out();
		for (j = 0; j < 16; j++)
		{
			All[Poor[i]][Course[j]] = 1;
		}
	}

	for (j = 0; j < 20; j++)
		rand_absent(j);

	ofstream fout;
	if (N == 0)
		fout.open("D:\\到勤情况.txt");
	else
		fout.open("D:\\到勤情况.txt", ios_base::app);

	for (i = 0; i < 90; i++)
	{
		for (j = 0; j < 20; j++)
		{
			fout << All[i][j];
		}
		fout << endl;
	}
	fout.close();

	//	for(i = 0; i < 90; i++)
	//	{
	//		cout<<"学生"<<"["<<i<<"] ";
	//		for(j = 0; j < 20; j++)
	//			cout<<All[i][j]<<" ";
	//		cout<<endl;
	//	}
}
