type enum = {
  ml_name : string;
  c_name : string;
  prefix_length : int option;
  variants : string list;
}

type section = {
  name : string;
  enums : enum list;
}

type t = section list

