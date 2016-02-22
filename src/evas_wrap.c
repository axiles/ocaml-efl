#include "include.h"

inline value copy_Evas_Button_Flags(Evas_Button_Flags f)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_bool(f & EVAS_BUTTON_DOUBLE_CLICK));
        Store_field(v, 1, Val_bool(f & EVAS_BUTTON_TRIPLE_CLICK));
        return v;
}

void ml_Evas_Smart_Cb(void *data, Evas_Object *obj, void *event_info)
{
      
        value *v_fun = (value*) data;
        caml_callback2(*v_fun, (value) obj, (value) event_info);
      
}

void ml_Evas_Smart_Cb_1_free(
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

void ml_Evas_Smart_Cb_on_del(
        void* data, Evas_Object* v_obj, void* event_info)
{
        value* v_data = (value*) data;
        ml_remove_value(v_data);
}

/* Top Level Functions */

PREFIX value ml_evas_init(value v_unit)
{
        return Val_int(evas_init());
}

PREFIX value ml_evas_shutdown(value v_unit)
{
        int r = evas_shutdown();
        ml_Evas_remove_values();
        return Val_int(r);
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

static Eina_List* ml_evas_values_list = NULL;

inline value* ml_Evas_register_value(value v)
{
        value* data = ml_register_value(v);
        ml_evas_values_list = eina_list_append(ml_evas_values_list, data);
        return data;
}

inline void ml_Evas_remove_values()
{
        Eina_List* tmp;
        value* data;
        EINA_LIST_FOREACH(ml_evas_values_list, tmp, data)
                ml_remove_value(data);
        eina_list_free(ml_evas_values_list);
        ml_evas_values_list = NULL;
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

/* Coordinate Mapping Functions */

PREFIX value ml_evas_coord_screen_x_to_world(value v_e, value v_x)
{
        return Val_int(evas_coord_screen_x_to_world((Evas*) v_e, Int_val(v_x)));
}

PREFIX value ml_evas_coord_screen_y_to_world(value v_e, value v_x)
{
        return Val_int(evas_coord_screen_y_to_world((Evas*) v_e, Int_val(v_x)));
}

PREFIX value ml_evas_coord_world_x_to_screen(value v_e, value v_x)
{
        return Val_int(evas_coord_world_x_to_screen((Evas*) v_e, Int_val(v_x)));
}

PREFIX value ml_evas_coord_world_y_to_screen(value v_e, value v_x)
{
        return Val_int(evas_coord_world_y_to_screen((Evas*) v_e, Int_val(v_x)));
}

/* Output Viewport Resizing Functions */

PREFIX value ml_evas_output_size_set(value v_e, value v_w, value v_h)
{
        evas_output_size_set((Evas*) v_e, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_output_size_get(value v_e)
{
        int w, h;
        evas_output_size_get((Evas*) v_e, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_evas_output_viewport_set(
        value v_e, value v_x, value v_y, value v_w, value v_h)
{
        evas_output_viewport_set((Evas*) v_e, Int_val(v_x), Int_val(v_y),
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_output_viewport_get(value v_e)
{
        Evas_Coord x, y, w, h;
        evas_output_viewport_get((Evas*) v_e, &x, &y, &w, &h);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        Store_field(v_r, 2, Val_int(w));
        Store_field(v_r, 3, Val_int(h));
        return v_r;
}

PREFIX value ml_evas_output_framespace_set(
        value v_e, value v_x, value v_y, value v_w, value v_h)
{
        evas_output_framespace_set((Evas*) v_e, Int_val(v_x), Int_val(v_y),
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_output_framespace_get(value v_e)
{
        Evas_Coord x, y, w, h;
        evas_output_framespace_get((Evas*) v_e, &x, &y, &w, &h);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        Store_field(v_r, 2, Val_int(w));
        Store_field(v_r, 3, Val_int(h));
        return v_r;
}

inline Evas_Callback_Priority Evas_Callback_Priority_val(value v)
{
        if(Is_long(v)) {
                switch(v) {
                        case Val_after: return EVAS_CALLBACK_PRIORITY_AFTER;
                        case Val_before: return EVAS_CALLBACK_PRIORITY_BEFORE;
                        case Val_default: return EVAS_CALLBACK_PRIORITY_DEFAULT;
                }
        } else {
                switch(Field(v, 0)) {
                        case Val_other: return Int_val(Field(v, 1));
                }
        }
        caml_failwith("Evas_Callback_Priority_val");
        return EVAS_CALLBACK_PRIORITY_AFTER;
}


/* Image Functions */

PREFIX value ml_evas_image_cache_flush(value v_e)
{
        evas_image_cache_flush((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_image_cache_reload(value v_e)
{
        evas_image_cache_reload((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_image_cache_set(value v_e, value v_size)
{
        evas_image_cache_set((Evas*) v_e, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_evas_image_cache_get(value v_e)
{
        return Val_int(evas_image_cache_get((Evas*) v_e));
}

PREFIX value ml_evas_image_max_size_get(value v_e)
{
        CAMLparam1(v_e);
        CAMLlocal2(v_r, v_size);
        int maxw, maxh;
        Eina_Bool r = evas_image_max_size_get((Evas*) v_e, &maxw, &maxh);
        if(r) {
                v_size = caml_alloc(2, 0);
                Store_field(v_size, 0, Val_int(maxw));
                Store_field(v_size, 1, Val_int(maxh));
                v_r = caml_alloc(1, 0);
                Store_field(v_r, 0, v_size);
        } else v_r = Val_int(0);
        CAMLreturn(v_r);
}

/* General Canvas Functions */

PREFIX value ml_evas_new(value v_unit)
{
        Evas* e = evas_new();
        if(e == NULL) caml_failwith("evas_new");
        return (value) e;
}

PREFIX value ml_evas_free(value v_e)
{
        evas_free((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_focus_in(value v_e)
{
        evas_focus_in((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_focus_out(value v_e)
{
        evas_focus_out((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_focus_state_get(value v_e)
{
        return Val_bool(evas_focus_state_get((Evas*) v_e));
}

PREFIX value ml_evas_nochange_push(value v_e)
{
        evas_nochange_push((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_nochange_pop(value v_e)
{
        evas_nochange_pop((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_damage_rectangle_add(
        value v_e, value v_x, value v_y, value v_w, value v_h)
{
        evas_damage_rectangle_add((Evas*) v_e, Int_val(v_x), Int_val(v_y),
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_obscured_rectangle_add(
        value v_e, value v_x, value v_y, value v_w, value v_h)
{
        evas_obscured_rectangle_add((Evas*) v_e, Int_val(v_x), Int_val(v_y),
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_obscured_clear(value v_e)
{
        evas_obscured_clear((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_render_async(value v_e)
{
        return Val_bool(evas_render_async((Evas*) v_e));
}

PREFIX value ml_evas_render_updates(value v_e)
{
        return copy_Eina_List_Eina_Rectangle(evas_render_updates((Evas*) v_e));
}

PREFIX value ml_evas_render(value v_e)
{
        evas_render((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_norender(value v_e)
{
        evas_norender((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_render_idle_flush(value v_e)
{
        evas_render_idle_flush((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_render_dump(value v_e)
{
        evas_render_dump((Evas*) v_e);
        return Val_unit;
}

/* Input Events Feeding Functions */

value copy_Eina_List_Evas_Device(const Eina_List* list);

inline value copy_Eina_List_Evas_Device(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Evas_Device* dev;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, dev) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) dev);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline value copy_Evas_Device_opt(const Evas_Device* dev)
{
        if(dev == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) dev);
        return v_r;
}

inline Evas_Device* Evas_Device_opt_val(value v)
{
        if(v == Val_int(0)) return NULL;
        else return (Evas_Device*) Field(v, 0);
}

PREFIX value ml_evas_device_add(value v_e)
{
        Evas_Device* dev = evas_device_add((Evas*) v_e);
        if(dev == NULL) caml_failwith("evas_device_add");
        return (value) dev;
}

PREFIX value ml_evas_device_del(value v_dev)
{
        evas_device_del((Evas_Device*) v_dev);
        return Val_unit;
}

PREFIX value ml_evas_device_push(value v_e, value v_dev)
{
        evas_device_push((Evas*) v_e, (Evas_Device*) v_dev);
        return Val_unit;
}

PREFIX value ml_evas_device_pop(value v_e)
{
        evas_device_pop((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_device_list(value v_e, value v_dev)
{
        return copy_Eina_List_Evas_Device(evas_device_list((Evas*) v_e,
                Evas_Device_opt_val(v_dev)));
}

PREFIX value ml_evas_device_name_set(value v_dev, value v_s)
{
        evas_device_name_set((Evas_Device*) v_dev, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_evas_device_name_get(value v_dev)
{
        return copy_string_opt(evas_device_name_get((Evas_Device*) v_dev));
}

PREFIX value ml_evas_device_description_set(value v_dev, value v_s)
{
        evas_device_description_set((Evas_Device*) v_dev, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_evas_device_description_get(value v_dev)
{
        return copy_string_opt(evas_device_description_get(
                (Evas_Device*) v_dev));
}

PREFIX value ml_evas_device_parent_set(value v_dev, value v_parent)
{
        evas_device_parent_set((Evas_Device*) v_dev,
                Evas_Device_opt_val(v_parent));
        return Val_unit;
}

PREFIX value ml_evas_device_parent_get(value v_dev)
{
        return copy_Evas_Device_opt(evas_device_parent_get(
                (Evas_Device*) v_dev));
}

/* Finding Objects */

PREFIX value ml_evas_focus_get(value v_e)
{
        return copy_Evas_Object_opt(evas_focus_get((Evas*) v_e));
}

PREFIX value ml_evas_objects_at_xy_get(
        value v_e, value v_x, value v_y, value v_ip, value v_ih)
{
        return copy_Eina_List_Evas_Object(evas_objects_at_xy_get((Evas*) v_e,
                Int_val(v_x), Int_val(v_y), Bool_val(v_ip), Bool_val(v_ih)));
}

PREFIX value ml_evas_objects_in_rectangle_get_native(
        value v_e, value v_x, value v_y, value v_w, value v_h, value v_ip,
        value v_ih)
{
        return copy_Eina_List_Evas_Object(evas_objects_in_rectangle_get(
                (Evas*) v_e, Int_val(v_x), Int_val(v_y), Int_val(v_w),
                Int_val(v_h), Bool_val(v_ip), Bool_val(v_ih)));
}

PREFIX value ml_evas_objects_in_rectangle_get_byte(value* argv, int argn)
{
        return ml_evas_objects_in_rectangle_get_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Shared Image Cache Server */

/*inline value copy_Evas_Cserve_Stats(Evas_Cserve_Stats s)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(6, 0);
        Store_field(v, 0, Val_int(s.saved_memory));
        Store_field(v, 1, Val_int(s.wasted_memory));
        Store_field(v, 2, Val_int(s.saved_memory_peak));
        Store_field(v, 3, Val_int(s.wasted_memory_peak));
        Store_field(v, 4, copy_double(s.saved_time_image_header_load));
        Store_field(v, 5, copy_double(s.saved_time_image_data_load));
        CAMLreturn(v);
}

inline Evas_Cserve_Config Evas_Cserve_Config_val(value v)
{
        Evas_Cserve_Config c;
        c.cache_max_usage = Int_val(Field(v, 0));
        c.cache_item_timeout = Int_val(Field(v, 1));
        c.cache_item_timeout_check = Int_val(Field(v, 2));
        return c;
}

inline value copy_Evas_Cserve_Config(Evas_Cserve_Config c)
{
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(c.cache_max_usage));
        Store_field(v, 1, Val_int(c.cache_item_timeout));
        Store_field(v, 2, Val_int(c.cache_item_timeout_check));
        return v;
}*/

PREFIX value ml_evas_cserve_want_get(value v_unit)
{
        return Val_bool(evas_cserve_want_get());
}

PREFIX value ml_evas_cserve_connected_get(value v_unit)
{
        return Val_bool(evas_cserve_connected_get());
}

PREFIX value ml_evas_cserve_stats_get(value v_unit)
{
        CAMLparam1(v_unit);
        CAMLlocal1(v_r);
        Evas_Cserve_Stats s;
        Eina_Bool r = evas_cserve_stats_get(&s);
        if(r) {
                v_r = caml_alloc(1, 0);
                Store_field(v_r, 0, copy_Evas_Cserve_Stats(s));
        } else v_r = Val_int(0);
        CAMLreturn(v_r);
}

PREFIX value ml_evas_cserve_config_get(value v_unit)
{
        CAMLparam1(v_unit);
        CAMLlocal1(v_r);
        Evas_Cserve_Config s;
        Eina_Bool r = evas_cserve_config_get(&s);
        if(r) {
                v_r = caml_alloc(1, 0);
                Store_field(v_r, 0, copy_Evas_Cserve_Config(s));
        } else v_r = Val_int(0);
        CAMLreturn(v_r);
}

PREFIX value ml_evas_cserve_config_set(value v_c)
{
        Evas_Cserve_Config c = Evas_Cserve_Config_val(v_c);
        return Val_bool(evas_cserve_config_set(&c));
}

PREFIX value ml_evas_cserve_disconnected(value v_unit)
{
        evas_cserve_disconnect();
        return Val_unit;
}

/* General Utilities */

PREFIX value ml_evas_load_error_str(value v_err)
{
        return copy_string(evas_load_error_str(Evas_Load_Error_val(v_err)));
}

PREFIX value ml_evas_color_hsv_to_rgb(value v_h, value v_s, value v_v)
{
        int r, g, b;
        evas_color_hsv_to_rgb(Double_val(v_h), Double_val(v_s),
                Double_val(v_v), &r, &g, &b);
        value v_res = caml_alloc(3, 0);
        Store_field(v_res, 0, Val_int(r));
        Store_field(v_res, 1, Val_int(g));
        Store_field(v_res, 2, Val_int(b));
        return v_res;
}

PREFIX value ml_evas_color_rgb_to_hsv(value v_r, value v_g, value v_b)
{
        CAMLparam3(v_r, v_g, v_b);
        CAMLlocal1(v_res);
        float h, s, v;
        evas_color_rgb_to_hsv(Int_val(v_r), Int_val(v_g), Int_val(v_b), &h, &s,
                &v);
        v_res = caml_alloc(3, 0);
        Store_field(v_res, 0, copy_double(h));
        Store_field(v_res, 1, copy_double(s));
        Store_field(v_res, 2, copy_double(v));
        CAMLreturn(v_res);
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

PREFIX value ml_evas_color_argb_unpremul(
        value v_a, value v_r, value v_g, value v_b)
{
        int r, g, b;
        r = Int_val(v_r);
        g = Int_val(v_g);
        b = Int_val(v_b);
        evas_color_argb_unpremul(Int_val(v_a), &r, &g, &b);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        return v;
}

PREFIX value ml_evas_data_argb_premul(value v_a)
{
        unsigned int size = Wosize_val(v_a);
        unsigned int a[size];
        int i;
        for(i = 0; i < size; i++) a[i] = Int_val(Field(v_a, i));
        evas_data_argb_premul(a, size);
        for(i = 0; i < size; i++) Store_field(v_a, i, Val_int(a[i]));
        return Val_unit;
}

PREFIX value ml_evas_data_argb_unpremul(value v_a)
{
        unsigned int size = Wosize_val(v_a);
        unsigned int a[size];
        int i;
        for(i = 0; i < size; i++) a[i] = Int_val(Field(v_a, i));
        evas_data_argb_unpremul(a, size);
        for(i = 0; i < size; i++) Store_field(v_a, i, Val_int(a[i]));
        return Val_unit;
}

PREFIX value ml_evas_string_char_next_get(value v_s, value v_pos)
{
        CAMLparam2(v_s, v_pos);
        CAMLlocal1(v);
        int decoded;
        int next = evas_string_char_next_get(String_val(v_s), Int_val(v_pos),
                &decoded);
        v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(next));
        Store_field(v, 1, copy_int32(decoded));
        CAMLreturn(v);
}

PREFIX value ml_evas_string_char_prev_get(value v_s, value v_pos)
{
        CAMLparam2(v_s, v_pos);
        CAMLlocal1(v);
        int decoded;
        int prev = evas_string_char_prev_get(String_val(v_s), Int_val(v_pos),
                &decoded);
        v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(prev));
        Store_field(v, 1, copy_int32(decoded));
        CAMLreturn(v);
}

PREFIX value ml_evas_string_char_len_get(value v_s)
{
        return Val_int(evas_string_char_len_get(String_val(v_s)));
}

PREFIX value copy_Evas_Coord_Size(Evas_Coord_Size* s)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(s->w));
        Store_field(v, 1, Val_int(s->h));
        return v;
}

