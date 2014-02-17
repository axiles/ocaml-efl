#include "include.h"

PREFIX inline value copy_Evas_Point(Evas_Point p)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(p.x));
        Store_field(v, 1, Val_int(p.y));
        return v;
}

PREFIX inline value copy_Evas_Coord_Point(Evas_Coord_Point p)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(p.x));
        Store_field(v, 1, Val_int(p.y));
        return v;
}

PREFIX inline value copy_Evas_Position(Evas_Position p)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_Evas_Point(p.output));
        Store_field(v, 1, copy_Evas_Coord_Point(p.canvas));
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Coord_Precision_Point(
        Evas_Coord_Precision_Point p)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(p.x));
        Store_field(v, 1, Val_int(p.y));
        Store_field(v, 2, copy_double(p.xsub));
        Store_field(v, 3, copy_double(p.ysub));
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Precision_Position(Evas_Precision_Position p)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_Evas_Point(p.output));
        Store_field(v, 1, copy_Evas_Coord_Precision_Point(p.canvas));
        CAMLreturn(v);
}

PREFIX inline value Val_Evas_Button_Flags(Evas_Button_Flags f)
{
        switch(f) {
                case EVAS_BUTTON_NONE: return Val_none;
                case EVAS_BUTTON_DOUBLE_CLICK: return Val_double_click;
                case EVAS_BUTTON_TRIPLE_CLICK: return Val_triple_click;
        }
        caml_failwith("Val_Evas_Button_Flag");
        return Val_none;
}

PREFIX void ml_Evas_Smart_Cb(void *data, Evas_Object *obj, void *event_info)
{
      
        value *v_fun = (value*) data;
        caml_callback2(*v_fun, (value) obj, (value) event_info);
      
}

PREFIX void ml_Evas_Smart_Cb_1_free(
        void *data, Evas_Object *obj, void *event_info)
{
      
        value* v_data = (value*) data;
        value v_fun = Field(*v_data, 1);
        caml_callback2(v_fun, (value) obj, (value) event_info);
        ml_remove_value(v_data); 
}

PREFIX value ml_string_of_ptr(value v_ptr)
{
        const char* ptr = (const char*) v_ptr;
        if(ptr == NULL) caml_failwith("string_of_ptr");
        return copy_string(ptr);
}

PREFIX value ml_string_opt_of_ptr(value v_ptr)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* ptr = (const char*) v_ptr;
        if(ptr == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(ptr));
        }
        CAMLreturn(v);
}

PREFIX inline Evas_Aspect_Control Evas_Aspect_Control_val(value v)
{
        switch(v) {
                case Val_none: return EVAS_ASPECT_CONTROL_NONE;
                case Val_neither: return EVAS_ASPECT_CONTROL_NEITHER;
                case Val_horizontal: return EVAS_ASPECT_CONTROL_HORIZONTAL;
                case Val_vertical: return EVAS_ASPECT_CONTROL_VERTICAL;
                case Val_both: return EVAS_ASPECT_CONTROL_BOTH;
        }
        caml_failwith("Evas_Aspect_Control_val");
        return EVAS_ASPECT_CONTROL_NONE;
}

PREFIX value ml_evas_pointer_canvas_xy_get(value v_e)
{
        Evas_Coord x, y;
        evas_pointer_canvas_xy_get((Evas*) v_e, &x, &y);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        return v_r;
}

PREFIX value ml_evas_smart_objects_calculate(value v_e)
{
        evas_smart_objects_calculate((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_bool_of_ptr(value v_ptr)
{
        Eina_Bool x = (Eina_Bool) v_ptr;
        return Val_bool(x);
}

PREFIX value ml_string_string_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_r);
        char** t = (char**) v_ptr;
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_string(t[0]));
        Store_field(v_r, 1, copy_string(t[1]));
        CAMLreturn(v_r);
}

PREFIX value ml_store_ptr_bool(value v_ptr, value v_x)
{
        Eina_Bool* ptr = (Eina_Bool*) v_ptr;
        *ptr = Bool_val(v_x);
        return Val_unit;
}

PREFIX value ml_obj_of_ptr(value v_ptr)
{
        Evas_Object* obj = (Evas_Object*) v_ptr;
        return (value) obj;
}

