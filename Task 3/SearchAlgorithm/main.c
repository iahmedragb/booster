#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define Target 70   //Required value
#define ArrMax 255  //Maximum array size
#define uint8_t_MAX 255 //maximum value
/*
 ============================================================================
 Name        : Binary Search
 Author      : Ahmed Ragab
 Assignment  : Task 3 (Implement your own searching algorithm)
 ========================================================
 *Search an array for a specific value
 *Array[0~255]
 *First check if the array is sorted
 *Sort the array if not sorted
 *Search for the value using binary search
 ============================================================================
*/

uint8_t binarySearch(uint32_t* ,uint8_t ,uint32_t );   //search an array using binary search
uint8_t sorted(uint32_t * ,uint8_t );    //check if an array is sorted in ascending order
void sortArray(uint32_t * ,uint8_t ); //sort an array in ascending order
void swapp(uint32_t* , uint32_t*);          //swap values
void printArray(uint32_t *Array , uint8_t SIZE); //print the array

int main(){
    uint8_t arrSize;        //Array size
    uint32_t exp[]={10,90,50,70,20,80,60,40,30,0};//integers to be searched

    //check if the array size within the boundary
    if((sizeof(exp)/sizeof(exp[0])) >ArrMax){
            printf("Invalid array size !\n");
    }else{
            //calculate array size
            arrSize=(sizeof(exp)/sizeof(exp[0]));

            //Print the array
            printf("Initial Array : ");
            printArray(exp , arrSize);

            //search the array for the target value
            uint8_t result=binarySearch(exp ,arrSize ,Target);
            if(result == uint8_t_MAX)
                printf("Target Not Found !!\n");
            else
                printf("\nFound at [%d] = %d\n",result,exp[result]);
    }

}

uint8_t binarySearch(uint32_t* exp,uint8_t SIZE,uint32_t target){
    if(!sorted(exp, SIZE)){
        sortArray(exp, SIZE);
        //Print the sorted array
        printf("\nAfter Sorting : ");
        printArray(exp , SIZE);
    }
    uint8_t lb=0;
    uint8_t ub=SIZE-1;
    uint8_t m;

    while(lb <= ub){
    m=(lb+ub)/2;
    if(exp[m] == target){
        return m;
    }else if(exp[m] < target){
        lb=m+1;
    }else if(exp[m] > target){
        ub=m-1;
    }
    }

    return uint8_t_MAX;

}
//Check if array is sorted
uint8_t sorted(uint32_t *exp ,uint8_t SIZE){
        uint8_t i;
        for( i=0 ;i<SIZE-1 ;i++){
                if( exp[i] > exp[i+1] )
                    return 0;
        }
        return 1;
}
//Sort array using bubble sort
void sortArray(uint32_t *exp ,uint8_t SIZE){

        uint8_t i;
        _Bool swapped;
        //Bubble Sort
        do{
            swapped=0;
            for(i=0 ; i<SIZE-1 ;i++){

                if(exp[i] > exp[i+1]){
                    swapp(&exp[i] , &exp[i+1]);
                    swapped=1;
                }
            }
        }while(swapped);

}

//Swap values using call by reference
void swapp(uint32_t* x, uint32_t* y){
                    uint32_t temp=*x;
                    *x=*y;
                    *y=temp;
}
void printArray(uint32_t *Array , uint8_t SIZE){
    uint8_t i;
    for(i=0 ; i<SIZE ; i++){
        printf("%4d",Array[i]);
    }
}
