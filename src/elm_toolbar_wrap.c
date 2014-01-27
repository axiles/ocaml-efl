#include "include.h"

PREFIX inline Elm_Toolbar_Shrink_Mode Elm_Toolbar_Shrink_Mode_val(value v)
{
        switch(v) {
                case Val_none: return ELM_TOOLBAR_SHRINK_NONE;
                case Val_hide: return ELM_TOOLBAR_SHRINK_HIDE;
                case Val_scroll: return ELM_TOOLBAR_SHRINK_SCROLL;
                case Val_menu: return ELM_TOOLBAR_SHRINK_MENU;
                case Val_expand: return ELM_TOOLBAR_SHRINK_EXPAND;
                case Val_last: return ELM_TOOLBAR_SHRINK_LAST;
                default: break;
        }
        caml_failwith("Elm_Toolbar_Shrink_Mode_val");
        return ELM_TOOLBAR_SHRINK_NONE;
}

PREFIX inline value Val_Elm_Toolbar_Shrink_Mode(Elm_Toolbar_Shrink_Mode m)
{
       switch(m) {
               case ELM_TOOLBAR_SHRINK_NONE: return Val_none;
               case ELM_TOOLBAR_SHRINK_HIDE: return Val_hide;
               case ELM_TOOLBAR_SHRINK_SCROLL: return Val_scroll;
               case ELM_TOOLBAR_SHRINK_MENU: return Val_menu;
               case ELM_TOOLBAR_SHRINK_EXPAND: return Val_expand;
               case ELM_TOOLBAR_SHRINK_LAST: return Val_last;
               default: break;
       }
       caml_failwith("Val_Elm_Toolbar_Shrink_Mode");
       return Val_none;
}

PREFIX inline Elm_Toolbar_Item_Scrollto_Type
Elm_Toolbar_Item_Scrollto_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_TOOLBAR_ITEM_SCROLLTO_NONE;
                case Val_in: return ELM_TOOLBAR_ITEM_SCROLLTO_IN;
                case Val_first: return ELM_TOOLBAR_ITEM_SCROLLTO_FIRST;
                case Val_middle: return ELM_TOOLBAR_ITEM_SCROLLTO_MIDDLE;
                case Val_last: return ELM_TOOLBAR_ITEM_SCROLLTO_LAST;
                default: break;
        }
        caml_failwith("Elm_Toolbar_Scrollto_Type_val");
        return ELM_TOOLBAR_ITEM_SCROLLTO_NONE;
}

PREFIX inline Elm_Toolbar_Item_Scrollto_Type
Elm_Toolbar_Item_Scrollto_Type_val_list(value v)
{
        Elm_Toolbar_Item_Scrollto_Type r;
        value v_tmp = v;
        while(v_tmp != Val_int(0)) {
                r = r | Elm_Toolbar_Item_Scrollto_Type_val(Field(v_tmp, 0));
                v_tmp = Field(v_tmp, 1);
        }
        return r;
}

PREFIX value ml_elm_toolbar_add(value v_parent)
{
        Evas_Object* obj = elm_toolbar_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_toolbar_add");
        return (value) obj;
}

