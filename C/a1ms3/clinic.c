/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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

        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber != 0)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int room = 0;
    int emptyIndex = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            room = 1;
            if (room == 1)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int index;
    int patientNumber;
    char yesOrNo;
    char yn[3] = "yn";

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

        yesOrNo = inputCharOption(yn);

        if (yesOrNo == 'n')
        {
            printf("Operation aborted.\n\n");
        }
        else if (yesOrNo == 'y')
        {
            patient[index].patientNumber = 0;

            printf("Patient record has been removed!\n\n");
        }

    }
    clearInputBuffer();
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i = 0;
    int j = 0;
    int index = 0;
    struct Appointment temp;

    displayScheduleTableHeader(&data->appointments->date, 1);
    
    for (i = 0; i < data->maxAppointments; i++)
    {
       for (j = i+1 ; j < data->maxAppointments; j++)
       {
           if(data->appointments[i].date.year > data->appointments[j].date.year)
           {
               
               temp.date = data->appointments[i].date;
               data->appointments[i].date = data->appointments[j].date;
               data->appointments[j].date = temp.date;
               temp.time = data->appointments[i].time;
               data->appointments[i].time = data->appointments[j].time;
               data->appointments[j].time = temp.time;
               temp.patientNumber = data->appointments[i].patientNumber;
               data->appointments[i].patientNumber = data->appointments[j].patientNumber;
               data->appointments[j].patientNumber = temp.patientNumber;

           }
           else if (data->appointments[i].date.year == data->appointments[j].date.year)
           {
               if(data->appointments[i].date.month > data->appointments[j].date.month)
               {
                   temp.date = data->appointments[i].date;
                   data->appointments[i].date = data->appointments[j].date;
                   data->appointments[j].date = temp.date;
                   temp.time = data->appointments[i].time;
                   data->appointments[i].time = data->appointments[j].time;
                   data->appointments[j].time = temp.time;
                   temp.patientNumber = data->appointments[i].patientNumber;
                   data->appointments[i].patientNumber = data->appointments[j].patientNumber;
                   data->appointments[j].patientNumber = temp.patientNumber;
               }
               else if (data->appointments[i].date.month == data->appointments[j].date.month)
               {
                   if(data->appointments[i].date.day > data->appointments[j].date.day)
                   {
                       temp.date = data->appointments[i].date;
                       data->appointments[i].date = data->appointments[j].date;
                       data->appointments[j].date = temp.date;
                       temp.time = data->appointments[i].time;
                       data->appointments[i].time = data->appointments[j].time;
                       data->appointments[j].time = temp.time;
                       temp.patientNumber = data->appointments[i].patientNumber;
                       data->appointments[i].patientNumber = data->appointments[j].patientNumber;
                       data->appointments[j].patientNumber = temp.patientNumber;
                   }
                   else if (data->appointments[i].date.day == data->appointments[j].date.day)
                   {
                       if (data->appointments[i].time.hour > data->appointments[j].time.hour)
                       {
                           temp.date = data->appointments[i].date;
                           data->appointments[i].date = data->appointments[j].date;
                           data->appointments[j].date = temp.date;
                           temp.time = data->appointments[i].time;
                           data->appointments[i].time = data->appointments[j].time;
                           data->appointments[j].time = temp.time;
                           temp.patientNumber = data->appointments[i].patientNumber;
                           data->appointments[i].patientNumber = data->appointments[j].patientNumber;
                           data->appointments[j].patientNumber = temp.patientNumber;
                       }
                       else if (data->appointments[i].time.hour == data->appointments[j].time.hour)
                       {
                           if (data->appointments[i].time.min > data->appointments[j].time.min)
                           {
                               temp.date = data->appointments[i].date;
                               data->appointments[i].date = data->appointments[j].date;
                               data->appointments[j].date = temp.date;
                               temp.time = data->appointments[i].time;
                               data->appointments[i].time = data->appointments[j].time;
                               data->appointments[j].time = temp.time;
                               temp.patientNumber = data->appointments[i].patientNumber;
                               data->appointments[i].patientNumber = data->appointments[j].patientNumber;
                               data->appointments[j].patientNumber = temp.patientNumber;
                           }
                       }
                   }
               }
           }
        }
  
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            {
                index = j;
                j = data->maxPatient;
            }
        }
        if (data->appointments[i].patientNumber != 0 && data->appointments[i].date.year != 0)
        {
            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
       
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{   int year = 0;
    int month = 0;
    int day = 0;
    int i;
    int j;
    struct Patient st1;
    struct Appointment st2;


    printf("Year        : ");
    scanf("%d", &year);
    printf("Month (1-12): ");
    scanf("%d", &month);
    inputMonth(&year, &month);
    scanf("%d", &day);
    inputDay(&year, &month, &day);

    st2.date.year = year;
    st2.date.month = month;
    st2.date.day = day;
    printf("\n");
    displayScheduleTableHeader(&st2.date, 0);

    for (i = 0; i < data->maxAppointments; i++)
    {
        if(data->appointments[i].date.year == year && data->appointments[i].date.month == month &&
            data->appointments[i].date.day == day)
        {
            st1.patientNumber = data->appointments[i].patientNumber;
            st2.time.hour = data->appointments[i].time.hour;
            st2.time.min = data->appointments[i].time.min;
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    strcpy(st1.name, data->patients[j].name);
                    strcpy(st1.phone.number, data->patients[j].phone.number);
                    strcpy(st1.phone.description, data->patients[j].phone.description);
                    displayScheduleData(&st1, &st2, 0);
                }
            }
        }
    }
    clearInputBuffer();
    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient)
{
    int patientNumber = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int i;
    int taken = 0;
    int index = 0;
    int hourSatisfied = 0;
    int minSatisfied = 0;

    do
    {
        taken = 0;
        if (patientNumber == 0)
        {
            printf("Patient Number: ");
            scanf("%d", &patientNumber);
        }
        printf("Year        : ");
        scanf("%d", &year);
        printf("Month (1-12): ");
        scanf("%d", &month);
        inputMonth(&year, &month);

        scanf("%d", &day);
        inputDay(&year, &month, &day);

        printf("Hour (0-23)  : ");
        scanf("%d", &hour);
        clearInputBuffer();
        printf("Minute (0-59): ");
        scanf("%d", &minute);

        

        for (i = 0; i < maxAppointments; i++)
        {
            if (appointments[i].patientNumber == patientNumber)
            {
                taken = 1;
            }
            else if (appointments[i].date.year == year && appointments[i].date.month == month &&
                appointments[i].date.day == day && appointments[i].time.hour == hour && appointments[i].time.min == minute)
            {
                taken = 1;
            }
        }
        if (taken == 1)
        {
            printf("\nERROR: Appointment timeslot is not available!\n");
        }
        else
        {
            
            while (hourSatisfied == 0 || minSatisfied == 0)
            {
                if (hour < appointmentStart || hour > appointmentEnd || minute % 30 != 0)
                {
                    printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", appointmentStart, appointmentEnd);
                    clearInputBuffer();
                    printf("Hour (0-23)  : ");
                    scanf("%d", &hour);
                    printf("Minute (0-59): ");
                    scanf("%d", &minute);


                }
                else if (hour == appointmentEnd)
                {
                    if (minute == 30)
                    {

                        printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", appointmentStart, appointmentEnd);
                        clearInputBuffer();
                        printf("Hour (0-23)  : ");
                        scanf("%d", &hour);
                        printf("Minute (0-59): ");
                        scanf("%d", &minute);

                    }
                }
                if (hour >= appointmentStart && hour <= appointmentEnd)
                {
                    hourSatisfied = 1;
                }
                if (hourSatisfied == 1)
                {
                    if (hour == appointmentEnd)
                    {
                        if(minute == 0)
                        {
                            minSatisfied = 1;
                        }
                        
                    }

                    else if (minute == 0 || minute == 30)
                    {
                        minSatisfied = 1;
                    }
                }
            }
        }
        
        clearInputBuffer();
        printf("\n");
    } while (taken != 0 || hourSatisfied != 1 || minSatisfied != 1);

    for (i = 0; i < maxAppointments; i++)
    {
        if (appointments[i].patientNumber == 0)
        {
            index = i;
            i = maxAppointments;

        }
    }
        appointments[index].patientNumber = patientNumber;
        appointments[index].date.year = year;
        appointments[index].date.month = month;
        appointments[index].date.day = day;
        appointments[index].time.hour = hour;
        appointments[index].time.min = minute;

    printf("*** Appointment scheduled! ***\n\n");
    
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{

    int patientNumber = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    int i = 0;
    char yesOrNo;
    int patientFound = 0;
    int found = 0;
    int index = 0;
    int index2 = 0;
    char yn[3] = "yn";

    printf("Patient Number: ");
    scanf("%d", &patientNumber);
    for (i = 0; i < maxAppointments; i++)
    {
        if (appointments[i].patientNumber == patientNumber)
        {
            patientFound = 1;
        }
    }
    if (patientFound == 1)
    {
        printf("Year        : ");
        scanf("%d", &year);
        printf("Month (1-12): ");
        scanf("%d", &month);
        inputMonth(&year, &month);
        scanf("%d", &day);
        inputDay(&year, &month, &day);

        for (i = 0; i < maxAppointments; i++)
        {
            if (appointments[i].patientNumber == patientNumber && appointments[i].date.year == year &&
                appointments[i].date.month == month && appointments[i].date.day == day)
            {
                found = 1;
                index = i;
                i = maxAppointments;
            }

        }

        for (i = 0; i < maxPatient; i++)
        {
            if (patients[i].patientNumber == appointments[index].patientNumber)
            {
                index2 = i;
                i = maxPatient;
            }
        }

        if (found == 0)
        {
            printf("ERROR: Patient record not found!\n");
        }
        else
        {
            printf("\nName  : %s\n", patients[index2].name);
            printf("Number: %05d\n", patients[index2].patientNumber);
            printf("Phone : ");
            displayFormattedPhone(patients[index2].phone.number);
            printf(" (%s)\n", patients[index2].phone.description);

            printf("Are you sure you want to remove this appointment (y,n): ");
            
            yesOrNo = inputCharOption(yn);
            
            
        }
       
        if (yesOrNo == 'y')
        {
            printf("\nAppointment record has been removed!\n\n");
            
       
            appointments[index].date.year = 0;
            appointments[index].date.month = 0;
            appointments[index].date.day = 0;
            appointments[index].time.hour = 0;
            appointments[index].time.min = 0;
            
            
        }
        else
        {
            printf("Operation Aborted!\n\n");
        }
        
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }

    clearInputBuffer();

}
    



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneNumber[10 + 1];
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
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int largestNumber = 0;
    int i;

    for (i = 0; i < max; i++)
    {
        if (largestNumber < patient[i].patientNumber)
        {
            largestNumber = patient[i].patientNumber;
        }
    }

    return largestNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    char phoneNumber[20];

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

        do
        {
            
            scanf("%s", phoneNumber);
            if (strlen(phoneNumber) != 10)
            {
                printf("Invalid 10-digit number! Number: ");
            }
          
        } while (strlen(phoneNumber) != 10);
            strcpy(phone->number, phoneNumber);
            printf("\n");

        
    }
    else if (selection == 2)
    {
        strcpy(phone->description, "HOME");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        do
        {
            
            scanf("%s", phoneNumber);
            if (strlen(phoneNumber) != 10)
            {
                printf("Invalid 10-digit number! Number: ");
            }
            
        } while (strlen(phoneNumber) != 10);
        strcpy(phone->number, phoneNumber);
        printf("\n");

    }
    else if (selection == 3)
    {
        strcpy(phone->description, "WORK");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        do
        {
            
            scanf("%s", phoneNumber);
            if (strlen(phoneNumber) != 10)
            {
                printf("Invalid 10-digit number! Number: ");
            }
        
        } while (strlen(phoneNumber) != 10);
        strcpy(phone->number, phoneNumber);
        printf("\n");

    }

    else
    {
        strcpy(phone->description, "TBD");
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;
    FILE* fp = NULL;
    int maxCount = 0;
     fp = fopen(datafile, "r");
     if (fp != NULL)
     {
         while (i<max)
         {
             fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
             i++;

             if (feof(fp) != 0)
             {
                 maxCount = i - 1;
                 break;
             }
             else
             {
                 maxCount = max;
             }
         }
     }
     fclose(fp);
     return maxCount;
}
  

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i = 0;
    FILE* fp = NULL;
    int maxCount = 0;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (i < max)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            i++;

            if (feof(fp) != 0)
            {
                maxCount = i - 1;
                break;
            }
            else
            {
                maxCount = max;
            }
        }
    }
    fclose(fp);
    return maxCount;
}
