#include "include.h"

PREFIX value ml_elm_actionslider_add(value v_parent)
{
        Evas_Object* obj = elm_actionslider_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_actionslider_add");
        return (value) obj;
}

