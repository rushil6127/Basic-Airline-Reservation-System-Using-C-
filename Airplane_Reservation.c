#include <stdio.h>

#define ROWS 8
#define COLS 4
#define TRUE 1
#define FALSE 0

char seats[ROWS][COLS];

void initializeSeats();
void displaySeats();
int makeReservation(int row, int col);
int cancelReservation(int row, int col);
void printWelcomeMessage();
void printMenu();

int main() {
    int choice, row, col, age, mo_number;
    char name[10],gender[10];
    printWelcomeMessage();
    initializeSeats();
    printf("Enter your Name: ");
    scanf("%s", name);

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter your Gender: ");
    scanf("%s", gender);

    printf("Enter your Mobile Number:");
    scanf("%d",&mo_number);

    while (getchar() != '\n');

    while (TRUE)
        {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("\n--- CURRENT SEATING CHART ---\n");
                displaySeats();
                break;

            case 2:
                printf("\nEnter Row (1-%d) and Column (1-%d) to reserve (e.g., 2 3): ", ROWS, COLS);
                if (scanf("%d %d", &row, &col) == 2)
                {
                    if (makeReservation(row - 1, col - 1) == TRUE)
                    {
                        printf("\nSUCCESS! Seat %d%c reserved. ***\n", row, 'A' + (col - 1));
                    }
                }
                break;

            case 3:
                printf("\nEnter Row (1-%d) and Column (1-%d) to cancel (e.g., 2 3): ", ROWS, COLS);
                if (scanf("%d %d", &row, &col) == 2)
                {
                    if (cancelReservation(row - 1, col - 1) == TRUE)
                    {
                        printf("\n*** SUCCESS! Reservation for Seat %d%c cancelled. ***\n", row, 'A' + (col - 1));
                    }
                }
                break;

            case 4:
                printf("*******************************************************\n");
                printf("*Name: %s\n", name);
                printf("*Age: %d\n", age);
                printf("*Gender: %s\n", gender);
                printf("*Mobile Number: %d\n", mo_number);
                printf("*******************************************************");
                break;

            case 5:
                printf("\nThank you for using the Airplane Reservation System. Goodbye!\n");
                return 0;

            default:
                printf("\n--- Invalid choice. Please select an option from 1 to 5. ---\n");
        }
    }
    return 0;
}

void initializeSeats()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            seats[i][j] = 'A';
        }
    }
}

void displaySeats()
{
    printf("       ");
    for (int j = 0; j < COLS; j++)
    {
        printf("  %c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++)
        {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf(" [%c]", seats[i][j]);
        }
        printf("\n");
    }
    printf("\nLegend: **[A]** = Available, **[R]** = Reserved\n");
}

int makeReservation(int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        printf("\n--- ERROR: Invalid row or column number. ---\n");
        return FALSE;
    }

    if (seats[row][col] == 'A')
    {
        seats[row][col] = 'R';
        return TRUE;
    }
    else
    {
        printf("\n--- ERROR: Seat %d%c is already Reserved. ---\n", row + 1, 'A' + col);
        return FALSE;
    }
}

int cancelReservation(int row, int col)
 {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        printf("\n--- ERROR: Invalid row or column number. ---\n");
        return FALSE;
    }

    if (seats[row][col] == 'R')
    {
        seats[row][col] = 'A';
        return TRUE;
    }
    else
    {
        printf("\n--- ERROR: Seat %d%c is not currently Reserved. ---\n", row + 1, 'A' + col);
        return FALSE;
    }
}

void printWelcomeMessage()
{
    printf("**********************************************\n");
    printf("*** Welcome to the Simple Airplane Booking ***\n");
    printf("**********************************************\n");
}

void printMenu()
{
    printf("\n--- MENU ---\n");
    printf("1. Display Seating Chart\n");
    printf("2. Make a Reservation\n");
    printf("3. Cancel a Reservation\n");
    printf("4. View Details\n");
    printf("5. Exit\n");
}
