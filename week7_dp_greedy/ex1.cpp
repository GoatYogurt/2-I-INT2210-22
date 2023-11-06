#include <iostream>
#include <vector>

using namespace std;

struct item {
    int weight;
    int value;

    item(int w, int v) {
        weight = w;
        value = v;
    }

    double getRatio() { return (double)value / weight; }
};

int main() {
    int W, N;
    cin >> W >> N;

    vector<item*> items;

    for (int i = 1; i <= N; ++i) {
        int w, v;
        cin >> w >> v;
        items.push_back(new item(w, v));
    }

    double max = 0;
    int iMax = 0;
    for (int i = 0; i < N; ++i) {
        if(items.at(i)->weight > W) {
            continue;
        }
        if (items.at(i)->getRatio() >= max) {
            max = items.at(i)->getRatio();
            iMax = i;
        }
    }

    int total = 0;
    int temp = 0;
    int quantity = 0;
    while (total < W) {
        ++quantity;
        temp = total;
        total += items.at(iMax)->weight;
    }

    cout << "Item chosen: " << iMax + 1 << endl 
         << "Item weight: " << items.at(iMax)->weight << endl
         << "item ratio: " << items.at(iMax)->getRatio() << endl
         << "Quantity: " << quantity - 1<< endl
         << "Total weight: " << temp;

    return 0;
}