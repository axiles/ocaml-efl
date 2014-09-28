#include "include.h"

PREFIX value ml_elm_thumb_add(value v_parent)
{
        Evas_Object* thumb = elm_thumb_add((Evas_Object*) v_parent);
        if(thumb == NULL) caml_failwith("elm_thumb_add");
        return (value) thumb;
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

PREFIX value ml_elm_thumb_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_thumb_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_thumb_crop_align_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        double x, y;
        elm_thumb_crop_align_get((Evas_Object*) v_obj, &x, &y);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_double(x));
        Store_field(v, 1, copy_double(y));
        CAMLreturn(v);
}

PREFIX value ml_elm_thumb_compress_get(value v_obj)
{
        int x;
        elm_thumb_compress_get((Evas_Object*) v_obj, &x);
        return Val_int(x);
}

PREFIX value ml_elm_thumb_quality_get(value v_obj)
{
        int x;
        elm_thumb_quality_get((Evas_Object*) v_obj, &x);
        return Val_int(x);
}

