#include "include.h"

PREFIX value ml_elm_photocam_add(value v_parent)
{
        Evas_Object* photocam = elm_photocam_add((Evas_Object*) v_parent);
        if(photocam == NULL) caml_failwith("elm_photocam_add");
        return (value) photocam;
}

PREFIX value ml_elm_photocam_file_set(value v_obj, value v_file)
{
        return Val_Evas_Load_Error(elm_photocam_file_set(
                (Evas_Object*) v_obj, String_val(v_file)));
}

PREFIX value ml_elm_photocam_file_get(value v_obj)
{
        const char* file = elm_photocam_file_get((Evas_Object*) v_obj);
        if(file == NULL) caml_failwith("elm_photocam_file_get");
        return copy_string(file);
}

