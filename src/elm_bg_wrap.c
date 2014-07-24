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
        /*const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));*/
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
        /*if(group == NULL) v1 = Val_int(0);
        else {
                v1 = caml_alloc(1, 0);
                Store_field(v1, 0, copy_string(group));
        }
        Store_field(v, 1, v1);*/
        CAMLreturn(v);
}

/*PREFIX value ml_elm_bg_option_set(value v_obj, value v_option)
{
        elm_bg_option_set((Evas_Object*) v_obj, Elm_Bg_Option_val(v_option));
        return Val_unit;
}

PREFIX value ml_elm_bg_option_get(value v_obj)
{
        return Val_Elm_Bg_Option(elm_bg_option_get((Evas_Object*) v_obj));
}*/

PREFIX value ml_elm_bg_color_set(value v_obj, value v_r, value v_g, value v_b)
{
        elm_bg_color_set((Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g),
                Int_val(v_b));
        return Val_unit;
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

/*PREFIX value ml_elm_bg_load_size_set(value v_obj, value v_w, value v_h)
{
        elm_bg_load_size_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}*/

