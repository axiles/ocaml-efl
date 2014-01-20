#include "include.h"

PREFIX value ml_elm_flipselector_add(value v_parent)
{
        Evas_Object* flipselector = elm_flipselector_add(
                (Evas_Object*) v_parent);
        if(flipselector == NULL) caml_failwith("elm_flipselector_add");
        return (value) flipselector;
}

