#include "include.h"

PREFIX value ml_elm_init_with_counter(value v_argv)
{
        int argc = Wosize_val(v_argv);
	char *argv[argc];
	int i;
	for(i = 0; i < argc; i++) {
                argv[i] = String_val(Field(v_argv, i));
        }
        return Val_int(elm_init(argc, argv));
}

PREFIX value ml_elm_run(value v_unit)
{
        elm_run();
        return Val_unit;
}

PREFIX value ml_elm_shutdown(value v_unit)
{
        elm_shutdown();
        return Val_unit;
}

PREFIX inline Elm_Win_Type Elm_Win_Type_val(value v_ty)
{
        switch(v_ty) {
                case Val_basic: return ELM_WIN_BASIC;
        }
        caml_failwith("Elm_Win_Type_val");
        return ELM_WIN_BASIC;
}

PREFIX value ml_elm_win_add(value v_parent, value v_name, value v_ty)
{
        Evas_Object* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Evas_Object*) Field(v_parent, 0);
        Evas_Object* win = elm_win_add(parent, String_val(v_name),
                Elm_Win_Type_val(v_ty));
        if(win == NULL) caml_failwith("elm_win_add");
        return (value) win;
}

PREFIX value ml_elm_win_title_set(value v_obj, value v_title)
{
        elm_win_title_set((Evas_Object*) v_obj, String_val(v_title));
        return Val_unit;
}

PREFIX value ml_elm_exit(value v_unit)
{
        elm_exit();
        return Val_unit;
}

PREFIX value ml_elm_bg_add(value v_parent)
{
        Evas_Object* bg = elm_bg_add((Evas_Object*) v_parent);
        if(bg == NULL) caml_failwith("elm_bg_add");
        return (value) bg;
}

