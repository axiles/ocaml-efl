#include "include.h"

PREFIX value ml_elm_ctxpopup_add(value v_parent)
{
        Evas_Object* ctxpopup = elm_ctxpopup_add((Evas_Object*) v_parent);
        if(ctxpopup == NULL) caml_failwith("elm_ctxpopup_add");
        return (value) ctxpopup;
}

