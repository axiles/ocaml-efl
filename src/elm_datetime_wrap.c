#include "include.h"

PREFIX value ml_elm_datetime_add(value v_parent)
{
        Evas_Object* datetime = elm_datetime_add((Evas_Object*) v_parent);
        if(datetime == NULL) caml_failwith("elm_datetime_add");
        return (value) datetime;
}

