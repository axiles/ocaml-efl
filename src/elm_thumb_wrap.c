#include "include.h"

PREFIX inline Elm_Thumb_Animation_Setting Elm_Thumb_Animation_Setting_val(
        value v)
{
        switch(v) {
                case Val_start: return ELM_THUMB_ANIMATION_START;
                case Val_loop: return ELM_THUMB_ANIMATION_LOOP;
                case Val_stop: return ELM_THUMB_ANIMATION_STOP;
                case Val_last: return ELM_THUMB_ANIMATION_LAST;
                default: break;
        }
        caml_failwith("Elm_Thumb_Animation_Setting_val");
        return ELM_THUMB_ANIMATION_START;
}

PREFIX inline value Val_Elm_Thumb_Animation_Setting(
        Elm_Thumb_Animation_Setting s)
{
        switch(s) {
                case ELM_THUMB_ANIMATION_START: return Val_start;
                case ELM_THUMB_ANIMATION_LOOP: return Val_loop;
                case ELM_THUMB_ANIMATION_STOP: return Val_stop;
                case ELM_THUMB_ANIMATION_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Thumb_Animation_Setting");
        return Val_start;
}

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

PREFIX value ml_elm_thumb_aspect_set(value v_obj, value v_a)
{
        elm_thumb_aspect_set((Evas_Object*) v_obj,
                Ethumb_Thumb_Aspect_val(v_a));
        return Val_unit;
}

PREFIX value ml_elm_thumb_aspect_get(value v_obj)
{
        return Val_Ethumb_Thumb_Aspect(elm_thumb_aspect_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_thumb_fdo_size_set(value v_obj, value v_s)
{
        elm_thumb_fdo_size_set((Evas_Object*) v_obj,
                Ethumb_Thumb_FDO_Size_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_thumb_fdo_size_get(value v_obj)
{
        return Val_Ethumb_Thumb_FDO_Size(elm_thumb_fdo_size_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_thumb_format_set(value v_obj, value v_f) {
        elm_thumb_format_set((Evas_Object*) v_obj,
                Ethumb_Thumb_Format_val(v_f));
        return Val_unit;
}

PREFIX value ml_elm_thumb_format_get(value v_obj)
{
        return Val_Ethumb_Thumb_Format(elm_thumb_format_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_thumb_orientation_set(value v_obj, value v_or)
{
        elm_thumb_orientation_set((Evas_Object*) v_obj,
                Ethumb_Thumb_Orientation_val(v_or));
        return Val_unit;
}

PREFIX value ml_elm_thumb_orientation_get(value v_obj)
{
        return Val_Ethumb_Thumb_Orientation(elm_thumb_orientation_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_thumb_size_set(value v_obj, value v_w, value v_h)
{
        elm_thumb_size_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
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

PREFIX value ml_elm_thumb_crop_align_set(value v_obj, value v_x, value v_y)
{
        elm_thumb_crop_align_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
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

PREFIX value ml_elm_thumb_compress_set(value v_obj, value v_x)
{
        elm_thumb_compress_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_thumb_compress_get(value v_obj)
{
        int x;
        elm_thumb_compress_get((Evas_Object*) v_obj, &x);
        return Val_int(x);
}

PREFIX value ml_elm_thumb_quality_set(value v_obj, value v_x)
{
        elm_thumb_quality_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_thumb_quality_get(value v_obj)
{
        int x;
        elm_thumb_quality_get((Evas_Object*) v_obj, &x);
        return Val_int(x);
}

PREFIX value ml_elm_thumb_animate_set(value v_obj, value v_s)
{
        elm_thumb_animate_set((Evas_Object*) v_obj,
                Elm_Thumb_Animation_Setting_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_thumb_animate_get(value v_obj)
{
        return Val_Elm_Thumb_Animation_Setting(elm_thumb_animate_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_thumb_ethumb_client_connected_get(value v_unit)
{
        return Val_bool(elm_thumb_ethumb_client_connected_get());
}

PREFIX value ml_elm_thumb_editable_set(value v_obj, value v_flag)
{
        elm_thumb_editable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_thumb_editable_get(value v_obj)
{
        return Val_Eina_Bool(elm_thumb_editable_get((Evas_Object*) v_obj));
}

