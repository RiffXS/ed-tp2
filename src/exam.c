// Getting the definition for the funcitons
#include "exam.h"

// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>

// Structure of 'exam'
struct exam {
    int id;
    int rx_id;
    int patient_id;
    int condition_IA;
    int timestamp;
};

// Create an Exam and return a pointer to it
Exam *exam_create(int id, int patient_id, int rx_id, int timestamp) {
  Exam *new_exam = (Exam *)malloc(sizeof(Exam));

  if (new_exam == NULL) {
    printf("Erro ao alocar memoria para o Exame\n");
    exit(1);
  }

  new_exam->id = id;
  new_exam->patient_id = patient_id;
  new_exam->rx_id = rx_id;
  new_exam->timestamp = timestamp;

  return new_exam;
}

// Free the memory associated with exam
void exam_destroy(Exam *exam) {
  if (exam != NULL) {
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
int get_exam_rx_id(Exam *exam) {
  return exam->rx_id;
}

// Get the timestamp of realization of the exam
int get_exam_timestamp(Exam *exam) {
  return exam->timestamp;
}