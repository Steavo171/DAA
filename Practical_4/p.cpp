#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

int maxDeadline(const vector<Job>& arr) {
    int max_deadline = 0;
    for (const auto& job : arr) {
        max_deadline = max(max_deadline, job.deadline);
    }
    return max_deadline;
}


void printJobScheduling(vector<Job>& arr, int n) {

    int maxDead = maxDeadline(arr);
    sort(arr.begin(), arr.end(), compare);

    vector<string> slot(n, "");     //creates n empty slots
    vector<string> result;
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        int k = min(maxDead, arr[i].deadline);
        while(k>=1){
            if(slot[k] == ""){
                slot[k] = arr[i].id;
                result.push_back(arr[i].id);
                totalProfit+= arr[i].profit;
                break;
            }
            else {
                k--;
            }
        }
    }

    cout << "Job sequence with maximum profit:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout<<endl<<"Profit: "<<totalProfit;
    cout << endl;
}
int main() {
    int jobs;
    cout << "Enter number of jobs: ";
    cin >> jobs;

    vector<Job> arr;
    for (int i = 0; i < jobs; i++) {
        string id;
        int deadline, profit;
        cout << "Enter details for job " << i + 1 << " (ID, deadline, profit): ";
        cin >> id >> deadline >> profit;
        arr.push_back({id, deadline, profit});
    }

    printJobScheduling(arr, jobs);
    return 0;
}