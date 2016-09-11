#include "include.h"

value copy_Eina_List_Elm_Map_Overlay(const Eina_List* list);
inline value copy_Eina_List_Elm_Map_Overlay(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Map_Overlay* obj;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, obj) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) obj);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline Eina_List* Eina_List_Elm_Map_Overlay_val(value v_list)
{
        Eina_List* list = NULL;
        value v = v_list;
        while(v != Val_int(0)) {
                list = eina_list_append(list, (Elm_Map_Overlay*) Field(v, 0));
                v = Field(v, 1);
        }
        return list;
}

void ml_Elm_Map_Overlay_Get_Cb(
        void* data, Evas_Object* map, Elm_Map_Overlay* overlay)
{
        value* v_fun = (value*) data;
        caml_callback2(*v_fun, (value) map, (value) overlay);
}

void ml_Elm_Map_Route_Cb(void* data, Evas_Object* map, Elm_Map_Route* route)
{
        value* v_fun = (value*) data;
        caml_callback2(*v_fun, (value) map, (value) route);
}

void ml_Elm_Map_Name_Cb(void* data, Evas_Object* map, Elm_Map_Name* name)
{
        value* v_fun = (value*) data;
        caml_callback2(*v_fun, (value) map, (value) name);
}

PREFIX value ml_elm_map_add(value v_parent)
{
        Evas_Object* map = elm_map_add(Evas_Object_val(v_parent));
        if(map == NULL) caml_failwith("elm_map_add");
        return (value) map;
}

PREFIX value ml_elm_map_region_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double lon, lat;
        elm_map_region_get(Evas_Object_val(v_obj), &lon, &lat);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(lon));
        Store_field(v_r, 1, copy_double(lat));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_canvas_to_region_convert(
        value v_obj, value v_x, value v_y)
{
        CAMLparam3(v_obj, v_x, v_y);
        CAMLlocal1(v_r);
        double lon, lat;
        elm_map_canvas_to_region_convert(Evas_Object_val(v_obj), Int_val(v_x),
                Int_val(v_y), &lon, &lat);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(lon));
        Store_field(v_r, 1, copy_double(lat));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_region_to_canvas_convert(
        value v_obj, value v_lon, value v_lat)
{
        Evas_Coord x, y;
        elm_map_region_to_canvas_convert(Evas_Object_val(v_obj),
                Double_val(v_lon), Double_val(v_lat), &x, &y);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        return v_r;
}

