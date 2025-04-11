#include <stdio.h> 

int main(){
    double arr_1[10000];
    double arr_2[10000];

    double answer=0;

    for(int i=0; i<1342/2; i++){
        scanf("%lf%lf", &arr_1[i], &arr_2[i]);
    }

    for(int i=0; i<1342/2; i++){
        answer += arr_1[i]*arr_2[i];
    }

    printf("%lf\n", answer);

    return 0;
}