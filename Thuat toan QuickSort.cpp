#include <bits/stdc++.h>
using namespace std;
 


void swap(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

long long partition(vector<long long> &a, long long low, long long high) {
    long long pivot = a[high];
    long long i = (low - 1);

    for (long long j = low; j <= high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort(vector<long long> &a, long long low, long long high) {
    if (low < high) {
        long long pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main() {
    ifstream ifs("Bo du lieu 5.txt");
	vector<long long> a(1000000);
	for(long long i = 0; i < 1000000; i++){
		ifs >> a[i];
	}
	clock_t begin, end;
	
	begin = clock();
    quickSort(a,0,999);
  	end = clock();
	cout<<"Time run: "<<(double)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    cout << a[999999];
  return 0;
}
