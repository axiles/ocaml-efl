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

PREFIX value ml_elm_photo_thumb_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        elm_photo_thumb_set((Evas_Object*) v_obj, String_val(v_file), group);
        return Val_unit;
}

PREFIX value ml_elm_photo_thumb_set_null(
        value v_obj, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        elm_photo_thumb_set((Evas_Object*) v_obj, NULL, group);
        return Val_unit;
}

PREFIX value ml_elm_photo_size_set(value v_obj, value v_x)
{
        elm_photo_size_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

