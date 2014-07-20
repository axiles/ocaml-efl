%{
  open Expr
%}

%token SECTION STRUCT MODULE LB RB SC STAR EOF
%token<string> IDENT

%type<field> field
%type<field list> field_list
%type<(string * bool)> c_type
%type<st> st
%type<st list> st_list
%type<section> section
%type<Expr.t> expr section_list

%start expr

%%

expr: section_list EOF { List.rev $1 }

section_list:
| section { [ $1 ] }
| section_list section { $2 :: $1 }

section: SECTION IDENT LB st_list RB {
  {Section.name = $2; sts = List.rev $4}
}

st_list:
| st { [ $1 ] }
| st_list st { $2 :: $1 }

st:
| STRUCT IDENT c_type LB field_list RB {
  let c_name, ptr = $3 in
  {St.ml_name = $2; c_name; modu = false; ptr; fields = List.rev $5}
}
| STRUCT IDENT c_type MODULE LB field_list RB {
  let c_name, ptr = $3 in
  {St.ml_name = $2; c_name; modu = true; ptr; fields = List.rev $6}
}

c_type:
| IDENT { ($1, false) }
| IDENT STAR { ($1, true) }

field_list:
| field { [ $1 ] }
| field_list field { $2 :: $1 }

field: IDENT IDENT SC {
  {Field.name = $1; ty = $2}
}

