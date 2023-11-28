#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PREFIX "bus"
#define FILE_EXTENSION ".txt"
#define MAX_SEATS 57
#define SEAT_PRICE 1300


char ch[10][130] = {"SimbaCoach-01", "SimbaCoach-02", "SimbaCoach-03", "SimbaCoach-04", "SimbaCoach-05", "SimbaCoach-06", "SimbaCoach-07", "SimbaCoach-08"};
char name[MAX_SEATS][100] = {'\0'};
char number[MAX_SEATS][2] = {'\0'};
int num1[MAX_SEATS] = {0};
int busno;

// Function prototypes
void login();
void bus();
void name_number(int booking, char numstr[100]);
void booking();
int read_number(int busno);
void read_name(int busno);
void status();
void status_1(int busno);
void cancel();

int main() {
	system("color f1");
    login();
    int num, i;

    do {
        system("cls");
        printf("\n\n\n");
        printf("\tSimba Bus Reservation System  \n");
        printf("\t____________________________\n\n");
        printf("\t1. Bus Available\n");
        printf("\n");
        printf("\t2. Book Ticket\n");
        printf("\n");
        printf("\t3. Cancel Booking\n");
        printf("\n");
        printf("\t4. Bus Status\n");
        printf("\n");
        printf("\t5. Exit\n\n");
        printf("\t_____________________________\n\n");
        printf("\tEnter your choice: ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                system("color f0");
                bus();
                printf("\n\n\t\tPress any key to exit this page.");
                break;
            case 2:
                system("color f8");
                booking();
                break;
            case 3:
                system("cls");
                system("color f4");
                cancel();
                break;
            case 4:
                system("cls");
                system("color f5");
                status();
                break;
            case 5:
                system("cls");
                system("color f1");
                printf("\t_________________________________________________\n");
                printf("\tThank you for using Simba Bus System.\t\t\t\t\t\t\n");
                printf("\t_________________________________________________\n");
                _getch();
                return 0;
        }

        _getch();
    } while (num != 5);

    system("CLS");
    printf("\tInvalid choice!\n");
    printf("\t_______________________________________________\n");
    printf("\tThank you for using Simba Bus System.\t\t\t\t\t\n");
    printf("\t_______________________________________________\n");
    _getch();
    return 0;
}

void bus() {
    int price = SEAT_PRICE;
    system("cls");
    printf("\n\n\n");
    printf("_________________________________________ Simba Bus Company _________________________________________\n\n\n");
    printf("   S.NO.   |   BUS NO.     |    SOURCE  |    DESTINATION  |        DAYS     |       TIME        |   PRICE");
    printf("\n           |               |            |                 |                 |                   |         ");
    int i;
    for (i = 0; i < 6; i++) {
        printf("\n    %d.    | %-12s |  NAIROBI   |     DESTINATION   |  EVERYDAY       |  7am,2pm,8pm      |   %d    ", i + 1, ch[i], price);
        printf("\n           |               |            |                 |                 |                   |          ");
    }
}


