#include <iostream>
# include <Windows.h>
using namespace std;
int p=1,k=0,h=0;
void vvod(int x,int y,int **mas)
{
for (int i=0;i<x;i++)
{for (int j=0; j<y;j++)
{cout<<"������� �������� ������� 1, ���� ������ ���������� ���� � 0,���� ����"<<endl;
	cin>> mas[i][j];
}}
}
void proverka(int x,int y,int **mas)
{int m[100],l[100];
	for (int i=0;i<x;i++)
{for (int j=0; j<y;j++)
{if (mas [i][j]==1)
{	cout<<"���������� �����:"<<i<<";"<<j<<endl;
	{m[k]=i;
	k++;
	l[h]=j;
	h++;
	}
	}
	}}
	for(int i=0;i<=k;i++)
		cout<<m[i]<<endl;
}

void main()
{
	SetConsoleCP(1251);
SetConsoleOutputCP(1251);
	int x,y;
cout<<"������� ���������� �����"<<endl;
cin>>x;
cout<<"������� ���������� ��������"<<endl;
cin>>y;
int** mas=new int *[x];
for (int i=0;i<x;i++)
mas[i]=new int[y];
vvod(x,y,mas);
proverka(x,y,mas);
system("pause");
}

