#include "include.h"

PREFIX value ml_evas_map_util_points_populate_from_object_full(
        value v_m, value v_obj, value v_z)
{
        evas_map_util_points_populate_from_object_full((Evas_Map*) v_m,
                (Evas_Object*) v_obj, Int_val(v_z));
        return Val_unit;
}
                
PREFIX value ml_evas_map_util_points_populate_from_object(
        value v_m, value v_obj)
{
        evas_map_util_points_populate_from_object((Evas_Map*) v_m,
                (Evas_Object*) v_obj);
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

