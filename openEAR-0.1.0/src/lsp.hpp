/*F******************************************************************************
 *
 * openSMILE - open Speech and Music Interpretation by Large-space Extraction
 *       the open-source Munich Audio Feature Extraction Toolkit
 * Copyright (C) 2008-2009  Florian Eyben, Martin Woellmer, Bjoern Schuller
 *
 *
 * Institute for Human-Machine Communication
 * Technische Universitaet Muenchen (TUM)
 * D-80333 Munich, Germany
 *
 *
 * If you use openSMILE or any code from openSMILE in your research work,
 * you are kindly asked to acknowledge the use of openSMILE in your publications.
 * See the file CITING.txt for details.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 ******************************************************************************E*/


/*  openSMILE component:

Computes LSP (line spectral pairs) from LPC coefficients

*/


#ifndef __CLSP_HPP
#define __CLSP_HPP


#include <smileCommon.hpp>
#include <vectorProcessor.hpp>

#define COMPONENT_DESCRIPTION_CLSP "Computes LSP (line spectral pairs) from LPC coefficients"
#define COMPONENT_NAME_CLSP "cLsp"

class cLsp : public cVectorProcessor {
  private:

    long lpcIdx, nLpc;

    FLOAT_DMEM cheb_poly_eva(FLOAT_DMEM *coef, FLOAT_DMEM x, int m);
    int lpc_to_lsp (const FLOAT_DMEM *a, int lpcrdr, FLOAT_DMEM *freq, int nb, FLOAT_DMEM delta);

  protected:
    SMILECOMPONENT_STATIC_DECL_PR

    virtual void fetchConfig();
    //virtual int setupNamesForField(int i, const char*name, long nEl);
    virtual int setupNewNames(long nEl);
    //virtual int myFinaliseInstance();

    //virtual int customVecProcess(cVector *vec);
    virtual int processVectorInt(const INT_DMEM *src, INT_DMEM *dst, long Nsrc, long Ndst, int idxi);
    virtual int processVectorFloat(const FLOAT_DMEM *src, FLOAT_DMEM *dst, long Nsrc, long Ndst, int idxi);

  public:
    SMILECOMPONENT_STATIC_DECL
    
    cLsp(const char *_name);

    virtual ~cLsp();
};


#endif // __CLSP_HPP
