#include "Mystack.h"
//initialize the stacks by (allocating memory) and set (top = -1)
void init(STACK *ptr ,uint8_t size){
    ptr->item=(TYPE*)calloc(size,sizeof(TYPE));   //allocating the required memory size
    if(ptr->item==NULL){
        printf("Unable to allocate memory !\n");
        exit(1);
    }
    ptr->top=-1;                                //Stack is empty and (top = -1)
    ptr->Size=size;
}
//push value to a stack
void push(STACK *ptr ,TYPE value){
    if(ptr->top == (ptr->Size)-1){                              //Check if the stack is overflow
      ptr->item=(TYPE*)realloc(ptr->item , 2*ptr->Size);        //allocating new memory size equals to the double of current
      if(ptr->item ==NULL){                                     //if failed to allocate the new memory size then the stack is overflow
        printf("Stack Overflow !!\n");
        return;
        }
        ptr->Size*=2;
    }
        ptr->top++;                                             //if succeeded then push the value to the stack
        ptr->item[ptr->top]=value;

}
//pop value from the stack
TYPE pop(STACK *ptr){
    if(ptr->top == -1){
        printf("Stack Underflow !!\n");             //Check if the stack is underflow
        return '0';
    }else{
        TYPE value=ptr->item[ptr->top];             //pop the value of the top and decrement the top by 1
        ptr->top--;
        return value;
    }
}
//free memory of the stack
void deallocate(STACK *ptr){
    if(ptr->item != NULL){                      //check if a memory is allocated
        free(ptr->item);                        //free the
        ptr->top=-1;                            //empty stack (size=0 and top = -1)
        ptr->Size=0;
    }
}

TYPE* balancedParentheses(TYPE *exp){
    TYPE* b="Balanced";
    TYPE* notB="Not Balanced";
    STACK brackets;
    init(&brackets,SIZE);
    uint8_t error = 0;
    uint8_t len=strlen(exp);                //calculate the string expression length for iterations
    uint8_t i=0;
    TYPE buff;                          //char buffer to scan the expression character by character
    while(i<len){
        buff=exp[i];
        //check if the char is an opening brackets
        if(buff=='(' || buff=='{' || buff=='['){
            push(&brackets,buff);
        }//check if the char is a closing bracket
        else if(buff==')' || buff=='}' || buff==']'){
                if(brackets.top == -1){                 //check if a stack is empty
                    error=1;
                    break;
                }else{  //check for a well formed matching
                    if(buff==')' && brackets.item[brackets.top]=='('){
                        pop(&brackets);
                    }else if(buff=='}' && brackets.item[brackets.top]=='{'){
                        pop(&brackets);
                    }else if(buff==']' && brackets.item[brackets.top]=='['){
                        pop(&brackets);
                    }else{
                        error=1;
                        break;
                    }
                }
        }

    i++;
    }
    if(!error && brackets.top!=-1){     //check if expression is ended and yet still an opening parentheses in the stack without match
            error=1;
        }
        deallocate(&brackets);

    return error ? notB : b ;


}
