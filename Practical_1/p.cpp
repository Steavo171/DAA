#include<bits/stdc++.h>
using namespace std;

void printArr(vector <int> arr, int n, string filename){
    ofstream outputfile(filename);
    for(int i=0; i<n; i++){
        outputfile << arr[i]<< " ";
    }
    outputfile.close();
}

void selectionSort(vector <int> arr, int n){
    for(int i = 0; i<n; i++){
        int mini = i;
        for(int j= i+1; j<n; j++)
            if(arr[j]< arr[mini])
                mini = j;
        swap(arr[i], arr[mini]);
    }
    printArr(arr, n, "selectionSort.txt");
}

void bubbleSort(vector <int> arr, int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j< n-1-i; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    }
    printArr(arr, n, "bubbleSort.txt");
}

void randomNums(int n){
    vector <int> arr;
    ofstream outputfile("input.txt");
    for(int i=0; i<n; i++){
        outputfile << rand() % (n+1)<< " ";
    }
    outputfile.close();

}

void driver(int num){
    randomNums(num); // put number of numbers to generate

    clock_t startTime, endTime;
    double totalTime;

    vector <int> arr;
    ifstream readfile("input.txt");

    int value;
    while(readfile >> value){
        arr.push_back(value);
    }
    readfile.close();

    startTime = clock();
    bubbleSort(arr, arr.size());
    endTime = clock();

    cout<<num;
    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"        "<<totalTime;
    
    startTime = clock();
    selectionSort(arr, arr.size());
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"             "<<totalTime<<endl;

}

int main(){

    cout<<"        Bubble Sort      Selection Sort"<<endl;
    driver(500);
    driver(1000);
    driver(1500);
    driver(2000);
    driver(2500);
    driver(3000);
    
    return 0;
}