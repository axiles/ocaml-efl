#include "include.h"

PREFIX value ml_elm_clock_add(value v_parent)
{
        Evas_Object* obj = elm_clock_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_clock_add");
        return (value) obj;
}

