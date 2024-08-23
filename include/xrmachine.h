#ifndef XRMACHINE_H
#define XRMACHINE_H

// Getting Patient and Exam TADs
#include "exam.h"
#include "patient.h"

// Define a forward declaration of a 'xr_machine' and 'xr_machine_manager
typedef struct xr_machine XRMachine;
typedef struct xr_machine_node XRMachineNode;
typedef struct xr_machine_manager XRMachineManager;

// Function prototypes

// Function to create a new XRMachineManager and return a pointer to it
XRMachineManager *xrmm_create();

// Verifies if the XRMachineManager is empty
int xrmm_is_empty(XRMachineManager *xrmm);

// Function to enqueue the patient to a XRMachine
void xrmm_enqueue(XRMachineManager *xrmm, Patient *p, int machine, int timestamp);

// Function to free the memory allocated to vector of XRMachine
void xrmm_destroy(XRMachineManager *xrmm);

// Function to dequeue the frontmost XRMachine and return it
XRMachine *xrmm_dequeue(XRMachineManager *xrmm);

// Function to verify if 10 units of time passed and create an Exam for the Patient
Exam *xrm_exam(XRMachine *xrm, int exam_id, int timestamp);

// Function to return the frontmost XRMachine
XRMachine *get_xrmm_front(XRMachineManager *xrmm);

// Function to return the id of the machine
int get_xrm_id(XRMachine *xrm);

// Function to return the id of the patient using XRMachine
int get_xrm_patient_id(XRMachine *xrm);

// Function to return the time the XRMachine started
int get_xrm_timestamp(XRMachine *xrm);

// Function to return the size of a XRMachineManager
int get_xrmm_size(XRMachineManager *xrmm);

#endif