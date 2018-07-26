// Caleb Brown A01023052
// Display.c
// June 25th, 2018

#define _CRT_SECURE_NO_WARNINGS
# include < stdio.h > 
#include < conio.h > 
#define NAMESIZE 255 // Max namesize
#define DATASIZE 10 // Max data count

typedef struct {
	int accountNum;
	double accountBalance;
	double lastPaymentAmount;
	char firstName[NAMESIZE];
	char lastName[NAMESIZE];
}
person;

void readData(char * argv[]);

int main(int argc, char * argv[]) {

	readData(argv); 

	_getch();

}

void readData(char * argv[]) { //Reads and displays data from .dat input file
	FILE * readFile = fopen(argv[1], "rb");
	person arr[DATASIZE];
	int count = 0, result;

	if (readFile == NULL) {
		printf("\n Error open readFile");
		_getch();
	}
	else {

		printf("AccountNumber    FirstName  LastName  AccountBalance  LastPaymentAmount\n");
		while (!feof(readFile)) {
			result = fread(&arr[count], sizeof(person), 1, readFile);

			if (result != 0 && arr[count].accountNum > 0) {
				printf("%d", arr[count].accountNum);
				printf("%23s", arr[count].firstName);
				printf("%10s", arr[count].lastName);
				printf("%16.2lf", arr[count].accountBalance);
				printf("%19.2lf\n", arr[count].lastPaymentAmount);

			}
			count++;
		}

	}

}
