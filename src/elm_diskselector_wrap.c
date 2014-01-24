#include "include.h"

PREFIX value ml_elm_diskselector_add(Evas_Object* v_parent)
{
        Evas_Object* diskselector = elm_diskselector_add(
                (Evas_Object*) v_parent);
        if(diskselector == NULL) caml_failwith("elm_diskselector_add");
        return (value) diskselector;
}

