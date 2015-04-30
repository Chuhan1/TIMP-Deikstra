/**
   *@file 123.cpp
   *@version 1.1
   *@title Release algoritym Deikstra
   */
#include<iostream>
using namespace std;
/**
	*@func ������� ���������� ������� ��������
	*@param **A - ���������� ��������� �� ������� ���������
	*@param st - ���������� ��������� (���������) ����
	*@param N - ���������� ����������� �������
	*/
void Deikstra(int** A, int st, int N)
{
	
int *rast= new int[N], count, index, i, u, m=st+1;
bool *posesh= new bool[N];
for (i=0; i<N; i++)
{
 rast[i]=INT_MAX; posesh[i]=false;/// �������� ����������� � ������ "�������������" � ����� �� ��� ��� �� ����������
}
 rast[st]=0;/// ����� 0 ��� ���������� ����
for (count=0; count<N-1; count++)/// �������� ���� ����������� �������� ��������
{
int min=INT_MAX;
for (i=0; i<N; i++)
if (!posesh[i] && rast[i]<=min)
{
 min=rast[i]; index=i;
}
 u=index;
 posesh[u]=true;
for (i=0; i<N; i++)
if (!posesh[i] && A[u][i] && rast[u]!=INT_MAX &&
 rast[u]+A[u][i]<rast[i])
 rast[i]=rast[u]+A[u][i];
}
cout<<"Minimalnoe rasstojanie puti iz nachalnoi vershini do ostalnich:"<<endl;
for (i=0; i<N; i++) if (rast[i]!=INT_MAX)
cout<<"iz "<<m<<" v "<<i+1<<" = "<<rast[i]<<endl;
else cout<<m<<" v "<<i+1<<" = "<<"Marshrut nedostupen"<<endl;
}

/**
	*@brief �������� �������� - �������� �� ������, ����������� ������������� ������ �. ��������� � 1959 ����. ������� ���������� ���� �� ����� �� ������ ����� �� ���� ���������.
		��������� ��������� ��������, ������� �������� ���������� �����, ����� ����������� ������� ��������� � ���������� ����, ��� ������� ����� �������� ����������� ���������� � ������� ������.


*/
void main()
{
	cout<<"Algoritm Deikstra"<<endl;
	int uzel;
	int N;
	cout<<"Vvedite kolichestvo uzlov: ";
	cin>>N;
	int **A= new int*[N];
	for(int i=0;i<N;i++)
		{
			A[i]= new int[N];
		}
	cout<<"Pravila vvoda:\n 1. Vvodite rasstojanie ot odnogo uzla k drugomu\n 2. Esli ne sushestvuet puti to vvodite 0\n 3. Esli mojno idti ot uzla 'a' k 'b' b obratno to vvodite pri zadanii rasstojania v dvuch sluchajach odinnakovoe rasstojanie"<<endl;
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i==j)
				{
					cout<<"Rasstojanie iz uzla "<<i+1<<" v "<<j+1<<" = 0";
					A[i][j]=0;
					cout<<endl;
				}
				else
				{
				cout<<"Rasstojanie iz uzla "<<i+1<<" v "<<j+1<<" = ";
				cin>>A[i][j];
				}
				
			}
			cout<<endl;
		}
	cout<<"Poluchivshajasa matriza:"<<endl;
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	cout<<"Vvedite nachalnauju vershinu - "; cin>>uzel;
 Deikstra(A, uzel-1, N);
 return;
}

