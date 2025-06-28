// MINI PROJECT BY AMAN VERMA B.TECH(C.S.E.) 2nd YEAR

#include<stdio.h>
#include<stdlib.h>

struct employee
{
    int id;
	char Name[50];
    int age;
    char address[25];
    char department[25];
    float salary;
}e;

FILE*fe;

void add();
void emp_remove();
void list(); 

void add()
{
    fe = fopen("employee.txt", "ab");
    
	printf("Enter employee ID:");
    scanf("%d",&e.id);
    
	printf("Employee's Name: ");
    fflush(stdin);
    gets(e.Name);

    printf("Age: ");
    fflush(stdin);
    scanf("%d",&e.age);

    printf("Address: ");
    fflush(stdin);
    gets(e.address);
    
    printf("Department: ");
    fflush(stdin);
    gets(e.department);
    
    printf("Salary: ");
    fflush(stdin);
    scanf("%f",&e.salary);
	
	fwrite(&e, sizeof(e), 1, fe);
    fclose(fe);
}

void emp_remove()
{  	    int id, f=0;
    printf("Enter Employee ID to be removed: ");
    scanf("%d", &id);

    FILE *ft;

    fe = fopen("employee.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&e, sizeof(e), 1, fe) == 1){

        if(id == e.id){
            f=1;
        }else{
            fwrite(&e, sizeof(e), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nEmployee Data Removed Successfully....");
    }else{
        printf("\n\n INVALID ID.....!!!");
    }

    fclose(fe);
    fclose(ft);

    remove("employee.txt");
    rename("temp.txt", "employee.txt");

}

void list()
{ fe = fopen("employee.txt", "rb");
   if(fe== NULL)
   { printf("\nLIST IS EMPTY....!!!");
   }
   else
   {  while(fread(&e, sizeof(e), 1, fe) == 1){ 
   printf("Employee name: %s\nEmployee's ID: %d\nAge: %d\nAddress: %s\nDepartment: %s\nSalary: %.2f\n\n",e.Name,e.id,e.age,e.address,e.department,e.salary);
}
  fclose(fe);
}
}

int main(){

    int ch;
  
    while(1){
    	system("cls");
        printf("EMPLOYEE MANAGEMENT SYSTEM \n\n");
        printf("1.Add new Employee\n");
        printf("2.Remove an Employee\n");
        printf("3.Employee's List\n");
        printf("0.Exit\n\n");
        printf("Choose the option: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
		   add();
            break;

        case 2:
            emp_remove();
            break;

        case 3:
            list();
            break;

        default:
            printf("Invalid request.....!!!!\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}
