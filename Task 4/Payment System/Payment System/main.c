/*
 ============================================================================
 Name        : Payment System
 Author      : Ahmed Ragab
 Assignment  : Task 4
 ========================================================
 *Implementation of a Payment System
 *Read User Card
 *Scan Terminal Inputs
 *Check if the card is expired
 *Check if the terminal input amount is within the limit
 *Check Server for card validity according to Primary Account Number
 *Check Server for account available balance
 *Verify the transaction
 *Save transaction data into a sorted log
 *Save transaction data into Transactions.txt
 ============================================================================
*/
#include "App.h"
#define MAXIMUM_TRANSACTION_AMOUNT 5000.0
int main()
{

    ST_transaction_t transaction;
    transaction.transData.maxTransAmount= MAXIMUM_TRANSACTION_AMOUNT;
        uint8_t choice='y';

    ///Bonus Requirement
    ST_logServer_t transactionServer;
    init(&transactionServer);
    ////////////////////////

    while(choice == 'y'){
    system("cls");
    readCard(&(transaction.cardHolderData));
    terminalData(&(transaction.transData));
    transaction.transStat=verify(&(transaction.cardHolderData), &(transaction.transData));
    if(transaction.transStat){
        puts("The Transaction is APPROVED");
    }else{
        puts("The Transaction is DECLINED");
    }

    ///Bonus Requirement
    insertOrder(&transactionServer, &transaction);
    /////////////////////////////////////////////
    puts("Do You Want To Continue (y/n) : ");
    choice=getch();
    while(choice != 'y' && choice != 'n'){
        printf("Invalid Entry !\n");
        choice=getch();
    }
    }
}
