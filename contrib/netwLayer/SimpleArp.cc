/* -*- mode:c++ -*- ********************************************************
 * file:        SimpleArp.cc
 *
 * author:      Daniel Willkomm
 *
 * copyright:   (C) 2005 Telecommunication Networks Group (TKN) at
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
 ***************************************************************************/

#include "SimpleArp.h"

Define_Module(SimpleArp);

int SimpleArp::getMacAddr(const int netwAddr)
{
    if(debug) {
        Enter_Method("getMacAddr(%d)",netwAddr);
    } else {
        Enter_Method_Silent();
    }
    EV << "for host[" << simulation.getModule( netwAddr )->getParentModule()->getIndex()
       << "]: netwAddr " << netwAddr << "; MAC address " 
       << simulation.getModule( netwAddr )->getParentModule()->getSubmodule( "nic" )->getId() <<endl;
    return simulation.getModule(netwAddr)->getParentModule()->getSubmodule("nic")->getId();
}

int SimpleArp::getNetwAddr(const int macAddr)
{
    if(debug) {
        Enter_Method("getNetwAddr(%d)",macAddr);
    } else {
        Enter_Method_Silent();
    }
    EV << "for host[" << simulation.getModule( macAddr )->getParentModule()->getIndex()
       << "]: macAddr " << macAddr << "; netw address " 
       << simulation.getModule( macAddr )->getParentModule()->getSubmodule("nic")->getId() <<endl;
    return simulation.getModule(macAddr)->getParentModule()->getSubmodule("netw")->getId();
}
