// Getting the definitions for the functions
#include "queue.h"

// Getting the definitions for the TADs Patient and Exam
#include "exam.h"
#include "patient.h"

// Getting the standard C libraries
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// PatientQueue functions

// Defining struct for the PatientQueue
struct patient_queue {
  PatientQueueNode *front; // 
  PatientQueueNode *rear;  // 
};

// Defining struct for the PatientQueueNode
struct patient_queue_node {
  Patient *info;           // A Patient value stored in the node.
  PatientQueueNode *next; // A pointer to the next node in the queue.
};

// Create a new PatientQueue and return a pointer to it
PatientQueue *pq_create() {
  // Allocating the memory for PatientQueue
  PatientQueue *pq = (PatientQueue *)malloc(sizeof(PatientQueue));

  // Defining the front and rear of PatientQueue as NULL
  pq->front = pq->rear = NULL;

  // Returning created PatientQueue
  return pq;
}

// Verifies if the PatientQueue is empty
int pq_is_empty(PatientQueue *pq) {
  return pq->front == NULL;
}

// Free the memory associated with the PatientQueue
void pq_destroy(PatientQueue *pq) {
  // Getting the start of the PatientQueue
  PatientQueueNode *p = pq->front;

  // Freeing the memory for all the PatientQueueNodes
  while (p != NULL) {
    PatientQueueNode *t = p->next;
    patient_destroy(p->info);
    free(p);
    p = t;
  }

  // Freeing the memory for PatientQueue
  free(pq);
}

// Enqueues a Patient to the end of the queue
void pq_enqueue(PatientQueue *pq, Patient *p) {
  // Creating a new queue node
  PatientQueueNode *node = (PatientQueueNode *)malloc(sizeof(PatientQueueNode));

  // Inserting the values into the node
  node->info = p;
  node->next = NULL;

  // Verifying if the Queue is empty to enqueue the Patient to the correct place
  if (pq_is_empty(pq))
    pq->front = node;
  else
    pq->rear->next = node;

  // Putting Patient to the end of the Queue
  pq->rear = node;
}

// Dequeues the Patient at the front and returns it
Patient *pq_dequeue(PatientQueue *pq) {
  assert(!pq_is_empty(pq));

  // Getting the values to return and to free
  Patient *p = pq->front->info;
  PatientQueueNode *node = pq->front; // Storing for removal

  // Verifies if the queue only has one element, if yes, front and rear are NULL, if not, front->next is the new front
  if (pq->front != pq->rear)
    pq->front = pq->front->next;
  else
    pq->front = pq->rear = NULL;

  // Frees the memory for the node
  free(node);

  // Returns the Patient
  return p;
}

void pq_print(PatientQueue *pq) {
  for (PatientQueueNode *p = pq->front; p != NULL; p = p->next) {
    printf("%d %s %d\n", get_patient_id(p->info), get_patient_name(p->info), get_patient_timestamp(p->info));
  }
}

// ExamPriorityQueue functions

// Defining struct for ExamPriorityQueue
struct exam_priority_queue {
  ExamPriorityQueueNode *front;
  ExamPriorityQueueNode *rear;
};

// Definig struct for ExamPriorityQueueNode
struct exam_priority_queue_node {
  Exam *info;
  ExamPriorityQueueNode *next;
};

// Create a new ExamPriorityQueue and return a pointer to it
ExamPriorityQueue *epq_create() {
  // Allocating the memory for ExamPriorityQueue
  ExamPriorityQueue *epq = (ExamPriorityQueue *)malloc(sizeof(ExamPriorityQueue));

  // Defining the front and rear of ExamPriorityQueue as NULL
  epq->front = epq->rear = NULL;

  // Returning created ExamPriorityQueue
  return epq;
}

// Verifies if the ExamPriorityQueue is empty
int epq_is_empty(ExamPriorityQueue *epq) {
  return epq->front == NULL;
}

// Free the memory associated with the ExamPriorityQueue
void epq_destroy(ExamPriorityQueue *epq) {
  // Getting the start of the PatientQueue
  ExamPriorityQueueNode *e = epq->front;

  // Freeing the memory for all the ExamPriorityQueueNodes
  while (e != NULL) {
    ExamPriorityQueueNode *t = e->next;
    exam_destroy(e->info);
    free(e);
    e = t;
  }

  // Freeing the memory for ExamPriorityQueue
  free(epq);
}

// Enqueues an Exam to the end of the queue
void epq_enqueue(ExamPriorityQueue *epq, Exam *e) {
  // Creating a new queue node
  ExamPriorityQueueNode *node = (ExamPriorityQueueNode *)malloc(sizeof(ExamPriorityQueueNode));

  // Inserting the values into the node
  node->info = e;
  node->next = NULL;

  // Verifying if the Queue is empty to enqueue the Exam to the correct place
  if (epq_is_empty(epq)) {
    epq->front = epq->rear = node;
  } else {
    // Getting the front node to go through the queue
    ExamPriorityQueueNode *p = epq->front;
    ExamPriorityQueueNode *t = NULL;

    // Loop to get the position of the new node
    while (p != NULL && get_exam_condition_gravity(e) <= get_exam_condition_gravity(p->info)) {
      t = p;
      p = p->next;
    }

    // Putting the current node as the next
    node->next = p;

    // Verifying if it is at the end of the Queue
    if (t == NULL) {
      epq->front = node;
    }
    else {
      t->next = node;
    }
  }
}

// Dequeues the Exam at the front and returns it
Exam *epq_dequeue(ExamPriorityQueue *epq) {
  assert(!epq_is_empty(epq));

  // Getting the values to return and to free
  Exam *e = epq->front->info;
  ExamPriorityQueueNode *node = epq->front; // Storing for removal

  // Verifies if the queue only has one element, if yes, front and rear are NULL, if not, front->next is the new front
  if (epq->front != epq->rear)
    epq->front = epq->front->next;
  else
    epq->front = epq->rear = NULL;

  // Frees the memory for the node
  free(node);

  // Returns the Exam
  return e;
}

// Returns the Exam at the front of the Queue
Exam *get_epq_front(ExamPriorityQueue *epq) {
  return epq->front->info;
}

void epq_print(ExamPriorityQueue *epq) {
  for (ExamPriorityQueueNode *p = epq->front; p != NULL; p = p->next) {
    printf("%d %s %d %d\n", get_exam_id(p->info), get_exam_condition_name(p->info), get_exam_condition_gravity(p->info), get_exam_timestamp(p->info));
  }

  printf("\n");
}