void name_number(int booking, char numstr[100]) {
    char tempstr[100], tempsbs1[12] = "status", tempsbs2[12] = "number";
    int number;
    FILE *a, *b;
    int i = 0;

    strcat(numstr, ".txt");
    strcat(tempsbs1, numstr);
    strcat(tempsbs2, numstr);
    a = fopen(tempsbs1, "a");
    b = fopen(tempsbs2, "a");

    for (i = 0; i < booking; i++) {
        printf("============================Enter details for %d Ticket ============================\n\n\n", i + 1);
        printf("\t\t\t\tEnter Seat Number: ");
        scanf("%d", &number);
        printf("\t\t\t\tEnter Passenger's Name: ");
        scanf("%s", name[number - 1]);
        printf("\n======================================================================================================\n\n");
        printf("\n");
        itoa(number, tempstr, 10);
        fprintf(a, "%s ", name[number - 1]);
        fprintf(b, "%s ", tempstr);
    }

    fclose(a);
    fclose(b);
}


 int read_number(int busno) {
    char tempstr[100], tempsbs2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(busno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempsbs2, numstr);
    a = fopen(tempsbs2, "a+");

    while (!feof(a)) {
        number[i][j] = fgetc(a);

        if (number[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++) {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}
void read_name(int busno) {
    char tempsbs1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(busno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempsbs1, numstr);
    b = fopen(tempsbs1, "a+");

    while (!feof(b)) {
        name[i][j] = fgetc(b);

        if (name[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}

void booking() {
    int i = 0;
    char numstr[100];
    system("cls");
    printf("=========================================== Simba Bus Company ============================================\n\n\n");//for entering bus number
    bus();
    printf("\n\nEnter Bus Number(1-8): ");
    scanf("%d", &busno);

    if (busno < 1 || busno > 8) {
        printf("Invalid Bus Number. Please enter a number between 1 and 8.");
        return;
    }

    system("cls");
    printf("=========================================== Simba Bus Company ============================================\n\n\n");//for selecting seat
    printf("\n\nYour Bus Number is %d \t %s", busno, ch[busno - 1]);
    status_1(busno);

    int availableSeats = read_number(busno);
    read_name(busno);

    printf("\n\t\t\t\tAvailable seats are: %d\n", availableSeats);
    printf("\n\t\t\t\tHow many seats are you booking?: ");
    int bookingCount;
    scanf("%d", &bookingCount);

    if (bookingCount <= 0 || bookingCount > availableSeats) {
        printf("Invalid number of seats. Please enter a valid number.");
        return;
    }

    printf("\n");

    name_number(bookingCount, numstr);

    FILE *file;
    char filename[20];
    sprintf(filename, "%s%d%s", FILE_PREFIX, busno, FILE_EXTENSION);

    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    // Write booking details to the file
    fprintf(file, "Bus Number: %d\n", busno);
    fprintf(file, "Total Amount: %d\n", SEAT_PRICE * bookingCount);
    fprintf(file, "Passenger Details:\n");

    for (i = 0; i < bookingCount; i++) {
        fprintf(file, "Seat Number: %d, Passenger Name: %s\n", num1[i], name[i]);
    }

    fclose(file);

    FILE *f1;
    char busFileName[10];
    sprintf(busFileName, "bs%d.txt", busno);
    f1 = fopen(busFileName, "r+");
    int seat1;
    fscanf(f1, "%d", &seat1);
    fclose(f1);

    if (seat1 < bookingCount) {
        printf("\n\nInsufficient seats available.");
        return;
    }

    seat1 = seat1 - bookingCount;

    printf("\n\t\t\t**-------- Receipt ---------**\n");
    printf("\n\t\t\tThe total amount is %d", SEAT_PRICE * bookingCount);
    printf("\n\n\t\t\tYour Bus Number is %d \t %s", busno, ch[busno - 1]);
    printf("\n\t\t\t**--------------------------**\n");

    printf("\n\t\t\tPress any key to continue...");

    f1 = fopen(busFileName, "w");
    fprintf(f1, "%d", seat1);
    fclose(f1);
}



void status() {
    system("cls");
    printf("=========================================== Simba Bus Company ============================================\n\n\n");
    FILE *file;
    char filename[20];
    sprintf(filename, "%s%d%s", FILE_PREFIX, busno, FILE_EXTENSION);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("No bookings available for Bus %d.\n", busno);
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    int i, j;
    printf("Enter Bus Number: ");
    scanf("%d", &busno);
    j = read_number(busno);
    read_name(busno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                     Bus No. %d \t %s                                                            \n", busno, ch[busno - 1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[MAX_SEATS][10] = {"Empty ", "Empty", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++) {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 14; i++) {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++) {
            printf("%d.%s\t", i * 4 + j + 1, tempname[i * 4 + j + 1]);
        }
        printf("\n");
    }
}


void status_1(int busno) {
    printf("Your Bus Number is %d \t %s", busno, ch[busno - 1]);
    system("cls");
    printf("=========================================== Simba Bus Company ============================================\n\n\n");
    int i, index = 0, j;
    j = read_number(busno);
    read_name(busno);
    char tempname[MAX_SEATS][10] = {"Empty ", "Empty", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++) {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 14; i++) {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++) {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void cancel() {
    int seat_no, i, j;
    char numstr[100], tempsbs2[15] = "number", tempsbs1[15] = "status";
    printf("_____________________________________________________________________________________________________________\n");
    printf("\n\nCancellation Fee = ksh 100 per Ticket\n");
    printf("_____________________________________________________________________________________________________________\n");
    printf("\n");
    printf("\n\nEnter Bus Number: ");
    scanf("%d", &busno);
    itoa(busno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempsbs1, numstr);
    strcat(tempsbs2, numstr);
    read_number(busno);
    read_name(busno);
    status_1(busno);
    printf("\nEnter Seat Number: ");
    scanf("%d", &seat_no);
    char filename[20];
    sprintf(filename, "%s%d%s", FILE_PREFIX, busno, FILE_EXTENSION);

    if (remove(filename) != 0) {
        printf("Error deleting the booking file for Bus %d.\n", busno);
    }

    FILE *a, *b;
    a = fopen(tempsbs1, "w+");
    b = fopen(tempsbs2, "w+");

    for (i = 0; i < MAX_SEATS; i++) {
        if (num1[i] == seat_no) {
            for (j = 0; j < MAX_SEATS; j++) {
                if (num1[j] != seat_no && num1[j] != 0) {
                    fprintf(b, "%d ", num1[j]);
                    fprintf(a, "%s", name[j]);
                } else if (num1[j] == seat_no && num1[j] != 0) {
                    strcpy(name[j], "Empty ");
                }
            }
        }
    }

    fclose(a);
    fclose(b);
    printf("\n\n");
    printf("======================================================================================================\n");
    printf("\t\t\t\tYour Booking has been cancelled successfully.\t\t\t\n");
    printf("======================================================================================================\n");
    printf("\t\t\t\tKindly wait as we process the refunding of your money.\t\t\t\n");
    printf("======================================================================================================\n");
    printf("\n\t\t\t\tPress any key to continue...");
}
void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t______________________________________________________\n");
        printf("\n\t\t\t\t\t\t\t\t  SIMBA BUS COMPANY\n");
        printf("\t\t\t\t\t\t______________________________________________________\n\n");
        printf("\t\t\t\t\t\t  Simba Bus Company is committed to providing\n");
        printf("\t\t\t\t\t\t  safe and reliable transportation services.\n");
        printf("\n\t\t\t\t\t\t  Please login to access the system.    \n");
        printf("\t\t\t\t\t\t______________________________________________________\n");
        printf(" \n\t\t\t\t\t\t  Enter Your name: ");
        scanf("%s", &uname);
        printf(" \n\t\t\t\t\t\t  Enter Password: ");
        while (i < 10) {
            pword[i] = _getch();
            c = pword[i];
            if (c == 13) {
                break;
            } else if (c == 8) {
                if (i > 0) {
                    printf("\b \b");
                    i--;
                }
            } else {
                printf("*");
                i++;
            }
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            printf("  \n\n\n \t\t\t\t\t\tLogin Successful...\n");
            printf("\n \n\n\t\t\t\t\t\tPress any key to continue...\n");
            _getch();
            break;
        } else {
            printf("\n\n\t\t\tUsername or Password is incorrect, please try again");
            a++;
            _getch();
        }
    } while (a <= 2);
    if (a > 2) {
        printf("You have entered the wrong username and password three times. Please try again later!");
        _getch();
    }
    system("cls");
}
