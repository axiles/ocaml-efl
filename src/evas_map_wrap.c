#include "include.h"

PREFIX value ml_evas_map_util_points_populate_from_object_full(
        value v_m, value v_obj, value v_z)
{
        evas_map_util_points_populate_from_object_full((Evas_Map*) v_m,
                Evas_Object_val(v_obj), Int_val(v_z));
        return Val_unit;
}
                
PREFIX value ml_evas_map_util_points_populate_from_object(
        value v_m, value v_obj)
{
        evas_map_util_points_populate_from_object((Evas_Map*) v_m,
                Evas_Object_val(v_obj));
        return Val_unit;
}
                
PREFIX value ml_evas_map_util_points_populate_from_geometry_native(
        value v_m, value v_x, value v_y, value v_w, value v_h, value v_z)
{
        evas_map_util_points_populate_from_geometry((Evas_Map*) v_m,
                Int_val(v_x), Int_val(v_y), Int_val(v_w), Int_val(v_h),
                Int_val(v_z));
        return Val_unit;
}

PREFIX value ml_evas_map_util_points_populate_from_geometry_byte(
        value* argv, int argn)
{
        return ml_evas_map_util_points_populate_from_geometry_native(argv[0],
                argv[1], argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_evas_map_util_points_color_set(
        value v_m, value v_r, value v_g, value v_b, value v_a)
{
        evas_map_util_points_color_set((Evas_Map*) v_m, Int_val(v_r),
                Int_val(v_g), Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_evas_map_util_rotate(value v_m, value v_d, value v_x, value v_y)
{
        evas_map_util_rotate((Evas_Map*) v_m, Double_val(v_d), Int_val(v_x),
                Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_map_util_zoom(
        value v_m, value v_zx, value v_zy, value v_x, value v_y)
{
        evas_map_util_zoom((Evas_Map*) v_m, Double_val(v_zx), Double_val(v_zy),
                Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_map_util_3d_rotate_native(
        value v_m, value v_dx, value v_dy, value v_dz, value v_cx, value v_cy,
        value v_cz)
{
        evas_map_util_3d_rotate((Evas_Map*) v_m, Double_val(v_dx),
                Double_val(v_dy), Double_val(v_dz), Int_val(v_cx),
                Int_val(v_cy), Int_val(v_cz));
        return Val_unit;
}

PREFIX value ml_evas_map_util_3d_rotate_byte(value* argv, int argn)
{
        return ml_evas_map_util_3d_rotate_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_evas_map_util_quat_rotate_native(
        value v_m, value v_qx, value v_qy, value v_qz, value v_qw, value v_cx,
        value v_cy, value v_cz)
{
        evas_map_util_quat_rotate((Evas_Map*) v_m, Double_val(v_qx),
                Double_val(v_qy), Double_val(v_qz), Double_val(v_qw),
                Double_val(v_cx), Double_val(v_cy), Double_val(v_cz));
        return Val_unit;
}

PREFIX value ml_evas_map_util_quat_rotate_byte(value* argv, int argn)
{
        return ml_evas_map_util_quat_rotate_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6], argv[7]);
}

PREFIX value ml_evas_map_util_3d_lighting_native(
        value v_m, value v_lx, value v_ly, value v_lz, value v_lr, value v_lg,
        value v_lb, value v_ar, value v_ag, value v_ab)
{
        evas_map_util_3d_lighting((Evas_Map*) v_m, Int_val(v_lx), Int_val(v_ly),
                Int_val(v_lz), Int_val(v_lr), Int_val(v_lg), Int_val(v_lb),
                Int_val(v_ar), Int_val(v_ag), Int_val(v_ab));
        return Val_unit;
}

PREFIX value ml_evas_map_util_3d_lighting_byte(value* argv, int argn)
{
        return ml_evas_map_util_3d_lighting_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}

PREFIX value ml_evas_map_util_3d_perspective(
        value v_m, value v_px, value v_py, value v_z0, value v_foc)
{
        evas_map_util_3d_perspective((Evas_Map*) v_m, Int_val(v_px),
                Int_val(v_py), Int_val(v_z0), Int_val(v_foc));
        return Val_unit;
}

PREFIX value ml_evas_map_util_clockwise_get(value v_m)
{
        return Val_bool(evas_map_util_clockwise_get((Evas_Map*) v_m));
}

PREFIX value ml_evas_map_new(value v_n)
{
        Evas_Map* m = evas_map_new(Int_val(v_n));
        if(m == NULL) caml_failwith("evas_map_new");
        return (value) m;
}

PREFIX value ml_evas_map_smooth_set(value v_m, value v_flag)
{
        evas_map_smooth_set((Evas_Map*) v_m, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_map_smooth_get(value v_m)
{
        return Val_bool(evas_map_smooth_get((Evas_Map*) v_m));
}

PREFIX value ml_evas_map_alpha_set(value v_m, value v_flag)
{
        evas_map_alpha_set((Evas_Map*) v_m, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_map_alpha_get(value v_m)
{
        return Val_bool(evas_map_alpha_get((Evas_Map*) v_m));
}

PREFIX value ml_evas_map_dup(value v_m)
{
        return (value) evas_map_dup((Evas_Map*) v_m);
}

PREFIX value ml_evas_map_free(value v_m)
{
        evas_map_free((Evas_Map*) v_m);
        return Val_unit;
}

PREFIX value ml_evas_map_count_get(value v_m)
{
        return Val_int(evas_map_count_get((Evas_Map*) v_m));
}

PREFIX value ml_evas_map_point_coord_set(
        value v_m, value v_i, value v_x, value v_y, value v_z)
{
        evas_map_point_coord_set((Evas_Map*) v_m, Int_val(v_i), Int_val(v_x),
                Int_val(v_y), Int_val(v_z));
        return Val_unit;
}

PREFIX value ml_evas_map_point_coord_get(value v_m, value v_i)
{
        Evas_Coord x, y, z;
        evas_map_point_coord_get((Evas_Map*) v_m, Int_val(v_i), &x, &y, &z);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(z));
        return v;
}

PREFIX value ml_evas_map_point_image_uv_set(
        value v_m, value v_i, value v_u, value v_v)
{
        evas_map_point_image_uv_set((Evas_Map*) v_m, Int_val(v_i),
                Double_val(v_u), Double_val(v_v));
        return Val_unit;
}

PREFIX value ml_evas_map_point_image_uv_get(value v_m, value v_i)
{
        CAMLparam2(v_m, v_i);
        CAMLlocal1(v_r);
        double u, v;
        evas_map_point_image_uv_get((Evas_Map*) v_m, Int_val(v_i), &u, &v);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(u));
        Store_field(v_r, 1, copy_double(v));
        CAMLreturn(v_r);
}

PREFIX value ml_evas_map_point_color_set_native(
        value v_m, value v_i, value v_r, value v_g, value v_b, value v_a)
{
        evas_map_point_color_set((Evas_Map*) v_m, Int_val(v_i), Int_val(v_r),
                Int_val(v_g), Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_evas_map_point_color_set_byte(value* argv, int argn)
{
        return ml_evas_map_point_color_set_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_evas_map_point_color_get(value v_m, value v_i)
{
        int r, g, b, a;
        evas_map_point_color_get((Evas_Map*) v_m, Int_val(v_i), &r, &g, &b, &a);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        Store_field(v, 3, Val_int(a));
        return v;
}

