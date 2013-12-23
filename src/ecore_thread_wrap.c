#include "include.h"

PREFIX value ml_ecore_thread_main_loop_begin(value v_unit)
{
        return Val_int(ecore_thread_main_loop_begin());
}

PREFIX value ml_ecore_thread_main_loop_end(value v_unit)
{
        return Val_int(ecore_thread_main_loop_end());
}

