// Getting the definition for the funcitons
#include "xrmachine.h"

// Getting TADs for the Queues, Patient, and Exam
#include "exam.h"
#include "queue.h"
#include "patient.h"
#include "condition.h"

// Getting necessary functions
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Structure of XRMachine
struct xr_machine {
  int id;
  Patient *patient;
  int timestamp;
};

struct xr_machine_node {
  XRMachine *info;
  XRMachineNode *next;
};

struct xr_machine_manager {
  int size;
  XRMachineNode *front;
  XRMachineNode *rear;
};

// Function to create a new XRMachineManager and return a pointer to it
XRMachineManager *xrmm_create() {
  XRMachineManager *xrmm = (XRMachineManager *)malloc(sizeof(XRMachineManager));

  xrmm->size = 0;
  xrmm->front = NULL;
  xrmm->rear = NULL;

  return xrmm;
}

// Verifies if the XRMachineManager is empty
int xrmm_is_empty(XRMachineManager *xrmm) {
  return xrmm->front == NULL;
}

// Function to free the memory allocated to vector of XRMachine
void xrmm_destroy(XRMachineManager *xrmm) {
  XRMachineNode *p = xrmm->front;

  while (p != NULL) {
    XRMachineNode *t = p->next;
    free(p->info);
    free(p);
    p = t;
  }

  free(xrmm);
}

// Function to enqueue the patient to a XRMachineManager
void xrmm_enqueue(XRMachineManager *xrmm, Patient *p, int machine, int timestamp) {
  XRMachine *xr = (XRMachine *)malloc(sizeof(XRMachine));
  XRMachineNode *xrn = (XRMachineNode *)malloc(sizeof(XRMachineNode));

  xr->id = machine;
  xr->patient = p;
  xr->timestamp = timestamp;

  xrn->info = xr;
  xrn->next = NULL;

  if (xrmm_is_empty(xrmm))
    xrmm->front = xrn;
  else
    xrmm->rear->next = xrn;

  xrmm->rear = xrn;
  xrmm->size++;
}

// Function to dequeue the frontmost XRMachine and return it
XRMachine *xrmm_dequeue(XRMachineManager *xrmm) {
  assert(!xrmm_is_empty(xrmm));

  XRMachine *xr = xrmm->front->info;
  XRMachineNode *xrn = xrmm->front;

  if (xrmm->front != xrmm->rear)
    xrmm->front = xrmm->front->next;
  else
    xrmm->front = xrmm->rear = NULL;

  xrmm->size--;

  free(xrn);

  return xr;
}

// Function to verify if 10 units of time passed and create an Exam for the Patient
Exam *xrm_exam(XRMachine *xrm, int exam_id, int timestamp) {
  int random = rand() % 1001;

  Condition *c = condition_create();

  condition_define(c, random);

  Exam *e = exam_create(exam_id, get_xrm_patient_id(xrm), get_xrm_id(xrm), c, timestamp);

  return e;
}

// Function to return the frontmost XRMachine
XRMachine *get_xrmm_front(XRMachineManager *xrmm) {
  return xrmm->front->info;
}

// Function to return the id of the machine
int get_xrm_id(XRMachine *xrm) {
  return xrm->id;
}

// Function to return the id of the patient using XRMachine
int get_xrm_patient_id(XRMachine *xrm) {
  return get_patient_id(xrm->patient);
}

// Function to return the time the XRMachine started
int get_xrm_timestamp(XRMachine *xrm) {
  return xrm->timestamp;
}

// Function to return the size of a XRMachineManager
int get_xrmm_size(XRMachineManager *xrmm) {
  return xrmm->size;
}