PREFIX value ml_elm_win_resize_object_add(value v_obj, value v_subobj)
{
        elm_win_resize_object_add((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_object_text_set(value v_obj, value v_text)
{
        elm_object_text_set((Evas_Object*) v_obj, String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_box_add(value v_parent)
{
        Evas_Object* box = elm_box_add((Evas_Object*) v_parent);
        if(box == NULL) caml_failwith("elm_box_add");
        return (value) box;
}

PREFIX value ml_elm_box_horizontal_set(value v_box, value v_flag)
{
        elm_box_horizontal_set((Evas_Object*) v_box, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_box_pack_end(value v_obj, value v_subobj)
{
        elm_box_pack_end((Evas_Object*) v_obj, (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_frame_add(value v_parent)
{
        Evas_Object* frame = elm_frame_add((Evas_Object*) v_parent);
        if(frame == NULL) caml_failwith("elm_frame_add");
        return (value) frame;
}

PREFIX value ml_elm_object_style_set_with_bool(value v_obj, value v_style)
{
        return Val_Eina_Bool(elm_object_style_set((Evas_Object*) v_obj,
                (const char*) String_val(v_style)));
}

PREFIX value ml_elm_object_content_set(value v_obj, value v_content)
{
        elm_object_content_set((Evas_Object*) v_obj, (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_box_homogeneous_set(value v_box, value v_flag)
{
        elm_box_homogeneous_set((Evas_Object*) v_box, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_autodel_set(value v_win, value v_flag)
{
        elm_win_autodel_set((Evas_Object*) v_win, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX inline unsigned int Elm_Policy_val(value v)
{
        switch(v) {
                case Val_quit: return ELM_POLICY_QUIT;
        }
        caml_failwith("Elm_Policy_val");
        return 0;
}

PREFIX inline int Elm_Policy_Value_val(value v)
{
        switch(v) {
                case Val_none: return ELM_POLICY_QUIT_NONE;
                case Val_last_window_closed:
                               return ELM_POLICY_QUIT_LAST_WINDOW_CLOSED;
        }
        caml_failwith("Elm_Policy_Value_val");
        return ELM_POLICY_QUIT_NONE;
}

PREFIX value ml_elm_policy_set_with_bool(value v_policy, value v_value)
{
        return Val_Eina_Bool(elm_policy_set(Elm_Policy_val(v_policy),
                Elm_Policy_Value_val(v_value)));
}

PREFIX value ml_elm_icon_add(value v_parent)
{
        Evas_Object* icon = elm_icon_add((Evas_Object*) v_parent);
        if(icon == NULL) caml_failwith("elm_icon_add");
        return (value) icon;
}

PREFIX value ml_elm_icon_standard_set_with_bool(value v_icon, value v_name)
{
        return Val_Eina_Bool(elm_icon_standard_set((Evas_Object*) v_icon,
                (const char*) String_val(v_name)));
}

PREFIX value ml_elm_object_part_content_set(
        value v_obj, value v_part, value v_content)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        elm_object_part_content_set((Evas_Object*) v_obj, (const char*) part,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_object_text_get(value v_obj)
{
        const char* text = elm_object_text_get((Evas_Object*) v_obj);
        if(text == NULL) caml_failwith("elm_object_text_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_part_content_get(value v_obj, value v_part)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        Evas_Object* content = elm_object_part_content_get((Evas_Object*) v_obj,
                (const char*) part);
        if(content == NULL) caml_failwith("elm_object_part_content_get");
        return (value) content;
}

PREFIX value ml_elm_object_content_unset(value v_obj)
{
        Evas_Object* content = elm_object_content_unset((Evas_Object*) v_obj);
        if(content == NULL) caml_failwith("elm_object_content_unset");
        return (value) content;
}

PREFIX value ml_elm_object_part_text_set(
        value v_obj, value v_part, value v_text)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        elm_object_part_text_set((Evas_Object*) v_obj, (const char*) part,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_object_part_tex_get(value v_obj, value v_part, value v_unit)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        const char* text = elm_object_part_text_get((Evas_Object*) v_obj,
                (const char*) v_part);
        if(text == NULL) caml_failwith("elm_object_part_content_get");
        return copy_string(text);
}

PREFIX value ml_elm_object_part_content_unset(
        value v_obj, value v_part, value v_unit)
{
        char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        Evas_Object* content = elm_object_part_content_unset(
                (Evas_Object*) v_obj, (const char*) part);
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

PREFIX ml_elm_object_signal_callback_add(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        CAMLparam4(v_obj, v_emission, v_source, v_fun);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_object_signal_callback_add((Evas_Object*) v_obj,
                (const char*) String_val(v_emission),
                (const char*) String_val(v_source), ml_Edje_Signal_Cb, data);
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
        const char* emission = (const char*) String_val(v_emission);
        const char* source = (const char*) String_val(v_source);
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

PREFIX value ml_elm_layout_add(value v_parent)
{
        Evas_Object* layout = elm_layout_add((Evas_Object*) v_parent);
        if(layout == NULL) caml_failwith("layout");
        return (value) layout;
}

PREFIX value ml_elm_layout_box_append_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_append((Evas_Object*) v_obj,
                (const char*) String_val(v_part), (Evas_Object*) v_child));
}

PREFIX value ml_elm_layout_box_insert_at_with_bool(
        value v_obj, value v_part, value v_child, value v_pos)
{
        return Val_Eina_Bool(elm_layout_box_insert_at((Evas_Object*) v_obj,
                (const char*) String_val(v_part), (Evas_Object*) v_child,
                Int_val(v_pos)));
}

PREFIX value ml_elm_layout_box_insert_before_with_bool(
        value v_obj, value v_part, value v_child, value v_ref)
{
        return Val_Eina_Bool(elm_layout_box_insert_before((Evas_Object*) v_obj,
                (const char*) String_val(v_part), (Evas_Object*) v_child,
                (Evas_Object*) v_ref));
}

PREFIX value ml_elm_layout_prepend_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_prepend((Evas_Object*) v_obj,
                (const char*) String_val(v_part), (Evas_Object*) v_child));
}

PREFIX inline Elm_Wrap_Type Elm_Wrap_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_WRAP_NONE;
                case Val_char: return ELM_WRAP_CHAR;
                case Val_word: return ELM_WRAP_WORD;
                case Val_mixed: return ELM_WRAP_MIXED;
        }
        caml_failwith("Elm_Wrap_Type_val");
        return ELM_WRAP_NONE;
}

PREFIX inline value Val_Elm_Wrap_Type(Elm_Wrap_Type t) {
        switch(t) {
                case ELM_WRAP_NONE: return Val_none;
                case ELM_WRAP_CHAR: return Val_char;
                case ELM_WRAP_WORD: return Val_word;
                case ELM_WRAP_MIXED: return Val_mixed;
        }
        caml_failwith("Val_Elm_Wrap_Type");
        return Val_none;
}

