#include "include.h"

PREFIX value ml_elm_hover_add(value v_parent)
{
        Evas_Object* obj = elm_hover_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_hover_add");
        return (value) obj;
}

