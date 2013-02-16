#include "include.h"

PREFIX value ml_elm_genlist_add(value v_parent)
{
        Evas_Object* obj = elm_genlist_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_genlist_add");
        return (value) obj;
}

PREFIX value ml_elm_genlist_clear(value v_obj)
{
        elm_genlist_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_genlist_multi_select_set(value v_obj, value v_flag)
{
        elm_genlist_multi_select_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_genlist_multi_select_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_genlist_mode_set(value v_obj, value v_mode)
{
        elm_genlist_mode_set((Evas_Object*) v_obj, Elm_List_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_genlist_mode_get(value v_obj)
{
        return Val_Elm_List_Mode(elm_genlist_mode_get((Evas_Object*) v_obj));
}
