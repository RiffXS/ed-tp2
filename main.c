// Getting TADs for PatientQueue and ExamPriorityQueue
#include "queue.h"

// Getting TADs for Exam and Patient
#include "exam.h"
#include "report.h"
#include "patient.h"
#include "xrmachine.h"

// Getting standard C libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void start() {
  FILE *exam = fopen("db_exam.txt", "w");
  FILE *report = fopen("db_report.txt", "w");
  FILE *patient = fopen("db_patient.txt", "w");

  fclose(exam);
  fclose(report);
  fclose(patient);
}

int main() {
  // Creates the necessary db files if they do not exist, and if they do, overwrite them
  start();

  // Declaring Constants
  int N = 1000;

  // Declaring variables for the loop
  int timestamp = 0;
  int patient = 0;
  int exam = 0;
  int report = 0;

  // Declaring variables to keep track of timestamp
  int last_report = 0;

  // Variables to make the periodical report
  int sum_report = 0;
  int sum_cancer = 0;
  int sum_tuberculosis = 0;
  int sum_fibrosis = 0;
  int sum_stroke = 0;
  int sum_embolism = 0;
  int sum_covid = 0;
  int sum_pneumonia = 0;
  int sum_bronchitis = 0;
  int sum_healthy = 0;

  // String for the full name of the patient
  char name[100];

  // Vector of First Names for the patients
  char f_name[10][10] = {"Ana", "Luiza", "Thiago", "Lorena", "Rafael", "Leticia", "Josias", "Davi", "Duda", "Paulo"};

  // Vector of Second Names for the patients
  char s_name[10][10] = {"Lasanha", "Hamburger", "Pizza", "Arroz", "Feijao", "Macarrao", "Pneu", "Aros", "Onibus", "Paixao"};

  // Creating a new PatientQueue
  PatientQueue *pq = pq_create();

  // Creating a new XRMachineManager
  XRMachineManager *xrmm = xrmm_create();

  // Creating a new ExamPriorityQueue
  ExamPriorityQueue *epq = epq_create();

  // Creating a scructure to get current time in milliseconds
  struct timeval ts;

  while (timestamp < 43200) {
    gettimeofday(&ts, NULL);
    srand(ts.tv_usec);

    int random = rand() % (N + 1);

    if (random <= (N * 0.2)) {
      int second_name = rand() % 10;
      srand((long int)ts.tv_usec / 1000);
      int first_name = rand() % 10;
      srand(ts.tv_usec);

      snprintf(name, sizeof(name), "%s %s", f_name[first_name], s_name[second_name]);
    
      Patient *p = patient_create(patient, name, timestamp);

      pq_enqueue(pq, p);

      patient++;
    }

    if (!pq_is_empty(pq) && get_xrmm_size(xrmm) < 5) {
      xrmm_enqueue(xrmm, pq_dequeue(pq), get_xrmm_size(xrmm), timestamp);
    }

    if (!xrmm_is_empty(xrmm) && timestamp - get_xrm_timestamp(get_xrmm_front(xrmm)) >= 10) {
      Exam *e = xrm_exam(xrmm_dequeue(xrmm), exam, timestamp);

      exam++;

      epq_enqueue(epq, e);
    }

    if (!epq_is_empty(epq) && (last_report == 0 || timestamp == last_report)) {
      last_report = timestamp + 30;

      srand((long int)ts.tv_usec / 1000);
      report_create(report, epq_dequeue(epq), last_report, rand() % (N + 1));

      report++;
    }

    if (timestamp % 100 == 0) {
      printf("Tempo atual: %d\n", timestamp);
      printf("Num de pacientes: %d\n", patient);
      printf("Num de pacientes na fila: %d\n", get_xrmm_size(xrmm));
      printf("Num de pacientes com exame: %d\n", exam);
      printf("%% que receberam laudo: %.2f%%\n", exam == 0 ? 0 : (double)(report * 100) / exam);
      printf("Tempo medio que exame esta na fila: %.2f\n", (double)sum_report / report)

      if (timestamp % 7200 == 0)
        printf("Num de exames apos 7200 ut: %d\n", exam);

      printf("\n");
    }

    timestamp++;

    // Sleeps for 5 milliseconds
    usleep(5 * 1000);
  }

  // Deallocating the memory for the Data Structures
  pq_destroy(pq);

  xrmm_destroy(xrmm);

  epq_destroy(epq);

  return 0;
}
