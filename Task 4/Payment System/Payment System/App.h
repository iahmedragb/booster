#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>

/**
*   ST_cardData_t : represent the required data to verify a card
*
*   uint8_t cardHolderName[25] : Name of the card holder
*   uint8_t primaryAccountNumber[20] : Number of the card
*   uint8_t cardExpirationDate[6]: Expiration date of the card
*/
//Card Data
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25], primaryAccountNumber[20], cardExpirationDate[6];
}ST_cardData_t;
/**
*   ST_terminalData_t : represent the applicable terminal data
*
*   float transAmount : transaction amount
*   float maxTransAmount : maximum transaction amount limit
*   uint8_t transactionDate[11]: transaction date
*/

///Terminal Data
typedef struct ST_terminalData_t
{
    float transAmount, maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

///Transaction Status
typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED,
}EN_transStat_t;

///Transaction data
typedef struct ST_transaction_t
{
    ST_terminalData_t transData;
    ST_cardData_t cardHolderData;
    EN_transStat_t transStat;
}ST_transaction_t;

///Server data
typedef struct ST_accountBalance_t
{

    uint8_t primaryAccountNumber[20];
    float balance;
}ST_accountBalance_t;


/**
*   readCard : This function reads the card and scan the name,PAN and ExpDate
*
*   paramter ST_cardData_t *CARD: pointer to structure ST_cardData_t represents the card
*/
void readCard(ST_cardData_t *CARD);

/**
*   terminalData : This function scan the amount of transaction and its date
*
*   paramter ST_terminalData_t *TERMINA: pointer to structure ST_terminalData_t represents the inputs of terminal
*/
void terminalData(ST_terminalData_t *TERMINAL);

/**
*   checkServer : This function check the card data verify if the card is expired
*                 then return the card state
*
*   paramter ST_cardData_t *CARD: pointer to structure ST_cardData_t represents the card
*
*   EN_transStat_t(return)  : the card state
*/

EN_transStat_t checkExpiry(ST_cardData_t *CARD, ST_terminalData_t *TERMINAL);


/**
*   checkMaximum : This function check if the transaction amount is within the limit
*
*   paramter ST_terminalData_t *TERMINAL: pointer to structure ST_terminalData_t represents the terminal
*
*   EN_transStat_t(return)  : the card state
*/

EN_transStat_t checkMaximum(ST_terminalData_t *TERMINAL);

/**
*   checkValid : This function check if the PAN exists on server
*
*   paramter ST_cardData_t *CARD: pointer to structure ST_cardData_t represents the card
*
*   EN_transStat_t(return)  : the card state
*/

EN_transStat_t checkValid(ST_cardData_t *CARD);


/**
*   checkBalance : This function check if the balance meets the required amount
*
*   paramter ST_cardData_t *CARD: pointer to structure ST_cardData_t represents the card
*
*   EN_transStat_t(return)  : the card state
*/

EN_transStat_t checkBalance(ST_cardData_t *CARD, float amount);

EN_transStat_t verify(ST_cardData_t *CARD, ST_terminalData_t *TERMINAL);

void transactionsLog(ST_transaction_t *TRANSACTION);

///Bouns Requirement
///Transactions Log Data Serever

typedef struct ST_log_t
{
    ST_transaction_t log;
    struct ST_log_t *next;
    struct ST_log_t *prev;
}ST_log_t;

typedef struct
{
    ST_log_t *header;
    ST_log_t *tail;
    uint32_t transactionsCount;
}ST_logServer_t;

void init(ST_logServer_t* ListPtr);
void insertOrder(ST_logServer_t *List ,ST_transaction_t *LAST_TRANSACTION);
void printServer(ST_logServer_t *List);


#endif // APP_H_INCLUDED
