#include "App.h"


ST_accountBalance_t serverData[10]={\
                {"123456789",100.00},\
                {"234567891",6000.00},\
                {"567891234",3250.25},\
                {"456789123",1500.12},\
                {"258649173",500.00},\
                {"654823719",2100.00},\
                {"971362485",0.00},\
                {"793148625",1.00},\
                {"123123456",10.12},\
                {"456789321",0.55}      };
void readCard(ST_cardData_t *CARD){

    puts("Please Enter Card Data : ");
    printf("Please Enter The Card Holder Name : ");
    scanf(" %[^\n]",CARD->cardHolderName);
    printf("Please Enter the Primary Account Number : ");
    scanf("%s",CARD->primaryAccountNumber);
    printf("Please card Expiry Date : ");
    scanf("%s",CARD->cardExpirationDate);
}
void terminalData(ST_terminalData_t *TERMINAL){
    puts("Please Enter Terminal Data : ");
    printf("Please Enter the transaction Amount : ");
    scanf("%f",&(TERMINAL->transAmount));
    printf("Please Enter transaction Date : ");
    scanf("%s",TERMINAL->transactionDate);


}
EN_transStat_t verify(ST_cardData_t *CARD, ST_terminalData_t *TERMINAL){
    if(!checkExpiry(CARD , TERMINAL)){
        puts("Card is Expired !");
        return DECLINED;
    }else if(!checkMaximum(TERMINAL)){
        puts("Sorry, Maximum Limit is 5000.00 !");
        return DECLINED;
    }else if(!checkValid(CARD)){
        puts("PAN Does Not Exist !");
        return DECLINED;
    }else if(!checkBalance(CARD, TERMINAL->transAmount)){
        puts("Not Enough Balance !");
        return DECLINED;
    }
    return APPROVED;
}
EN_transStat_t checkExpiry(ST_cardData_t *CARD, ST_terminalData_t *TERMINAL){
    uint8_t cardExpiryDateMonth;
    uint8_t cardExpiryDateYear;
    uint8_t transactionMonth;
    uint8_t transactionYear;
    uint8_t* token;
    uint8_t delim[]="/";

    ///For Card Date
    token=strtok(CARD->cardExpirationDate, delim);
    cardExpiryDateMonth=atoi(token);
    token=strtok(NULL, delim);
    cardExpiryDateYear=atoi(token);
    ///For Terminal
    token=strtok(TERMINAL->transactionDate, delim);
    token=strtok(NULL, delim);
    transactionMonth=atoi(token);
    token=strtok(NULL, delim);
    transactionYear= (atoi(token))%100;
    if(cardExpiryDateYear > transactionYear){
        return APPROVED;
    }else if(cardExpiryDateYear < transactionYear){
        return DECLINED;
    }else{
        if(cardExpiryDateMonth > transactionMonth)
            return APPROVED;
        else
            return DECLINED;
    }

}
EN_transStat_t checkMaximum(ST_terminalData_t *TERMINAL){

   return (TERMINAL->transAmount > TERMINAL->maxTransAmount) ? DECLINED : APPROVED ;
}
EN_transStat_t checkBalance(ST_cardData_t *CARD, float amount){
    uint8_t i;
    for(i=0 ; i<10 ; i++){
        if( strcmp(CARD->primaryAccountNumber, serverData[i].primaryAccountNumber) == 0){
            if(serverData[i].balance >= amount)
            return APPROVED;
        }
    }
    return DECLINED;
}
EN_transStat_t checkValid(ST_cardData_t *CARD){
    uint8_t i;
    for(i=0 ; i<10 ; i++){
        if( strcmp(CARD->primaryAccountNumber, serverData[i].primaryAccountNumber) == 0)

            return APPROVED;
    }
    return DECLINED;
}


///Bouns Requirement
///Transactions Log Data Server

void init(ST_logServer_t* List){
    List->header=NULL;
    List->tail=NULL;
    List->transactionsCount=0;
}
//Insert in ascending order according to PAN
void printServer(ST_logServer_t *List){
    FILE *fp=fopen("transactionServer.txt","w");
    if(fp == NULL){
        printf("Can not find Server");
        exit(-9999);
    }
    ST_log_t *current=List->header;
    uint8_t index=1;

    fprintf(fp,"         %3d Transactions\n",(List->transactionsCount));
    fprintf(fp,"======================================\n");
    fprintf(fp,"\n          |   PAN   |   |Transaction Amount|   |  Status  |\n")  ;

    while(current != NULL){

            fprintf(fp,"Log[%3d] : %s       %4.2f              ",index++,current->log.cardHolderData.primaryAccountNumber, current->log.transData.transAmount);
            if(current->log.transStat)
                fprintf(fp,"APPROVED\n");
            else
                fprintf(fp,"DECLINED\n");
            current=current->next;
        }
    fprintf(fp,"\nNo More Logs\n");
    fclose(fp);
    fp=NULL;
    free(current);
}
void insertOrder(ST_logServer_t *List ,ST_transaction_t *LAST_TRANSACTION){
    ST_log_t* newLog=(ST_log_t*)malloc(sizeof(ST_log_t));
    if(newLog==NULL){
        printf("Unable to allocate new log !\n");
        return;
    }
    ///for PAN
    strcpy(newLog->log.cardHolderData.primaryAccountNumber, LAST_TRANSACTION->cardHolderData.primaryAccountNumber);
    ///Transaction Amount
    newLog->log.transData.transAmount=LAST_TRANSACTION->transData.transAmount;
    ///State
    newLog->log.transStat=LAST_TRANSACTION->transStat;
    newLog->next=NULL;
    newLog->prev=NULL;
    //check if list is empty
    if(List->transactionsCount==0){
    List->tail=newLog;
    List->header=newLog;
    }else{
            ST_log_t *current=List->header;
            while(1){
            if (strcmp(newLog->log.cardHolderData.primaryAccountNumber ,current->log.cardHolderData.primaryAccountNumber) < 0){
                    if(current == List->header){
                        List->header=newLog;
                        newLog->next=current;
                        current->prev=newLog;
                        break;
                    }else{

                    current->prev->next=newLog;
                    newLog->prev=current->prev;
                    current->prev=newLog;
                    newLog->next=current;

                    break;

                    }
            }else if(current->next==NULL){
                    List->tail->next=newLog;
                    newLog->prev=List->tail;
                    List->tail=newLog;
                    break;
            }
            current=current->next;
        }
    }
            List->transactionsCount++;
            printServer(List);

}
