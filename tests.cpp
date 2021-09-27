#include <stdio.h>

#include "algo.h"

using namespace algo;

int main() {
    

    ///////////////////////
    //// SORT TEST
    ///////////////////////
    
    int n = 1000;
    int koef1 = 233;
    int koef2 = 3643;
    

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    int* arr4 = new int[n];
    
    // generate pseudo random ints
    for(int i=0; i<n; ++i) {
            arr1[i] = (i*koef1) % koef2;
            arr2[i] = (i*koef1) % koef2;
            arr3[i] = (i*koef1) % koef2;
            arr4[i] = (i*koef1) % koef2;
    }
    

    // heap sort
    /////////////

    ArrHeapSort<int>(arr1, n);
    ArrHeapSort<int>(arr2, n, false);
    
    // check if sorted arrays are ascending/descending
    for(int i=0; i<n-1; ++i) if(arr1[i] > arr1[i+1]) printf("Error heap sort\n");
    for(int i=0; i<n-1; ++i) if(arr2[i] < arr2[i+1]) printf("Error heap sort\n");
    
    printf("End of heap sort\n");
   

    // merge sort
    /////////////
    
    ArrMergeSort<int>(arr3, n);
    
    // compare to sorted array
    for(int i=0; i<n; ++i) if(arr1[i] != arr3[i]) printf("Error merge sort\n");
    
    printf("End of merge sort\n");
    
    // Count Sort
    CountSort(arr4, n);
    
    // compare to sorted array
    for(int i=0; i<n; ++i) if(arr1[i] != arr4[i]) printf("Error count sort\n");

    printf("End of count sort\n");

    
    // Binary Search 
    /////////////////
    
    if(!BinarySearch<int>(arr1, (0    *koef1)%koef2, 0, n-1)) printf("Error binary search\n");
    if(!BinarySearch<int>(arr1, ((n/2)*koef1)%koef2, 0, n-1)) printf("Error binary search\n");
    if(!BinarySearch<int>(arr1, ((n-1)*koef1)%koef2, 0, n-1)) printf("Error binary search\n");
    
    if(BinarySearch<int>(arr1, -1, 0, n-1)) printf("Error binary search\n");
    if(BinarySearch<int>(arr1,  koef2 + 1, 0, n-1)) printf("Error binary search\n");

    printf("End of binary search\n");


    ///////////////////////
    //// F/LIFO TEST
    ///////////////////////

    FIFO<int> fifo;
    LIFO<int> lifo;
    
    for(int i=0; i<n; ++i) {
        fifo.Insert(arr1[i]);
        lifo.Insert(arr2[i]);
    } 

    for(int i=0; i<n; ++i) {
        if(fifo.Remove() != lifo.Remove()) printf("Error l/fifo\n");
    }



    printf("End of binary l/fifo\n");





    ///////////////////////
    //// AVL TREE TEST
    ///////////////////////
    
     
    AVLTree<int> avltree;
    
    for(int i=0; i<1000; ++i) avltree.Insert(i);
    for(int i=0; i<1000; ++i) if(!avltree.Find(i)) printf("Error AVL tree\n");

    for(int i=999; i>=0; --i) avltree.Remove(i);
    for(int i=0; i<1000; ++i) if(avltree.Find(i)) printf("Error AVL tree\n");

    for(int i=500; i>-500; --i) avltree.Insert(i);
    for(int i=-1000; i<1000; ++i) if(avltree.Find(i) != (i <= 500 && i>-500)) printf("Error AVL Tree\n");

    printf("End of AVL tree\n");
    

    ///////////////////////
    //// AB TREE TEST
    ///////////////////////
    
    // 2-4 tree
    ABTree<int> abtree = ABTree<int>(2,4);
   

    for(int i=0; i<1000; ++i) abtree.Insert(i);
    for(int i=0; i<1000; ++i) if(!abtree.Find(i)) printf("Error 2-4 tree\n");

    for(int i=999; i>=0; --i) abtree.Remove(i);
    for(int i=0; i<1000; ++i) if(abtree.Find(i)) printf("Error 2-4 tree\n");

    for(int i=500; i>-500; --i) abtree.Insert(i);
    for(int i=-1000; i<1000; ++i) if(abtree.Find(i) != (i <= 500 && i>-500)) printf("Error 2-4 tree\n");
 
    printf("End of 2-4 tree\n");
    
    // 4-100 tree 
    ABTree<int> abtree2 = ABTree<int>(4,100);

    for(int i=0; i<1000; ++i) abtree2.Insert(i);
    for(int i=0; i<1000; ++i) if(!abtree2.Find(i)) printf("Error č-100 tree\n");

    for(int i=999; i>=0; --i) abtree2.Remove(i);
    for(int i=0; i<1000; ++i) if(abtree2.Find(i)) printf("Error 4-100 tree\n");

    for(int i=500; i>-500; --i) abtree2.Insert(i);
    for(int i=-1000; i<1000; ++i) if(abtree2.Find(i) != (i <= 500 && i>-500)) printf("Error 4-100 tree\n");
    
    printf("End of 4-100 tree\n");

    printf("End of test\n");
}

