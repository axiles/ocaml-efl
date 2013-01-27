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

PREFIX value ml_elm_exit(value v_unit)
{
        elm_exit();
        return Val_unit;
}

PREFIX value ml_elm_frame_add(value v_parent)
{
        Evas_Object* frame = elm_frame_add((Evas_Object*) v_parent);
        if(frame == NULL) caml_failwith("elm_frame_add");
        return (value) frame;
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

PREFIX value ml_elm_policy_set(value v_policy, value v_value)
{
        return Val_Eina_Bool(elm_policy_set(Elm_Policy_val(v_policy),
                Elm_Policy_Value_val(v_value)));
}

PREFIX value ml_elm_win_inwin_add(value v_parent)
{
        Evas_Object* obj = elm_win_inwin_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_win_inwin_add");
        return (value) obj;
}

PREFIX value ml_elm_win_inwin_content_set(value v_obj, value v_content)
{
        elm_win_inwin_content_set((Evas_Object*) v_obj,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_add(value v_parent)
{
        Evas_Object* obj = elm_naviframe_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_naviframe_add");
        return (value) obj;
}

PREFIX char* ml_Elm_Gen_Item_Text_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0();
        CAMLlocal2(v_part, v);
        value* v_class = (value*) data;
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 1), (value) obj, v_part);
        char* r = strdup(String_val(v));
        if(r == NULL) caml_raise_out_of_memory();
        CAMLreturnT(char*, r);
}

PREFIX Evas_Object* ml_Elm_Gen_Item_Content_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0();
        CAMLlocal2(v_part, v);
        value* v_class = (value*) data;
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 2), (value) obj, v_part);
        if(v == Val_int(0)) CAMLreturnT(Evas_Object*, NULL);
        else CAMLreturnT(Evas_Object*, (Evas_Object*) Field(v, 0));
}

PREFIX Eina_Bool ml_Elm_Gen_Item_State_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0();
        CAMLlocal2(v_part, v);
        value* v_class = (value*) data;
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 3), (value) obj, v_part);
        CAMLreturnT(Eina_Bool, Eina_Bool_val(v));
}

PREFIX void ml_Elm_Gen_Item_Del_Cb(void* data, Evas_Object* obj)
{
        value* v_class = (value*) data;
        caml_callback(Field(*v_class, 4), (value) obj);
}

PREFIX void ml_Elm_Gengrid_Item_Class(
        Elm_Gengrid_Item_Class** class, void** data, value v)
{
        Elm_Gengrid_Item_Class* c = elm_gengrid_item_class_new();
        if(c == NULL) caml_raise_out_of_memory();

        c->item_style = String_val(Field(v, 0));
        c->func.text_get = ml_Elm_Gen_Item_Text_Get_Cb;
        c->func.content_get = ml_Elm_Gen_Item_Content_Get_Cb;
        c->func.state_get = ml_Elm_Gen_Item_State_Get_Cb;
        c->func.del = ml_Elm_Gen_Item_Del_Cb;

        value* v_data = caml_stat_alloc(sizeof(value));
        *v_data = v;
        caml_register_global_root(v_data);

        *class = c;
        *data = v_data;
}

PREFIX value ml_elm_gengrid_add(value v_parent)
{
        Evas_Object* obj = elm_gengrid_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_gengrid_add");
        return (value) obj;
}

PREFIX value ml_elm_gengrid_item_append(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = caml_stat_alloc(sizeof(value));
        *data_func = v_func;
        caml_register_global_root(data_func);

        Elm_Object_Item* item = elm_gengrid_item_append((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) caml_failwith("elm_gengrid_item_append");
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_size_set(value v_obj, value v_w, value v_h)
{
        elm_gengrid_item_size_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_theme_list_item_path_get(value v_f)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_Bool flag;
        char* path = elm_theme_list_item_path_get(String_val(v_f), &flag);
        if(path == NULL) v = Val_int(0);
        else {
                v1 = caml_alloc(2, 0);
                Store_field(v1, 0, copy_string(path));
                Store_field(v1, 1, Val_Eina_Bool(flag));
                v = caml_alloc(1, 0);
                Store_field(v, 0, v1);
                free(path);
        }
        CAMLreturn(v);
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

PREFIX value ml_elm_naviframe_item_simple_promote(value v_obj, value v_content)
{
        elm_naviframe_item_simple_promote((Evas_Object*) v_obj,
                (Evas_Object*) v_content);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_title_visible_set(value v_it, value v_flag)
{
        elm_naviframe_item_title_visible_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

