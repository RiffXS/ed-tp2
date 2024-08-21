// Getting TADs for PatientQueue and ExamPriorityQueue
#include "queue.h"

// Getting TADs for Exam and Patient
#include "exam.h"
#include "patient.h"

// Getting standard C libraries
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declaring Constants
  int N = 1000;

  // Declaring variables for the loop
  int timestamp = 0;
  int patient = 0;
  int exam = 0;
  int report = 0;

  // String for the full name of the patient
  char name[100];

  // Vector of First Names for the patients
  char f_name[10][10] = {"Ana", "Luiza", "Thiago", "Lorena", "Rafael", "Leticia", "Josias", "Davi", "Duda", "Paulo"};

  // Vector of Second Names for the patients
  char s_name[10][10] = {"Lasanha", "Hamburger", "Pizza", "Arros", "Feijao", "Macarrao", "Silva", "Turra", "Barros", "Paixao"};

  // Creating a new PatientQueue
  PatientQueue *pq = pq_create();

  // Creating a scructure to get current time in milliseconds
  struct timeval ts;

  while (1) {
    gettimeofday(&ts, NULL);
    srand(ts.tv_usec);

    int random = rand() % (N + 1);

    if (random < (N * 0.2)) {
      int second_name = rand() % 10;
      srand((long int)ts.tv_usec / 1000);
      int first_name = rand() % 10;
      srand(ts.tv_usec);

      snprintf(name, sizeof(name), "%s %s", f_name[first_name], s_name[second_name]);
    
      Patient *p = patient_create(patient, name, timestamp);

      pq_enqueue(pq, p);


    }
  }

  // // Definindo uma data de nascimento fictícia para o paciente
  // Patient *p1 = patient_create(1, "Joao Silva", 5);
  // Patient *p2 = patient_create(2, "Rafael Barros", 5);

  // pq_enqueue(pq, p1);
  // pq_enqueue(pq, p2);

  // pq_print(pq);

  // pq_destroy(pq);

  return 0;
}
