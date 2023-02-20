#include <iostream>
#include "locale.h" 
#include <time.h> 
#include <limits>
#include <cmath> 
#include <stdlib.h> 
#define cons 100

using namespace std;

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

short checkshort (short &x){
	
	cin>>x;	
	do{
		
		
		if (fabs(x)>SHRT_MAX || fabs(x)<SHRT_MIN) {
			cout<<"Ошибка. Не входит в диапазон \n";
		} 
		
	}while(fabs(x)>SHRT_MAX || fabs(x)<SHRT_MIN);
	
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

void output_mas (short B[cons], short x){

	cout<<endl<<"Порядкова фуннкция:"<<endl;

	for(int i=0;i<(x-1);i++){
		if(B[i]>=10){
			cout<<"O(X"<<B[i]/10+1<<") = "<<i<<endl;	
			cout<<"O(X"<<B[i]%10+1<<") = "<<i<<endl;
		}
		else{
			cout<<"O(X"<<B[i]+1<<") = "<<i<<endl;
		}
		
	}
	
}

void way( short b[cons], short A[cons][cons], short x){
		
	short c[cons][cons];
	short s=0, count=0, count1=0, count2=0, count3=0,count4=0, fix;
	short g=99;
	
	for(int i=0; i<x;i++){
		for(int j=0;j<x;j++){

			c[i][j] = A[i][j];

			}
		}
		
		for(int i=0;i<x;i++){
			b[i]=98;
		}
		
	do{
		count4=0;
		for (int j=0;j<x;j++){
		
			for (int i=0;i<x;i++){
			
				s += c[i][j];
			}
			

				
			if(s==0){
				count1=0;
				for(int p=0;p<x;p++){
					
					if(b[p]== j){
						count1++;
					}		
				}
				
				if(count1==0){
					
				count4++;
				if(count4==1){
					
					b[count2]=j;
					count2++;	
				}
				if(count4==2){
					
					b[count2]=j;
					count2++;
					fix=j;
				}	
	
				
								
				}

			}
			
	 		s=0;  
	 	
			}
			
			for(int i=0;i<x;i++){
				
				for(int j=0;j<x;j++){

				c[b[i]][j] = 0;

				}
			}	
		
		
		count++;
		count3++;
		output(c,x);

	}while(count<6);
	

		b[fix-3]=b[fix-3]*10+b[fix-2];
		
		for(int i=fix-2;i<x;i++){
			b[i]=b[i+1];
		}
	


	return;
}


int main(){
	setlocale(LC_ALL, "Russian"); 

	short a[cons][cons];     
	short res[cons], n; 
 	
    do{         

		cout<<"Размер = ";         
    	checkshort(n);
		   
 	}while (n<=0);    
 	
 	cout<<"Введите матрицу смежности \n";
 	
	 input(a,n);
	 output(a,n);
	  
	  cout<<endl<<"Зануляем строки матрицы"<<endl<<endl;
	  
 	way(res,a,n);
   output_mas(res,n) ;
         
 return 0;  
	
}

