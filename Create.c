// Caleb Brown A01023052
// Create.c
// June 25th, 2018


#define _CRT_SECURE_NO_WARNINGS
#include < stdio.h > 
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

void getData(char * args[], person arr[]);
int writeData(person arr[], char * args[], int unitNum);
void readData(const char * fileName);

int main(int argc, char * argv[]) {
	person arr[DATASIZE];
	int arraySize = DATASIZE;

	int argSize = sizeof(argv);

	if (argSize < 3) { // Checks if command line arguments contain an input and output file
		printf("\nError open inputFile \\ outputFile\n");
		_getch();
		return 0;
	}

	getData(argv, arr); // Reads inputFiles and populates array of structs with person data.
	
	if (writeData(arr, argv, arraySize) == 1) { // Writes array of structs to file to the passed file.
		
		readData("accounts.dat"); // Used for testing purposes
	
	}

	_getch();

}

void getData(char * args[], person arr[]) {
	int count = 0;
	FILE * inputFile = fopen(args[1], "r");

	while (!feof(inputFile)) {

		fscanf(inputFile, "%d,%[^,],%[^,],%lf,%lf", &arr[count].accountNum, &arr[count].firstName, &arr[count].lastName, &arr[count].accountBalance, &arr[count].lastPaymentAmount);
		count++;
	}
	fclose(inputFile);
}

int writeData(person arr[], char * args[], int unitNum) {
	FILE * outputFile = fopen(args[2], "r");
	int choice = 0;
	if (outputFile == NULL) { // If file doesn't exist
		outputFile = fopen(args[2], "w");
		fwrite(arr, sizeof(person), unitNum, outputFile);

	}
	else { // If file exists
		printf("File already exists\n1 to overwrite\n0 to exit\n");
		scanf("%d", &choice);

		while (choice != 1 || choice != 0) {

			if (choice == 1) {
				outputFile = fopen(args[2], "w+");
				fwrite(arr, sizeof(person), unitNum, outputFile);
				fclose(outputFile);
				return 1;
				
			}

			if (choice == 0) {
				fclose(outputFile);
				exit(0);
			}

			printf("\nNot a valid choice, try again");
			scanf("\n%d", &choice);

		}

	}
	fclose(outputFile);
	return 1;

}


void readData(const char * fileName) {   // Used for testing puposes, reads and displays data from .dat file
	FILE * readFile = fopen(fileName, "rb");
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
