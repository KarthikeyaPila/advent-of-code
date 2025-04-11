#include <stdio.h> 

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
    int diff;

    for(int i=0; i<1000; i++){
        scanf("%d%d", &arr_1[i], &arr_2[i]);
    }

    int len_1 = sizeof(arr_1)/sizeof(arr_1[0]);
    int len_2 = sizeof(arr_2)/sizeof(arr_2[0]);

    sort(arr_1, len_1);
    sort(arr_2, len_2);

    for(int i=0; i<len_1; i++){
        diff += arr_1[i] < arr_2[i] ? arr_2[i] - arr_1[i] : arr_1[i] - arr_2[i];
    }

    print_arr(arr_1, len_1);
    print_arr(arr_2, len_2);
        
    printf("%d\n", diff);

    return 0;
}

//answer: 1722302