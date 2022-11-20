#include <stdio.h>


typedef struct hostel{
  int rno;
  char name[100];
  char location[100];
  char gender[100];
  int roomno;
}hostel;

int lower = 1 ,upper =10;
void create(){
  
  

  hostel h;
  FILE *fp=fopen("hostel.text","a+");

  printf("Enter Roll Number : ");
  scanf("%d",&h.rno);

  printf("Enter name : ");
  scanf("%s",&h.name);

  printf("Enter location : ");
  scanf("%s",&h.location);

  printf("Enter gender : ");
  scanf("%s",&h.gender);

  h.roomno = getRoomNo(((rand()%(upper-lower+1))+lower));
  
  if(h.roomno!=0)
  {
    fwrite(&h,sizeof(hostel),1,fp);
  }


  
  fclose(fp);
}

int getRoomNo(int roomno){
  
  int allocated =0;
  FILE *fp = fopen("hostel.text","r");
  hostel h1;
  while(fread(&h1,sizeof(hostel),1,fp))
    {
    if(h1.roomno == roomno)
      allocated=1;
    }
  if(allocated==0)
  {
    return roomno;
  }
  else
    return getRoomNo(((rand()%(upper-lower+1))+lower));
  fclose(fp);
}
void display(){
  hostel h1;
  FILE *fp = fopen("hostel.text","r");
   printf("=======================================================================\n");
  printf("%-10s%-20s%-15s%-10s%-5s","Roll No","Name","Location","gender","Room-no");
  printf("\n=======================================================================\n");
  while(fread(&h1,sizeof(hostel),1,fp)){
    printf("%-10d%-20s%-15s%-10s%-5d \n \n",h1.rno,h1.name,h1.location,h1.gender,h1.roomno);
  }
  
  
}

int main(void) {
 int ch;
  do{
    printf("\n 1. New Room");
    printf("\n 2. Display");
    printf("\n 3. Exit");
    printf("\n 4. Enter Your Choice :");
    scanf("%d",&ch);

    switch(ch){
      case 1:
        create();
        break;
      case 2:
        display();
        break;
      case 3:
        break;
    }


    
  }while(ch!=0);
}