#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 1, 4, 2, 3, 5};
    unordered_map<int, int> freqMap;

    for (int num : arr) {
        freqMap[num]++;
    }

    cout << "Frequency of elements:" << endl;
    for (auto &entry : freqMap) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
