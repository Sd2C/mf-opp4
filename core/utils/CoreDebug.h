/* -*- mode:c++ -*- ********************************************************
 * file:        CoreDebug.h
 *
 * author:      Andreas Koepke
 *
 * copyright:   (C) 2006 Telecommunication Networks Group (TKN) at
 *              Technische Universitaet Berlin, Germany.
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 *              For further information see file COPYING
 *              in the top level directory
 ***************************************************************************
 * part of:     framework implementation developed by tkn
 **************************************************************************/


#ifndef CORE_DEBUG_H
#define CORE_DEBUG_H

#include <omnetpp.h>

#ifndef coreEV
#define coreEV_clear (ev.isDisabled()||!coreDebug) ? ev : ev
#define coreEV (ev.isDisabled()||!coreDebug) ? ev : ev << logName() << "::" << getClassName() <<": "
#endif




#endif


