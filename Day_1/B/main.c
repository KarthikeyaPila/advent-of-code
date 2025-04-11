#include <stdio.h> 
#include <stdlib.h> 

#define HASH_SIZE 100000

void print_arr(int *arr, int len){
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return;
}

void sort(int *arr, int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

int main(){
    int arr_1[1000];
    int arr_2[1000];
    int hash[HASH_SIZE];
    int sum = 0;

    for(int i=0; i<HASH_SIZE; i++){
        hash[i] = 0;
    }

    for(int i=0; i<1000; i++){
        scanf("%d%d", &arr_1[i], &arr_2[i]);
        hash[arr_2[i]]++;
    }

    int len_1 = sizeof(arr_1)/sizeof(arr_1[0]);
    int len_2 = sizeof(arr_2)/sizeof(arr_2[0]);

    for(int i=0; i<1000; i++){
        sum += arr_1[i]*hash[arr_1[i]];
    }
        
    printf("%d\n", sum);
    
    return 0;
}
