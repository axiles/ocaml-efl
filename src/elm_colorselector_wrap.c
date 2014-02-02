#include "include.h"

PREFIX value ml_elm_colorselector_add(value v_parent)
{
        Evas_Object* colorselector = elm_colorselector_add(
                (Evas_Object*) v_parent);
        if(colorselector == NULL) caml_failwith("elm_colorselector_add");
        return (value) colorselector;
}

