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