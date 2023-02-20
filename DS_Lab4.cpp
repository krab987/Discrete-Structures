#include <iostream>
#include "locale.h" 
#include <time.h> 
#include <limits>
#include <cmath> 
#include <stdlib.h> 
#define cons 20

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


void input(short A[], short x){
	
	for (int i=0;i<x;i++){
			
			cout<< "A["<<i<<"]"<<" = ";
			A[i] = checkshort(A[i]);	
		}    
 return; 
}

void input_matrix(short A[][cons], short x){
	
	for (int i=0;i<x;i++){
	
		for (int j=0;j<x;j++){
			
			cout<< "A["<<i<<"]["<<j<<"]"<<" = ";
			A[i][j] = checkbool(A[i][j]);	
		}
         
	}     
 return; 
}


void output(short A[], short x){
	
	cout<<"Output elements: \n";
	for (int i=0;i<x;i++){
			
			 cout<<A[i]<<"\n";
			
	} 
	return;
}

void output_colours(short A[], short x){
	
	cout<<"Output elements & colors numbers: \n";
	for (int i=0;i<x;i++){
			
		cout<<"X"<<A[i] %100<<" color = "<<A[i]/100<<"\n";
	
	} 
	return;
}

void output_matrix(short A[][cons], short x){
	
	cout<<"Output elements: \n";
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 cout<<A[i][j]<<"\t";
			
		}
        cout<<"\n";
	} 
	return;
}


void creation_mas(short A[][cons], short B[], short x){
	
	int s=0;
	
	for (int i=0;i<x;i++){
		
		for (int j=0;j<x;j++){
			
			 s+=A[i][j];
			
		}
        B[i]=s;
        s=0;
	} 	
}

void sort(short A[], short x){
	
	short B[x];
	short ch;
	
	for(int i=0; i<x; i++){
		B[i]=i;
	}
		
	for (int i = 0; i < x; i++)
	{
		int max = i;

		for (int j = i + 1; j < x; j++)
			{
			if (A[j] > A[max]) max = j;
			}
 		
		swap(A[i], A[max]);
		swap(B[i], B[max]);

	}
	
	for(int i=0; i < x; i++){
		A[i]=B[i];
	}	
	
}

void kras(short b[cons], short a[][cons], short x ){
	
	int color = 100, i=0;
	short arr[cons], col[cons], i_arr=0;
	short count1 = 0;
	
	for(int j=0; j<cons; j++){
		col[j]=0;
	}
	
	do{

		int i_poch = i_arr;
		
		for(int j=0; j<x; j++){
			
			if(a[b[i]][j] == 0){
				arr[i_arr]=j+1;
				i_arr++;
				
			}
		}
		arr[i_arr]=0;		
		
		int sdvig = i_poch;
		
		do{
			for(int j=sdvig; j<i_arr; j++){
				if(a[arr[sdvig]-1][arr[j]-1] == 1){
				
					for(int p=j;p<i_arr;p++){
						
						arr[p]=arr[p+1];
					}
				}	
			}
			sdvig++;
		}while(sdvig<i_arr);
					
	
		for(int g=0; g<i_arr; g++){
			for(int j=0; j<x; j++){
			
				a[j][arr[g]-1] = 1;
			}
		}
		
			
		for(int j=i_poch; j < i_arr; j++){
			col[j] = arr[j]-1 + color;
		
		}
		
		for(int j=0; j < i_arr; j++){
			if(arr[j] <= 0) {
				i_arr=j;
			}
		}				
		
		color += 100;
		i++;	
		 				
	}while(i!=x);			
	
	for(int i=0; i<x; i++){
		b[i] = col[i];
	}
	
}


int main(){ 
	setlocale(LC_ALL, "Russian"); 

	short mas[cons], matrix[cons][cons];     
	short n; 
 	
 	int count=0;
 	while(count!=2){
 		
 		do{         

			cout<<"Размер = ";         
    		checkshort(n);
		   
 		}while (n<=0);    
 	
		cout<<"Введите матрицу связей графа \n";
 		input_matrix(matrix,n);
 		output_matrix(matrix,n);
 	
 		cout<<"Сортированные степени вершин графа (индексы)\n";

 		creation_mas(matrix,mas,n);
		sort(mas,n);
		output(mas,n);
	
		kras(mas,matrix,n);
		output_colours(mas,n); 
		
		if(count==0){
			cout<<"Хроматичне число графа: \n"<<mas[n-1]/100<<endl;
			cout<<"Выверните ваш граф\n";
		}
		else
			cout<<"Хроматичний клас графа: \n"<<mas[n-1]/100<<endl;	
		
		
		count++;
	 };

 return 0;  
	
}
/*
0
1
0
0
0
0
1
1
1
0
1
1
0
0
1
0
0
1
0
1
0
0
0
0
0
1
1
0
1
0
1
0
0
0
0
1
0
1
1
0
0
0
0
0
1
0
1
0
1
1
0
1
1
1
0
0
1
0
0
0
0
0
0
0

реберця

0
1
0
0
0
0
0
1
0
0
0
0
1
0
1
0
0
0
0
1
0
1
1
0
0
1
0
1
0
0
0
0
0
1
1
0
0
0
1
0
1
0
0
0
1
1
0
0
0
0
0
1
0
1
0
0
1
1
0
1
0
0
0
0
1
0
1
0
0
0
0
1
0
0
0
0
0
1
0
1
1
0
1
1
1
1
0
0
0
0
1
0
1
0
1
1
0
0
0
1
1
0
1
1
0
1
1
1
0
1
1
1
1
0
0
0
1
0
1
0
0
1
1
0
0
0
1
1
1
1
0
1
0
0
0
0
1
1
1
1
1
0
1
0

*/

/*
		cout<<"col\n\n";
		for(int j=0; j < x; j++){
			
			cout<<col[j]<<endl;
		
		}
				cout<<"arr new new vivod\n";
		for(int j=0; j<i_arr; j++){
			
		cout<<arr[j]-1<<endl;
		}
		cout<<"sdvig = "<<sdvig<<"    i_arr  = "<<i_arr<<endl;
				
		cout<<"arr vivod\n";
		for(int j=0; j<i_arr; j++){
			
		cout<<arr[j]-1<<endl;
		}

*/

