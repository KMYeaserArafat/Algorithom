/*
   //Selection sort, Bubble Sort, Insertion short ;
   // show time : 
*/

#include<ctime>
#include<iostream>
using namespace std;

//Selection Sort : 
void Selection(int Array2[], int power){
    int midIntex, temp;
    for(int i=0; i<power-1; i++){
       midIntex = i;
        for(int j=i+1; j<power; j++){
             if(Array2[j]>Array2[midIntex]){
                midIntex = j;
             }
             temp = Array2[midIntex];
             Array2[midIntex] = Array2[i];
             Array2[i]=temp;
        }
    }
}

//Insertion Sort : 
void Insertion(int Array2[],int power){
    int j,key;
    for(int i=0; i<power; i++){
        key = Array2[i];
        j = i-1;
        if(j>=0 && Array2[j]>key){
            Array2[j+1] = Array2[j];
        }
       Array2[j+1] = key;
    }
}


//Bubble Sort : 
void Bubble(int Array2[],int power){
    int temp;
    for(int a=0; a<power; a++){
        for(int b=a+1; b<power; b++){
            if(Array2[a]>Array2[b]){
                temp = Array2[a];
                Array2[a]=Array2[b];
                Array2[b]=temp;
            }
        }
    }
}




//Insert Data :
void Insert_Array(int Array2[],int power){
    for(int a=0; a<power; a++){
        cin>>Array2[a];
    }
}

//print Data : 
void Print_Array(int Array2[],int power){
    for(int b=0; b<power; b++){
        cout<<Array2[b]<<" ";
    }
    cout<<endl;
}

int main(){

   int power;
   cout<<"How much data wantto take : ";
   cin>>power;
   int Array2[power];


   clock_t start;
   clock_t end;
   double timetakenBubbleSort;
   double timetakenSelectionSort; 
   double timetakenInsertionSort;

 

   cout<<"Insert Data : ";
   Insert_Array(Array2,power);
   cout<<"Original Data : ";
   Print_Array(Array2,power);

//Selection sort : 
   cout<<"Selection Data : ";
   start = clock();
   Selection(Array2,power);
   end = clock();
   Print_Array(Array2,power);
   timetakenSelectionSort = (end - start) / (double)CLOCKS_PER_SEC;
   cout<<"Selection Time : "<<timetakenSelectionSort<<endl;


 //Insertion Sort :   
   cout<<"Insertion Data : ";
   start = clock();
   Insertion(Array2,power);
   end = clock();
   Print_Array(Array2,power);
   timetakenInsertionSort = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Intertion Time : "<<timetakenInsertionSort<<endl;



//Bubble Sort : 
   cout<<"Bubble Data : ";
   start = clock();
   Bubble(Array2,power);
   Print_Array(Array2,power);
   end = clock();
    timetakenBubbleSort = (end-start)/(double)CLOCKS_PER_SEC;
     cout<<"Bubble Time : "<<timetakenBubbleSort<<endl;


    return 0;
}