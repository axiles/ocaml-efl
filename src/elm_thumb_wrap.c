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

PREFIX value ml_elm_thumb_file_set(value v_obj, value v_file, value v_key)
{
        elm_thumb_file_set((Evas_Object*) v_obj, String_val(v_file),
                String_val(v_key));
        return Val_unit;
}

PREFIX value ml_elm_thumb_file_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        const char* file;
        const char* key;
        elm_thumb_file_get((Evas_Object*) v_obj, &file, &key);
        if(file == NULL) caml_failwith("elm_thumb_file_get");
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_string(file));
        Store_field(v_r, 1, copy_string(key));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_thumb_path_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        const char* path;
        const char* key;
        elm_thumb_path_get((Evas_Object*) v_obj, &path, &key);
        if(path == NULL) caml_failwith("elm_thumb_path_get");
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_string(path));
        Store_field(v_r, 1, copy_string(key));
        CAMLreturn(v_r);
}

