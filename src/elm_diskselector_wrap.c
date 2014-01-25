#include "include.h"

PREFIX value ml_elm_diskselector_add(Evas_Object* v_parent)
{
        Evas_Object* diskselector = elm_diskselector_add(
                (Evas_Object*) v_parent);
        if(diskselector == NULL) caml_failwith("elm_diskselector_add");
        return (value) diskselector;
}

PREFIX value ml_elm_diskselector_round_enabled_set(value v_obj, value v_flag)
{
        elm_diskselector_round_enabled_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_diskselector_round_enabled_get(value v_obj)
{
        return Val_bool(elm_diskselector_round_enabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_diskselector_side_text_max_length_get(value v_obj)
{
        return Val_int(elm_diskselector_side_text_max_length_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_diskselector_side_text_max_length_set(value v_obj,
        value v_x)
{
        elm_diskselector_side_text_max_length_set((Evas_Object*) v_obj,
                Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_diskselector_display_item_num_set(value v_obj,
        value v_x)
{
        elm_diskselector_display_item_num_set((Evas_Object*) v_obj,
                Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_diskselector_display_item_num_get(value v_obj)
{
        return Val_int(elm_diskselector_display_item_num_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_diskselector_clear(value v_obj)
{
        elm_diskselector_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_diskselector_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_diskselector_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_diskselector_item_append(
        value v_obj, value v_label, value v_icon, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = (value*) caml_stat_alloc(sizeof(value));
                *data = Field(v_func, 0);
                caml_register_global_root(data);
        }
        Elm_Object_Item* item = elm_diskselector_item_append(
                (Evas_Object*) v_obj, label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_diskselector_item_append");
        }
        return (value) item;
}

PREFIX value ml_elm_diskselector_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_diskselector_selected_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_diskselector_item_selected_set(value v_it, value v_flag)
{
        elm_diskselector_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

