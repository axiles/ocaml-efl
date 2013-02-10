#include "include.h"

PREFIX value ml_elm_progressbar_add(value v_parent)
{
        Evas_Object* obj = elm_progressbar_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_progressbar_add");
        return (value) obj;
}

