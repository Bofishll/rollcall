#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int C = 0, T = 0, all[450][20];
void out(int N);

int main()
{
	int i, j;
	float E;

	srand(time(NULL));

	ifstream fin;
	fin.open("D:\\�������.txt");

	for (i = 0; i < 450; i++)
	{
		char buf[50];
		fin.getline(buf, 50);

		for (j = 0; j < 20; j++)
		{
			all[i][j] = (int)buf[j] - 48;
		}

	}
	fin.close();

	//	for(i = 0; i < 450; i++)
	//	{
	//		cout<<"ѧ��"<<"["<<i<<"] ";
	//		for(j = 0; j < 20; j++)
	//			cout<<all[i][j]<<" ";
	//		cout<<endl;
	//	}

	for (i = 0; i < 5; i++)
	{
		out(i + 1);
	}

	E = 1.0 * C / T;
	cout << "E = " << E << endl;

	return 0;
}

void out(int N)
{
	cout << "��" << N << "�ſ�" << endl;

	int All[90][20], temp_poor[90] = { 0 }, now_poor[90] = { 0 };
	int i, j, k, cnt, correct, total;

	for (i = 0, k = (N - 1) * 90; i < 90 && k < N * 90; i++, k++)
	{
		for (j = 0; j < 20; j++)
			All[i][j] = all[k][j];
	}

	//	for(i = 0; i < 90; i++)
	//	{
	//		cout<<"ѧ��"<<"["<<i<<"] ";
	//		for(j = 0; j < 20; j++)
	//			cout<<All[i][j]<<" ";
	//		cout<<endl;
	//	}

	k = 0, cnt = 0, correct = 0, total = 0;
	for (j = 0; j < 20; j++)
	{
		if (j < 5)//ǰ5�γ�� 
		{
			vector<int> temp;
			for (int i = 0; i < 90; ++i)
			{
				temp.push_back(i);
			}
			random_shuffle(temp.begin(), temp.end());

			cout << "��" << j + 1 << "�ڿ� " << endl;
			for (i = 0; i < 9; i++)
			{
				if (All[temp[i]][j] == 1)
				{
					temp_poor[temp[i]]++;
					correct++;
				}
				total++;

				cout << temp[i] << " ";
			}cout << endl;

		}
		else
		{
				//				cout<<"�ݶ�����"<<endl;
				//				for(i = 0; i < 90; i++)
				//				{
				//					if(temp_poor[i] > 0)
				//						cout<<i<<"����"<<temp_poor[i]<<"��"<<" "; 
				//				}cout<<endl;

				for (i = 0; i < 90; i++)
				{
					if (temp_poor[i] > 0)
					{
						if (cnt == 5)//5�ν���һ���޳�
						{
							if (temp_poor[i] == 1)
								temp_poor[i] = 0;
						}
						else
						{
							int flag = 0;
							for (int l = 0; l < k; l++)
							{
								if (now_poor[l] == i)
								{
									flag = 1;
									break;
								}
							}
							if (flag) continue;
							now_poor[k] = i;
							k++;//ȷ��Ϊ������¼ 
						}
					}
				}
				


				//				cout<<"�����������"<<k<<endl;
				//	    		for(i = 0; i < k; i++)
				//	    		{ 
				//					cout<<now_poor[i]<<" ";	
				//				}cout<<endl;
		
	


				cout << "��" << j + 1 << "�ڿ� " << endl;
				for (i = 0; i < k; i++)
				{
					if (All[now_poor[i]][j] == 1)
					{
						temp_poor[now_poor[i]]++;
						correct++;
					}
					total++;

					cout << now_poor[i] << " ";
				}

				if(k<8)
				{
					for(i = 0; i < 8-k; i++)
					{
						int temp = 0 + rand() % (89 - 0 + 1);
						if (All[temp][j] == 1)//���ڿ�δ�������ڲ�����ѡ�� 
						{
							int flag = 0;
							for(int l = 0; l < k; l++)
							{
								if(now_poor[l] == temp)
								{
									flag = 1;
									break;
								}
							}
							if(flag) continue;
								temp_poor[temp]++; 
								correct++;
								total++;
								cout<<i<<" ";
						}
						
					} 
				}
			cout << endl;
			cnt++;
		}

	}
	
	C += correct;
	T += total;
	cout << endl;
	return;
	//	cout<<correct<<" "<<total<<endl;
}

