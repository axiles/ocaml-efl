#ifndef ECORE_H
#define ECORE_H

PREFIX void raise_not_X(void);
PREFIX void raise_not_Wayland(void);

PREFIX void ml_Ecore_Cb(void* data);
PREFIX void ml_Ecore_Cb_1_free(void* data);
PREFIX void ml_Ecore_Cb_free(void* data);
Eina_Bool ml_Ecore_Task_Cb_free_on_last(void* data);

#endif

