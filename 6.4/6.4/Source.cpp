#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(double* a, int n, int l, int h);
double sum(double* a, int n);
void print(double* a, int n);
int max_abs(double* a, int n);
int min_abs(double* a, int n);
double dob(double* a, int n);
void Sort(double* a, const int size);

int main() {
    srand((unsigned)time(NULL));

    int n;
    int l = -10;
    int h = 10;
    double s;
    double dob_;

    cout << "n = "; cin >> n;

    double* a = new double[n];

    create(a, n, l, h);

    print(a, n);

    s = sum(a, n);

    dob_ = dob(a, n);

    Sort(a, n);

    print(a, n);

    cout << endl << "| dob = " << dob_ << " |";
    cout << endl << "| s = " << s << " |";

    return 0;
}



void create(double* a, int n, int l, int h) {
    for (int i = 0; i < n; i++) {
        a[i] = ((((double)rand()) / (double)RAND_MAX) * ((double)h - (double)l)) + (double)l;
    }
}

double sum(double* a, int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            s += a[i];
        }
    }
    return s;
}

void print(double* a, int n) {
    cout << "| a |";
    for (int i = 0; i < n; i++) {
        cout << setw(7) << setprecision(6) << a[i] << " |";
    }
    cout << endl;
}

int max_abs(double* a, int n) {
    double max_a = abs(a[0]);
    int max_i = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) > max_a) {
            max_a = abs(a[i]);
            max_i = i;
        }
    }
    return max_i;
}

int min_abs(double* a, int n) {
    double min_a = abs(a[0]);
    int min_i = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) < min_a) {
            min_a = abs(a[i]);
            min_i = i;
        }
    }
    return min_i;
}

double dob(double* a, int n) {
    double dob = 1;
    int tmp;
    int i = min_abs(a, n) + 1;
    int j = max_abs(a, n);
    if (i > j) {
        tmp = i;
        i = j;
        j = tmp;
    }
    for (i; i < j; i++) {
        dob *= a[i];
    }
    return dob;
}

void Sort(double* a, const int size)
{
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - i; j++)
            if (a[j] < a[j + 1]) {
                double tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

            }
}