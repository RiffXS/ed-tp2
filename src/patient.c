// Getting the definition for the funcitons
#include "patient.h"

// Including necessary libraries
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Structure of 'patient'
struct patient {
  int id;
  char* name;
  int timestamp;
};

// Create a new patient and return a pointer to it
Patient *patient_create(int id, const char *name, int timestamp) {
  Patient *new_patient = (Patient *)malloc(sizeof(Patient));

  if (new_patient == NULL) {
    printf("Erro ao alocar memória para o paciente.\n");
    exit(1);
  }

  new_patient->id = id;
  new_patient->name = strdup(name);
  new_patient->timestamp = timestamp;

  patient_file_insert(new_patient);

  return new_patient;
}

// Inserts Patient in a file
void patient_file_insert(Patient *p) {
  // Opens a file named 'db_patient.txt'
  FILE *file = fopen("db_patient.txt", "a");

  // Checks if the file did not open
  if (file == NULL) {
    printf("Arquivo 'db_patient.txt' não aberto.\n");
    exit(0);
  }

  // Puts the Patient data inside the file
  fprintf(file, "Id:   %d\n", get_patient_id(p));
  fprintf(file, "Name: %s\n", get_patient_name(p));
  fprintf(file, "Time: %d\n\n", get_patient_timestamp(p));

  // Closes the file
  fclose(file);
}

// Free the memory associated with patient
void patient_destroy(Patient* patient) {
  if (patient != NULL) {
    free(patient->name);
    free(patient);
  }
}

// Get the patient ID
int get_patient_id(Patient* patient) {
  return patient->id;
}

// Get the patient Name
const char *get_patient_name(Patient* patient) {
  return patient->name;
}

// Get the patient timestamp
int get_patient_timestamp(Patient* patient) {
  return patient->timestamp;
}