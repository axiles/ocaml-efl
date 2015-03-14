open Common

let t = simple_ty ~ptr:true "Ecore" "Animator"
let pos_map = Ecore.pos_map
let source = simple_ty "Ecore_Animator" "Source"

let funs = [
  prop ~args:[] "frametime" double;
  simple "pos_map" [double; pos_map; double; double] double;
  prop ~args:[] "source" source;
  simple_unit "custom_tick" [];
  simple_unit "freeze" [t];
  simple_unit "thaw" [t];
]

