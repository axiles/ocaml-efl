#include "include.h"

PREFIX value ml_elm_plug_add(value v_parent)
{
        Evas_Object* plug = elm_plug_add((Evas_Object*) v_parent);
        if(plug == NULL) caml_failwith("elm_plug_add");
        return (value) plug;
}

PREFIX value ml_elm_plug_image_object_get(value v_obj)
{
        Evas_Object* img = elm_plug_image_object_get((Evas_Object*) v_obj);
        if(img == NULL) caml_failwith("elm_plug_image_object_get");
        return (value) img;
}

