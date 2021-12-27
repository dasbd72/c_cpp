#include <iostream>
int main() {
    using namespace std;
    int *a, *b;
    int n, times;
    bool finish;

    while (cin >> n) {
        // init
        times = 0;
        finish = false;
        a = new int[2 * n + 1];
        b = new int[2 * n + 1];
        for (int i = 1; i <= 2 * n; i++) a[i] = i;

        // loop
        while (!finish) {
            int l = 1, r = n + 1;
            times++;
            for (int i = 1; i <= 2 * n; i += 2) {
                b[i] = a[r++];
                b[i + 1] = a[l++];
            }
            swap(a, b);

            cout << times << " : ";

            finish = true;
            for (int i = 1; i <= 2 * n; i++) {
                if (a[i] != i)
                    finish = false;
                cout << a[i] << (i == 2 * n ? '\n' : ' ');
            }
        }
        delete[] a;
        delete[] b;
    }
}