PREFIX value ml_float_of_ptr(value v_ptr)
{
        double* x = (double*) x;
        return copy_double(*x);
}

PREFIX inline Evas_Load_Error Evas_Load_Error_val(value v)
{
        switch(v) {
                case Val_none: return EVAS_LOAD_ERROR_NONE;
                case Val_generic: return EVAS_LOAD_ERROR_GENERIC;
                case Val_does_not_exist: return EVAS_LOAD_ERROR_DOES_NOT_EXIST;
                case Val_permission_denied:
                        return EVAS_LOAD_ERROR_PERMISSION_DENIED;
                case Val_resource_allocation_failed:
                        return EVAS_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED;
                case Val_corrupt_file: return EVAS_LOAD_ERROR_CORRUPT_FILE;
                case Val_unknown_format: return EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                default: break;
        }
        caml_failwith("Evas_Load_Error_val");
        return EVAS_LOAD_ERROR_NONE;
}

PREFIX inline value Val_Evas_Load_Error(Evas_Load_Error e)
{
        switch(e) {
                case EVAS_LOAD_ERROR_NONE: return Val_none;
                case EVAS_LOAD_ERROR_GENERIC: return Val_generic;
                case EVAS_LOAD_ERROR_DOES_NOT_EXIST:
                        return Val_does_not_exist;
                case EVAS_LOAD_ERROR_PERMISSION_DENIED:
                        return Val_permission_denied;
                case EVAS_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED:
                        return Val_resource_allocation_failed;
                case EVAS_LOAD_ERROR_CORRUPT_FILE: return Val_corrupt_file;
                case EVAS_LOAD_ERROR_UNKNOWN_FORMAT: return Val_unknown_format;
        }
        caml_failwith("Val_Evas_Load_Error");
        return Val_none;
}

PREFIX value ml_evas_color_argb_premul(
        value v_a, value v_r, value v_g, value v_b)
{
        int r, g, b;
        r = Int_val(v_r);
        g = Int_val(v_g);
        b = Int_val(v_b);
        evas_color_argb_premul(Int_val(v_a), &r, &g, &b);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        return v;
}

PREFIX void ml_Evas_Smart_Cb_on_del(
        void* data, Evas_Object* v_obj, void* event_info)
{
        value* v_data = (value*) data;
        ml_remove_value(v_data);
}

/* Top Level Functions */

PREFIX inline value Val_Evas_Alloc_Error(Evas_Alloc_Error e)
{
        switch(e) {
                case EVAS_ALLOC_ERROR_NONE: return Val_none;
                case EVAS_ALLOC_ERROR_FATAL: return Val_fatal;
                case EVAS_ALLOC_ERROR_RECOVERED: return Val_recovered;
        }
        caml_failwith("Val_Evas_Alloc_Error");
        return Val_none;
}

PREFIX value ml_evas_init(value v_unit)
{
        return Val_int(evas_init());
}

PREFIX value ml_evas_shutdown(value v_unit)
{
        return Val_int(evas_shutdown());
}

PREFIX value ml_evas_alloc_error(value v_unit)
{
        return Val_Evas_Alloc_Error(evas_alloc_error());
}

PREFIX value ml_evas_async_events_fd_get(value v_unit)
{
        return Val_int(evas_async_events_fd_get());
}

PREFIX value ml_evas_async_events_process(value v_unit)
{
        return Val_int(evas_async_events_process());
}

/* Render Engine Functions */

PREFIX value ml_evas_render_method_lookup(value v_name)
{
        return Val_int(evas_render_method_lookup(String_val(v_name)));
}

PREFIX value ml_evas_render_method_list(value v_unit)
{
        Eina_List* list = evas_render_method_list();
        value v_list = copy_Eina_List_string(list);
        evas_render_method_list_free(list);
        return v_list;
}

PREFIX value ml_evas_output_method_set(value v_e, value v_m)
{
        evas_output_method_set((Evas*) v_e, Int_val(v_m));
        return Val_unit;
}

PREFIX value ml_evas_output_method_get(value v_e)
{
        return Val_int(evas_output_method_get((Evas*) v_e));
}

