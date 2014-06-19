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

inline Elm_Focus_Autoscroll_Mode Elm_Focus_Autoscroll_Mode_val(value v)
{
        switch(v) {
                case Val_show: return ELM_FOCUS_AUTOSCROLL_MODE_SHOW;
                case Val_none: return ELM_FOCUS_AUTOSCROLL_MODE_NONE;
                case Val_bring_in: return ELM_FOCUS_AUTOSCROLL_MODE_BRING_IN;
                default: break;
        }
        caml_failwith("Elm_Focus_Autoscroll_Mode_val");
        return ELM_FOCUS_AUTOSCROLL_MODE_SHOW;
}

inline value Val_Elm_Focus_Autoscroll_Mode(Elm_Focus_Autoscroll_Mode m)
{
        switch(m) {
                case ELM_FOCUS_AUTOSCROLL_MODE_SHOW: return Val_show;
                case ELM_FOCUS_AUTOSCROLL_MODE_NONE: return Val_none;
                case ELM_FOCUS_AUTOSCROLL_MODE_BRING_IN: return Val_bring_in;
        }
        caml_failwith("Val_Elm_Focus_Autoscroll_Mode");
        return Val_show;
}

inline Elm_Focus_Direction Elm_Focus_Direction_val(value v)
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

inline value Val_Elm_Focus_Direction(Elm_Focus_Direction d)
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

inline Elm_Focus_Move_Policy Elm_Focus_Move_Policy_val(value v)
{
        switch(v) {
                case Val_click: return ELM_FOCUS_MOVE_POLICY_CLICK;
                case Val_in: return ELM_FOCUS_MOVE_POLICY_IN;
                default: break;
        }
        caml_failwith("Elm_Focus_Move_Policy_val");
        return ELM_FOCUS_MOVE_POLICY_CLICK;
}

inline value Val_Elm_Focus_Move_Policy(Elm_Focus_Move_Policy p)
{
        switch(p) {
                case ELM_FOCUS_MOVE_POLICY_CLICK: return Val_click;
                case ELM_FOCUS_MOVE_POLICY_IN: return Val_in;
        }
        caml_failwith("Val_Elm_Focus_Move_Policy");
        return Val_click;
}

/* General */

inline int Elm_Policy_Quit_val(value v)
{
        switch(v) {
                case Val_none: return ELM_POLICY_QUIT_NONE;
                case Val_last_window_closed:
                               return ELM_POLICY_QUIT_LAST_WINDOW_CLOSED;
        }
        caml_failwith("Elm_Policy_Quit_val");
        return ELM_POLICY_QUIT_NONE;
}

inline value Val_Elm_Policy_Quit(int pv)
{
        switch(pv) {
                case ELM_POLICY_QUIT_NONE: return Val_none;
                case ELM_POLICY_QUIT_LAST_WINDOW_CLOSED:
                        return Val_last_window_closed;
                default: break;
        }
        caml_failwith("Val_Elm_Policy_Quit");
        return Val_none;
}

inline int Elm_Policy_Exit_val(value v)
{
        switch(v) {
                case Val_none: return ELM_POLICY_EXIT_NONE;
                case Val_windows_del: return ELM_POLICY_EXIT_WINDOWS_DEL;
                default: break;
        }
        caml_failwith("Elm_Policy_Exit_val");
        return ELM_POLICY_EXIT_NONE;
}

inline value Val_Elm_Policy_Exit(int pv)
{
        switch(pv) {
                case ELM_POLICY_EXIT_NONE: return Val_none;
                case ELM_POLICY_EXIT_WINDOWS_DEL: return Val_windows_del;
                default: break;
        }
        caml_failwith("Val_Elm_Policy_Exit");
        return Val_none;
}

inline int Elm_Policy_Throttle_val(value v)
{
        switch(v) {
                case Val_config: return ELM_POLICY_THROTTLE_CONFIG;
                case Val_hidden_always:
                        return ELM_POLICY_THROTTLE_HIDDEN_ALWAYS;
                case Val_never: return ELM_POLICY_THROTTLE_NEVER;
                default: break;
        }
        caml_failwith("Elm_Policy_Throttle_val");
        return ELM_POLICY_THROTTLE_CONFIG;
}

inline value Val_Elm_Policy_Throttle(int pv)
{
        switch(pv) {
                case ELM_POLICY_THROTTLE_CONFIG: return Val_config;
                case ELM_POLICY_THROTTLE_HIDDEN_ALWAYS:
                        return Val_hidden_always;
                case ELM_POLICY_THROTTLE_NEVER: return Val_never;
                default: break;
        }
        caml_failwith("Val_Elm_Policy_Throttle");
        return Val_config;
}

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

inline Elm_Tooltip_Orient Elm_Tooltip_Orient_val(value v)
{
        switch(v) {
                case Val_none: return ELM_TOOLTIP_ORIENT_NONE;
                case Val_top_left: return ELM_TOOLTIP_ORIENT_TOP_LEFT;
                case Val_top: return ELM_TOOLTIP_ORIENT_TOP;
                case Val_top_right: return ELM_TOOLTIP_ORIENT_TOP_RIGHT;
                case Val_left: return ELM_TOOLTIP_ORIENT_LEFT;
                case Val_center: return ELM_TOOLTIP_ORIENT_CENTER;
                case Val_right: return ELM_TOOLTIP_ORIENT_RIGHT;
                case Val_bottom_left: return ELM_TOOLTIP_ORIENT_BOTTOM_LEFT;
                case Val_bottom: return ELM_TOOLTIP_ORIENT_BOTTOM;
                case Val_bottom_right: return ELM_TOOLTIP_ORIENT_BOTTOM_RIGHT;
                case Val_last: return ELM_TOOLTIP_ORIENT_LAST;
        }
        caml_failwith("Elm_Tooltip_Orient_val");
        return ELM_TOOLTIP_ORIENT_NONE;
}

inline value Val_Elm_Tooltip_Orient(Elm_Tooltip_Orient o)
{
        switch(o) {
                case ELM_TOOLTIP_ORIENT_NONE: return Val_none;
                case ELM_TOOLTIP_ORIENT_TOP_LEFT: return Val_top_left;
                case ELM_TOOLTIP_ORIENT_TOP: return Val_top;
                case ELM_TOOLTIP_ORIENT_TOP_RIGHT: return Val_top_right;
                case ELM_TOOLTIP_ORIENT_LEFT: return Val_left;
                case ELM_TOOLTIP_ORIENT_CENTER: return Val_center;
                case ELM_TOOLTIP_ORIENT_RIGHT: return Val_right;
                case ELM_TOOLTIP_ORIENT_BOTTOM_LEFT: return Val_bottom_left;
                case ELM_TOOLTIP_ORIENT_BOTTOM: return Val_bottom;
                case ELM_TOOLTIP_ORIENT_BOTTOM_RIGHT: return Val_bottom_right;
                case ELM_TOOLTIP_ORIENT_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Tooltip_Orient");
        return Val_none;
}
                                             
