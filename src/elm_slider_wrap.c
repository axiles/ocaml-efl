#include "include.h"

PREFIX value ml_elm_slider_add(value v_parent)
{
        Evas_Object* obj = elm_slider_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_slider_add");
        return (value) obj;
}

