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

PREFIX inline Elm_Focus_Direction Elm_Focus_Direction_val(value v)
{
        switch(v) {
                case Val_previous: return ELM_FOCUS_PREVIOUS;
                case Val_next: return ELM_FOCUS_NEXT;
                case Val_up: return ELM_FOCUS_UP;
                case Val_down: return ELM_FOCUS_DOWN;
                case Val_right: return ELM_FOCUS_RIGHT;
                case Val_left: return ELM_FOCUS_LEFT;
                default: break;
        }
        caml_failwith("Elm_Focus_Direction_val");
        return ELM_FOCUS_PREVIOUS;
}

PREFIX inline value Val_Elm_Focus_Direction(Elm_Focus_Direction d)
{
        switch(d) {
                case ELM_FOCUS_PREVIOUS: return Val_previous;
                case ELM_FOCUS_NEXT: return Val_next;
                case ELM_FOCUS_UP: return Val_up;
                case ELM_FOCUS_DOWN: return Val_down;
                case ELM_FOCUS_RIGHT: return Val_right;
                case ELM_FOCUS_LEFT: return Val_left;
                default: break;
        }
        caml_failwith("Val_Elm_Focus_Direction");
        return Val_previous;
}

/* General */

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

PREFIX inline value Val_Elm_Policy_Value(int pv)
{
        switch(pv) {
                case ELM_POLICY_QUIT_NONE: return Val_none;
                case ELM_POLICY_QUIT_LAST_WINDOW_CLOSED:
                        return Val_last_window_closed;
                default: break;
        }
        caml_failwith("Val_Elm_Policy_Value");
        return Val_none;
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

PREFIX value ml_elm_policy_set(value v_policy, value v_value)
{
        return Val_Eina_Bool(elm_policy_set(Elm_Policy_val(v_policy),
                Elm_Policy_Value_val(v_value)));
}

PREFIX value ml_elm_policy_get(value v_policy)
{
        return Val_Elm_Policy_Value(elm_policy_get(Elm_Policy_val(v_policy)));
}

PREFIX value ml_elm_language_set(value v_lang)
{
        elm_language_set(String_val(v_lang));
        return Val_unit;
}

/* Others */

PREFIX value ml_elm_frame_add(value v_parent)
{
        Evas_Object* frame = elm_frame_add((Evas_Object*) v_parent);
        if(frame == NULL) caml_failwith("elm_frame_add");
        return (value) frame;
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

PREFIX value ml_elm_need_ethumb(value v_unit)
{
        return Val_Eina_Bool(elm_need_ethumb());
}

