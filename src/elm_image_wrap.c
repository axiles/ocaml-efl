#include "include.h"

PREFIX inline Elm_Image_Orient Elm_Image_Orient_val(value v_o)
{
        switch(v_o) {
                case Val_orient_0: return ELM_IMAGE_ORIENT_0;
                case Val_rotate_90: return ELM_IMAGE_ROTATE_90;
                case Val_rotate_180: return ELM_IMAGE_ROTATE_180;
                case Val_rotate_270: return ELM_IMAGE_ROTATE_270;
                case Val_flip_horizontal: return ELM_IMAGE_FLIP_HORIZONTAL;
                case Val_flip_vertical: return ELM_IMAGE_FLIP_VERTICAL;
                case Val_flip_transpose: return ELM_IMAGE_FLIP_TRANSPOSE;
                case Val_flip_transverse: return ELM_IMAGE_FLIP_TRANSVERSE;
        }
        caml_failwith("Elm_Image_Orient_val");
        return ELM_IMAGE_ORIENT_NONE;
}

PREFIX inline value Val_Elm_Image_Orient(value o)
{
        switch(o) {
                case ELM_IMAGE_ORIENT_0: return Val_orient_0;
                case ELM_IMAGE_ROTATE_90: return Val_rotate_90;
                case ELM_IMAGE_ROTATE_180: return Val_rotate_180;
                case ELM_IMAGE_ROTATE_270: return Val_rotate_270;
                case ELM_IMAGE_FLIP_HORIZONTAL: return Val_flip_horizontal;
                case ELM_IMAGE_FLIP_VERTICAL: return Val_flip_vertical;
                case ELM_IMAGE_FLIP_TRANSPOSE: return Val_flip_transpose;
                case ELM_IMAGE_FLIP_TRANSVERSE: return Val_flip_transverse;
        }
        caml_failwith("Val_Elm_Image_Orient");
        return Val_orient_0;
}

PREFIX value ml_elm_image_add(value v_parent)
{
        Evas_Object* obj = elm_image_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_image_add");
        return (value) obj;
}

PREFIX value ml_elm_image_file_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        return Val_Eina_Bool(elm_image_file_set((Evas_Object*) v_obj,
                String_val(v_file), group));
}

PREFIX value ml_elm_image_file_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        const char *file, *group;
        elm_image_file_get((Evas_Object*) v_obj, &file, &group);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(file));
        if(group == NULL) v1 = Val_int(0);
        else {
                v1 = caml_alloc(1, 0);
                Store_field(v1, 0, copy_string(group));
        }
        Store_field(v, 1, v1);
        CAMLreturn(v);
}

PREFIX value ml_elm_image_smooth_set(value v_obj, value v_flag)
{
        elm_image_smooth_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_image_smooth_get(value v_obj)
{
        return Val_Eina_Bool(elm_image_smooth_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_image_object_size_get(value v_obj)
{
        int x, y;
        elm_image_object_size_get((Evas_Object*) v_obj, &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_image_no_scale_set(value v_obj, value v_flag)
{
        elm_image_no_scale_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_image_no_scale_get(value v_obj)
{
        return Val_Eina_Bool(elm_image_no_scale_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_image_resizable_set(value v_obj, value v_up, value v_down)
{
        elm_image_resizable_set((Evas_Object*) v_obj, Eina_Bool_val(v_up),
                Eina_Bool_val(v_down));
        return Val_unit;
}

PREFIX value ml_elm_image_resizable_get(value v_obj)
{
        Eina_Bool up, down;
        elm_image_resizable_get((Evas_Object*) v_obj, &up, &down);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Eina_Bool(up));
        Store_field(v, 1, Val_Eina_Bool(down));
        return v;
}

PREFIX value ml_elm_image_fill_outside_set(value v_obj, value v_flag)
{
        elm_image_fill_outside_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_image_fill_outside_get(value v_obj)
{
        return Val_Eina_Bool(elm_image_fill_outside_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_image_preload_disabled_set(value v_obj, value v_flag)
{
        elm_image_preload_disabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_image_prescale_set(value v_obj, value v_size)
{
        elm_image_prescale_set((Evas_Object*) v_obj, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_image_prescale_get(value v_obj)
{
        return Val_int(elm_image_prescale_get((Evas_Object*) v_obj));
}