PREFIX value ml_elm_toolbar_icon_size_set(value v_obj, value v_size)
{
        elm_toolbar_icon_size_set((Evas_Object*) v_obj, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_icon_size_get(value v_obj)
{
        return Val_int(elm_toolbar_icon_size_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_icon_order_lookup_set(value v_obj, value v_order)
{
        elm_toolbar_icon_order_lookup_set((Evas_Object*) v_obj,
                Elm_Icon_Lookup_Order_val(v_order));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_icon_order_lookup_get(value v_obj)
{
        return Val_Elm_Icon_Lookup_Order(elm_toolbar_icon_order_lookup_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_item_append(
        value v_obj, value v_icon, value v_label, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_append((Evas_Object*) v_obj,
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_append");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_prepend(
        value v_obj, value v_icon, value v_label, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_prepend((Evas_Object*) v_obj,
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_prepend");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_insert_before_native(
        value v_obj, value v_before, value v_icon, value v_label, value v_func,
        value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_insert_before(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_before, icon, label,
                func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_insert_before");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_insert_before_byte(value* argv, int argn)
{
        return ml_elm_toolbar_item_insert_before_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_toolbar_item_insert_after_native(
        value v_obj, value v_after, value v_icon, value v_label, value v_func,
        value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_insert_after(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_after, icon, label,
                func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_insert_after");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_insert_after_byte(value* argv, int argn)
{
        return ml_elm_toolbar_item_insert_after_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_toolbar_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_toolbar_first_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_toolbar_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_toolbar_last_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_toolbar_item_next_get(value v_it)
{
        Elm_Object_Item* it1 = elm_toolbar_item_next_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_toolbar_item_prev_get(value v_it)
{
        Elm_Object_Item* it1 = elm_toolbar_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_toolbar_item_show(value v_it, value v_t)
{
        elm_toolbar_item_show((Elm_Object_Item*) v_it,
                Elm_Toolbar_Item_Scrollto_Type_val_list(v_t));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_bring_in(value v_it, value v_t)
{
        elm_toolbar_item_bring_in((Elm_Object_Item*) v_it,
                Elm_Toolbar_Item_Scrollto_Type_val_list(v_t));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_priority_set(value v_it, value v_x)
{
        elm_toolbar_item_priority_set((Elm_Object_Item*) v_it, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_priority_get(value v_it)
{
        return Val_int(elm_toolbar_item_priority_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_toolbar_item_find_by_label(value v_obj, value v_label)
{
       Elm_Object_Item* it = elm_toolbar_item_find_by_label(
               (Evas_Object*) v_obj, String_val(v_label));
       if(it == NULL) return Val_int(0);
       value v_it = caml_alloc(1, 0);
       Store_field(v_it, 0, (value) it);
       return (value) v_it;
}

PREFIX value ml_elm_toolbar_item_selected_set(value v_it, value v_flag)
{
        elm_toolbar_item_selected_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_toolbar_selected_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_toolbar_more_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_toolbar_more_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_toolbar_item_icon_set(value v_it, value v_icon)
{
        elm_toolbar_item_icon_set((Elm_Object_Item*) v_it, String_val(v_icon));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_icon_get(value v_it)
{
        const char* icon = elm_toolbar_item_icon_get((Elm_Object_Item*) v_it);
        if(icon == NULL) caml_failwith("elm_toolbar_item_icon_get");
        return copy_string(icon);
}

PREFIX value ml_elm_toolbar_item_object_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_object_get((Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_toolbar_item_object_get");
        return (value) obj;
}

PREFIX value ml_elm_toolbar_item_icon_object_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_icon_object_get(
                (Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_toolbar_item_icon_object_get");
        return (value) obj;
}

PREFIX value ml_elm_toolbar_item_icon_file_set(
        value v_it, value v_file, value v_key, value v_unit)
{
        const char* key;
        if(v_key == Val_int(0)) key = NULL;
        else key = String_val(Field(v_key, 0));
        return Val_bool(elm_toolbar_item_icon_file_set((Elm_Object_Item*) v_it,
                String_val(v_file), key));
}

PREFIX value ml_elm_toolbar_item_separator_set(value v_it, value v_flag)
{
        elm_toolbar_item_separator_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_separator_get(value v_it)
{
        return Val_bool(elm_toolbar_item_separator_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_toolbar_shrink_mode_set(value v_obj, value v_mode)
{
        elm_toolbar_shrink_mode_set((Evas_Object*) v_obj,
                Elm_Toolbar_Shrink_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_shrink_mode_get(value v_obj)
{
        return Val_Elm_Toolbar_Shrink_Mode(elm_toolbar_shrink_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_transverse_expanded_set(value v_obj, value v_flag)
{
        elm_toolbar_transverse_expanded_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_transverse_expanded_get(value v_obj)
{
        return Val_bool(elm_toolbar_transverse_expanded_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_homogeneous_set(value v_obj, value v_flag)
{
        elm_toolbar_homogeneous_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_homogeneous_get(value v_obj)
{
        return Val_bool(elm_toolbar_homogeneous_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_menu_parent_set(value v_obj, value v_parent)
{
        elm_toolbar_menu_parent_set((Evas_Object*) v_obj,
                (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_toolbar_menu_parent_get(value v_obj)
{
        return (value) elm_toolbar_menu_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_toolbar_align_set(value v_obj, value v_x)
{
        elm_toolbar_align_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_align_get(value v_obj)
{
        return copy_double(elm_toolbar_align_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_item_menu_set(value v_it, value v_flag)
{
        elm_toolbar_item_menu_set((Elm_Object_Item*) v_it, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_menu_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_menu_get((Elm_Object_Item*) v_it);
        if(obj == NULL) return Val_int(0);
        value v_obj = caml_alloc(1, 0);
        Store_field(v_obj, 0, (value) obj);
        return v_obj;
}

PREFIX value ml_elm_toolbar_item_state_add(
        value v_it, value v_icon, value v_label, value v_func, value v_unit)
{
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = caml_stat_alloc(sizeof(value));
                *data = Field(v_func, 0);
                caml_register_global_root(data);
        }
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_add(
                (Elm_Object_Item*) v_it, icon, label, func, data);
        if(state == NULL) caml_failwith("elm_toolbar_item_state_add");
        return (value) state;
}

PREFIX value ml_elm_toolbar_item_state_del(value v_it, value v_state)
{
        return Bool_val(elm_toolbar_item_state_del((Elm_Object_Item*) v_it,
                (Elm_Toolbar_Item_State*) v_state));
}

PREFIX value ml_elm_toolbar_item_state_set(value v_it, value v_state)
{
        return Bool_val(elm_toolbar_item_state_set((Elm_Object_Item*) v_it,
                (Elm_Toolbar_Item_State*) v_state));
}

PREFIX value ml_elm_toolbar_item_state_set_null(value v_it)
{
        return Bool_val(elm_toolbar_item_state_set((Elm_Object_Item*) v_it,
                NULL));
}

PREFIX value ml_elm_toolbar_item_state_get(value v_it)
{
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_get(
                (Elm_Object_Item*) v_it);
        if(state == NULL) return Val_int(0);
        value v_state = caml_alloc(1, 0);
        Store_field(v_state, 0, (value) state);
        return v_state;
}

PREFIX value ml_elm_toolbar_item_state_next(value v_it)
{
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_next(
                (Elm_Object_Item*) v_it);
        if(state == NULL) return Val_int(0);
        value v_state = caml_alloc(1, 0);
        Store_field(v_state, 0, (value) state);
        return v_state;
}

PREFIX value ml_elm_toolbar_item_state_prev(value v_it)
{
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_prev(
                (Elm_Object_Item*) v_it);
        if(state == NULL) return Val_int(0);
        value v_state = caml_alloc(1, 0);
        Store_field(v_state, 0, (value) state);
        return v_state;
}

PREFIX value ml_elm_toolbar_horizontal_set(value v_obj, value v_flag)
{
        elm_toolbar_horizontal_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_horizontal_get(value v_obj)
{
        return Val_bool(elm_toolbar_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_items_count(value v_obj)
{
        return Val_int(elm_toolbar_items_count((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_standard_priority_set(value v_obj, value v_x)
{
        elm_toolbar_standard_priority_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_standard_priority_get(value v_obj)
{
        return Val_int(elm_toolbar_standard_priority_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_select_mode_set(value v_obj, value v_mode)
{
        elm_toolbar_select_mode_set((Evas_Object*) v_obj,
                Elm_Object_Select_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_select_mode_get(value v_obj)
{
        return Val_Elm_Object_Select_Mode(elm_toolbar_select_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_reorder_mode_set(value v_obj, value v_flag)
{
        elm_toolbar_reorder_mode_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_reorder_mode_get(value v_obj)
{
        return Val_bool(elm_toolbar_reorder_mode_get((Evas_Object*) v_obj));
}

