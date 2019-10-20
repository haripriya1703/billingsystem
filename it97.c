#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
struct product
{
    int productid;
    int quantity;
    float price;
};
struct product p[20]={{1,10,30.00},{2,30,100.00},{3,15,80.00},
{4,18,121.00},{5,22,500.00},{6,11,129.00},{7,8,12.00},{8,30,99.00},
{9,11,111.00},{10,12,123.00}};
int homepage()
{
    int ch;
    printf("Welcome to Dollar's House\n");
    printf("Login as:\n");
    printf("1.Admin\n");
    printf("2.Billing Agent\n");
    scanf("%d",&ch);
    return ch;
}//homepage
void display(int i)
{
    printf("Details of %d product are:\n",i+1);
    printf("productid %d\t\t\t",p[i].productid);
    printf("available quantity of product %d\t\t\t",p[i].quantity);
    printf("price of the product is %.2f\n",p[i].price);
}
char username[]="haripriya";
char password[]="12345678";
char userbillagent[]="dollar";
char pwdbillingagent[]="1234";
char s[]="Dollar's House";
int discountpercent=5;
int main()
{
    int ch,j,k,ch1,ch2,i,pid,flag=0,r;
    int billcount=0,id[10],quantity[10],stockcount;
    char un[100];
    char un1[100];
    char pwd1[100];
    char pw[100];
    float newprice;
    char uba[100];
    char pba[100];
    int discount,h=112;
    do
    {
    int a=homepage();
    switch(a)
    {
        case 1://login as admin
        printf("Kindly enter user name:\n");
        scanf("%s",&un);
        printf("Kindly enter the password:\n");
        scanf("%s",&pw);
        if((strcmp(un,username)==0) && (strcmp(pw,password))==0)
            {
            printf("Welcome, %s!!\n",un);
            printf("1.Update username and password\n");
            printf("2.Update cost\n");
            printf("3.Update stock\n");
            printf("4.Update Discount Percentage\n");
            printf("5.Display Product information\n");
            printf("6.logout\n");
            scanf("%d",&ch1);
            do
            {
            switch(ch1)
            {
            case 1://Update username and password
                printf("enter new username and password\n");
                scanf("%s %s",&un1,&pwd1);
                strcpy(username,un1);
                strcpy(password,pwd1);
                printf("successfully updated username as %s and password as %s\n",username,password);
                break;
            case 2://Update cost
                printf("enter productid whose cost per unit is to be updated\n");
                scanf("%d",&pid);
                for(i=0;i<=9;i++)
                {
                if(pid==p[i].productid)
                {
                    printf("enter new price of %d product\n",pid);
                    scanf("%f",&newprice);
                    p[i].price=newprice;
                    printf("cost of %d updated sucessfully...\n",pid);
                    printf("new price of %d is %.2f\n",pid,p[i].price);
                    flag=1;
                }//if
                }//for
                if(flag==0)
                    printf("please enter valid product id\n");
                break;
            case 3://Update stock
                printf("enter productid to update stock\n");
                scanf("%d",&pid);
                printf("enter stock value to increase stock\n");
                scanf("%d",&stockcount);
                for(i=0;i<=9;i++)
                {
                    if(pid==p[i].productid)
                    {
                        p[i].quantity=p[i].quantity+stockcount;
                        printf("stock for %d updated successfully\n",pid);
                        printf("new stock for %d is %d\n",pid,p[i].quantity);
                        flag=1;
                    }//if
                }//for
                if(flag==0)
                    printf("please enter valid product id\n");
                break;
            case 4://Update Discount Percentage
                printf("enter new discount percentage\n");
                scanf("%d",&discount);
                discountpercent=discount;
                printf("discount percent updated successfully as %d\n",discountpercent);
                break;
            case 5://Display Product information
                printf("enter productid to display product info");
                scanf("%d",&pid);
                for(i=0;i<=9;i++)
                {
                    if(pid==p[i].productid)
                    {
                        display(i);
                        flag=1;
                    }//if
                }//for
                if(flag==0)
                    printf("please enter valid product id\n");
                break;
            case 6://logout
                printf("Successfully logged out\n");
                break;
            default:exit(0);
            }//switch
            }while(ch==6);//do
            }//if
        else
        {
            printf("invalid login.... try again\n");
        }//else
        break;
            case 2://login as billing agent
                printf("Welcome...!!\n");
                printf("enter username\n");
                scanf("%s",&uba);
                printf("enter password\n");
                scanf("%s",&pba);
                float totalbill=0.00;
                do
                {
                switch(1)//
                {
                case 1:
                if((strcmp(uba,userbillagent)==0) && (strcmp(pba,pwdbillingagent))==0)
                {
                printf("enter product count\n");
                scanf("%d",&billcount);
                printf("enter product id followed by quantity purchased of %d items:\n",
                       billcount);
                for(i=0;i<billcount;i++)
                {
                scanf("%d %d",&id[i],&quantity[i]);
                //printf("%d",id[i]);
                }//for
                printf("**********************************************************************************************************************\n");
                printf("                        Thankyou for visiting %s",s,"            \n");
                time_t T= time(NULL);
                struct  tm tm = *localtime(&T);
                printf("\nDate:%02d/%02d/%04d\t\t\t\t",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
                printf("Time:%02d:%02d:%02d\t\t\t\t",tm.tm_hour, tm.tm_min, tm.tm_sec);
                printf("Bill Number:%d\n",h);
                h++;
                printf("ProductID\t\t\tQuantity\t\t\tPricePerQty\t\t\tPrice\n");
                for(i=0;i<billcount;i++)
                {
                int u=id[i];
                float v=quantity[i]*p[u-1].price;
                printf("%-9d\t\t\t%-8d\t\t\t%-11.2f\t\t\t%-5.2f\n",id[i],quantity[i],p[u-1].price,v);
                totalbill=totalbill+v;
                }//for
                printf("\t\t\t\t\t \t\t  \tSub Total:\t\t\t%-5.2f\n",totalbill);
                printf("\t\t\t\t\t \t\t  \tDiscount:\t\t\t%5d%%\n",discountpercent);
                totalbill=totalbill-(totalbill*discountpercent)/100;
                printf("\t\t\t\t\t \t\t  \tTotal:\t\t\t\t%-5.2f\n",totalbill);
                printf("**********************************************************************************************************************\n");
                totalbill=0;
                }//if
                else
                {
                    printf("invalid login....\n");
                }//else
                break;
                default:exit(0);
                }//switch
                printf("do you want to continue billing yes-1/no-0\n");
                scanf("%d",&r);
                }while(r==1);//do
                break;
            default:exit(0);
    }//switch
    printf("do you want to continue yes-1/no-0\n");
    scanf("%d",&k);
    }while(k==1);//do
    return 0;
}//main
