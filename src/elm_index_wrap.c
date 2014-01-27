#include "include.h"

PREFIX value ml_elm_index_add(value v_parent)
{
        Evas_Object* obj = elm_index_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_index_add");
        return (value) obj;
}

PREFIX value ml_elm_index_autohide_disabled_set(value v_obj, value v_flag)
{
        elm_index_autohide_disabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value  ml_elm_index_autohide_disabled_get(value v_obj)
{
        return Val_bool(elm_index_autohide_disabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_index_item_level_set(value v_obj, value v_x)
{
        elm_index_item_level_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_index_item_level_get(value v_obj)
{
        return Val_int(elm_index_item_level_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_index_item_selected_set(value v_it, value v_flag)
{
        elm_index_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

