// // Q1- Given is an array with n elements that represents n positions along a straight line. Find K elements such that the minimum distance between many 2 elements is the maximum possible.

// // C++ program to find largest minimum distance
// // among m points.
// #include <bits/stdc++.h>
// using namespace std;

// bool isFeasible(int mid, int arr[], int n, int m)
// {
// 	int pos = arr[0];
// 	int elements = 1;
// 	for (int i = 1; i < n; i++) {
// 		if (arr[i] - pos >= mid) {
// 			pos = arr[i];
// 			elements++;
// 			if (elements == m)
// 				return true;
// 		}
// 	}
// 	return 0;
// }

// int largestMinDist(int arr[], int n, int m)
// {
// 	sort(arr, arr + n);
// 	int res = -1;
// 	int left = 1, right = arr[n-1];
// 	while (left < right) {
// 		int mid = (left + right) / 2;
// 		if (isFeasible(mid, arr, n, m)) {
// 			res = max(res, mid);
// 			left = mid + 1;
// 		}
// 		else
// 			right = mid;
// 	}

// 	return res;
// }

// int main()
// {
// 	int arr[] = { 1, 2, 8, 4, 9 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int m = 3;
// 	cout<<"The max Min Distance is: "<<largestMinDist(arr, n, m)<<endl;
// 	return 0;
// }



// Q-2 Allocate Minimum Pages n - number of pages in n different books [ascending order] m- number of students All the books have to be divided among m students, consecutively. Allocate the pages in such a way that maximum pages allocated to a student is minimum.

// #include<bits/stdc++.h>
// using namespace std;

// bool isPossible(int arr[], int n, int m, int barrier){
// 	int allocatedStu = 1, pages=0;
// 	for(int i=0; i<n; i++){
// 		if(arr[i] > barrier){
// 			return false;
// 		}
// 		if(pages + arr[i] > barrier){
// 			allocatedStu++;
// 			pages += arr[i];

// 			if(allocatedStu > m){
// 				return false;
// 			} 
// 		}
// 		else{
// 			pages += arr[i];
// 		}
// 	}
// 	return true;
// }

// int allocateMinimumPages(int arr[], int n, int m){ //n=students, m=books
// 	int sum=0;
// 	if(n < m){
// 		return -1;
// 	}
// 	for(int i=0; i<n; i++){
// 		sum += arr[i];
// 	}
// 	int start = 0, end = sum, ans = INT_MAX;
// 	while(start < end){
// 		int mid = (start + end)/2;
// 		if(isPossible(arr, n, m, mid)){
// 			ans = min(ans, mid);
// 			end = mid-1;
// 		}
// 		else{
// 			start = mid+1;
// 		}
// 	}
// 	return ans;

// }

// int main()
// {
// 	int arr[] = {12,34,67,90};
// 	int n = 4;
// 	int m = 2;
// 	cout<<"The Max Minimum number of pages allocated: "<<allocateMinimumPages(arr, n, m)<<endl;
	

// 	return 0;
// }


// Q-3 Painter partition problem- Given are N boards of with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of the board. The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

#include<bits/stdc++.h>
using namespace std;

// bool isPossibleSol(int boards[], int n, int m, int mid){
//     int painter  = 1;
//     int boardsPainted = 0;
    
//     for(int i = 0; i<n; i++){
//         if(boardsPainted + boards[i] <= mid){
//             boardsPainted = boardsPainted + boards[i];
//         }
//         else{
//             painter++;
//             if(painter > m || boards[i] > mid){
//                 return false;
//             }
//             boardsPainted = boards[i];
//         }
//     }
//     return true;
// }

// int painterPartition(int boards[], int n, int m)
// {
//     int start = 0;
//     int sum = 0;
//     for(int i = 0; i<n; i++){
//         sum = sum + boards[i];
//     }
//     int high = sum;
//     int mid = (start+high)>>1; // == (start+high)/2
//     int ans = -1;
    
