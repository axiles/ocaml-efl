#include "include.h"

PREFIX value ml_elm_thumb_add(value v_parent)
{
        Evas_Object* thumb = elm_thumb_add((Evas_Object*) v_parent);
        if(thumb == NULL) caml_failwith("elm_thumb_add");
        return (value) thumb;
}

PREFIX value ml_elm_thumb_reload(value v_obj)
{
        elm_thumb_reload((Evas_Object*) v_obj);
        return Val_unit;
}

