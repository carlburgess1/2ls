#include "template_generator_acdl.h"
#include <cstdlib>

#define SHOW_TEMPLATE
#define SHOW_TEMPLATE_VARIABLES

/*******************************************************************\

Function: template_generator_acdlt::operator()

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void template_generator_acdlt::operator()(const local_SSAt &SSA, const symbol_exprt &var)
{
  add_var(var,true_exprt(),true_exprt(),domaint::OUT,var_specs);
  
  instantiate_standard_domains(SSA);

#ifdef SHOW_TEMPLATE_VARIABLES
  debug() << "Template variables: " << eom;
  domaint::output_var_specs(debug(),var_specs,SSA.ns); debug() << eom;
#endif  
#ifdef SHOW_TEMPLATE
  debug() << "Template: " << eom;
  domain_ptr->output_domain(debug(), SSA.ns); debug() << eom;
#endif
}

/*******************************************************************\

Function: template_generator_acdlt::operator()

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void template_generator_acdlt::operator()(const local_SSAt &SSA,
					  const std::set<symbol_exprt> &vars)
{
  for(std::set<symbol_exprt>::const_iterator it = vars.begin();
      it != vars.end(); ++it)
    add_var(*it,true_exprt(),true_exprt(),domaint::OUT,var_specs);
  
  instantiate_standard_domains(SSA);

#ifdef SHOW_TEMPLATE_VARIABLES
  debug() << "Template variables: " << eom;
  domaint::output_var_specs(debug(),var_specs,SSA.ns); debug() << eom;
#endif  
#ifdef SHOW_TEMPLATE
  debug() << "Template: " << eom;
  domain_ptr->output_domain(debug(), SSA.ns); debug() << eom;
#endif
}


/*******************************************************************\

Function: template_generator_acdlt::positive_template()

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void template_generator_acdlt::positive_template(std::vector<exprt> &templates)
{
  domain_ptr->positive_template(templates);
}
