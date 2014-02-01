#include "include.h"

PREFIX value ml_elm_photocam_add(value v_parent)
{
        Evas_Object* photocam = elm_photocam_add((Evas_Object*) v_parent);
        if(photocam == NULL) caml_failwith("elm_photocam_add");
        return (value) photocam;
}

