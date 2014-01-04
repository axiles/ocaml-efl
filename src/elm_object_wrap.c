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

/* Other */

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

PREFIX value ml_elm_object_part_tex_get(value v_obj, value v_part, value v_unit)
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

PREFIX value ml_elm_object_text_set(value v_obj, value v_text)
{
        elm_object_text_set((Evas_Object*) v_obj, String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_style_set(value v_obj, value v_style)
{
        return Val_Eina_Bool(elm_object_style_set((Evas_Object*) v_obj,
                String_val(v_style)));
}

PREFIX value ml_elm_object_content_set(value v_obj, value v_content)
{
        elm_object_content_set((Evas_Object*) v_obj, (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_text_get(value v_obj)
{
        const char* text = elm_object_text_get((Evas_Object*) v_obj);
        if(text == NULL) caml_failwith("elm_object_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_content_unset(value v_obj)
{
        Evas_Object* content = elm_object_content_unset((Evas_Object*) v_obj);
        if(content == NULL) caml_failwith("elm_object_content_unset");
        return (value) content;
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

PREFIX value ml_elm_object_item_del(value v_item)
{
        elm_object_item_del((Elm_Object_Item*) v_item);
        return Val_unit;
}

PREFIX value ml_elm_object_item_disabled_set(value v_item, value v_flag)
{
        elm_object_item_disabled_set((Elm_Object_Item*) v_item,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_object_item_text_get(value v_item)
{
        const char* text = elm_object_item_text_get((Elm_Object_Item*) v_item);
        if(text == NULL) caml_failwith("elm_object_item_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_item_content_set(value v_item, value v_content)
{
        elm_object_item_content_set((Elm_Object_Item*) v_item,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_item_widget_get(value v_item)
{
        return (value) elm_object_item_widget_get((Elm_Object_Item*) v_item);
}

