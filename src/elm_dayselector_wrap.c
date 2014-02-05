#include "include.h"

PREFIX value ml_elm_dayselector_add(value v_parent)
{
        Evas_Object* dayselector = elm_dayselector_add((Evas_Object*) v_parent);
        if(dayselector == NULL) caml_failwith("elm_dayselector_add");
        return (value) dayselector;
}

