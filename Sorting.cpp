// Author: proRam
// Name: Shubh Bansal
// Dated: 13 January, 2021
// Question: Sorting Algorithms for MLH LHD Build

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {

    for ( int i = 1 ; i < n ; ++i ) {
        int target = arr[i],j = i-1 ;

        for ( j = i-1 ; j > -1 && arr[j]>target ; --j ){
            arr[j+1] = arr[j] ;
        }

        arr[j+1] = target ;
    }

}

void bubbleSort(int arr[], int n) {

    for ( int i = 0 ; i < n ; ++i ) 
        for ( int j = 0 ; j < n-1 ; ++j )
            if (arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]) ;
                
}

void selectionSort(int arr[], int n) {

    for ( int i = 0 ; i < n ; ++i ) {
        int target = i ;
        for ( int j = i+1 ; j < n ; ++j ) {
            if ( arr[j]<arr[target] )
                target = j ;
        }
        swap(arr[i],arr[target]) ;
    }
    
}

void countingSort( int arr[], int n ) {

    int max_element = 0 ;
    for ( int i = 0 ; i < n ; ++i )
        max_element = max(max_element, arr[i]);
    
    const int N = max_element+1 ;
    int *freq = new int[N]{0};

    for ( int i = 0 ; i < n ; ++i )
        ++freq[arr[i]] ;
    
    int k = 0 ;
    for ( int i = 0 ; i < N ; ++i ) 
        while ( freq[i]-- ) 
            arr[k++] = i ;

}

void radixCountSort(int arr[], int n, int t ) { 
    
    int ans[n], count[10] = {0}; 
  
    for ( int i = 0 ; i < n ; ++i ) 
        ++count[ (arr[i]/t)%10 ]; 
  
    for ( int i = 1 ; i < 10 ; ++i ) 
        count[i] += count[i - 1]; 
  
    for ( int i = n-1; i > -1 ; --i ) { 
        ans[count[ (arr[i]/t)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/t)%10 ]--; 
    } 

    for ( int i = 0 ; i < n ; ++i ) 
        arr[i] = ans[i]; 
} 

void radixSort( int arr[], int n ) {

    int max_element = 0 ;
    for ( int i = 0 ; i < n ; ++i )
        max_element = max(max_element, arr[i]);

    for ( int i = 1; max_element/i > 0; i *= 10 ) 
        radixCountSort(arr, n, i);
}

int shellSort(int arr[], int n) { 
    
    for ( int gap = n>>1 ; gap ; gap>>=1 ) 
        for (int i = gap; i < n; ++i ) { 
            int temp = arr[i], j = i ;             
            for ( j = i ; j>=gap and arr[j-gap]>temp ; j-=gap )  
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
        
    return 0; 
} 


void merge(int arr[], int l, int r) {

    int l1=1,r1=(l+r)>>1;
    int l2=r1+1, r2=r;

    int i = l1, j = l2, k = 0 ;
    int temp[r-l+1];
    while ( i<=r1 and j<=r2 ) {
        temp[k++] = ( arr[i]>arr[j] ) ? arr[j++] : arr[i++];
    }
    while( i<=r1 )
        temp[k++] = arr[i++];
    while( j<=r2 )
        temp[k++] = arr[j++];
    
    for ( k = 0 ; k <= r-l ; ++k )
        arr[k] = temp[k] ;

}

void mergeSort(int arr[], int l, int r) {
    
    if (l<=r) {
        return ;
    }
    mergeSort(arr,l,(l+r)>>1);
    mergeSort(arr,1+((l+r)>>1),r);
    merge(arr,l,r);

}


int partition(int arr[], int l, int r) { 
    
    int pivot = arr[r]; 
    int i = (l - 1); 
    for (int j = l; j < r; ++j ) 
        if (arr[j] <= pivot) 
            swap(arr[++i], arr[j]); 
    swap(arr[i + 1], arr[r]); 
    return (i + 1); 

} 

int rPartition(int arr[], int l, int r) { 
    
    srand(time(NULL)); 
    int random = l + rand() % (r - l); 
    swap(arr[random], arr[r]); 
    return partition(arr, l, r); 

} 

void quickSort(int arr[], int l, int r) {  
    
    if (l < r) {  
        int p = rPartition(arr, l, r);
        quickSort(arr, l, p - 1);  
        quickSort(arr, p + 1, r);  
    }

} 

int32_t main(int argc, char** argv) {

    const int N = 10000;

    for ( int i = 1 ; i <= 5 ; ++i ) {

        const int n = N*i;
        int best[n], worst[n], average[n];
        clock_t start,end ; 
        start = clock() ;
        cout << "\nn = " << n << endl ;

        // ----------------------------------------------------------------

        // 1. Insertion Sort
        cout << "\n1. Insertion Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = i+1, worst[i] = n-i, average[i] = rand()%n+1 ;
        }

        // Best case 
        start = clock() ;
        insertionSort(best,n) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        insertionSort(average,n) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        insertionSort(worst,n) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------

        // 2. Selection Sort
        cout << "\n2. Selection Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = i+1, worst[i] = n-i, average[i] = rand()%n+1 ;
        }

        // Best case 
        start = clock() ;
        selectionSort(best,n) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        selectionSort(average,n) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        selectionSort(worst,n) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------

        // 3. Bubble Sort
        cout << "\n3. Bubble Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = i+1, worst[i] = n-i, average[i] = rand()%n+1 ;
        }

        // Best case 
        start = clock() ;
        bubbleSort(best,n) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        bubbleSort(average,n) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        bubbleSort(worst,n) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------

        // 4. Counting Sort
        cout << "\nCounting Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = 1, average[i] = 10000, worst[i] = rand()%n+1 ;
        }
        
        // Best case 
        start = clock() ;
        countingSort(best,n) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        countingSort(average,n) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        countingSort(worst,n) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------

        // 5. Radix Sort
        cout << "\nRadix Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = 1, worst[i] = 10000, average[i] = rand()%n+1 ;
        }
        
        // Best case 
        start = clock() ;
        radixSort(best,n) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        radixSort(average,n) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        radixSort(worst,n) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------

        // 6. Shell Sort
        cout << "\nShell Sort\n" ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = 1, worst[i] = 10000, average[i] = rand()%n+1 ;
        }

        // Best case 
        start = clock() ;
        radixSort(best,n) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        radixSort(average,n) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        radixSort(worst,n) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------
        
        // 7. Merge Sort
        cout << "\n1. Merge Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = i+1, worst[i] = n-i, average[i] = rand()%n+1 ;
        }

        // Best case 
        start = clock() ;
        mergeSort(best,0,n-1) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        mergeSort(average,0,n-1) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        mergeSort(worst,0,n-1) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // ----------------------------------------------------------------

        // 8. Quick Sort
        cout << "\n2. Quick Sort\n" ;

        for ( int i = 0 ; i < n ; ++i ) {
            best[i] = i+1, worst[i] = n-i, average[i] = rand()%n+1 ;
        }
        start = clock() ;

        // Best case 
        start = clock() ;
        quickSort(best,0,n-1) ;
        end = clock() ;
        printf("Time for Best Case:    %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // averag case 
        start = clock() ;
        quickSort(average,0,n-1) ;
        end = clock() ;
        printf("Time for Average Case: %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        // worst case 
        start = clock() ;
        quickSort(worst,0,n-1) ;
        end = clock() ;
        printf("Time for Worst Case:   %.8f secs\n", (double(end - start)/double(CLOCKS_PER_SEC))) ; 

        cout << "\n----------------------------------------------------------------" << endl;

    }

    return 0;

}
