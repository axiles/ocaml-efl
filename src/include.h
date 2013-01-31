#ifndef INCLUDE_H
#define INCLUDE_H

/* Common headers */

#include <stdio.h>

/* OCaml headers */

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>

/* EFL headers */

#include <Elementary.h>

/* Prefix used on all functions */

#define PREFIX CAMLprim EAPI

/* Local headers */

#include "variants.h"
#include "eina_wrap.h"
#include "evas_wrap.h"
#include "ecore_wrap.h"
#include "edje_wrap.h"
#include "elm_wrap.h"
#include "elm_scroller_wrap.h"

#endif