PREFIX value ml_elm_map_rotate_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double a;
        Evas_Coord x, y;
        elm_map_rotate_get(Evas_Object_val(v_obj), &a, &x, &y);
        v_r = caml_alloc(3, 0);
        Store_field(v_r, 0, copy_double(a));
        Store_field(v_r, 1, Val_int(x));
        Store_field(v_r, 2, Val_int(y));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_overlay_add(value v_obj, value v_lon, value v_lat)
{
        Elm_Map_Overlay* ov = elm_map_overlay_add(Evas_Object_val(v_obj),
                Double_val(v_lon), Double_val(v_lat));
        if(ov == NULL) caml_failwith("elm_map_overlay_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlays_get(value v_obj)
{
        return copy_Eina_List_Elm_Map_Overlay(elm_map_overlays_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_map_overlay_content_set(value v_ov, value v_obj)
{
        Evas_Object* obj;
        if(v_obj == Val_int(0)) obj = NULL;
        else obj = Evas_Object_val(Field(v_obj, 0));
        elm_map_overlay_content_set((Elm_Map_Overlay*) v_ov, obj);
        return Val_unit;
}

PREFIX value ml_elm_map_overlay_content_get(value v_ov)
{
        return copy_Evas_Object_opt(elm_map_overlay_content_get(
                (Elm_Map_Overlay*) v_ov));
}

PREFIX value ml_elm_map_overlay_icon_set(value v_ov, value v_obj)
{
        Evas_Object* obj;
        if(v_obj == Val_int(0)) obj = NULL;
        else obj = Evas_Object_val(Field(v_obj, 0));
        elm_map_overlay_icon_set((Elm_Map_Overlay*) v_ov, obj);
        return Val_unit;
}

PREFIX value ml_elm_map_overlay_icon_get(value v_ov)
{
        return copy_Evas_Object_opt(elm_map_overlay_icon_get(
                (Elm_Map_Overlay*) v_ov));
}

PREFIX value ml_elm_map_overlay_region_get(value v_ov)
{
        CAMLparam1(v_ov);
        CAMLlocal1(v_r);
        double lon, lat;
        elm_map_overlay_region_get((Elm_Map_Overlay*) v_ov, &lon, &lat);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(lon));
        Store_field(v_r, 1, copy_double(lat));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_overlay_color_get(value v_ov)
{
        int r, g, b, a;
        elm_map_overlay_color_get((Elm_Map_Overlay*) v_ov, &r, &g, &b, &a);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        Store_field(v, 3, Val_int(a));
        return v;
}

PREFIX value ml_elm_map_overlays_show(value v_list)
{
        Eina_List* list = Eina_List_Elm_Map_Overlay_val(v_list);
        elm_map_overlays_show(list);
        eina_list_free(list);
        return Val_unit;
}

PREFIX value ml_elm_map_overlay_get_cb_set(value v_ov, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_map_overlay_get_cb_set((Elm_Map_Overlay*) v_ov,
                ml_Elm_Map_Overlay_Get_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_map_overlay_class_add(value v_obj)
{
        Elm_Map_Overlay* ov = elm_map_overlay_class_add(Evas_Object_val(v_obj));
        if(ov == NULL) caml_failwith("elm_map_overlay_class_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlay_group_members_get(value v_ov)
{
        return copy_Eina_List_Elm_Map_Overlay(elm_map_overlay_group_members_get(
                (Elm_Map_Overlay*) v_ov));
}

PREFIX value ml_elm_map_overlay_bubble_add(value v_obj)
{
        Elm_Map_Overlay* ov = elm_map_overlay_bubble_add(
                Evas_Object_val(v_obj));
        if(ov == NULL) caml_failwith("elm_map_overlay_bubble_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlay_route_add(value v_obj, value v_route)
{
        Elm_Map_Overlay* ov = elm_map_overlay_route_add(Evas_Object_val(v_obj),
                (Elm_Map_Route*) v_route);
        if(ov == NULL) caml_failwith("elm_map_overlay_route_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlay_line_add(
        value v_obj, value v_flon, value v_flat, value v_tlon, value v_tlat)
{
        Elm_Map_Overlay* ov = elm_map_overlay_line_add(Evas_Object_val(v_obj),
                Double_val(v_flon), Double_val(v_flat), Double_val(v_tlon),
                Double_val(v_tlat));
        if(ov == NULL) caml_failwith("elm_map_overlay_line_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlay_polygon_add(value v_obj)
{
        Elm_Map_Overlay* ov = elm_map_overlay_polygon_add(
                Evas_Object_val(v_obj));
        if(ov == NULL) caml_failwith("elm_map_overlay_polygon_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlay_circle_add(
        value v_obj, value v_lon, value v_lat, value v_radius)
{
        Elm_Map_Overlay* ov = elm_map_overlay_circle_add(Evas_Object_val(v_obj),
                Double_val(v_lon), Double_val(v_lat), Double_val(v_radius));
        if(ov == NULL) caml_failwith("elm_map_overlay_circle_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlay_scale_add(value v_obj, value v_x, value v_y)
{
        Elm_Map_Overlay* ov = elm_map_overlay_scale_add(Evas_Object_val(v_obj),
                Int_val(v_x), Int_val(v_y));
        if(ov == NULL) caml_failwith("elm_map_overlay_scale_add");
        return (value) ov;
}

PREFIX value ml_elm_map_tile_load_status_get(value v_obj)
{
        int try_num, finish_num;
        elm_map_tile_load_status_get(Evas_Object_val(v_obj), &try_num,
                &finish_num);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(try_num));
        Store_field(v_r, 1, Val_int(finish_num));
        return v_r;
}

PREFIX value ml_elm_map_sources_get(value v_obj, value v_type)
{
        CAMLparam2(v_obj, v_type);
        CAMLlocal3(v_r, v_tmp, v_tmp1);
        const char** sources = elm_map_sources_get(Evas_Object_val(v_obj),
                Elm_Map_Source_Type_val(v_type));
        if(sources[0] == NULL) CAMLreturn(Val_int(0));
        v_tmp = caml_alloc(2, 0);
        Store_field(v_tmp, 0, copy_string(sources[0]));
        Store_field(v_tmp, 1, Val_int(0));
        v_r = v_tmp;
        int i;
        for(i = 1; sources[i] != NULL; i++) {
                v_tmp1 = v_tmp;
                v_tmp = caml_alloc(2, 0);
                Store_field(v_tmp, 0, copy_string(sources[i]));
                Store_field(v_tmp, 1, Val_int(0));
                Store_field(v_tmp1, 1, v_tmp);
        }
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_route_add_native(
        value v_obj, value v_type, value v_method, value v_flon, value v_flat,
        value v_tlon, value v_tlat, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        Elm_Map_Route* route = elm_map_route_add(Evas_Object_val(v_obj),
                Elm_Map_Route_Type_val(v_type),
                Elm_Map_Route_Method_val(v_method), Double_val(v_flon),
                Double_val(v_flat), Double_val(v_tlon), Double_val(v_tlat),
                ml_Elm_Map_Route_Cb, data);
        if(route == NULL) caml_failwith("elm_map_route_add");
        return (value) route;
}

PREFIX value ml_elm_map_route_add_bytecode(value* argv, int argn)
{
        return ml_elm_map_route_add_native(argv[0], argv[1], argv[2], argv[3],
                argv[4], argv[5], argv[6], argv[7]);
}

PREFIX value ml_elm_map_name_add_native(
        value v_obj, value v_addr, value v_lon, value v_lat, value v_cb,
        value v_unit)
{
        Evas_Object* obj = Evas_Object_val(v_obj);
        const char* addr;
        if(v_addr == Val_int(0)) addr = NULL;
        else addr = String_val(Field(v_addr, 0));
        double lon;
        if(v_lon == Val_int(0)) lon = 0;
        else lon = Double_val(Field(v_lon, 0));
        double lat;
        if(v_lat == Val_int(0)) lat = 0;
        else lat = Double_val(Field(v_lat, 0));
        Elm_Map_Name_Cb cb;
        value* data;
        if(v_cb == Val_int(0)) {
                cb = NULL;
                data = NULL;
        } else {
                cb = ml_Elm_Map_Name_Cb;
                data = ml_register_value(Field(v_cb, 0));
        }
        Elm_Map_Name* name = elm_map_name_add(obj, addr, lon, lat, cb, data);
        if(name == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_map_name_add");
        }
        if(data != NULL) ml_Evas_Object_gc_value(obj, data);
        return (value) name;
}

PREFIX value ml_elm_map_name_add_bytecode(value* argv, int argn)
{
        return ml_elm_map_name_add_native(argv[0], argv[1], argv[2], argv[3],
                argv[4], argv[5]);
}

PREFIX value ml_elm_map_name_region_get(value v_name)
{
        CAMLparam1(v_name);
        CAMLlocal1(v_r);
        double lon, lat;
        elm_map_name_region_get((Elm_Map_Name*) v_name, &lon, &lat);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(lon));
        Store_field(v_r, 1, copy_double(lat));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_track_add(value v_obj, value v_route)
{
        Evas_Object* r = elm_map_track_add(Evas_Object_val(v_obj),
                (Elm_Map_Route*) v_route);
        if(r == NULL) caml_failwith("elm_map_track_add");
        return (value) r;
}

