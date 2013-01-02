#include "include.h"

PREFIX value ml_elm_init_with_counter(value v_argv)
{
        int argc = Wosize_val(v_argv);
	char** argv = (char**) caml_stat_alloc(sizeof(char*) * (argc + 1));
	int i;
	for(i = 0; i < argc; i++) {
                char* arg = String_val(Field(v_argv, i));
                argv[i] = caml_stat_alloc(strlen(arg) + 1);
                strcpy(argv[i], arg);
                argv[i][strlen(arg)] = '\0';
        }
        argv[argc] = NULL;
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
                String_val(v_style)));
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
                String_val(v_name)));
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

PREFIX ml_elm_object_signal_callback_add(
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
                String_val(v_part), (Evas_Object*) v_child));
}

PREFIX value ml_elm_layout_box_insert_at_with_bool(
        value v_obj, value v_part, value v_child, value v_pos)
{
        return Val_Eina_Bool(elm_layout_box_insert_at((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child,
                Int_val(v_pos)));
}

PREFIX value ml_elm_layout_box_insert_before_with_bool(
        value v_obj, value v_part, value v_child, value v_ref)
{
        return Val_Eina_Bool(elm_layout_box_insert_before((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child,
                (Evas_Object*) v_ref));
}

PREFIX value ml_elm_layout_box_prepend_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_prepend((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child));
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

PREFIX ml_elm_layout_file_set_with_bool(
        value v_obj, value v_file, value v_group)
{
        return Val_Eina_Bool(elm_layout_file_set((Evas_Object*) v_obj,
                String_val(v_file), String_val(v_group)));
}

PREFIX ml_elm_layout_theme_set_with_bool(
        value v_obj, value v_clas, value v_group, value v_style)
{
        return Val_Eina_Bool(elm_layout_theme_set((Evas_Object*) v_obj,
                String_val(v_clas), String_val(v_group), String_val(v_style)));
}

PREFIX ml_elm_layout_signal_emit(value v_obj, value v_emission, value v_source)
{
        elm_layout_signal_emit((Evas_Object*) v_obj, String_val(v_emission),
                String_val(v_source));
        return Val_unit;
}

PREFIX ml_elm_layout_signal_callback_add(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        value *data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_layout_signal_callback_add((Evas_Object*) v_obj,
                String_val(v_emission), String_val(v_source),
                ml_Edje_Signal_Cb, data);
        return Val_unit;
}

PREFIX ml_elm_layout_signal_callback_del(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        const char* emission = (const char*) String_val(v_emission);
        const char* source = (const char*) String_val(v_source);
        value* data;
        value_ptr_list* list = NULL;
        value_ptr_list* list1;
        while(1) {
                data = elm_layout_signal_callback_del(obj, emission, source,
                        ml_Edje_Signal_Cb);
                if(*data == v_fun) {
                        caml_remove_global_root(data);
                        free(data);
                        break;
                } else {
                        list1 = list;
                        list = caml_stat_alloc(sizeof(value_ptr_list));
                        list->hd = data;
                        list->tl = list1;
                }
        }
        while(list != NULL) {
                elm_layout_signal_callback_add(obj, emission, source,
                        ml_Edje_Signal_Cb, list->hd);
                list1 = list->tl;
                free(list1);
                list = list1;
        }
        return Val_unit;
}

PREFIX inline Elm_Icon_Type Elm_Icon_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_ICON_NONE;
                case Val_file: return ELM_ICON_FILE;
                case Val_standard: return ELM_ICON_STANDARD;
        }
        caml_failwith("Elm_Icon_Type_val");
        return ELM_ICON_NONE;
}

PREFIX inline value Val_Elm_Icon_Type(Elm_Icon_Type ty)
{
        switch(ty) {
                case ELM_ICON_NONE: return Val_none;
                case ELM_ICON_FILE: return Val_file;
                case ELM_ICON_STANDARD: return Val_standard;
        }
        caml_failwith("Val_Elm_Icon_Type");
        return Val_none;
}

