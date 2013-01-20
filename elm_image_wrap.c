#include "include.h"

PREFIX value ml_elm_image_file_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else v_group = String_val(Field(v_group, 0));
        return Val_Eina_Bool(elm_image_file_set((Evas_Object*) v_obj,
                String_val(v_file), group));
}

