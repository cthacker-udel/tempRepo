#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
#define RANGE 255


/*

void printArr(int *newArr,int len){

	for(int i = 0; i < len; i++){
		cout << *(newArr+i) << ",";
	}
	cout << endl;

	editing code

}

// newest version --- finalized complete binary search using array splitting and indexing

int getClosestPrime(int x){
	int mapSize = x;

	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	// start at half

	int arrSize = 25;
	int half = arrSize / 2;

	// make tmp array that is the result of cutting the result in half

	int *tmp = p; // tmparray
	int *arr = tmp; // tmp to store tmp
	int newLen = arrSize; // tmpsize
	int target = x*2; // target value

	while(newLen >= 3){


		// middle = 43

		if(tmp[half] == target){
			return tmp[half];
		}
		else if(tmp[half] > target){

			// target is to left of our market
			//size = 25, half = 12[index] // result = 13
			newLen = newLen - half;
			tmp = new int[newLen];
			for(int i = half-1; i >= 0; i--){
				*(tmp+i) = *(arr+i);
			}
			newLen--;
			arr = tmp;
			half = newLen / 2;


		}
		else if(tmp[half] < target){

			// size = 25, half = 12[index] // result = 12
			newLen = newLen - (half+1);
			tmp = new int[newLen];
			for(int i = 0, j = half+1; i < newLen; i++,j++){
				*(tmp+i) = *(arr+j);
			}
			arr = tmp;
			half = newLen / 2;


		}


	}
	if(newLen == 2){
		return *(tmp+1);
	}
	else{
		return *(tmp+0);
	}
}
*/




/*void getClosestPrime(int x){
	int mapSize = x;

	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	// 46

	//int mini[] = {1,2,3,4,5,6,7,8,9,10};

	int sizeArr = 25;
	int s = 2*mapSize;
	int *arr = p;
	int *tmpArr;

	int n = 13; // middle of initial array <-- 43
	int newLen = sizeArr;
	for(;;){
		//int tempN = n;
		cout << "The value is " << arr[n] << endl;
		if(arr[n] == s){
			// found double
			mapSize = p[n];
		}
		else if(s < arr[n]){
			// found prime greater than double meaning that our marker is in front of the prime

			newLen = newLen-(n-1); // calculate the middle
			tmpArr = new int[newLen];
			for(int i = n-1; i >= 0; i--){
				*(tmpArr+i) = arr[i];
			}
			arr = tmpArr;
			printArr(arr,newLen);
			n = newLen / 2; // goes to middle

		}
		else if(s>arr[n]){ // meaning that our marker is behind the prime
			// found prime less than double
			int index = 0;
			newLen = newLen-(n+1); // calculate the middle
			tmpArr = new int[newLen];
			int tmpN = n+1;
			for(int i = 0; i < newLen; i++){
				*(tmpArr+index) = arr[tmpN];
				tmpN += 1;
				index += 1;
			}
			arr = tmpArr;
			printArr(arr,newLen);
			n = newLen / 2; // goes to middle
		}
		if(newLen <= 3){
			break;
		}

	}
	mapSize = arr[n];
	cout << "New mapsize is " << mapSize << endl;


}*/

/*
void getClosestPrime(int x){
	int mapSize = x;

	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	//int mini[] = {1,2,3,4,5,6,7,8,9,10};

	int s = 2*mapSize;
	int a=0;
	int b=24;
	int n = 12;
	for(;b-a> 2;){
		if(p[n] == s){
			// found double
			mapSize = p[n];
		}
		else if(s < p[n+1]){
			// found prime greater than double
			b=n;
			n= n-(b-a)/2;
		}
		else if(s>p[n+1]){
			// found prime less than double
			a=n;
			n = n+(b-a)/2; // moves us to the next double
		}
	}
	if(p[n+1]>s){
		mapSize = p[n+1];
	}
	else{
		mapSize = p[n+2];
	}
	cout << "New mapsize is " << mapSize << endl;




}

int main(void){

	getClosestPrime(11); // next size will be close to 22
	getClosestPrime(15); // next size will be close to 31
	getClosestPrime(20); // next size will be close to 41
	getClosestPrime(29); // next size will be close to 59

}
*/

int maxElem(int arr[], int len){

	int max = 0;
	for(int i = 0; i < len; i++){
		max = fmax(max,arr[i]);
	}
	return max;

}

void display(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}


void countSort(int arr[], int k){

	int max = maxElem(arr,k);
	int count[max+1];
	int output[k+1];
	for(int i = 0; i <= max; i++){
		count[i] = 0;
	}
	for(int i = 1; i <= k; i++){
		count[arr[i]]++;
	}
	for(int i = 1; i <= max; i++){
		count[i] += count[i-1];
	}
	for(int i = k; i >= 1; i--){
		output[count[arr[i]]] = arr[i];
		count[arr[i]] -= 1;
	}
	for(int i = 1; i <= k; i++){
		arr[i] = output[i];
	}

}


int main(void){

	int arr[11] = {2,5,6,2,3,10,3,6,7,8};

	display(arr, 10);
	   countSort(arr, 10);
	   cout << "Array after Sorting: " << endl;
	   display(arr, 10);



}
