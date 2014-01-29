#include "include.h"

PREFIX value ml_elm_photo_add(value v_parent)
{
        Evas_Object* obj = elm_photo_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_photo_add");
        return (value) obj;
}

PREFIX value ml_elm_photo_file_set(value v_obj, value v_file)
{
        return Val_bool(elm_photo_file_set((Evas_Object*) v_obj,
                String_val(v_file)));
}

PREFIX value ml_elm_photo_file_set_null(value v_obj)
{
        return Val_bool(elm_photo_file_set((Evas_Object*) v_obj, NULL));
}

