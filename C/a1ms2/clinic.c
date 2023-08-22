/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Eric Jo
Student ID#: 137057188
Email      : hjo9@myseneca.ca
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    if (patient == NULL)
    {
        printf(" *** No records found ***");
    }

    else
    {
        displayPatientTableHeader();
    
        for(i=0; i < max; i++)
        {   if(patient[i].patientNumber!=0)
            {
                if (fmt == FMT_FORM)
                {
                    printf("Name  : %s\n"
                        "Number: %05d\n"
                        "Phone : ", patient[i].name, patient[i].patientNumber);
                    displayFormattedPhone(patient[i].phone.number);
                    printf(" (%s)\n", patient[i].phone.description);
                }
                else
                {
                    printf("%05d %-15s ", patient[i].patientNumber,
                        patient[i].name);
                    displayFormattedPhone(patient[i].phone.number);
                    printf(" (%s)\n", patient[i].phone.description);
                }
            }
        }
  
    }
    
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int option;
    do
    {
        printf("Search Options\n"
        "==========================\n"
        "1) By patient number\n"
        "2) By phone number\n"
        "..........................\n"
        "0) Previous menu\n"
        "..........................\n"
        "Selection: ");

        
        scanf("%d", &option);
        clearInputBuffer();
        printf("\n");

        if (option != 0)
        {
            if (option == 1)
            {
                searchPatientByPatientNumber(patient, max);
                clearInputBuffer();
                suspend();
            }



            else
            {
                searchPatientByPhoneNumber(patient, max);
                clearInputBuffer();
                suspend();
            }
        }
    } while (option != 0);
 
}
// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int room = 0;
    int emptyIndex = 0;

    for(i=0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            room = 1;
            if(room == 1)
            {
                emptyIndex = i;
                i = max;
            }
        }
    }

    if (room == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[emptyIndex].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[emptyIndex]);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
}
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int index;
    int patientNumber;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);
    index = findPatientIndexByPatientNum(patientNumber, patient, max);
    
    printf("\n");
    if (index == -1)
    {
        printf("ERROR: Patient record not found!");
    }
    else
    {
        menuPatientEdit(&patient[index]);


    }
}
// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int index;
    int patientNumber;
    char yesOrNo;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);

    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        printf("\nName  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)\n\n", patient[index].phone.description);

        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &yesOrNo);

        if (yesOrNo == 'n')
        {
            printf("Operation aborted.\n\n");
        }
        else
        {
            patient[index].patientNumber = 0;

            printf("Patient record has been removed!\n\n");
        }

    }
    clearInputBuffer();
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber;
    int index = 0;

    printf("Search by patient number: ");
    scanf("%d", &patientNumber);
 
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index != -1)
    {
        printf("\nName  : %s\n" 
            "Number: %05d\n"
            "Phone : ", patient[index].name, patient[index].patientNumber);
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)\n\n", patient[index].phone.description);
    }
   
    
    else
    {
        printf("\n*** No records found ***\n\n");
    }
 
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneNumber[10+1];
    int i;
    int found = 0;
    
    printf("Search by phone number: ");
    scanf("%s", phoneNumber);
    printf("\n");
    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            found = 1;
        }
    }

    if (found == 1)
    {
        displayPatientTableHeader();

        for (i = 0; i < max; i++)
        {
            if (strcmp(patient[i].phone.number, phoneNumber) == 0)
            {
                printf("%05d %-15s ", patient[i].patientNumber,
                    patient[i].name);
                displayFormattedPhone(patient[i].phone.number);
                printf(" (%s)\n", patient[i].phone.description);
                found = 1;
                
            }
            
        }
        printf("\n");
    }

    else
    {
        displayPatientTableHeader();
        printf("\n*** No records found ***\n\n");
    }
    
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int largestNumber = 0;
    int i;
    
    for(i = 0; i < max; i++)
    {
        if (largestNumber < patient[i].patientNumber)
        {
            largestNumber = patient[i].patientNumber;
        }
    }

    return largestNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;
    int found = 0;
    int index = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            found = 1;
            index = i;
        }
    }
    
    if (found == 1)
        return index;
    else
        return -1;
    
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    scanf("%[^\n]", patient->name);
    printf("\n");
    inputPhoneData(&patient->phone);
}
// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    char phoneNumber[10+1];

    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    scanf("%d", &selection);
    printf("\n");
   
    if (selection == 1)
    {
        strcpy(phone->description, "CELL");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phoneNumber);
        strcpy(phone->number, phoneNumber);
        printf("\n");
        
    }
    else if (selection == 2)
    {
        strcpy(phone->description, "HOME");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phoneNumber);
        strcpy(phone->number, phoneNumber);
        printf("\n");
        
    }
    else if (selection == 3)
    {
        strcpy(phone->description, "WORK");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phoneNumber);
        strcpy(phone->number, phoneNumber);
        printf("\n");
        
    }

    else
    {
        strcpy(phone->description, "TBD");
    }
}