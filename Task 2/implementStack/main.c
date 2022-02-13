#include "Mystack.h"
/*
 ============================================================================
 Name        : Check an expression for a balanced parentheses
 Author      : Ahmed Ragab
 Assignment  : Task 2 (Implement your own stack)
 ========================================================
 *Input an expression to check for a balanced or non-balanced format
 *Balanced example [{()}]
 *Non-Balanced example [)
 ============================================================================
*/
int main(){
    TYPE exp[SIZE];                                //Determine buffer DataType & Size  for the expression string
    while(1){
    printf("Enter expression to check : ");         //User input an expression
    gets(exp);
    printf("%s\n",balancedParentheses(exp));        //Check expression
    }
}
