<<<<<<< HEAD
/*Question :- Median of two sorted arrays of same size
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)). 
Examples :  

   ar1[] = {1, 12, 15, 26, 38}
   ar2[] = {2, 13, 17, 30, 45}
For above two arrays m1 = 15 and m2 = 17
For the above ar1[] and ar2[], m1 is smaller than m2. So median is present in one of the following two subarrays. 

   [15, 26, 38] and [2, 13, 17]
Let us repeat the process for above two subarrays:  

    m1 = 26 m2 = 13.
m1 is greater than m2. So the subarrays become  

  [15, 26] and [13, 17]
Now size is 2, so median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
                       = (max(15, 13) + min(26, 17))/2 
                       = (15 + 17)/2
                       = 16*/


#include <iostream>
#include<string>
using namespace std;
int median(int arr[], int n){
    if(n%2 == 0){
        return (arr[n/2] + arr[n/2 - 1])/2;
    }
    else{
        return arr[n/2];
    }
}
int getMedian(int arr1[],int arr2[], int n){
    if(n <=0) return -1;
    if(n == 1) return (arr1[0] + arr2[0])/2;
    if(n == 2){
        return (max(arr1[0], arr2[0]) + min(arr1[1],arr2[1]))/2;
    }
    int m1 = median(arr1,n);
    int m2 = median(arr2,n);
    
    if(m1 == m2){
        return m1;
    }
    if(m1 < m2){
        if(n%2==0){
            return getMedian(arr1 + n/2 -1,arr2,n- n/2 +1);
        }
        return getMedian(arr1 + n/2,arr2,n- n/2);
    }
    if(n%2 == 0){
        getMedian(arr1 + n/2 -1,arr2,n- n/2 +1);
    }
    return getMedian(arr1 + n/2,arr2,n- n/2);
    
}

int main()
{
    int arr1[] = {1, 2, 3, 6};
    int arr2[] = {4, 6, 8, 10};
    int n1 = sizeof(arr1) /
             sizeof(arr1[0]);
    int n2 = sizeof(arr2) /
             sizeof(arr2[0]);
    if(n1 == n2){
        cout<<"Median is: "<<getMedian(arr1,arr2,n1);
    }
    return 0;
=======
/*Question :- Median of two sorted arrays of same size
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)). 
Examples :  

   ar1[] = {1, 12, 15, 26, 38}
   ar2[] = {2, 13, 17, 30, 45}
For above two arrays m1 = 15 and m2 = 17
For the above ar1[] and ar2[], m1 is smaller than m2. So median is present in one of the following two subarrays. 

   [15, 26, 38] and [2, 13, 17]
Let us repeat the process for above two subarrays:  

    m1 = 26 m2 = 13.
m1 is greater than m2. So the subarrays become  

  [15, 26] and [13, 17]
Now size is 2, so median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
                       = (max(15, 13) + min(26, 17))/2 
                       = (15 + 17)/2
                       = 16*/


#include <iostream>
#include<string>
using namespace std;
int median(int arr[], int n){
    if(n%2 == 0){
        return (arr[n/2] + arr[n/2 - 1])/2;
    }
    else{
        return arr[n/2];
    }
}
int getMedian(int arr1[],int arr2[], int n){
    if(n <=0) return -1;
    if(n == 1) return (arr1[0] + arr2[0])/2;
    if(n == 2){
        return (max(arr1[0], arr2[0]) + min(arr1[1],arr2[1]))/2;
    }
    int m1 = median(arr1,n);
    int m2 = median(arr2,n);
    
    if(m1 == m2){
        return m1;
    }
    if(m1 < m2){
        if(n%2==0){
            return getMedian(arr1 + n/2 -1,arr2,n- n/2 +1);
        }
        return getMedian(arr1 + n/2,arr2,n- n/2);
    }
    if(n%2 == 0){
        getMedian(arr1 + n/2 -1,arr2,n- n/2 +1);
    }
    return getMedian(arr1 + n/2,arr2,n- n/2);
    
}

int main()
{
    int arr1[] = {1, 2, 3, 6};
    int arr2[] = {4, 6, 8, 10};
    int n1 = sizeof(arr1) /
             sizeof(arr1[0]);
    int n2 = sizeof(arr2) /
             sizeof(arr2[0]);
    if(n1 == n2){
        cout<<"Median is: "<<getMedian(arr1,arr2,n1);
    }
    return 0;
>>>>>>> 53b0ddf321242fd26a181611702a9b333131c39f
}