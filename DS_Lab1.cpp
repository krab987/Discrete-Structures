#include <iostream>
#include "locale.h" 
#include <cmath>
#include <math.h>


using namespace std;

	bool first (bool  a, double &x, double &y){
		
		a=(x<=2 && x>=0 && y<=2 && y>=0 && (x*x + y*y)<=1);
		
		return a;
	}
	bool second (bool  b, double &x, double &y){
		
		b=(x>=-2 && x<=0 && y<=2 && y>=0 && (x*x + y*y)>=1);
		
		return b;
	}
	bool third (bool  c, double &x, double &y){
		
		c=(x>=-2 && x<=0 && y>=-2 && y<=0 && (x*x + y*y)<=1);
		
		return c;
	}
	bool fourth (bool  d, double &x, double &y){
		
		d=(x<=2 && x>=0 && y>=-2 && y<=0 && (x*x + y*y)>=1) ;
		
		return d;
	}

int main()
{
	setlocale(LC_ALL, "Russian"); 
	
	double xx,yy; 
	bool res, aa,bb,cc,dd;
	bool povtor;
	
	do{
	cout<<"������� �\n";	
	cin>>xx;
	cout<<"������� �\n";
	cin>>yy;
	
	// ���� ��� � ���������� �� ������������ ��������� : 
	
	res=( 
	first(aa,xx,yy) || //��� ������
	second(bb,xx,yy) ||  //������
	third(cc,xx,yy) ||  //������ 
	fourth(dd,xx,yy)) ; //�� � ���������
	
	if(res==1)
		cout<<"����� ������ � �������"<<endl;
	else
		cout<<"����� �� ������ � �������"<<endl;
	
	cout<<"���������? (1 - ��, 0 - ���)\n";
	cin>>povtor;
	}while(povtor==1);
	
	
return 0;
}
