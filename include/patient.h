#ifndef PATIENT_H
#define PATIENT_H

// Define a forward declaration of a 'patient' structure
typedef struct patient Patient;

// Function prototypes

// Create a new Patient and return a pointer to it
Patient *patient_create(int id, const char *name, int timestamp);

// Inserts a Patient inside a file
void patient_file_insert(Patient *p);

// Free the memory associated with the patient
void patient_destroy(Patient* patient);

// Get the ID of the patient
int get_patient_id(Patient* patient);

// Get the Name of the patient
const char *get_patient_name(Patient* patient);

// Get the timestamp of the patient
int get_patient_timestamp(Patient* patient);

// End of conditional compilation directives
#endif