//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "SodiumProperties.h"

registerMooseObject("FluidPropertiesApp", SodiumProperties);

template <>
InputParameters
validParams<SodiumProperties>()
{
  InputParameters params = validParams<FluidProperties>();
  params.addClassDescription("Fluid properties for sodium");
  return params;
}

SodiumProperties::SodiumProperties(const InputParameters & parameters) : FluidProperties(parameters)
{
}
