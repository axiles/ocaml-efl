#include "include.h"

PREFIX value ml_elm_slideshow_add(value v_parent)
{
        Evas_Object* slideshow = elm_slideshow_add((Evas_Object*) v_parent);
        if(slideshow == NULL) caml_failwith("elm_slideshow_add");
        return (value) slideshow;
}

