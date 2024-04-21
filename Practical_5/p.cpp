#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Object {
    int id;
    int weight;
    int profit;
    double factor;
};

bool compare_factor(const Object a, const Object b) {
    return (a.factor > b.factor);
}

bool compare_profit(const Object a, const Object b) {
    return (a.profit > b.profit);
}

bool compare_weight(const Object a, const Object b) {
    return (a.weight < b.weight);
}

void knapsack(vector<Object>& objects, int capacity, int choice) {
    if (choice == 1) {
        sort(objects.begin(), objects.end(), compare_profit);
    } else if (choice == 2) {
        sort(objects.begin(), objects.end(), compare_weight);
    } else if (choice == 3) {
        for (auto& obj : objects) {
            obj.factor = static_cast<double>(obj.profit) / obj.weight;
        }
        sort(objects.begin(), objects.end(), compare_factor);
    }

    int totalProfit = 0;
    int remainingCap = capacity;

    for (const auto& obj : objects) {
        if (remainingCap >= obj.weight) {
            remainingCap -= obj.weight;
            totalProfit += obj.profit;
        } else {
            double ratio = static_cast<double>(remainingCap) / obj.weight;
            remainingCap = 0; // Knapsack full
            totalProfit += ratio * obj.profit;
            break;
        }
    }

    cout << "Knapsack problem result:\n";
    cout << "Profit: " << totalProfit << endl;
}

int main() {
    int numObjects, capacity, choice;
    cout << "Enter number of objects: ";
    cin >> numObjects;

    vector<Object> objects;
    for (int i = 0; i < numObjects; i++) {
        int id, weight, profit;
        cout << "Enter details for object " << i + 1 << " (ID, weight, profit): ";
        cin >> id >> weight >> profit;
        objects.push_back({id, weight, profit});
    }

    cout << "Enter the capacity: ";
    cin >> capacity;

    cout << "Enter 1 for Maximum profit\n2 for Minimum weight\n3 for Maximum profit-to-weight ratio: ";
    cin >> choice;

    knapsack(objects, capacity, choice);

    return 0;
}