#include "include.h"

PREFIX value ml_elm_image_file_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        return Val_Eina_Bool(elm_image_file_set((Evas_Object*) v_obj,
                String_val(v_file), group));
}

PREFIX value ml_elm_image_resizable_set(value v_obj, value v_up, value v_down)
{
        elm_image_resizable_set((Evas_Object*) v_obj, Eina_Bool_val(v_up),
                Eina_Bool_val(v_down));
        return Val_unit;
}

PREFIX value ml_elm_image_no_scale_set(value v_obj, value v_flag)
{
        elm_image_no_scale_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

