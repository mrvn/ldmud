#ifndef PROLANG_H__
#define PROLANG_H__ 1

#include "driver.h"
#include "typedefs.h"

#include "exec.h"  /* fulltype_t, vartype_t */

/* --- Variables --- */
extern int yychar;
extern int32 current_id_number;
extern int approved_object;
extern int num_virtual_variables;
extern short hook_type_map[];
extern string_t *inherit_file;
extern int num_parse_error;
extern program_t *compiled_prog;

#ifndef INITIALIZATION_BY___INIT
extern svalue_t *prog_variable_values;
#endif

/* --- Prototypes --- */
extern int proxy_efun(int, int);
extern void yyerrorf VARPROT((const char *format, ...), printf, 1, 2);
extern void yyerror(const char *str);
extern void yywarnf VARPROT((const char *format, ...), printf, 1, 2);
extern void yywarn(const char *str);
extern void free_all_local_names(void);
extern void store_line_number_info(void);
extern void store_line_number_backward(int offset);
extern void store_include_info(char *name);
extern void store_include_end(void);
extern void compile_file(void);

#if defined( DEBUG ) && defined ( TRACE_CODE )
extern void set_code_window(void);
extern void show_code_window(void);
#endif

#ifdef MALLOC_smalloc
extern void count_compiler_refs(void);
#endif

#endif /* PROLANG_H__ */
