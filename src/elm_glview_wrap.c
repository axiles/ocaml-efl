#include "include.h"

PREFIX value ml_elm_glview_add(value v_parent)
{
        Evas_Object* glview = elm_glview_add((Evas_Object*) v_parent);
        if(glview == NULL) caml_failwith("elm_glview_add");
        return (value) glview;
}

