#include "include.h"

PREFIX value ml_ecore_evas_engines_get(value v_unit)
{
        Eina_List* list = ecore_evas_engines_get();
        value v = copy_Eina_List_string(list);
        ecore_evas_engines_free(list);
        return v;
}

PREFIX value ml_ecore_evas_new_native(
        value v_engine_name, value v_x, value v_y, value v_w, value v_h,
        value v_extra_options, value v_unit)
{
        Ecore_Evas* ee = ecore_evas_new(String_opt_val(v_engine_name),
                Int_opt_val(v_x), Int_opt_val(v_y), Int_val(v_w), Int_val(v_h),
                String_opt_val(v_extra_options));
        if(ee == NULL) caml_failwith("ecore_evas_new");
        return Val_Ecore_Evas(ee);
}

PREFIX value ml_ecore_evas_new_byte(value* argv, int argn)
{
      return ml_ecore_evas_new_native(argv[0], argv[1], argv[2], argv[3],
              argv[4], argv[5], argv[6]);
}

