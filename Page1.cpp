/*
    Sorting By Asending Order, 
    Sorting By Dscending Order.
*/


#include<iostream>
#include<ctime>
using namespace std;

//Sorting by Ascending : 
void Sorting_By_Ascending(int Array1[],int power){
    int temp;
    for(int i=0; i<power; i++){
        for(int j=i+1; j<power; j++){
            if(Array1[i]>Array1[j]){
                temp = Array1[i];
                Array1[i]=Array1[j];
                Array1[j]=temp;
            }
        }
    }
}

//sorting by Dscinding : 
void Sorting_By_Dscending(int Array1[], int power){
    int temp;
    for(int a=0; a<power; a++){
        for(int b=a+1; b<power; b++){
            temp=Array1[a];
            Array1[a]=Array1[b];
            Array1[b]=temp;
        }
    }
}




//Take Input From User : 
void InsertData(int Array1[],int power){
      for(int a=0; a<power; a++){
         cin>>Array1[a];
      }
}
//Output : 
void PrintArray(int Array1[], int power){
     for(int a=0; a<power; a++){
        cout<<Array1[a]<<" ";
     }
     cout<<endl;
}


int main(){

    clock_t start;
    clock_t end;

    double TimeAscending, TimeDscending;

    int power;
    cout<<"How Many Data wanto to Insert : ";
    cin>>power;

    int Array1[power];

    cout<<"Insert Data : ";
    InsertData(Array1,power);

    cout<<"Original Array : ";
    PrintArray(Array1,power);

    //Ascending Order : 
    cout<<"Sorting By Ascending Order : ";
    start = clock();
    Sorting_By_Ascending(Array1,power);
    end = clock();
    PrintArray(Array1,power);
    TimeAscending = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Ascending Time : "<<TimeAscending<<endl;

    //Dscending Order :
    cout<<"Sorting By Dscending Order : ";
    start = clock();
    Sorting_By_Dscending(Array1,power);
    end = clock();
    PrintArray(Array1,power);
    TimeDscending = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Dscending Time : "<<TimeDscending<<endl;



    return 0;
}