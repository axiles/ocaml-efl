#include "include.h"

PREFIX value ml_elm_ctxpopup_add(value v_parent)
{
        Evas_Object* ctxpopup = elm_ctxpopup_add((Evas_Object*) v_parent);
        if(ctxpopup == NULL) caml_failwith("elm_ctxpopup_add");
        return (value) ctxpopup;
}

PREFIX value ml_elm_ctxpopup_hover_parent_set(value v_obj, value v_parent)
{
        elm_ctxpopup_hover_parent_set((Evas_Object*) v_obj,
                (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_hover_parent_get(value v_obj)
{
        return (value) elm_ctxpopup_hover_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_ctxpopup_clear(value v_obj)
{
        elm_ctxpopup_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_horizontal_set(value v_box, value v_flag)
{
        elm_ctxpopup_horizontal_set((Evas_Object*) v_box, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_horizontal_get(value v_obj)
{
        return Val_bool(elm_ctxpopup_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_ctxpopup_item_append(
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_ctxpopup_item_append((Evas_Object*) v_obj,
                label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_ctxpopup_item_append");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return (value) item;
}

PREFIX value ml_elm_ctxpopup_item_prepend(
        value v_obj, value v_label, value v_icon, value v_func, value v_unit)
{
        const char* label = String_opt_val(v_label);
        Evas_Object* icon = Evas_Object_opt_val(v_icon);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_ctxpopup_item_prepend((Evas_Object*) v_obj,
                label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_ctxpopup_item_prepend");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return (value) item;
}

PREFIX value ml_elm_ctxpopup_direction_priority_set(
        value v_obj, value v_d1, value v_d2, value v_d3, value v_d4)
{
        elm_ctxpopup_direction_priority_set((Evas_Object*) v_obj,
                Elm_Ctxpopup_Direction_val(v_d1),
                Elm_Ctxpopup_Direction_val(v_d2),
                Elm_Ctxpopup_Direction_val(v_d3),
                Elm_Ctxpopup_Direction_val(v_d4));
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_direction_priority_get(value v_obj)
{
        Elm_Ctxpopup_Direction d1, d2, d3, d4;
        elm_ctxpopup_direction_priority_get((Evas_Object*) v_obj, &d1, &d2, &d3,
                &d4);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_Elm_Ctxpopup_Direction(d1));
        Store_field(v_r, 1, Val_Elm_Ctxpopup_Direction(d2));
        Store_field(v_r, 2, Val_Elm_Ctxpopup_Direction(d3));
        Store_field(v_r, 3, Val_Elm_Ctxpopup_Direction(d4));
        return v_r;
}

PREFIX value ml_elm_ctxpopup_direction_get(value v_obj)
{
        return Val_Elm_Ctxpopup_Direction(elm_ctxpopup_direction_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_ctxpopup_dismiss(value v_obj)
{
        elm_ctxpopup_dismiss((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_auto_hide_disabled_set(value v_box, value v_flag)
{
        elm_ctxpopup_auto_hide_disabled_set((Evas_Object*) v_box,
          Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_auto_hide_disabled_get(value v_obj)
{
        return Val_bool(elm_ctxpopup_auto_hide_disabled_get(
          (Evas_Object*) v_obj));
}

PREFIX value ml_elm_ctxpopup_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_ctxpopup_items_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_ctxpopup_first_item_get(value v_obj)
{
        return copy_Elm_Object_Item_opt(elm_ctxpopup_first_item_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_ctxpopup_last_item_get(value v_obj)
{
        return copy_Elm_Object_Item_opt(elm_ctxpopup_last_item_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_ctxpopup_item_prev_get(value v_it)
{
        return copy_Elm_Object_Item_opt(elm_ctxpopup_item_prev_get(
                Elm_Object_Item_val(v_it)));
}

PREFIX value ml_elm_ctxpopup_item_next_get(value v_it)
{
        return copy_Elm_Object_Item_opt(elm_ctxpopup_item_next_get(
                Elm_Object_Item_val(v_it)));
}

