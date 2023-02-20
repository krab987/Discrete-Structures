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
		int min = i;

		for (int j = i + 1; j < x; j++)
			{
			if (A[j] < A[min]) min = j;
			}
 		
		swap(A[i], A[min]);
		swap(B[i], B[min]);

	}
	
	for(int i=0; i < x; i++){
		A[i]=B[i];
	}	
	
}

void find(short b[cons], short a[][cons], short x ){
	
	// используеться поиск вдлину
    
    short check[cons], derevo[cons];
    int count_b = 0,count_check = 1, count_derevo = 1, kol=1, first;
	
	for(int i=0;i<x;i++){
		check[i] = 0;
	}
    
    do{
    	first = b[count_b];
    	check[b[count_b]] = 1;
    	derevo[0] = b[count_b]; 
    	
    	for(int i=0;i<x;i++){
    	
    		if(a[first][i] == 1 && check[i] == 0){
    		
    			derevo[count_derevo] = i;
    			count_derevo++;
    			
    			check[i] = 1;
				first = i;
    			i = 0;
    			
    			kol++;
    			
			}
    	
		}
		
		if(check[x-1] == 0){
			count_b++;
		}
		
		cout<<"Пройденные вершины:"<<endl;
		output(derevo,x); 	
		cout<<"Количество пройденых вершин:\t"<<kol<<endl;	
	}while(check[x-1] == 0);
    		 
    cout<<"Конец работы программы: все деревья найдены"<<endl;
}

	
int main(){ 
	setlocale(LC_ALL, "Russian"); 

	short mas[cons], matrix[cons][cons];     
	short n; 
 	
 	int count=0;
 		
 	do{         

		cout<<"Размер = ";         
   		checkshort(n);
		   
 	}while (n<=0);    
 	
	cout<<"Введите матрицу связей графа \n";
 	input_matrix(matrix,n);
 	output_matrix(matrix,n);
 	
 	cout<<"Сортированные степени вершин графа по возрастанию к-ва связей (индексы)\n";

 	creation_mas(matrix,mas,n);
	sort(mas,n);
	output(mas,n);

	find(mas,matrix,n);


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