PREFIX inline Elm_Text_Format Elm_Text_Format_val(value v)
{
        switch(v) {
                case Val_plain_utf8: return ELM_TEXT_FORMAT_PLAIN_UTF8;
                case Val_markup_utf8: return ELM_TEXT_FORMAT_MARKUP_UTF8;
        }
        caml_failwith("Elm_Text_Format_val");
        return ELM_TEXT_FORMAT_PLAIN_UTF8;
}

PREFIX inline value Val_Elm_Text_Format(Elm_Text_Format f)
{
        switch(f) {
                case ELM_TEXT_FORMAT_PLAIN_UTF8: return Val_plain_utf8;
                case ELM_TEXT_FORMAT_MARKUP_UTF8: return Val_markup_utf8;
        }
        caml_failwith("Val_Elm_Text_Format");
        return Val_plain_utf8;
}

PREFIX inline Elm_Input_Panel_Layout Elm_Input_Panel_Layout_val(value v)
{
        switch(v) {
                case Val_normal: return ELM_INPUT_PANEL_LAYOUT_NORMAL;
                case Val_number: return ELM_INPUT_PANEL_LAYOUT_NUMBER;
                case Val_email: return ELM_INPUT_PANEL_LAYOUT_EMAIL;
                case Val_url: return ELM_INPUT_PANEL_LAYOUT_URL;
                case Val_phonenumber: return ELM_INPUT_PANEL_LAYOUT_PHONENUMBER;
                case Val_ip: return ELM_INPUT_PANEL_LAYOUT_IP;
                case Val_month: return ELM_INPUT_PANEL_LAYOUT_MONTH;
                case Val_numberonly: return ELM_INPUT_PANEL_LAYOUT_NUMBERONLY;
                case Val_invalid: return ELM_INPUT_PANEL_LAYOUT_INVALID;
                case Val_hex: return ELM_INPUT_PANEL_LAYOUT_HEX;
                case Val_terminal: return ELM_INPUT_PANEL_LAYOUT_TERMINAL;
                case Val_password: return ELM_INPUT_PANEL_LAYOUT_PASSWORD;
        }
        caml_failwith("Elm_Input_Panel_Layout_val");
        return ELM_INPUT_PANEL_LAYOUT_NORMAL;
}

PREFIX inline value Val_Elm_Input_Panel_Layout(Elm_Input_Panel_Layout l)
{
        switch(l) {
                case ELM_INPUT_PANEL_LAYOUT_NORMAL: return Val_normal;
                case ELM_INPUT_PANEL_LAYOUT_NUMBER: return Val_number;
                case ELM_INPUT_PANEL_LAYOUT_EMAIL: return Val_email;
                case ELM_INPUT_PANEL_LAYOUT_URL: return Val_url;
                case ELM_INPUT_PANEL_LAYOUT_PHONENUMBER: return Val_phonenumber;
                case ELM_INPUT_PANEL_LAYOUT_IP: return Val_ip;
                case ELM_INPUT_PANEL_LAYOUT_MONTH: return Val_month;
                case ELM_INPUT_PANEL_LAYOUT_NUMBERONLY: return Val_numberonly;
                case ELM_INPUT_PANEL_LAYOUT_INVALID: return Val_invalid;
                case ELM_INPUT_PANEL_LAYOUT_HEX: return Val_hex;
                case ELM_INPUT_PANEL_LAYOUT_TERMINAL: return Val_terminal;
                case ELM_INPUT_PANEL_LAYOUT_PASSWORD: return Val_password;
        }
        caml_failwith("Val_Elm_Input_Pannel_Layout");
        return Val_normal;
}

PREFIX inline Elm_Autocapital_Type Elm_Autocapital_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_AUTOCAPITAL_TYPE_NONE;
                case Val_word: return ELM_AUTOCAPITAL_TYPE_WORD;
                case Val_sentence: return ELM_AUTOCAPITAL_TYPE_SENTENCE;
                case Val_allcharacter: return ELM_AUTOCAPITAL_TYPE_ALLCHARACTER;
        }
        caml_failwith("Elm_Autocapital_Type_val");
        return ELM_AUTOCAPITAL_TYPE_NONE;
}

