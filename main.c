#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ON 1
#define OFF 0
///#include<conio.h>
///Fuction 
void addstock();///for add stock to db
void sellstock();///for sell stock
void reportst();///for report
///public variables///
FILE * db,* temp,*report;///Direct to database
char filename [255] = "data.dat";
char temp_filename [255]= "temp.dat";
char report_filename[255] ="report.dat";
struct data add;///structure for add function
struct data{
    int amount;
    double price;
    double sellprice;
    double totalprice,totalsellprice;
    char name[50],id[255];
};
int main(){
    int x = ON;///Mode turn on program if 0 it is mean turn off
    while(x == ON){
        ///system("cls");///To clear terminal screen
        printf("=======Stock Management System By MADE=========\n");
        printf("1.ADD Stock\n2.Sell Stock\n3.Report\n4.Exit\n");///User interface
        int bnt;///Select Mode
        scanf("%d",&bnt);
        switch (bnt) {
            case 1: 
            ///for Add Stock
            addstock();
            
            break;
            case 2: 
            ///Sell Stock
            sellstock();
            break;
            case 3: 
            ///Report Stock
            reportst();
            break;
            case 4: 
            ///exit
            x = OFF;
            ///fclose(db);
            break;
        }
    }
    printf("Program already closed");
    exit(1);
    return 0;
}




///Fuction sessions

void addstock(){
    db = fopen(filename, "a");
    report = fopen(report_filename,"a");
    rewind(db);
    rewind(report);
    system("cls");
    printf("=======Add Stock========\n");
    printf("Insert Stock ID here:\n");
    scanf("%s", add.id);
    printf("Insert Stock name here:\n");
    scanf("%s", add.name);
    printf("Insert Stock price here:\n");
    scanf("%lf", &add.price);
    printf("Insert Stock amount here:\n");
    scanf("%d", &add.amount);
    printf("Insert Stock Sell price here:\n");
    scanf("%lf", &add.sellprice);
    add.totalprice = add.price * add.amount;
    if(db == NULL){
        printf("Cannot open file");
        exit(1);

    }else{
      fprintf(db,"\n%-5s %-5d  %-8.2lf %-5s  ",add.id,add.name,add.amount,add.sellprice);     
      fscanf(db,"%s  %s %d  %lf ",add.id,add.name,&add.amount,&add.sellprice);
      fprintf(report,"\n%-5s  %-5s  %-8.2lf  %-5d  %-8.2lf %-8.2lf",add.id,add.name,add.price,add.amount,add.totalprice,add.totalsellprice);
      fclose(db);
      fclose(report);
    }

    
}




///Sell stock 
void sellstock(){
  db = fopen(filename,"r");
  temp = fopen(temp_filename,"a+");
  if (temp == NULL){
    printf("Error");
  }else{
    char _inputid[6];
    printf("Insert ID here:");
    scanf("%s",_inputid);
    printf("%s\n",_inputid);
    int x = 1;
    int y,pay,file;
    
    while(x==1){
       fscanf(db,"%s  %s %d  %lf",add.id,add.name,&add.amount,&add.sellprice); 
        y = strcmp(_inputid,add.id);
      
        if (y== 0){
           printf("\n%-5s  %-5s %-5d  %-8.2lf\n",add.id,add.name,add.amount,add.sellprice);
          printf("How many to u want to sell:");
          scanf("%d",&pay);
          add.amount = add.amount - pay ;
          fprintf(temp,"\n%-5s  %-5s %-5d  %-8.2lf",add.id,add.name,add.amount,add.sellprice); 
          printf("\n%-5s  %-5s %-5d  %-8.2lf\n",add.id,add.name,add.amount,add.sellprice);
          
        }else{
          fprintf(temp,"\n%-5s  %-5s %-5d  %-8.2lf",add.id,add.name,add.amount,add.sellprice); 
        }
        
        
        if(feof(db)){
          file = remove(filename);
          file = rename(temp_filename,filename);
          fclose(temp);
          x = 0;
          break;
      
        }
      
      
     

    }
    fclose(db);
    





  }
}

    
    
        
    
    
    
    



void reportst(){
  db =fopen(filename,"r");
  report = fopen(report_filename,"a");
  if(db == NULL && report == NULL){
    perror("Error:");
  }else{
    ///statement
  }
}