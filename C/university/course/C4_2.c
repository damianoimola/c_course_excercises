#include <stdio.h>

int binary_search(int n, int arr[n], int v);
int rec_binary_search(int n, int arr[n], int start, int end, int v);

int main(int argc, char * argv[]){
	int n1=4, n2 = 11;
	int arr1[4] = {1,2,4,5};
	int arr2[11] = {1,2,3,4,5,6,7,8,9,10,11};

	int res1 = binary_search(n1, arr1, 3);
	int res2 = binary_search(n2, arr2, 1);

	printf(res1 == -1 ? "L'elemento non e' presente\n" : "L'elemento si trova nell'indice %d dell'array\n", res1);
	printf(res2 == -1 ? "L'elemento non e' presente\n" : "L'elemento si trova nell'indice %d dell'array\n", res2);



	int res3 = rec_binary_search(n1, arr1, 0, n1-1, 3);
	int res4 = rec_binary_search(n2, arr2, 0, n2-1, 1);

	printf(res3 == -1 ? "L'elemento non e' presente\n" : "L'elemento si trova nell'indice %d dell'array\n", res1);
	printf(res4 == -1 ? "L'elemento non e' presente\n" : "L'elemento si trova nell'indice %d dell'array\n", res2);

	return 0;
}




int binary_search(int n, int arr[n], int v){
	int end = n-1;
	int start = 0;

	while(end != start && end > start){
		int middle = (end + start)/2;
		int midval = arr[middle];

		if(midval == v){
			return middle;
		} else if(midval > v){
			end = middle - 1;
		} else {
			start = middle + 1;
		}
	}
	return -1;
}





// recursive
int rec_binary_search(int n, int arr[n], int start, int end, int v){
	int middle = (start + end)/2;
	int midval = arr[middle];
	if(start == end || start > end){
		return -1;
	} else if (midval == v){
		return middle;
	} else if(midval < v){
		return rec_binary_search(n, arr, middle+1, end, v);
	} else {
		return rec_binary_search(n, arr, start, middle-1, v);
	}

}
