#include "include.h"

PREFIX value ml_elm_naviframe_add(value v_parent)
{
        Evas_Object* obj = elm_naviframe_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_naviframe_add");
        return (value) obj;
}

PREFIX value ml_elm_naviframe_item_push_native(
        value v_obj, value v_title_label, value v_prev_btn, value v_next_btn,
        value v_content, value v_item_style, value v_unit)
{
        Evas_Object *prev_btn, *next_btn;
        if(v_prev_btn == Val_int(0)) prev_btn = NULL;
        else prev_btn = (Evas_Object*) Field(v_prev_btn, 0);
        if(v_next_btn == Val_int(0)) next_btn = NULL;
        else next_btn = (Evas_Object*) Field(v_next_btn, 0);
        char *title_label, *item_style;
        if(v_title_label == Val_int(0)) title_label = NULL;
        else title_label = String_val(Field(v_title_label, 0));
        if(v_item_style == Val_int(0)) item_style = NULL;
        else item_style = String_val(Field(v_item_style, 0));
        Elm_Object_Item* item = elm_naviframe_item_push((Evas_Object*) v_obj,
                title_label, prev_btn, next_btn, (Evas_Object*) v_content,
                item_style);
        if(item == NULL) caml_failwith("elm_naviframe_item_push");
        return (value) item;
}

PREFIX value ml_elm_naviframe_item_push_byte(value* argv, int argn)
{
        return ml_elm_naviframe_item_push_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_naviframe_item_insert_before_native(
        value v_obj, value v_before, value v_title_label, value v_prev_btn,
        value v_next_btn, value v_content, value v_item_style, value v_unit)
{
        Evas_Object *prev_btn, *next_btn;
        if(v_prev_btn == Val_int(0)) prev_btn = NULL;
        else prev_btn = (Evas_Object*) Field(v_prev_btn, 0);
        if(v_next_btn == Val_int(0)) next_btn = NULL;
        else next_btn = (Evas_Object*) Field(v_next_btn, 0);
        char *title_label, *item_style;
        if(v_title_label == Val_int(0)) title_label = NULL;
        else title_label = String_val(Field(v_title_label, 0));
        if(v_item_style == Val_int(0)) item_style = NULL;
        else item_style = String_val(Field(v_item_style, 0));
        Elm_Object_Item* item = elm_naviframe_item_insert_before(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_before, title_label,
                prev_btn, next_btn, (Evas_Object*) v_content, item_style);
        if(item == NULL) caml_failwith("elm_naviframe_item_insert_before");
        return (value) item;
}
        
PREFIX value ml_elm_naviframe_item_insert_before_byte(value* argv, int argn)
{
        return ml_elm_naviframe_item_insert_before_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

PREFIX value ml_elm_naviframe_item_insert_after_native(
        value v_obj, value v_after, value v_title_label, value v_prev_btn,
        value v_next_btn, value v_content, value v_item_style, value v_unit)
{
        Evas_Object *prev_btn, *next_btn;
        if(v_prev_btn == Val_int(0)) prev_btn = NULL;
        else prev_btn = (Evas_Object*) Field(v_prev_btn, 0);
        if(v_next_btn == Val_int(0)) next_btn = NULL;
        else next_btn = (Evas_Object*) Field(v_next_btn, 0);
        char *title_label, *item_style;
        if(v_title_label == Val_int(0)) title_label = NULL;
        else title_label = String_val(Field(v_title_label, 0));
        if(v_item_style == Val_int(0)) item_style = NULL;
        else item_style = String_val(Field(v_item_style, 0));
        Elm_Object_Item* item = elm_naviframe_item_insert_after(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_after, title_label,
                prev_btn, next_btn, (Evas_Object*) v_content, item_style);
        if(item == NULL) caml_failwith("elm_naviframe_item_insert_after");
        return (value) item;
}
        
PREFIX value ml_elm_naviframe_item_insert_after_byte(value* argv, int argn)
{
        return ml_elm_naviframe_item_insert_after_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

PREFIX value ml_elm_naviframe_item_pop(value v_obj)
{
        Evas_Object* top = elm_naviframe_item_pop((Evas_Object*) v_obj);
        if(top == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) top);
        return v;
}

PREFIX value ml_elm_naviframe_item_pop_to(value v_it)
{
        elm_naviframe_item_pop_to((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_promote(value v_it)
{
        elm_naviframe_item_promote((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_content_preserve_on_pop_set(
        value v_obj, value v_flag)
{
        elm_naviframe_content_preserve_on_pop_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_title_visible_set(value v_it, value v_flag)
{
        elm_naviframe_item_title_visible_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_simple_promote(value v_obj, value v_content)
{
        elm_naviframe_item_simple_promote((Evas_Object*) v_obj,
                (Evas_Object*) v_content);
        return Val_unit;
}

