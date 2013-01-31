#ifndef EINA_H
#define EINA_H

#include "include.h"

PREFIX inline Eina_Bool Eina_Bool_val(value v);
PREFIX inline value Val_Eina_Bool(Eina_Bool b);

PREFIX inline value copy_Eina_List_string(Eina_List* list);

PREFIX inline value copy_Eina_List_Evas_Object(Eina_List* list);

PREFIX inline value copy_Eina_List_Elm_Object_Item(const Eina_List* list);

#endif
