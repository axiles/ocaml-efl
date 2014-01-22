#include "include.h"

PREFIX value ml_elm_thumb_add(Evas_Object* v_parent)
{
        Evas_Object* thumb = elm_thumb_add((Evas_Object*) v_parent);
        if(thumb == NULL) caml_failwith("elm_thumb_add");
        return (value) thumb;
}

