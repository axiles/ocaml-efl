#include "include.h"

PREFIX value ml_elm_plug_add(value v_parent)
{
        Evas_Object* plug = elm_plug_add((Evas_Object*) v_parent);
        if(plug == NULL) caml_failwith("elm_plug_add");
        return (value) plug;
}

