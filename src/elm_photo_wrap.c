#include "include.h"

PREFIX value ml_elm_photo_add(value v_parent)
{
        Evas_Object* obj = elm_photo_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_photo_add");
        return (value) obj;
}

