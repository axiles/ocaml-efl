open Printf

external get_hash_value : string -> string = "ml_get_hash_value"

let f x y = printf "#define %s %s\n" x (get_hash_value y)

let g x = f (sprintf "Val_%s" x) x

let () =
  g "abort";
  g "accelerate";
  g "all";
  g "allcharacter";
  g "alpha";
  g "alphabet";
  g "always";
  g "auto";
  g "automatic";
  g "basic";
  g "block_horizontal";
  g "block_vertical";
  g "block_vertical_horizontal";
  g "both";
  g "bottom";
  g "bottom_left";
  g "bottom_right";
  g "center";
  g "char";
  g "close";
  g "combo";
  g "compress";
  g "config";
  g "content";
  g "cube";
  g "cube_down";
  g "cube_left";
  g "cube_right";
  g "cube_up";
  g "datetime";
  g "decelerate";
  g "default";
  g "desktop";
  g "dialog_basic";
  g "display_only";
  g "dnd";
  g "dock";
  f "Val_done" "_done";
  g "down";
  g "dropdown_menu";
  g "email";
  f "Val_end" "_end";
  g "expand";
  g "fdo";
  g "fdo_theme";
  g "file";
  g "first";
  g "flip_horizontal";
  g "flip_transpose";
  g "flip_transverse";
  g "flip_vertical";
  g "focus_back";
  g "focus_forward";
  g "focus_home";
  g "go";
  g "grid";
  g "group";
  g "hard";
  g "hex";
  g "hidden_always";
  g "hide";
  g "horizontal";
  g "host";
  f "Val_in" "_in";
  g "inlined_image";
  g "invalid";
  g "ip";
  g "j2me";
  g "join";
  g "keypad";
  g "last";
  g "last_window_closed";
  g "left";
  g "limit";
  g "linear";
  g "list";
  g "login";
  g "markup";
  g "markup_utf8";
  g "menu";
  g "middle";
  g "mixed";
  g "momentum";
  g "month";
  g "move";
  g "n_double_taps";
  g "n_flicks";
  g "n_lines";
  g "n_long_taps";
  g "n_taps";
  g "n_triple_taps";
  g "neither";
  g "never";
  g "next";
  g "no_block";
  g "no_image";
  g "none";
  g "normal";
  g "notification";
  g "number";
  g "numberonly";
  g "numeric";
  g "off";
  g "on";
  g "opacity_unknown";
  g "opaque";
  g "orient_none";
  g "page";
  g "page_down";
  g "page_left";
  g "page_right";
  g "page_up";
  g "password";
  g "phone_number";
  g "phonenumber";
  g "pin";
  g "plain_utf8";
  g "plaintext";
  g "popup_menu";
  g "previous";
  g "right";
  g "rotate";
  g "rotate_180";
  g "rotate_270";
  g "rotate_90";
  g "rotate_xz_center_axis";
  g "rotate_x_center_axis";
  g "rotate_yz_center_axis";
  g "rotate_y_center_axis";
  g "scale";
  g "scroll";
  g "search";
  g "send";
  g "sentence";
  g "show";
  g "signin";
  g "sinusoidal";
  g "socket_image";
  g "soft";
  g "splash";
  g "standard";
  g "start";
  g "state";
  g "stretch";
  g "terminal";
  g "text";
  g "theme";
  g "theme_fdo";
  g "tile";
  g "toolbar";
  g "tooltip";
  g "top";
  g "top_left";
  g "top_right";
  g "translucent";
  g "transparent";
  g "tree";
  g "undefined";
  g "unknown";
  g "up";
  g "url";
  g "utility";
  g "vertical";
  g "windows_del";
  g "word";
  g "x";
  g "y";
  g "zoom";
  flush stdout
