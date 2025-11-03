#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    double weight;
    double value;
    bool divisible;
    int priority;

    Item(string n, double w, double v, bool d, int p)
        : name(n), weight(w), value(v), divisible(d), priority(p) {}

    double valuePerWeight() const {
        return value / weight;
    }
};

// Compare by priority first, then value/weight
bool compareItems(const Item &a, const Item &b) {
    if (a.priority == b.priority)
        return a.valuePerWeight() > b.valuePerWeight();
    return a.priority < b.priority; // smaller priority = higher importance
}

double fractionalKnapsack(vector<Item> &items, double capacity, double &totalWeight) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    totalWeight = 0.0;

    cout << "\nItems chosen:\n";
    for (auto &item : items) {
        if (capacity <= 0) break;

        if (item.divisible) {
            double take = min(item.weight, capacity);
            totalValue += item.valuePerWeight() * take;
            capacity -= take;
            totalWeight += take;
            cout << " - " << item.name << " (" << take << " kg, divisible)\n";
        } else {
            if (item.weight <= capacity) {
                totalValue += item.value;
                capacity -= item.weight;
                totalWeight += item.weight;
                cout << " - " << item.name << " (" << item.weight << " kg, indivisible)\n";
            }
        }
    }
    return totalValue;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;
    for (int i = 0; i < n; i++) {
        string name;
        double weight, value;
        int divisibleInt, priority;

        cin.ignore(); // clear newline
        cout << "\nItem " << i + 1 << " name: ";
        getline(cin, name);
        cout << "Weight (kg): ";
        cin >> weight;
        cout << "Utility value: ";
        cin >> value;
        cout << "Divisible? (1=Yes, 0=No): ";
        cin >> divisibleInt;
        cout << "Priority (1=High, 2=Medium, 3=Low): ";
        cin >> priority;

        items.emplace_back(name, weight, value, divisibleInt == 1, priority);
    }

    double capacity, totalWeight;
    cout << "\nEnter boat capacity (kg): ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(items, capacity, totalWeight);

    cout << "\n===== Final Report =====\n";
    cout << "Total weight: " << fixed << setprecision(2) << totalWeight << " kg\n";
    cout << "Total utility: " << fixed << setprecision(2) << maxValue << "\n";

    return 0;
}
