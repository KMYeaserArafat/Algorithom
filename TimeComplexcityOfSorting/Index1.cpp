
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

void generateNumbers(int n){
    ofstream outfile("numbers.txt");
    srand(time(NULL));
    for(int i=0; i<n; i++){
        outfile<< rand() << endl;
    }
    outfile.close();
}

int* readNumbers(int n){
    int* numbers = new int[n];
    ifstream infile("numbers.txt");
    for(int i=0; i<n; i++){
        infile >> numbers[i];
    }
    infile.close();
    return numbers;
}

// sorting : /

void InsertionSort(int numbers[],int n){
    clock_t start;
    clock_t end;
    double timetakenInsertionSort;
    int j,key;
     start = clock();
    for(int i=0; i<n; i++){
        key = numbers[i];
        j = i-1;
        if(j>=0 && numbers[j]>key){
            numbers[j+1] = numbers[j];
        }
        numbers[j+1] = key;
    }
    end = clock();
    timetakenInsertionSort = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Insertion Sort Time : "<<timetakenInsertionSort<<endl;
}  


void SelectionSort(int numbers[], int n){
      int minIndex,temp;
       clock_t start;
       clock_t end;
       double timetakenSelectionSort; 
       start = clock();
      for(int i=0; i<n-1; i++){
        minIndex = i;
        for(int j=i+1; j<n; j++){
            if(numbers[j]>numbers[minIndex]){
                minIndex = j;
            }
        }
        temp = numbers[minIndex];
        numbers[minIndex]= numbers[i];
        numbers[i]=temp;
      }
      end = clock();
      timetakenSelectionSort = (end-start)/(double)CLOCKS_PER_SEC;
      cout<<"Selection Sort Time : "<< timetakenSelectionSort<<endl;
      
}

void BubbleSort(int numbers[],int n){
    int temp;
    clock_t start;
    clock_t end;
    double timetakenBubbleSort; 
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(numbers[i]>numbers[j]){
                temp = numbers[i];
                numbers[i]=numbers[j];
                numbers[j]=temp;
            }
        }
    }
    timetakenBubbleSort = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Bubble Sort Time : "<<timetakenBubbleSort<<endl;
}

// Marge sort;
void merge(int numbers[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = numbers[l + i];
    for (j = 0; j < n2; j++)
        R[j] = numbers[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            numbers[k] = L[i];
            i++;
        }
        else {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numbers[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        numbers[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int numbers[], int l, int r) {
    clock_t start;
    clock_t end;
    double timetakenMargeSort; 
    start = clock();
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(numbers, l, m);
        mergeSort(numbers, m + 1, r);

        merge(numbers, l, m, r);
    }
    end = clock();
    timetakenMargeSort = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Marge Sort Time : "<<timetakenMargeSort<<endl;
}

//  start from the procees of quick sort;
int partition(int numbers[], int low, int high)
{
    int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (numbers[j] <= pivot) {
            i++;
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[i + 1], numbers[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int numbers[], int low, int high)
{
    clock_t start;
    clock_t end;
    double timetakenQuickSort; 
    start  = clock();
    if (low < high) {
        int pi = partition(numbers, low, high);

        quickSort(numbers, low, pi - 1);
        quickSort(numbers, pi + 1, high);
    }
    end = clock();
    timetakenQuickSort = (end-start)/(double)CLOCKS_PER_SEC;
    cout<<"Quick Sort Time : "<<timetakenQuickSort<<endl;;
}


void PrintArray(int numbers[],int n){
    cout<<"Data : ";
    for(int i=0; i<n; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

int main(){

    int n;
    cout<<"How Many Number you wantto take : ";
    cin>>n;
    generateNumbers(n);
    int* numbers = readNumbers(n);
    cout<<endl;

// INSERTION SORT :
   cout<<"Insertion Sort : "<<endl;
   InsertionSort(numbers,n);
   PrintArray(numbers,n);


// SELECTION SORT :
   cout<<"Selection Sort : "<<endl;
   SelectionSort(numbers,n);
   PrintArray(numbers,n);

// BUBBLE SORT :
   cout<<"Bubble Sort : "<<endl;
   BubbleSort(numbers,n);
   PrintArray(numbers,n);

// MARGE SORT :
   cout<<"Marge Sort : "<<endl;
   mergeSort(numbers,0,n-1);
   PrintArray(numbers,n);

// QUICK SORT :
   cout<<"Quick Sort : "<<endl;
   quickSort(numbers,0,n-1);
   PrintArray(numbers,n);


    return 0;
}