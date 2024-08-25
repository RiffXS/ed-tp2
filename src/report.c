// Getting the definition for the funcitons
#include "report.h"

// Getting the TAD for Exam and Condition
#include "exam.h"

// Getting the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Structure of 'Report'
struct report {
  int id;
  int exam_id;
  Condition *condition; 
  int timestamp;
};

// Creates a new Report and return a pointer to it
Report *report_create(int id, Exam *exam, int timestamp, int random) {
  Report *r = (Report *)malloc(sizeof(Report));

  r->id = id;
  r->exam_id = get_exam_id(exam);
  r->condition = get_exam_condition(exam);
  r->timestamp = timestamp;

  struct timeval ts;

  if (random > 800) {
    Condition *new_condition = condition_create();

    while (strcmp(get_condition_name(new_condition), get_exam_condition_name(exam)) != 0) {
      gettimeofday(&ts, NULL);

      condition_define(new_condition, rand() % 1001);

      srand(ts.tv_usec);
    }

    r->condition = new_condition;
  }

  report_file_insert(r);

  return r;
}

// Inserts Report in a file
void report_file_insert(Report *r) {
  // Opens a file named 'db_report.txt'
  FILE *file = fopen("db_report.txt", "a");

  // Checks if the file did not open
  if (file == NULL) {
    printf("Arquivo 'db_report.txt' não aberto.\n");
    exit(0);
  }

  // Puts the Report data inside the file
  fprintf(file, "Id:                %d\n", get_report_id(r));
  fprintf(file, "Exam Id:           %d\n", get_report_exam_id(r));
  fprintf(file, "Condition Name:    %s\n", get_report_condition_name(r));
  fprintf(file, "Condition Gravity: %d\n", get_report_condition_gravity(r));
  fprintf(file, "Time:              %d\n\n", get_report_timestamp(r));

  // Closes the file
  fclose(file);
}

// Free the memory associated with the Report
void report_destroy(Report *r) {
  free(r->condition);
  free(r);
}


void report_condition(const char *c, int timestamp, int *sum_cancer, int *qtd_cancer, int *sum_tuberculosis, int *qtd_tuberculosis, int *sum_fibrosis, int *qtd_fibrosis, int *sum_stroke, int *qtd_stroke, int *sum_embolism, int *qtd_embolism, int *sum_covid, int *qtd_covid, int *sum_pneumonia, int *qtd_pneumonia, int *sum_bronchitis, int *qtd_bronchitis, int *sum_healthy, int *qtd_healthy) {
  if (strcmp(c, "Saude Normal") == 0) {
    *sum_healthy += timestamp;
    *qtd_healthy += 1;
  } else if (strcmp(c, "Bronquite") == 0) {
    *sum_bronchitis += timestamp;
    *qtd_bronchitis += 1;
  } else if (strcmp(c, "Penumonia") == 0) {
    *sum_pneumonia += timestamp;
    *qtd_pneumonia += 1;
  } else if (strcmp(c, "COVID") == 0) {
    *sum_covid += timestamp;
    *qtd_covid += 1;
  } else if (strcmp(c, "Embolia pulmonar") == 0) {
    *sum_embolism += timestamp;
    *qtd_embolism += 1;
  } else if (strcmp(c, "Derrame pleural") == 0) {
    *sum_stroke += timestamp;
    *qtd_stroke += 1;
  } else if (strcmp(c, "Fibrose pulmonar") == 0) {
    *sum_fibrosis += timestamp;
    *qtd_fibrosis += 1;
  } else if (strcmp(c, "Tuberculose") == 0) {
    *sum_tuberculosis += timestamp;
    *qtd_tuberculosis += 1;
  } else if (strcmp(c, "Cancer de pulmao") == 0) {
    *sum_cancer += timestamp;
    *qtd_cancer += 1;
  }
}

// Get the id of the report
int get_report_id(Report *report) {
  return report->id;
}

// Get the exam_id of the report
int get_report_exam_id(Report *report) {
  return report->exam_id;
}

// Get the name of the condition of the report
char *get_report_condition_name(Report *report) {
  return get_condition_name(report->condition);
}

// Get the gravity of the condition of the report
int get_report_condition_gravity(Report *report) {
  return get_condition_gravity(report->condition);
}

// Get the timestamp of the report
int get_report_timestamp(Report *report) {
  return report->timestamp;
}