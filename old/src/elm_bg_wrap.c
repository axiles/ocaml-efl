#include "include.h"

PREFIX value ml_elm_bg_add(value v_parent)
{
        Evas_Object* bg = elm_bg_add((Evas_Object*) v_parent);
        if(bg == NULL) caml_failwith("elm_bg_add");
        return (value) bg;
}

PREFIX value ml_elm_bg_file_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group = String_opt_val(v_group);
        return Val_Eina_Bool(elm_bg_file_set((Evas_Object*) v_obj,
                String_val(v_file), group));
}
        
PREFIX value ml_elm_bg_file_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        const char *file, *group;
        elm_bg_file_get((Evas_Object*) v_obj, &file, &group);
        v = caml_alloc(2, 0);
        Store_field(v, 0, safe_copy_string(file));
        Store_field(v, 1, copy_string_opt(group));
        CAMLreturn(v);
}

PREFIX value ml_elm_bg_color_get(value v_obj)
{
        int r, g, b;
        elm_bg_color_get((Evas_Object*) v_obj, &r, &g, &b);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        return v;
}

