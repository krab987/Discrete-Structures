#include <iostream>
#include "locale.h" 
#include <time.h> 
#include <limits>
#include <cmath> 
#include <stdlib.h> 
#define cons 100

using namespace std;

void checkshort (short &x){
	
	cin>>x;	
	do{
		
		
		if (fabs(x)>SHRT_MAX || fabs(x)<SHRT_MIN) {
			cout<<"Ошибка. Не входит в диапазон \n";
		} 
		
	}while(fabs(x)>SHRT_MAX || fabs(x)<SHRT_MIN);
	
	return ;
}

bool checkbool (bool y){
	
	int x;
	x=y;
	do{
		
		cin>>x;	

		if (x>1 || x<0) {
			cout<<"Ошибка. Введите 0 или 1 \n";
		} 
		
	}while(x>1 || x<0);
	
	return x;
}

void input(short A[][cons], short x){
	
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			cout<< "A["<<i<<"]["<<j<<"]"<<" = ";
			A[i][j] = checkbool(A[i][j]);	
		}
         
	}     
 return; 
}

void output(short A[][cons], short x){
	
	cout<<"Output elements: \n";
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 cout<<A[i][j]<<"\t";
			
		}
        cout<<"\n";
	} 
	return;
}

void way(short A[][cons], short x){
		
	short b[cons][cons], c[cons][cons], s;
	short n=x; 
	short count, step=1;
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 b[i][j]=A[i][j];
		}
         
	} 
	
	do{
	count=0;	
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 c[i][j] = b[i][j];
		}
         
	} 	
		
	for (int i=0;i<x;i++){
		
		for (int p=0;p<x;p++){
			
			s=0;	
			
			for (int j=0;j<x;j++){
	
				s += c[i][j] * c[j][p];
			}
			if (s>0)
			b[i][p] = 1;
			else
			b[i][p] = 0;
		}	
	}
	
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 if(c[i][j] != b[i][j]){
			 	count++;
			 }
		}
         
	} 	
	
	step=step*2;	
	cout<<"||B||^"<<step<<endl;
	output(b,n);
	}while(count!=0);
	
	cout<<"Значит вот мы и получили ответ\n";
	output(b,n);
	
	return;
}

void ways(short A[][cons], short x){
			
	short b[cons][cons],c[cons][cons], s;
	short n=x, k;
	short count=1;
	
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			b[i][j] = A[i][j];	
		}   
	} 
	
	cout<<"Введите k - довжину\n";
	checkshort(k);
	
	do{
		
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 c[i][j] = b[i][j];
		}
         
	} 	
		
	for (int i=0;i<x;i++){
		
		for (int p=0;p<x;p++){
			
			s=0;	
			
			for (int j=0;j<x;j++){
	
				s += c[i][j] * A[j][p];
			}
			if (s>0)
			b[i][p] = 1;
			else
			b[i][p] = 0;
		}	
	}
	
	
	count++;	
	cout<<"k = "<<count<<endl;
	output(b,n);
	
	}while(count!=k);
		
	return;
	
}

int main(){
	setlocale(LC_ALL, "Russian"); 

	short a[cons][cons];     
	short n; 
	bool ch; 
 	
    do{         

		cout<<"Размер = ";         
    	checkshort(n);
		   
 	}while (n<=0);    
 	
	 input(a,n);
	 output(a,n);
	  
	cout<<"Выберите: \n0 - Вывести матрицу существования путей между парами вершин графа \n1 - Вывести матрицу количества путей между парами вершин графа длиной k: \n";
	ch = checkbool (ch); 
 	if (ch==0){
 		
 		way(a,n);
	 }
	 else{
	 	ways(a,n);
	 }
     
         
 return 0;  
	
}
