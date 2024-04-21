#include<bits/stdc++.h>
using namespace std;

void printArr(vector <int> arr, int n, string filename){
    ofstream outputfile(filename);
    for(int i=0; i<n; i++){
        outputfile << arr[i]<< " ";
    }
    outputfile.close();
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arr, int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void insertionsort(vector <int>& arr,int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

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

    int n=arr.size();
    vector<int> arr_copy = arr;     //copy arr for merge sort

    startTime = clock();
    insertionsort(arr,n);
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"        "<<totalTime;

    printArr(arr, n, "insertionsort.txt");
    
    startTime = clock();
    mergesort(arr_copy, 0, n-1);
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"              "<<totalTime<<endl;

    printArr(arr_copy, n, "mergesort.txt");

}

int main(){

    cout<<"   Insertion Sort     Merge Sort"<<endl;
    driver(500);
    driver(1000);
    driver(1500);
    driver(2000);
    driver(2500);
    driver(3000);
    
    return 0;
}