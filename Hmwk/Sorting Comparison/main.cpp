

#include <iostream>
#include <cmath>
using namespace std;
 
void quickSort(int [],int,int);
int pivot(int [],int,int);
void swap(int&,int&);
void print(int [],const int&);
void merge(int*,int,const int, const int);
void merge_sort(int*, const int, const int);
void heapsort(int [],int);
void buildheap(int [],int);
void heapify(int [],int,int);
 
int main(){
    int test[] = { 7,-13,1,3,10,5,2,4};
    int N = sizeof(test)/sizeof(int);
 
    cout << "Size of test array :"  << N << endl;
 
    cout << "Before sorting : " << endl;
    print(test, N);
 
    //quickSort(test, 0, N-1);
    //merge_sort(test, 0, N-1);
    heapsort(test, N);
 
    cout << endl << endl << "After sorting : " << endl;
    print(test, N);
     
    return 0;
}
 
/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
*/
void quickSort(int a[], int first, int last ) {
    int pivotElement;
 
    if(first < last) {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}
 
/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
*/
int pivot(int a[], int first, int last) {
    int  p = first;
    int pivotElement = a[first];
 
    for(int i = first+1 ; i <= last ; i++) {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement) {
            p++;
            swap(a[i], a[p]);
        }
    }
 
    swap(a[p], a[first]);
 
    return p;
}
 
 
/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
 
/**
 * Print an array.
 * @param a - The array.
 * @param N - The size of the array.
*/
void print(int a[], const int& N){
    for(int i = 0 ; i < N ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
} 

void merge(int* A,int p,const int q, const int r){
    const int n_1=q-p+1;
    const int n_2=r-q;
    int* L = new int[n_1+1];
    int* R = new int[n_2+1];
    L[n_1]=0;
    R[n_2]=0;
    for(int i = 0; i < n_1; i++) 
        L[i] = A[p+i];
    for (int j = 0; j < n_2; j++)
        R[j] = A[q+j+1];

    int i=0;
    int j=0;
    // for(int k = p; k <= r; p++)   broken code
    int k;
    for(k=p; k <= r && i < n_1 && j < n_2; ++k) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;        
        }
    }
    // Added the following two loop.
    // Note only zero or one loop will actually activate.
    while (i < n_1) {A[k++] = L[i++];}
    while (j < n_2) {A[k++] = R[j++];}
}     

void merge_sort(int* A, const int p, const int r){
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(A, p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

//(takes O(n lg n) time)
void heapsort(int A[], int length) {
	int heapsize = length;
	
	buildheap(A, length);	//Take the unsorted list and make it a heap
	for (int i = length-1; i >=1; i--) {
		swap(A[0], A[i]);
		heapsize--;
		heapify(A, heapsize, 0);		
	}
}

//     (takes O(n) time)
void buildheap(int A[], int length) {	
	for (int i = floor((length)/2); i >= 0 ; i--)
		heapify(A, length, i);
}

//(takes O(h) h is the height of root
void heapify(int A[], int heapsize, int root) {
	int left = 2*root+1, 
		right = 2*root +2,
		largest;
	
	if ( (left < heapsize) && (A[left] > A[root]))
		largest = left;
	else 
		largest = root;
	
	if ( (right < heapsize) && (A[right] > A[largest]))
		largest = right;
		
	if (largest != root) {
		swap(A[root], A[largest]);
		heapify(A, heapsize, largest);
	}
}