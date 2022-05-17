#include <iostream>
#include <clocale>
#include<cstdlib>
#include<ctime>
using namespace std;

//int count=2;
int c[10][10] ={{0,0,0,0,0,0,0,0,0,0},
           {0,1,0,0,0,0,0,0,1,0},
		   {0,0,0,0,1,1,1,0,1,0},
           {0,0,0,0,1,1,1,0,1,0},
		   {0,0,0,0,1,1,1,0,1,0},
           {0,0,0,0,0,0,0,0,1,0},
		   {0,1,0,0,0,1,1,1,1,0},
           {0,1,1,1,0,0,0,0,0,0}, 
		   {0,0,0,1,1,1,0,0,0,0},
           {0,0,0,0,0,0,0,0,0,0 }
		   };           

int num=1;

int vivod (int kol,int mas[10][10],int count,int num){
	int n=0;

	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			if (mas[i][j]==kol){
				n++;
				if(n==1)  
					cout<<"\nкординаты:";
				cout<<i<<":"<<j<<" ";
			}
		}
	}
	if(n!=0)
		cout<<"\n"<<num<<" остров: "<<n<<endl;
	//return vivod(kol++,mas,count,num++);
	return n;
}


 void change(int k,int l,int mas[10][10]){
	 for (int i=0;i<10;i++){
		 for (int j=0;j<10;j++){
			 if (mas[i][j]==k)
				mas[i][j]=l; 
		 }
	 }
}

bool backward (int i,int j,int mas[10][10])
{
	if (mas[i][j-1]>1){
		if (j==0)
			return false;
		else{
			mas[i][j]=mas[i][j-1];
			return true;
		}
	}
    return false;
}



bool up (int i,int j,int mas[10][10])
{
	if (mas[i-1][j]>1){
		//c[i-1][j]=count;
		mas[i][j]=mas[i-1][j];
		return true;
	}
	return false;
}

int down (int mas[10][10]){
	int k,l;
	for (int i=0;i<10;i++){
		for (int j=1;j<10;j++){
			if(mas[i][j-1]>1 && mas[i][j]>1){
				if (mas[i][j-1]==mas[i][j])	{
					continue;
				}else {
					k=mas[i][j];
					l=mas[i][j-1];
					//cout<<k<<l;
					change(k,l,mas);
				}
			}else
				continue;
		}
	}
	return 0;
}

int first(int mas[10][10]){
	for (int i=0;i<10;i++){
		for (int j=0; j<10;j++){
			if (mas[i][j]==1){
				//cout<<"\n\n"<<i<<j<<"\n\n";
				mas[i][j]=2;
				return 0;
			}
		}
	}
	cout<<"\nkarta empty";
}



void random(int b[10][10])
{
	srand((unsigned)time(0));
	for (int i=0;i<10;i++){
		cout<<endl;
		for (int j=0;j<10;j++){
			b[i][j] = rand()%2;
			cout<<b[i][j];
		}
	}
}

void zadom(int mas[10][10])
{
	for (int i=0;i<10;i++){
		cout<<endl;
		for (int j=0;j<10;j++){
			cout<<mas[i][j];
		}
	}
}

void zapis2(int mas[10][10],int count)
{
	for (int i=0;i<10;i++){
		for (int j=0; j<10;j++){
			if (mas [i][j]==1){
				//if(eniq(i,j,mas,count)==true){continue;} 
			if((up(i,j,mas)==true) || (backward(i,j,mas)==true)){
				continue;
			}
			mas[i][j]=++count;
			}
		}
	}
	down(mas);
	//backward1();
	cout<<endl<<endl;
	//zadom(mas);
	//int kol=2;
	for(int q=0,kol=2;q<count-1;q++,kol++){
		if (vivod(kol,mas,count,num)!=0)
			num++;
	}
}
	
int main(){
	setlocale(0,"");
	int way,count=2;
	cout<<"выберете вариант\nвариант 2: матрица содается рендомна\nвариант 3: используется матрица заданная в программе"<<endl;
	cout << "введите вариант: ";
	cin>>way;
	switch (way){
		case 2:{
			int bas[10][10];
			random(bas);
			first(bas);
			zapis2(bas,count);
			break;
		}
		case 3:{
			zadom(c);
			first(c);
			zapis2(c,count);
			//cout<<sizeof();
			break;
		}
		default:
			cout<<"такого варианта нет\n";	
	}
	system("pause");
}
