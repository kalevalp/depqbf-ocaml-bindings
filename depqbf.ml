(* File depqbf.ml -- declaration of primitives and data types *)
type solver                   (* The type "solver" remains abstract *)

external qdpll_create: unit -> solver = "caml_qdpll_create"
external qdpll_delete: solver -> unit = "caml_qdpll_delete"
external qdpll_configure: solver -> string -> unit = "caml_qdpll_configure"
external qdpll_new_forall_scope_at_nesting: solver -> int -> unit = "caml_qdpll_new_forall_scope_at_nesting"
external qdpll_new_exists_scope_at_nesting: solver -> int -> unit = "caml_qdpll_new_exists_scope_at_nesting"
external qdpll_add: solver -> int -> unit = "caml_qdpll_add"
external qdpll_print: solver -> unit = "caml_qdpll_print"
external qdpll_sat: solver -> int = "caml_qdpll_sat"
