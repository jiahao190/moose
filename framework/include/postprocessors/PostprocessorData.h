/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef POSTPROCESSORDATA_H
#define POSTPROCESSORDATA_H

//MOOSE includes
#include "Moose.h" // for PostprocessorValue
#include "FormattedTable.h"

//Forward Declarations
class MooseSystem;

class PostprocessorData
{
public:
  bool empty();
  
  PostprocessorData(MooseSystem & moose_system);

  void init(const std::string & name);

  PostprocessorValue & getPostprocessorValue(const std::string & name);

  void addData(const std::string & name, Real value, Real time);

  void print_table(std::ostream & out);
  void print_table(const std::string & file_name);
  void print_csv(const std::string & file_name);
  void print_ensight(const std::string & file_name);
  void write_exodus(ExodusII_IO * ex_out,
                    const std::string & file_name, Real time);
  void make_gnuplot(const std::string & file_name, const std::string & format);
  
private:
  MooseSystem & _moose_system;
  FormattedTable _output_table;
  std::map<std::string, Real> _values;
};
#endif //POSTPROCESSORDATA_H
