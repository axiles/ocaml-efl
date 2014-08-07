#include "include.h"

/* Cache */

PREFIX value ml_elm_cache_all_flush(value v_unit)
{
        elm_cache_all_flush();
        return Val_unit;
}

/* Fingers */

PREFIX value ml_elm_coords_finger_size_adjust(value v_times_w, value v_times_h)
{
        Evas_Coord w, h;
        elm_coords_finger_size_adjust(Int_val(v_times_w), &w,
                Int_val(v_times_h), &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

/* Focus */

/* General */

Eina_Bool ml_Elm_Event_Cb(
        void* data, Evas_Object* obj, Evas_Object* src, Evas_Callback_Type type,
        void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_event_info, v_r);
        value* v_fun = (value*) data;
        v_event_info = copy_Evas_Event_Info(type, event_info);
        v_r = caml_callback3(*v_fun, (value) obj, (value) src, v_event_info);
        CAMLreturnT(Eina_Bool, Bool_val(v_r));
}

Ecore_Select_Function original_select_function = NULL;

PREFIX int my_select_function(
        int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
        struct timeval* timeout)
{
        caml_release_runtime_system();
        int r = original_select_function(nfds, readfds, writefds, exceptfds,
                timeout);
        caml_acquire_runtime_system();
        return r;
}

PREFIX value ml_elm_init_with_counter(value v_argv)
{
        _elm_startup_time = ecore_time_unix_get(); 
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
        int r = elm_init(argc, argv);
        if(original_select_function == NULL)
                original_select_function = ecore_main_loop_select_func_get();
        ecore_main_loop_select_func_set(my_select_function);
        return Val_int(r);
}


PREFIX value ml_elm_shutdown(value v_unit)
{
        elm_shutdown();
        ml_Evas_remove_values();
        return Val_unit;
}

PREFIX value ml_elm_run(value v_unit)
{
      
        elm_run();
      
        return Val_unit;
}

PREFIX value ml_elm_exit(value v_unit)
{
        elm_exit();
        return Val_unit;
}

PREFIX value ml_elm_policy_quit_set(value v_pv)
{
        return Val_bool(elm_policy_set(ELM_POLICY_QUIT,
                Elm_Policy_Quit_val(v_pv)));
}

PREFIX value ml_elm_policy_quit_get(value v_unit)
{
        return Val_Elm_Policy_Quit(elm_policy_get(ELM_POLICY_QUIT));
}

PREFIX value ml_elm_policy_exit_set(value v_pv)
{
        return Val_bool(elm_policy_set(ELM_POLICY_EXIT,
                Elm_Policy_Exit_val(v_pv)));
}

PREFIX value ml_elm_policy_exit_get(value v_unit)
{
        return Val_Elm_Policy_Exit(elm_policy_get(ELM_POLICY_EXIT));
}

PREFIX value ml_elm_policy_throttle_set(value v_pv)
{
        return Val_bool(elm_policy_set(ELM_POLICY_THROTTLE,
                Elm_Policy_Throttle_val(v_pv)));
}

PREFIX value ml_elm_policy_throttle_get(value v_unit)
{
        return Val_Elm_Policy_Throttle(elm_policy_get(ELM_POLICY_THROTTLE));
}

PREFIX value ml_elm_language_set(value v_lang)
{
        elm_language_set(String_val(v_lang));
        return Val_unit;
}

inline Elm_Glob_Match_Flags Elm_Glob_Match_Flags_val_list(
        value v_list)
{
        value v = v_list;
        Elm_Scroller_Movement_Block r = 0;
        while(v != Val_int(0)) {
                r = r | Elm_Glob_Match_Flags_val(Field(v, 0));
                v = Field(v, 1);
        }
        return r;
}

/* Colors */

PREFIX value copy_Elm_Color_Class(Elm_Color_Class* c)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(c->name));
        Store_field(v, 1, copy_string(c->desc));
        CAMLreturn(v);
}

inline value copy_Eina_List_Elm_Color_Class(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_c);
        Eina_List* it;
        Elm_Color_Class* c;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, c) {
                v1 = v;
                v_c = copy_Elm_Color_Class(c);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_c);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX value copy_Elm_Color_Overlay(Elm_Color_Overlay* o)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 13);
        Store_field(v, 0, copy_string(o->color_class));
        Store_field(v, 1, Val_int(o->color.r));
        Store_field(v, 2, Val_int(o->color.g));
        Store_field(v, 3, Val_int(o->color.b));
        Store_field(v, 4, Val_int(o->color.a));
        Store_field(v, 5, Val_int(o->outline.r));
        Store_field(v, 6, Val_int(o->outline.g));
        Store_field(v, 7, Val_int(o->outline.b));
        Store_field(v, 8, Val_int(o->outline.a));
        Store_field(v, 9, Val_int(o->shadow.r));
        Store_field(v, 10, Val_int(o->shadow.g));
        Store_field(v, 11, Val_int(o->shadow.b));
        Store_field(v, 12, Val_int(o->shadow.a));
        CAMLreturn(v);
}

inline value copy_Eina_List_Elm_Color_Overlay(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_o);
        Eina_List* it;
        Elm_Color_Overlay* o;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, o) {
                v1 = v;
                v_o = copy_Elm_Color_Overlay(o);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_o);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

/* Need */

PREFIX value ml_elm_need_efreet(value v_unit)
{
        return Val_Eina_Bool(elm_need_efreet());
}

PREFIX value ml_elm_need_systray(value v_unit)
{
        return Val_Eina_Bool(elm_need_systray());
}

PREFIX value ml_elm_need_sys_notify(value v_unit)
{
        return Val_Eina_Bool(elm_need_sys_notify());
}

PREFIX value ml_elm_need_eldbus(value v_unit)
{
        return Val_Eina_Bool(elm_need_eldbus());
}

PREFIX value ml_elm_need_elocation(value v_unit)
{
        return Val_Eina_Bool(elm_need_elocation());
}

PREFIX value ml_elm_need_ethumb(value v_unit)
{
        return Val_Eina_Bool(elm_need_ethumb());
}

PREFIX value ml_elm_need_web(value v_unit)
{
        return Val_Eina_Bool(elm_need_web());
}

/* Tooltips */

