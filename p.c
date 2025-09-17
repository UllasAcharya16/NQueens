#include <stdio.h>

// void array(int arr[][]){

// arr[0][1] = 1;
// }

void main (){

    int i , j, n= 5;
    int arr[n][n];

    for( i =1 ; i<= n ;i++){
        for( i =1 ; i<= n ;i++){
        arr[i][j] = 0;
    }

}

// array (arr[][]);

    for( i =1 ; i<= n ;i++){
        for( j =1 ; j<= n ;j++){
            printf("%d", arr[i][j]);
}
    }
    printf("/n");
}