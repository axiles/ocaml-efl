#include "include.h"

PREFIX value ml_elm_spinner_add(value v_parent)
{
        Evas_Object* obj = elm_spinner_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_spinner_add");
        return (value) obj;
}

