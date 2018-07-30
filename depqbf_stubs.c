/* File depqbf_stubs.c -- stub code for DEPQBF */
#include "/home/kalevalp/bin/depqbf-version-6.03/qdpll.h"
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/custom.h>

/* Encapsulation of opaque solver handles (of type QDPLL *)
   as OCaml custom blocks. */

static struct custom_operations depqbf_solver_ops = {
  "depqbf.solver.operations",
  custom_finalize_default,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default,
  custom_compare_ext_default
};

/* Accessing the solver (QDPLL *) part of an OCaml custom block */
#define Solver_val(v) (*((QDPLL **) Data_custom_val(v)))

/* Allocating an OCaml custom block to hold the given solver (QDPLL *) */
static value alloc_solver(QDPLL * s)
{
  value v = alloc_custom(&depqbf_solver_ops, sizeof(QDPLL *), 0, 1);
  Solver_val(v) = s;
  return v;
}

value caml_qdpll_create(value unit)
{
  CAMLparam1 (unit);
  CAMLreturn (alloc_solver(qdpll_create()));
}

value caml_qdpll_delete(value solver)
{
  CAMLparam1 (solver);
  qdpll_delete (Solver_val(solver));
  CAMLreturn (Val_unit);
}

value caml_qdpll_configure(value solver, value s)
{
  CAMLparam2 (solver, s);
  qdpll_configure (Solver_val(solver), String_val(s));
  CAMLreturn (Val_unit);
}
value caml_qdpll_new_forall_scope_at_nesting(value solver, value i)
{
  CAMLparam2 (solver, i);
  qdpll_new_scope_at_nesting (Solver_val(solver),
			      QDPLL_QTYPE_FORALL,
			      Int_val(i));
  CAMLreturn (Val_unit);
}
value caml_qdpll_new_exists_scope_at_nesting(value solver, value i)
{
  CAMLparam2 (solver, i);
  qdpll_new_scope_at_nesting (Solver_val(solver),
			      QDPLL_QTYPE_EXISTS,
			      Int_val(i));
  CAMLreturn (Val_unit);
}
value caml_qdpll_add(value solver, value i)
{
  
  CAMLparam2 (solver, i);
  qdpll_add (Solver_val(solver),Int_val(i));
  CAMLreturn (Val_unit);

}
value caml_qdpll_print(value solver)
{
  CAMLparam1 (solver);
  qdpll_print (Solver_val(solver), stdout);
  CAMLreturn (Val_unit);


}
value caml_qdpll_sat(value solver)
{
  CAMLparam1 (solver);
  CAMLreturn (Val_int(qdpll_sat (Solver_val(solver))));
}

