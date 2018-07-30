open Depqbf;;
let solver = qdpll_create() in

    qdpll_print solver;

    qdpll_configure solver "--dep-man=simple";
    qdpll_configure solver "--incremental-use";
    
    qdpll_print solver;
    
    qdpll_new_forall_scope_at_nesting solver 1;
    qdpll_add solver 1;
    qdpll_add solver 0;
    
    qdpll_print solver;
    
    qdpll_new_exists_scope_at_nesting solver 2;
    qdpll_add solver 2;
    qdpll_add solver 0;
    
    qdpll_print solver;

    qdpll_add solver 1;
    qdpll_add solver (-2);
    qdpll_add solver 0;
    
    qdpll_print solver;

    qdpll_add solver (-1);
    qdpll_add solver 2;
    qdpll_add solver 0;
    
    qdpll_print solver;
    
    let res = qdpll_sat(solver) in
    print_int res;
    
    qdpll_delete(solver)
      
(* let main_window = initscr () in
 * let small_window = newwin 10 5 20 10 in
 *   mvwaddstr main_window 10 2 "Hello";
 *   mvwaddstr small_window 4 3 "world";
 *   refresh();
 *   Unix.sleep 5;
 *   endwin() *)
(* external qdpll_create: unit -> solver = "caml_qdpll_create"
 * external qdpll_delete: solver -> unit = "caml_qdpll_delete"
 * external qdpll_configure: solver -> string -> unit = "caml_qdpll_configure"
 * external qdpll_new_forall_scope_at_nesting: solver -> int -> unit = "caml_qdpll_new_forall_scope_at_nesting"
 * external qdpll_new_exists_scope_at_nesting: solver -> int -> unit = "caml_qdpll_new_exists_scope_at_nesting"
 * external qdpll_add: solver -> int -> unit = "caml_qdpll_add"
 * external qdpll_print: unit -> unit = "caml_qdpll_print"
 * external qdpll_sat: solver -> unit = "caml_qdpll_sat" *)
