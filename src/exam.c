// Getting the definition for the funcitons
#include "exam.h"

// Including necessary libraries
#include "condition.h"
#include <stdio.h>
#include <stdlib.h>

// Structure of 'exam'
struct exam {
  int id;
  int xr_id;
  int patient_id;
  Condition *condition_IA;
  int timestamp;
};

// Create an Exam and return a pointer to it
Exam *exam_create(int id, int patient_id, int xr_id, Condition *condition_IA, int timestamp) {
  Exam *new_exam = (Exam *)malloc(sizeof(Exam));

  if (new_exam == NULL) {
    printf("Erro ao alocar memoria para o Exame\n");
    exit(1);
  }

  new_exam->id = id;
  new_exam->patient_id = patient_id;
  new_exam->xr_id = xr_id;
  new_exam->condition_IA = condition_IA;
  new_exam->timestamp = timestamp;

  exam_file_insert(new_exam);

  return new_exam;
}

// Inserts Exam in a file
void exam_file_insert(Exam *e) {
  // Opens a file named 'db_exam.txt'
  FILE *file = fopen("db_exam.txt", "a");

  // Checks if the file did not open
  if (file == NULL) {
    printf("Arquivo 'db_exam.txt' não aberto.\n");
    exit(0);
  }

  // Puts the Exam data inside the file
  fprintf(file, "Id:                %d\n", get_exam_id(e));
  fprintf(file, "XR Id:             %d\n", get_exam_xr_id(e));
  fprintf(file, "Patient Id:        %d\n", get_exam_patient_id(e));
  fprintf(file, "Condition Name:    %s\n", get_exam_condition_name(e));
  fprintf(file, "Condition Gravity: %d\n", get_exam_condition_gravity(e));
  fprintf(file, "Time:              %d\n\n", get_exam_timestamp(e));

  // Closes the file
  fclose(file);
}

// Free the memory associated with exam
void exam_destroy(Exam *exam) {
  if (exam != NULL) {
    free(exam->condition_IA);
    free(exam);
  }
}

// Get the ID of the exam
int get_exam_id(Exam *exam) {
  return exam->id;
}

// Get the ID of the pacient associated with the exam
int get_exam_patient_id(Exam *exam) {
  return exam->patient_id;
}

// Get the X-ray machine ID for the exam
int get_exam_xr_id(Exam *exam) {
  return exam->xr_id;
}

// Get the condition diagnosed
Condition *get_exam_condition(Exam *exam) {
  return exam->condition_IA;
}

// Get the name of the condition diagnosed
char *get_exam_condition_name(Exam *exam) {
  return get_condition_name(exam->condition_IA);
}

// Get the gravity of the condition diagnosed
int get_exam_condition_gravity(Exam *exam) {
  return get_condition_gravity(exam->condition_IA);
}

// Get the timestamp of realization of the exam
int get_exam_timestamp(Exam *exam) {
  return exam->timestamp;
}