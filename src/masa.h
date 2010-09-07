// -*-c++-*-
//
//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// MASA - Manufactured Analytical Solutions Abstraction Library
//
// Copyright (C) 2010 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-
//
// masa.h: public functions designed to be exposed in MASA
//
// $Id: masa.h.in 12823 2010-08-31 11:41:32Z karl $
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#ifndef MASA_H_
#define MASA_H_

/*
 * Library version/build info
 */

#define MASA_MAJOR_VERSION  0
#define MASA_MINOR_VERSION  11
#define MASA_MICRO_VERSION  0

#define MASA_BUILD_USER     "nick"
#define MASA_BUILD_ARCH     "x86_64-unknown-linux-gnu"
#define MASA_BUILD_HOST     "tensor.ices.utexas.edu"
#define MASA_BUILD_DATE     "2010-09-07 18:29"
#define MASA_BUILD_VERSION  "13009"

#define MASA_LIB_VERSION    "0.11"

#define MASA_CXX            "icpc"
#define MASA_CXXFLAGS       "-O0 -fp-model precise"


// This header file contains the public functions designed to be exposed in MASA
// What follows is the masa.h doxygen documentation headers

/*! \file masa.h
\brief MASA header file containing all public C++ API

MASA.h is a header file that contains all the public objects and member functions for the c++ interfaces.

*/

/*! \fn int masa_init(string unique_name, string mms)
\brief Initialize a MASA manufactured solution class
\param unique_name This is a string that provides a unique identity for the initialized manufactured class, e.g. "bob"
\param mms This is the manufactured class to be initialized, e.g. "euler_1d"
*/

#include <string>

namespace MASA
{

  // --------------------------------
  // new masa api function
  // --------------------------------

  int masa_init      (std::string, std::string);
  int masa_select_mms(std::string);
  int masa_curr_mms  (std::string*);
  int masa_list_mms  ();

  // --------------------------------
  // interact with mms variables
  // --------------------------------
  int masa_init_param();
  int masa_set_param(std::string,double);
  int masa_get_param(std::string,double*);

  // --------------------------------
  // source term(s) -- 1D
  // --------------------------------
  int masa_eval_t_source  (double,double*);        // x
  int masa_eval_t_source  (double,double,double*); // x,t
  int masa_eval_u_source  (double,double*);
  int masa_eval_e_source  (double,double*);
  int masa_eval_rho_source(double,double*);
  int masa_eval_rho_u_source(double,double,double*); // 1d sod: x,t

  int masa_eval_t_an      (double,double*);        // x
  int masa_eval_t_an      (double,double,double*); // x,t
  int masa_eval_u_an      (double,double*);
  int masa_eval_p_an      (double,double*);
  int masa_eval_rho_an    (double,double*);

  // --------------------------------
  // source term(s) -- 2D
  // --------------------------------
  int masa_eval_t_source    (double,double,double,double*); //x,y,t
  int masa_eval_u_source    (double,double,double*);
  int masa_eval_v_source    (double,double,double*);
  int masa_eval_w_source    (double,double,double*); // for axisymmetric
  int masa_eval_e_source    (double,double,double*);
  int masa_eval_rho_source  (double,double,double*);

  int masa_eval_t_an        (double,double,double,double*); //x,y,t
  int masa_eval_u_an        (double,double,double*);
  int masa_eval_v_an        (double,double,double*);
  int masa_eval_w_an        (double,double,double*); // for axisymmetric
  int masa_eval_p_an        (double,double,double*);
  int masa_eval_rho_an      (double,double,double*);

  // --------------------------------
  // source term(s) -- 3D
  // --------------------------------
  int masa_eval_t_source  (double,double,double,double,double*); // x,y,z,t
  int masa_eval_u_source  (double,double,double,double*);
  int masa_eval_v_source  (double,double,double,double*);
  int masa_eval_w_source  (double,double,double,double*);
  int masa_eval_e_source  (double,double,double,double*);
  int masa_eval_rho_source(double,double,double,double*);

  int masa_eval_t_an      (double,double,double,double,double*); // x,y,z,t
  int masa_eval_u_an      (double,double,double,double*);
  int masa_eval_v_an      (double,double,double,double*);
  int masa_eval_w_an      (double,double,double,double*);
  int masa_eval_p_an      (double,double,double,double*);
  int masa_eval_rho_an    (double,double,double,double*);

  // --------------------------------
  // gradient of analytical solution
  // --------------------------------
  int masa_eval_1d_grad(int,double,double*);
  int masa_eval_2d_grad(int,double,double,double*);
  int masa_eval_3d_grad(int,double,double,double,double*);

  // --------------------------------
  // internal masa functions user might want to call
  // --------------------------------
  int masa_map (std::string*);
  int masa_map2(std::string, std::string);

  // --------------------------------
  // old masa core functions (to be called by user)
  // --------------------------------
  int masa_getid(void**,std::string);
  int masa_printid();
  int masa_display_param();
  int masa_get_name(std::string*);
  int masa_get_dimension(int*);
  int masa_sanity_check();

  // --------------------
  // Versioning routines
  // --------------------

  int masa_version_stdout();
  int masa_get_numeric_version();
  
} //end MASA namespace

#endif
