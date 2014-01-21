#include "include.h"

/* Cursors */

PREFIX value ml_elm_object_cursor_set(value v_obj, value v_cursor)
{
        elm_object_cursor_set((Evas_Object*) v_obj, String_val(v_cursor));
        return Val_unit;
}

PREFIX value ml_elm_object_cursor_get(value v_obj)
{
        return copy_string(elm_object_cursor_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_cursor_unset(value v_obj)
{
        elm_object_cursor_unset((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_cursor_style_set(value v_obj, value v_cursor)
{
        elm_object_cursor_style_set((Evas_Object*) v_obj, String_val(v_cursor));
        return Val_unit;
}

PREFIX value ml_elm_object_cursor_style_get(value v_obj)
{
        return copy_string(elm_object_cursor_style_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_cursor_theme_search_enabled_set(
        value v_obj, value v_flag)
{
        elm_object_cursor_theme_search_enabled_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_cursor_theme_search_enabled_get(value v_obj)
{
        return Val_bool(elm_object_cursor_theme_search_enabled_get(
                (Evas_Object*) v_obj));
}

/* Debug */

PREFIX value ml_elm_object_tree_dump(value v_obj)
{
        elm_object_tree_dump((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_tree_dot_dump(value v_obj, value v_file)
{
        elm_object_tree_dot_dump((Evas_Object*) v_obj, String_val(v_file));
        return Val_unit;
}

/* Focus */

PREFIX value ml_elm_object_focus_get(value v_obj)
{
        return Val_bool(elm_object_focus_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_focus_set(value v_obj, value v_flag)
{
        elm_object_focus_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_focus_allow_set(value v_obj, value v_flag)
{
        elm_object_focus_allow_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_focus_allow_get(value v_obj)
{
        return Val_bool(elm_object_focus_allow_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_focus_custom_chain_set(value v_obj, value v_list)
{
        elm_object_focus_custom_chain_set((Evas_Object*) v_obj,
                Eina_List_Evas_Object_val(v_list));
        return Val_unit;
}

PREFIX value ml_elm_object_focus_custom_chain_unset(value v_obj)
{
        elm_object_focus_custom_chain_unset((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_focus_custom_chain_get(value v_obj)
{
        return copy_Eina_List_Evas_Object(elm_object_focus_custom_chain_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_focus_custom_chain_append(
        value v_obj, value v_child, value v_relative_child)
{
        Evas_Object* relative_child;
        if(v_relative_child == Val_int(0)) relative_child = NULL;
        else relative_child = (Evas_Object*) Field(v_relative_child, 0);
        elm_object_focus_custom_chain_append((Evas_Object*) v_obj,
                (Evas_Object*) v_child, relative_child);
        return Val_unit;
}

PREFIX value ml_elm_object_focus_custom_chain_prepend(
        value v_obj, value v_child, value v_relative_child)
{
        Evas_Object* relative_child;
        if(v_relative_child == Val_int(0)) relative_child = NULL;
        else relative_child = (Evas_Object*) Field(v_relative_child, 0);
        elm_object_focus_custom_chain_prepend((Evas_Object*) v_obj,
                (Evas_Object*) v_child, relative_child);
        return Val_unit;
}

PREFIX value ml_elm_object_focus_next(value v_obj, value v_d)
{
        elm_object_focus_next((Evas_Object*) v_obj,
                Elm_Focus_Direction_val(v_d));
        return Val_unit;
}

PREFIX value ml_elm_object_focus_next_object_get(value v_obj, value v_d)
{
        Evas_Object* next = elm_object_focus_next_object_get(
                (Evas_Object*) v_obj, Elm_Focus_Direction_val(v_d));
        if(next == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) next);
        return v_r;
}

PREFIX value ml_elm_object_focus_next_object_set(
        value v_obj, value v_next, value v_d)
{
        Evas_Object* next;
        if(v_next == Val_int(0)) next = NULL;
        else next = (Evas_Object*) Field(v_next, 0);
        elm_object_focus_next_object_set((Evas_Object*) v_obj, next,
                Elm_Focus_Direction_val(v_d));
        return Val_unit;
}

PREFIX value ml_elm_object_focused_object_get(value v_obj)
{
        Evas_Object* focused = elm_object_focused_object_get(
                (Evas_Object*) v_obj);
        if(focused == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) focused);
        return v_r;
}

PREFIX value ml_elm_object_tree_focus_allow_set(value v_obj, value v_flag)
{
        elm_object_tree_focus_allow_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_tree_focus_allow_get(value v_obj)
{
        return Val_bool(elm_object_tree_focus_allow_get((Evas_Object*) v_obj));
}

/* General */

PREFIX inline Elm_Object_Select_Mode Elm_Object_Select_Mode_val(value v_m)
{
        switch(v_m) {
                case Val_default: return ELM_OBJECT_SELECT_MODE_DEFAULT;
                case Val_always: return ELM_OBJECT_SELECT_MODE_ALWAYS;
                case Val_none: return ELM_OBJECT_SELECT_MODE_NONE;
                case Val_display_only:
                               return ELM_OBJECT_SELECT_MODE_DISPLAY_ONLY;
		default: break;
        }
        caml_failwith("Elm_Object_Select_Mode_val");
        return ELM_OBJECT_SELECT_MODE_DEFAULT;
}

PREFIX inline value Val_Elm_Object_Select_Mode(Elm_Object_Select_Mode m)
{
        switch(m) {
                case ELM_OBJECT_SELECT_MODE_DEFAULT: return Val_default;
                case ELM_OBJECT_SELECT_MODE_ALWAYS: return Val_always;
                case ELM_OBJECT_SELECT_MODE_NONE: return Val_none;
                case ELM_OBJECT_SELECT_MODE_DISPLAY_ONLY:
                                                  return Val_display_only;
		default: break;
        }
        caml_failwith("Val_Elm_Object_Select_Mode");
        return Val_default;
}

PREFIX Evas_Object* ml_Elm_Tooltip_Content_Cb(
        void* data, Evas_Object* obj, Evas_Object* v_tooltip)
{
        CAMLparam0();
        CAMLlocal1(v_content);
        value* v_fun = (value*) data;
        v_content = caml_callback2(*v_fun, (value) obj, (value) v_tooltip);
        Evas_Object* content;
        if(v_content == Val_int(0)) content = NULL;
        else content = (Evas_Object*) Field(v_content, 0);
        CAMLreturnT(Evas_Object*, content);
}

PREFIX Evas_Object* ml_Elm_Tooltip_Item_Content_Cb(
        void* data, Evas_Object* obj, Evas_Object* v_tooltip, void* item)
{
        CAMLparam0();
        CAMLlocal1(v_content);
        value* v_fun = (value*) data;
        v_content = caml_callback2(*v_fun, (value) obj, (value) v_tooltip);
        Evas_Object* content;
        if(v_content == Val_int(0)) content = NULL;
        else content = (Evas_Object*) Field(v_content, 0);
        CAMLreturnT(Evas_Object*, content);
}

PREFIX void ml_Elm_Object_Item_Signal_Cb(
        void* data, Elm_Object_Item* it, const char* emission,
        const char* source)
{
        CAMLparam0();
        CAMLlocal2(v_emission, v_source);
        value* v_fun = (value*) data;
        v_emission = copy_string(emission);
        v_source = copy_string(source);
        caml_callback3(*v_fun, (value) it, v_emission, v_source);
        CAMLreturn0;
}

PREFIX void ml_Evas_Smart_Cb_del(void* data, Evas_Object* v_obj, void* info)
{
        value* v_fun = (value*) data;
        caml_remove_global_root(v_fun);
        free(v_fun);
}

PREFIX value ml_elm_object_domain_translatable_part_text_set(
        value v_obj, value v_part, value v_domain, value v_text, value v_unit)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* domain;
        if(v_domain == Val_int(0)) domain = NULL;
        else domain = String_val(Field(v_domain, 0));
        const char* text;
        if(v_text == Val_int(0)) text = NULL;
        else text = String_val(Field(v_text, 0));
        elm_object_domain_translatable_part_text_set((Evas_Object*) v_obj,
                part, domain, text);
        return Val_unit;
}

PREFIX value ml_elm_object_translatable_part_text_get(
        value v_obj, value v_translatable_part, value v_unit)
{
        char* translatable_part;
        if(v_translatable_part == Val_int(0)) translatable_part = NULL;
        else translatable_part = String_val(Field(v_translatable_part, 0));
        const char* text = elm_object_translatable_part_text_get(
                (Evas_Object*) v_obj, translatable_part);
        if(text == NULL) caml_failwith("elm_object_translatable_part_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_domain_part_text_translatable_set(
        value v_obj, value v_part, value v_domain, value v_flag)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* domain;
        if(v_domain == Val_int(0)) domain = NULL;
        else domain = String_val(Field(v_domain, 0));
        elm_object_domain_part_text_translatable_set((Evas_Object*) v_obj, part,
                domain, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_text_set(value v_obj, value v_text)
{
        elm_object_text_set((Evas_Object*) v_obj, String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_part_text_set(
        value v_obj, value v_part, value v_text)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        elm_object_part_text_set((Evas_Object*) v_obj, part,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_text_get(value v_obj)
{
        const char* text = elm_object_text_get((Evas_Object*) v_obj);
        if(text == NULL) caml_failwith("elm_object_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_part_text_get(
        value v_obj, value v_part, value v_unit)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* text = elm_object_part_text_get((Evas_Object*) v_obj, part);
        if(text == NULL) caml_failwith("elm_object_part_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_part_content_set(
        value v_obj, value v_part, value v_content)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        elm_object_part_content_set((Evas_Object*) v_obj, part,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_content_set(value v_obj, value v_content)
{
        elm_object_content_set((Evas_Object*) v_obj, (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_part_content_set_NULL(value v_obj, value v_part)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        elm_object_part_content_set((Evas_Object*) v_obj, part, NULL);
        return Val_unit;
}

PREFIX value ml_elm_object_part_content_get(
                value v_obj, value v_part, value v_unit)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        Evas_Object* content = elm_object_part_content_get((Evas_Object*) v_obj,
                part);
        if(content == NULL) caml_failwith("elm_object_part_content_get");
        return (value) content;
}

PREFIX value ml_elm_object_content_unset(value v_obj)
{
        Evas_Object* content = elm_object_content_unset((Evas_Object*) v_obj);
        if(content == NULL) caml_failwith("elm_object_content_unset");
        return (value) content;
}

PREFIX value ml_elm_object_part_content_unset(
        value v_obj, value v_part, value v_unit)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        Evas_Object* content = elm_object_part_content_unset(
                (Evas_Object*) v_obj, part);
        if(content == NULL) caml_failwith("elm_object_part_content_unset");
        return (value) content;
}

PREFIX value ml_elm_object_access_info_set(value v_obj, value v_txt)
{
        elm_object_access_info_set((Evas_Object*) v_obj, String_val(v_txt));
        return Val_unit;
}

PREFIX value ml_elm_object_name_find(value v_obj, value v_name, value v_recurse)
{
        Evas_Object* child = elm_object_name_find((Evas_Object*) v_obj,
                String_val(v_name), Int_val(v_recurse));
        if(child == NULL) return Val_int(0);
        value v_child = caml_alloc(1, 0);
        Store_field(v_child, 0, (value) child);
        return v_child;
}

PREFIX value ml_elm_object_signal_emit(
        value v_obj, value v_emission, value v_source)
{
        elm_object_signal_emit((Evas_Object*) v_obj, String_val(v_emission),
                String_val(v_source));
        return Val_unit;
}

PREFIX value ml_elm_object_signal_callback_add(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        CAMLparam4(v_obj, v_emission, v_source, v_fun);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_object_signal_callback_add((Evas_Object*) v_obj,
                String_val(v_emission), String_val(v_source),
                ml_Edje_Signal_Cb, data);
        CAMLreturn(Val_unit);
}

typedef struct _value_ptr_list {
        value* hd;
        struct _value_ptr_list* tl;
} value_ptr_list;

PREFIX value ml_elm_object_signal_callback_del(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        CAMLparam4(v_obj, v_emission, v_source, v_fun);
        value_ptr_list* list = NULL;
        value_ptr_list* list1;
        value* data;
        Evas_Object* obj = (Evas_Object*) v_obj;
        const char* emission = String_val(v_emission);
        const char* source = String_val(v_source);
        while(1) {
                data = (value*) elm_object_signal_callback_del(obj, emission,
                        source, ml_Edje_Signal_Cb);
                if(*data == v_fun) {
                        caml_remove_global_root(data);
                        free(data);
                        break;
                } else {
                        list1 = list;
                        list = (value_ptr_list*)
                                caml_stat_alloc(sizeof(value_ptr_list));
                        list->hd = data;
                        list->tl = list1;
                }
        }
        while(list != NULL) {
                elm_object_signal_callback_add(obj, emission, source,
                        ml_Edje_Signal_Cb, list->hd);
                list1 = list->tl;
                free(list);
                list = list1;
        }
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_object_event_callback_add(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_object_event_callback_add((Evas_Object*) v_obj, ml_Elm_Event_Cb,
                data);
        return Val_unit;
}

PREFIX value ml_elm_object_orientation_mode_disabled_set(
        value v_obj, value v_flag)
{
        elm_object_orientation_mode_disabled_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_orientation_mode_disabled_get(value v_obj)
{
        return Val_bool(elm_object_orientation_mode_disabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_item_widget_get(value v_item)
{
        return (value) elm_object_item_widget_get((Elm_Object_Item*) v_item);
}

PREFIX value ml_elm_object_item_content_set(value v_item, value v_content)
{
        elm_object_item_content_set((Elm_Object_Item*) v_item,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_item_part_content_set(
        value v_it, value v_parent, value v_content)
{
        const char* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = String_val(Field(v_parent, 0));
        elm_object_item_part_content_set((Elm_Object_Item*) v_it, parent,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_item_part_content_get(
        value v_it, value v_parent, value v_unit)
{
        const char* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        Evas_Object* content = elm_object_item_part_content_get(
                (Elm_Object_Item*) v_it, parent);
        if(content == NULL) caml_failwith("elm_object_item_part_content_get");
        return (value) content;
}

PREFIX value ml_elm_object_item_part_content_unset(
        value v_it, value v_parent, value v_unit)
{
        const char* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        Evas_Object* content = elm_object_item_part_content_unset(
                (Elm_Object_Item*) v_it, parent);
        if(content == NULL) caml_failwith("elm_object_item_part_content_unset");
        return (value) content;
}

PREFIX value ml_elm_object_item_part_text_set(
        value v_it, value v_parent, value v_text)
{
        const char* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = String_val(Field(v_parent, 0));
        elm_object_item_part_text_set((Elm_Object_Item*) v_it, parent,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_item_text_get(value v_item)
{
        const char* text = elm_object_item_text_get((Elm_Object_Item*) v_item);
        if(text == NULL) caml_failwith("elm_object_item_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_item_part_text_get(
        value v_it, value v_parent, value v_unit)
{
        const char* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        const char* text = elm_object_item_part_text_get(
                (Elm_Object_Item*) v_it, parent);
        if(text == NULL) caml_failwith("elm_object_item_part_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_item_domain_translatable_part_text_set(
        value v_it, value v_part, value v_domain, value v_text, value v_unit)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* domain;
        if(v_domain == Val_int(0)) domain = NULL;
        else domain = String_val(Field(v_domain, 0));
        const char* text;
        if(v_text == Val_int(0)) text = NULL;
        else text = String_val(Field(v_text, 0));
        elm_object_item_domain_translatable_part_text_set(
                (Elm_Object_Item*) v_it, part, domain, text);
        return Val_unit;
}

PREFIX value ml_elm_object_item_translatable_part_text_get(
        value v_it, value v_part, value v_unit)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* text = elm_object_item_translatable_part_text_get(
                (Elm_Object_Item*) v_it, part);
        if(text == NULL)
                caml_failwith("elm_object_item_translatable_part_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_item_domain_part_text_translatable_set(
        value v_it, value v_part, value v_domain, value v_flag)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* domain;
        if(v_domain == Val_int(0)) domain = NULL;
        else domain = String_val(Field(v_domain, 0));
        elm_object_item_domain_part_text_translatable_set(
                (Elm_Object_Item*) v_it, part, domain, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_item_access_info_set(value v_it, value v_txt)
{
        elm_object_item_access_info_set((Elm_Object_Item*) v_it,
                String_val(v_txt));
        return Val_unit;
}

PREFIX value ml_elm_object_item_access_register(value v_it)
{
        Evas_Object* obj = elm_object_item_access_register(
                (Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_object_item_access_register");
        return (value) obj;
}

PREFIX value ml_elm_object_item_access_unregister(value v_it)
{
        elm_object_item_access_unregister((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_object_item_access_object_get(value v_it)
{
        Evas_Object* obj = elm_object_item_access_object_get(
                (Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_object_item_access_object_get");
        return (value) obj;
}

PREFIX value ml_elm_object_item_access_order_set(value v_it, value v_list)
{
        elm_object_item_access_order_set((Elm_Object_Item*) v_it,
                Eina_List_Evas_Object_val(v_list));
        return Val_unit;
}

PREFIX value ml_elm_object_item_access_order_get(value v_it)
{
        return copy_Eina_List_Evas_Object(elm_object_item_access_order_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_object_item_access_order_unset(value v_it)
{
        elm_object_item_access_order_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_object_item_signal_emit(
        value v_it, value v_emission, value v_source)
{
        elm_object_item_signal_emit((Elm_Object_Item*) v_it,
                String_val(v_emission), String_val(v_source));
        return Val_unit;
}

PREFIX value ml_elm_object_item_signal_callback_add(
        value v_it, value v_emission, value v_source, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_object_item_signal_callback_add((Elm_Object_Item*) v_it,
                String_val(v_emission), String_val(v_source),
                ml_Elm_Object_Item_Signal_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_object_item_del(value v_item)
{
        elm_object_item_del((Elm_Object_Item*) v_item);
        return Val_unit;
}

PREFIX value ml_elm_object_item_tooltip_text_set(value v_it, value v_text)
{
        elm_object_item_tooltip_text_set((Elm_Object_Item*) v_it,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_item_tooltip_content_cb_set(
        value v_item, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_object_item_tooltip_content_cb_set((Elm_Object_Item*) v_item,
                ml_Elm_Tooltip_Item_Content_Cb, data, ml_Evas_Smart_Cb_del);
        return Val_unit;
}

PREFIX value ml_elm_object_item_tooltip_unset(value v_it)
{
        elm_object_item_tooltip_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_object_item_tooltip_style_set(value v_it, value v_style)
{
        elm_object_item_tooltip_style_set((Elm_Object_Item*) v_it,
                String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_object_item_tooltip_style_get(value v_it)
{
        return copy_string(elm_object_item_tooltip_style_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_object_item_cursor_set(value v_it, value v_item_cursor)
{
        elm_object_item_cursor_set((Elm_Object_Item*) v_it,
                String_val(v_item_cursor));
        return Val_unit;
}

PREFIX value ml_elm_object_item_cursor_unset(value v_it)
{
        elm_object_item_cursor_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_object_item_cursor_style_set(value v_it, value v_style)
{
        elm_object_item_cursor_style_set((Elm_Object_Item*) v_it,
                String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_object_item_cursor_style_get(value v_it)
{
        return copy_string(elm_object_item_cursor_style_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_object_item_cursor_engine_only_set(value v_it, value v_flag)
{
        elm_object_item_cursor_engine_only_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_item_cursor_engine_only_get(value v_it)
{
        return Val_bool(elm_object_item_cursor_engine_only_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_object_item_track(value v_it)
{
        Evas_Object* obj = elm_object_item_track((Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_object_item_track");
        return (value) obj;
}

PREFIX value ml_elm_object_item_untrack(value v_it)
{
        elm_object_item_untrack((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_object_item_track_get(value v_it)
{
        return Val_int(elm_object_item_track_get((Elm_Object_Item*) v_it));
}

/* Scrollhints */

PREFIX value ml_elm_object_scroll_hold_push(value v_obj)
{
        elm_object_scroll_hold_push((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_scroll_hold_pop(value v_obj)
{
        elm_object_scroll_hold_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_scroll_hold_get(value v_obj)
{
        return Val_int(elm_object_scroll_hold_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_scroll_freeze_push(value v_obj)
{
        elm_object_scroll_freeze_push((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_scroll_freeze_pop(value v_obj)
{
        elm_object_scroll_freeze_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_scroll_freeze_get(value v_obj)
{
        return Val_int(elm_object_scroll_freeze_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_scroll_lock_x_set(value v_obj, value v_flag)
{
        elm_object_scroll_lock_x_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_scroll_lock_y_set(value v_obj, value v_flag)
{
        elm_object_scroll_lock_y_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_scroll_lock_x_get(value v_obj, value v_flag)
{
        return Val_bool(elm_object_scroll_lock_x_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_scroll_lock_y_get(value v_obj, value v_flag)
{
        return Val_bool(elm_object_scroll_lock_y_get((Evas_Object*) v_obj));
}

/* Mirroring */

PREFIX value ml_elm_object_mirrored_get(value v_obj)
{
        return Val_bool(elm_object_mirrored_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_mirrored_set(value v_obj, value v_flag)
{
        elm_object_mirrored_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_mirrored_automatic_get(value v_obj)
{
        return Val_bool(elm_object_mirrored_automatic_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_mirrored_automatic_set(value v_obj, value v_flag)
{
        elm_object_mirrored_automatic_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

/* Widget Scaling */

PREFIX value ml_elm_object_scale_set(value v_obj, value v_scale)
{
        elm_object_scale_set((Evas_Object*) v_obj, Double_val(v_scale));
        return Val_unit;
}

PREFIX value ml_elm_object_scale_get(value v_obj)
{
        return copy_double(elm_object_scale_get((Evas_Object*) v_obj));
}

/* Styles */

PREFIX value ml_elm_object_style_set(value v_obj, value v_style)
{
        return Val_Eina_Bool(elm_object_style_set((Evas_Object*) v_obj,
                String_val(v_style)));
}

PREFIX value ml_elm_object_style_get(value v_obj)
{
        return copy_string(elm_object_style_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_disabled_set(value v_obj, value v_flag)
{
        elm_object_disabled_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_disabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_object_disabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_item_disabled_set(value v_item, value v_flag)
{
        elm_object_item_disabled_set((Elm_Object_Item*) v_item,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_item_disabled_get(value v_it)
{
        return Val_bool(elm_object_item_disabled_get((Elm_Object_Item*) v_it));
}

/* Theme */

PREFIX value ml_elm_object_theme_set(value v_obj, value v_th)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = (Elm_Theme*) Field(v_th, 0);
        elm_object_theme_set((Evas_Object*) v_obj, th);
        return Val_unit;
}

PREFIX value ml_elm_object_theme_get(value v_obj)
{
        Elm_Theme* th = elm_object_theme_get((Evas_Object*) v_obj);
        if(th == NULL) return Val_int(0);
        value v_th = caml_alloc(1, 0);
        Store_field(v_th, 0, (value) th);
        return v_th;
}

/* Widget Tree Navigation */

PREFIX value ml_elm_object_widget_check(Evas_Object* v_obj)
{
        return Val_bool(elm_object_widget_check((Evas_Object*) v_obj));
}

PREFIX value ml_elm_object_parent_widget_get(value v_obj)
{
        Evas_Object* parent = elm_object_parent_widget_get(
                (Evas_Object*) v_obj);
        if(parent == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) parent);
        return v;
}

PREFIX value ml_elm_object_top_widget_get(value v_obj)
{
        Evas_Object* top = elm_object_top_widget_get((Evas_Object*) v_obj);
        if(top == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) top);
        return v;
}

PREFIX value ml_elm_object_widget_type_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_t);
        const char* t = elm_object_widget_type_get((Evas_Object*) v_obj);
        if(t == NULL) v_t = Val_int(0);
        else {
                v_t = caml_alloc(1, 0);
                Store_field(v_t, 0, copy_string(t));
        }
        CAMLreturn(v_t);
}

/* Tooltips */

PREFIX value ml_elm_object_tooltip_show(value v_obj)
{
        elm_object_tooltip_show((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_tooltip_hide(value v_obj)
{
        elm_object_tooltip_hide((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_tooltip_text_set(value v_obj, value v_text)
{
        elm_object_tooltip_text_set((Evas_Object*) v_obj,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_tooltip_content_cb_set(
        value v_objem, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_object_tooltip_content_cb_set((Evas_Object*) v_objem,
                ml_Elm_Tooltip_Content_Cb, data, ml_Evas_Smart_Cb_del);
        return Val_unit;
}

PREFIX value ml_elm_object_tooltip_unset(value v_obj)
{
        elm_object_tooltip_unset((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_object_tooltip_style_set(value v_obj, value v_style)
{
        elm_object_tooltip_style_set((Evas_Object*) v_obj,
                String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_object_tooltip_style_get(value v_obj)
{
        return copy_string(elm_object_tooltip_style_get(
                (Evas_Object*) v_obj));
}

