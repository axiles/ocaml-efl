#include "include.h"

PREFIX value ml_ecore_evas_engines_get(value v_unit)
{
        Eina_List* list = ecore_evas_engines_get();
        value v = copy_Eina_List_string(list);
        ecore_evas_engines_free(list);
        return v;
}