//     while(start<=high){
//         if(isPossibleSol(boards,n,m,mid)){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             start = mid + 1;
//         }
//         mid = (start + high)>>1; // == (start+high)/2
//     }
//     return ans;
// }
// int main()
// { 
// 	int boards[] = {10, 20, 30, 40};
// 	// int boards[] = {10, 10, 10, 10};
// 	int n = 4;
// 	int m = 2;
// 	cout<<"Mininimun time to paint boards: "<<painterPartition(boards, n, m)<<endl;
	

// 	return 0;
// }


// //Q-3 You are given an array consisting of n integers which denote the position of a stall. You are also given an integer key which denotes the number of aggressive cows. You are given the task of assigning stalls to key cows such that the minimum distance between any two of them is the maximum possible. The first line of input contains two space-separated integers n and key. The second line contains n space-separated integers denoting the position of the stalls.

// #include<iostream>
// using namespace std;

// bool isPossible(vector<int> &stalls, int key, int mid){
//     int cowCount = 1;
//     int lastpos = stalls[0];

//     for(int i=0; i<stalls.size(); i++){
//         if(stalls[i] - lastpos >= mid){
//             cowCount++;
//             if(cowCount == key){
//                 return true;
//             }
//             lastpos = stalls[i];
//         }
//     }
//     return false;
// }

// int aggressiveCow(vector<int> &stalls, int key){
//     sort(stalls.begin(), stalls.end());
//     int start = 0, maxi = INT_MIN;
//     for(int i = 0; i <stalls.size(); i++){
//         maxi = max(maxi, stalls[i]);
//     }
//     int high = maxi;
//     int ans = -1;
//     int mid = (start+high) >> 1;
//     while(start <= high){
//         if(isPossible(stalls, key, mid)){
//             ans = mid;
//             start = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//         mid = (start+high) >> 1;
//     }
//     return ans;

// }

// int main()
// {
//     vector<int> stalls = {4,2,1,3,6};
//     int key = 2;
//     cout<<"The max min Distance between cows: "<<aggressiveCow(stalls, key)<<endl;
    

//     return 0;
// }


// //Q-4 Search element in sorted & rotated array - We are given an ascending sorted array that has been rotated from a pivot point (unknown to us) and an element X. Search for X in the array with complexity less than that of linear search

// #include<bits/stdc++.h>
// using namespace std;

// int searchInRotatedArray(int arr[], int key, int left, int right){
//     while(left <= right){
//         int mid =   (left + right) >> 1;
//         if(arr[mid] == key){
//             return mid;
//         }
        
//         if(arr[left] <= arr[mid]){
//             if(arr[left] <= key && key <= arr[mid]){
//                 right = mid - 1;
//             }
//             else{
//                 left = mid + 1;
//             }
//         }
//         else{
//             if(arr[mid] <= key &&  key <= arr[right]){
//                 left = mid + 1;
//             }
//             else{
//                 right = mid - 1;
//             }
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int arr[] = {6,7,8,9,10,1,2,5};
//     int n = 8;
//     int key = 1;
//     cout<<"Value present at: "<<searchInRotatedArray(arr, key, 0, n-1)<<endl;

//     return 0;
// }


//Q-5 A Find the peak element For a given array, find the peak element in the array. Peak element is one which is greater than both, left and right neighbours of itself.

#include<bits/stdc++.h>
using namespace std;

int findPeakElement(int arr[], int low, int high, int n){
    int mid = low + (high - low)/2;

    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])){
        return mid;
    }
    else if(mid > 0 && arr[mid - 1] > arr[mid]){
        return findPeakElement(arr, low, mid-1, n);
    }else{
        return findPeakElement(arr,mid+1, high, n);
    }
}
int main()
{
    int arr[] = {0,6,8,5,7,9};
    int n = 6;
    cout<<"Peak element index is: "<<findPeakElement(arr,0,n-1,n)<<endl;
    

    return 0;
}