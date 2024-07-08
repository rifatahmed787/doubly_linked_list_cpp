#include <bits/stdc++.h>
using namespace std;

void print_list(list<int>& values) {
    cout << "L -> ";
    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "R -> ";
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    list<int> values;
    int t;
    cin >> t;
    while (t--) {
        int x, v;
        cin >> x >> v;

        if (x == 0) {
            values.push_front(v);
        } else if (x == 1) {
            values.push_back(v);
        } else if (x == 2) {
            if (v < 0 || v >= values.size()) {
                print_list(values);
                continue;
            }
            auto it = values.begin();
            advance(it, v);
            values.erase(it);
        }

        print_list(values);
    }

    return 0;
}
