#include<bits/stdc++.h>
using namespace std;

void printArr(vector <int> arr, int n, string filename){
    ofstream outputfile(filename);
    for(int i=0; i<n; i++){
        outputfile << arr[i]<< " ";
    }
    outputfile.close();
}


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;  

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
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
    quickSort(arr, 0, n - 1);
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"        "<<totalTime;

    printArr(arr, n, "Quicksort.txt");
    
    startTime = clock();
    heapSort(arr_copy);
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"              "<<totalTime<<endl;

    printArr(arr_copy, n, "Heapsort.txt");

}

int main(){

    cout<<"   Quick Sort     Heap Sort"<<endl;
    driver(5000);
    driver(10000);
    driver(15000);
    driver(20000);
    driver(25000);
    driver(30000);
    
    return 0;
}