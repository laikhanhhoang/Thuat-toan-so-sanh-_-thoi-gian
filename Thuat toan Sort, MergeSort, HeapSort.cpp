// laikhanhhoang_from_uit
// bit.ly/facebook_of_laikhanhhoang
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef long double ld;
#define PB push_back
#define el endl
#define uset unordered_set
#define umap unordered_map
#define MP make_pair
#define vt vector
//void solve(){}
ll partition(vector<ll> &a,ll low,ll high)
{
  //choose the pivot
   
  ll pivot= a[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  ll i=(low-1);
   
  for(ll j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(a[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[i+1],a[high]);
  return (i+1);
}
 
// The Quicksort function Implement
            
void quickSort(vector<ll> &a,ll low,ll high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
     
    ll pi=partition(a,low,high);
     
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(a,low,pi-1);
    quickSort(a,pi+1,high);
  }
}
void merge(vector<ll> &a, ll const left, ll const mid, ll const right){
    ll const subArrayOne = mid - left + 1;
    ll const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new ll[subArrayOne],
         *rightArray = new ll[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = a[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = a[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    ll indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            a[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            a[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        a[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        a[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergesort(vector<ll> &a, ll const begin, ll const end)
{
    if (begin >= end)
        return;
 
    ll mid = begin + (end - begin) / 2;
    mergesort(a, begin, mid);
    mergesort(a, mid + 1, end);
    merge(a, begin, mid, end);
}

void heapify(vector<ll> &a, ll N, ll i)
{
 
    // Initialize largest as root
    ll largest = i;
 
    // left = 2*i + 1
    ll l = 2 * i + 1;
 
    // right = 2*i + 2
    ll r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && a[l] > a[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && a[r] > a[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(a, N, largest);
    }
}
 
// Main function to do heap sort
void heapsort(vector<ll> &a, ll N)
{
 
    // Build heap (rearrange array)
    for (ll i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i);
 
    // One by one extract an element
    // from heap
    for (ll i = N - 1; i > 0; i--) {
 
        // Move current root to end
        swap(a[0], a[i]);
 
        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}
int main(){
	ifstream ifs("Bo du lieu 10.txt");
	vector<ll> a(1000000);
	for(int i = 0; i < 1000000; i++) ifs >> a[i];
	clock_t start, end;
	double timeused;
	start = clock();
	//sort(a.begin(), a.end());
	//quickSort(a,0,999999);
	//mergesort(a,0,999999);
	heapsort(a,1000000);
	end = clock();
	timeused = (double)(end - start) / CLOCKS_PER_SEC;
	cout<<"Time run: "<<timeused<<" s"<<endl;
	cout << a[999999];
	
return 0;
}


// Cau lenh khai bao vector kieu int n phan tu: vector<int> a(n);
// Cau lenh khai bao vector kieu int n phan tu 0: vector<int> a(n,0);
// Cau lenh kiem tra dieu kien: bool x &= (dieu kien);
// Cau lenh khai bao map: map<int, int> m;
// Cau lenh chuyen thanh long db: int x = (int) round((long double) b * n / (a + b));
// Ham ep int sang string: to_string(x)
// assert( && )



/* Note bai toan:

*/







