#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>


struct cashier
{
    float price;
    char product_name[100];
    int product_id;
    int quantity;
    struct cashier *next;
};


struct cashier *start = NULL,*last=NULL,*k;
void create(int);
void insert_product(struct cashier *start);
float total;
float cash(float);


float gst_tax(float sum)
{
    float gst;
    if(sum>=10000.0)
    {
        return (0.30);
    }
    else if(sum>=5000.0&&sum<10000.0)
    {
        return(0.25);
    }
    else if(sum>=1000.0&&sum<5000.0)
    {

        return(0.18);

    }
    else
    {
        return(0.12);
    }
}




void create(int n)
{
    int i;

    start=(struct cashier*)malloc(sizeof(struct cashier));

    printf("\nEnter the product ID of the product: ");
    scanf("%d",&start->product_id);
    printf("\nEnter the name of the product: ");
    scanf("%s",start->product_name);
    printf("\nEnter the Quantity of the Product: ");
    scanf("\n %d",&start->quantity);
    printf("\nEnter the Price of Single Item: ");
    scanf("%f",&start->price);
    start->next=NULL;
    last=start;
    for(i=1;i<n;i++)
    {
        k=(struct cashier*)malloc(sizeof(struct cashier));
        printf("\nEnter the product ID of the product: ");
        scanf("%d",&k->product_id);
        printf("\nEnter the name of the product: ");
        scanf("%s",k->product_name);
        printf("\nEnter the Quantity of the Product: ");
        scanf("%d",&k->quantity);
        printf("\nEnter the price of Single Product: ");
        scanf("%f",&k->price);
        k->next=NULL;
        last->next=k;
        last=k;
    }
}
void insert_product(struct cashier *k){

    struct cashier *k1;

    k1=(struct cashier*)malloc(sizeof(struct cashier));
    printf("\nEnter the product ID of the product: ");
    scanf("%d",&k1->product_id);
    printf("\nEnter the name of the product: ");
    scanf("%s",k1->product_name);
    printf("\nEnter the Quantity of the Product: ");
    scanf("\n %d",&k1->quantity);
    printf("\nEnter the price of Single Product: ");
    scanf("%f",&k1->price);
    k1->next=NULL;
    k=start;
    while (k->next!=NULL){
        k=k->next;
    }
    k->next=k1;

}
void delete_product()
{
    struct cashier *back,*t,*k;
    int id;
    int flag=0;
    printf("\nEnter the Product ID you want to delete: ");
    scanf("%d",&id);
    if(start->product_id==id)
    {
        start=start->next;
        flag=1;
    }
    else
    {
        back=start;
        k=start->next;
        while(k->product_id!=id)
        {
            back=k;
            k=k->next;
        }
        back->next=k->next;
        free(k);
        flag=1;
    }
    if(flag==0) {
        printf("\nThe item was not not found!!!");
    }else{
        printf("\n The item is deleted ");
}
}

void display_bill(struct cashier *ptr2)
{

    struct cashier *ptr;
    float sum=0.0,new;
    float totalquantiyprice=0.0;
    ptr = ptr2;



    printf("\n******************************************************************************************");
    printf("\n****************************************RECIEPT*******************************************");
    printf("\n******************************************************************************************");
    printf("\nID\t\tProduct\t\tQuantity\tProduct Price\t\tTotal Price");
    while(ptr!=NULL)
    {
        printf("\n%d\t",ptr->product_id);
        printf("\t%s\t",ptr->product_name);
        printf("\t%d\t",ptr->quantity);
        printf("\t%f\t", ptr->price);
        totalquantiyprice=(ptr->quantity)* (ptr->price);
        printf("\t%f\n",totalquantiyprice);
        printf("\n******************************************************************************************");
        sum=sum+totalquantiyprice;
        ptr=ptr->next;
    }
    total= sum + (sum * gst_tax(sum));
    printf("\nFinal Price= %f",sum);

    printf("\nGST Added= %f",gst_tax(sum));
    printf("\nTotal Amount= %f",total);
//    printf("\nThe Discounted Price is: ",avail_discount(total));
}

void printing_bill(struct cashier *ptr2)
{
    struct cashier *ptr;
    float sum=0.0,new;
    float totalquantiyprice=0.0;
    ptr = ptr2;
    FILE *fpw;

    /*Char array to store strings */


    /*Opening the file FILEW.TXT in "w" mode for writing*/
    fpw = fopen("C:\\Users\\Reuben Coutinho\\CLionProjects\\Supermarket Cashier System\\cmake-build-debug\\Bill.txt", "w");
    if (fpw == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }
    /*Error handling for output file*/

        fprintf(fpw,"\n*******************************Super Market Cashier System********************************");
        fprintf(fpw,"\n****************************************RECIEPT*******************************************");
        fprintf(fpw,"\n******************************************************************************************");
        fprintf(fpw,"\nID\t\tProduct\t\tQuantity\t\tProduct Price\t\tTotal Price");
        while(ptr!=NULL)
        {
            fprintf(fpw,"\n%d\t\t%s\t\t%d\t\t\t    %f\t",ptr->product_id,ptr->product_name,ptr->quantity,ptr->price);
            totalquantiyprice=(ptr->quantity)* (ptr->price);
            fprintf(fpw,"\t\t%f\n",totalquantiyprice);
            fprintf(fpw,"\n******************************************************************************************");
            sum=sum+totalquantiyprice;
            ptr=ptr->next;
        }
        total= sum + (sum * gst_tax(sum));
        fprintf(fpw,"\nFinal Price= %f",sum);

        fprintf(fpw,"\nGST Added= %f",gst_tax(sum));
        fprintf(fpw,"\nTotal Amount= %f",total);
        printf("Bill Printed");



    /*Closing the Output file after successful writing*/
    fclose(fpw);








}



float cash(float balance)
{

    float amount=0.0;
    char n;
    printf("\nEnter the Amount of Cash given by Customer: ");
    scanf("%f",&amount);
    if(amount==balance)
    {
        return amount;
    }
    else if(amount>=balance)
    {
        amount=amount-balance;
        printf("\nThe amount to be returned(Change) is: %f",amount);
        printf("\nEnter Y/y after amount returned");
        scanf("%c",&n);
        if(n=='y'||n=='Y')
        {
            return balance;
        }
    }
}
//float avail_discount(float balance)
//{
//    float discount;
//    printf("\n\nEnter the discount Percentage");
//    scanf("%f",discount);
//    balance=balance-(discount*balance);
//    return balance;
//}
void main()
{ char name[50];
    int option,n;
    do{printf("\n-----Supermarket Queue and Billing System-----\n");


        printf("\n1) To Entering the number of products you have");
        printf("\n2) To Add the list of products");
        printf("\n3) To Insert Another Product");
        printf("\n4) To Delete a product from the list");
        printf("\n5) To Display the BILL");
        printf("\n6) Payment by Cash Supported Only");
        printf("\n7) To Print The Bill");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {


            case 1:printf("Enter the number of items");
                scanf("%d",&n);
                break;
            case 2: create(n);
                printf("\nBILL DETAILS ENTERED");
                break;
            case 3: insert_product(k);
                printf("\nBILL DETAILS ENTERED");
                break;
            case 4: delete_product();
                break;
            case 5:
                display_bill(start);
                break;
            case 6: cash(total);
                break;
            case 7: printing_bill(start);
                break;
            default:printf("Wrong Choice Entered");
        }
    }while(option!=7);
    getch();
}