PREFIX inline value Val_Elm_Autocapital_Type(Elm_Autocapital_Type t)
{
        switch(t) {
                case ELM_AUTOCAPITAL_TYPE_NONE: return Val_none;
                case ELM_AUTOCAPITAL_TYPE_WORD: return Val_word;
                case ELM_AUTOCAPITAL_TYPE_SENTENCE: return Val_sentence;
                case ELM_AUTOCAPITAL_TYPE_ALLCHARACTER: return Val_allcharacter;
        }
        caml_failwith("Val_Elm_Autocapital_Type");
        return Val_none;
}
               
PREFIX inline Elm_Input_Panel_Lang Elm_Input_Panel_Lang_val(value v)
{
        switch(v) {
                case Val_automatic: return ELM_INPUT_PANEL_LANG_AUTOMATIC;
                case Val_alphabet: return ELM_INPUT_PANEL_LANG_ALPHABET;
        }
        caml_failwith("Elm_Input_Panel_Lang_val");
        return ELM_INPUT_PANEL_LANG_AUTOMATIC;
}

PREFIX inline value Val_Elm_Input_Panel_Lang(Elm_Input_Panel_Lang l)
{
        switch(l) {
                case ELM_INPUT_PANEL_LANG_AUTOMATIC: return Val_automatic;
                case ELM_INPUT_PANEL_LANG_ALPHABET: return Val_alphabet;
        }
        caml_failwith("Val_elm_Input_Panel_Lang");
        return Val_automatic;
}

PREFIX inline Elm_Input_Panel_Return_Key_Type
        Elm_Input_Panel_Return_Key_Type_val(value v)
{
        switch(v) {
                case Val_default:
                        return ELM_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
                case Val_done: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_DONE;
                case Val_go: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_GO;
                case Val_join: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_JOIN;
                case Val_login: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_LOGIN;
                case Val_next: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_NEXT;
                case Val_search: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_SEARCH;
                case Val_send: return ELM_INPUT_PANEL_RETURN_KEY_TYPE_SEND;
        }
        caml_failwith("Elm_Input_Panel_Return_Key_Type_val");
        return ELM_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
}

PREFIX inline value Val_Elm_Input_Panel_Return_Key_Type(
        Elm_Input_Panel_Return_Key_Type t)
{
        switch(t) {
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT:
                        return Val_default;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_DONE: return Val_done;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_GO: return Val_go;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_JOIN: return Val_join;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_LOGIN: return Val_login;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_NEXT: return Val_next;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_SEARCH: return Val_search;
                case ELM_INPUT_PANEL_RETURN_KEY_TYPE_SEND: return Val_send;
        }
        caml_failwith("Val_Elm_INput_Return_Key_Type");
        return Val_default;
}

PREFIX inline Elm_Cnp_Mode Elm_Cnp_Mode_val(value v)
{
        switch(v) {
                case Val_markup: return ELM_CNP_MODE_MARKUP;
                case Val_no_image: return ELM_CNP_MODE_NO_IMAGE;
                case Val_plaintext: return ELM_CNP_MODE_PLAINTEXT;
        }
        caml_failwith("Elm_Cnp_Mode_val");
        return ELM_CNP_MODE_MARKUP;
}

PREFIX inline value Val_elm_Cnp_Mode(Elm_Cnp_Mode m)
{
        switch(m) {
                case ELM_CNP_MODE_MARKUP: return Val_markup;
                case ELM_CNP_MODE_NO_IMAGE: return Val_no_image;
                case ELM_CNP_MODE_PLAINTEXT: return Val_plaintext;
        }
        caml_failwith("Val_Elm_Cnp_Mode");
        return Val_markup;
}


