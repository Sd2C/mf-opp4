/* -*- mode:c++ -*- ********************************************************
 * file:        ChannelAccess.h
 *
 * author:      Marc Loebbers
 *
 * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
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
 * description: - Base class for physical layers
 *              - if you create your own physical layer, please subclass 
 *                from this class and use the sendToChannel() function!!
 **************************************************************************/


#ifndef CHANNEL_ACCESS_H
#define CHANNEL_ACCESS_H

#include <omnetpp.h>
#include <vector>

#include "BasicModule.h"
#include "HostMove.h"

class ChannelControl;

/**
 * @brief Basic class for all physical layers, please don't touch!!
 *
 * This class is not supposed to work on its own, but it contains
 * functions and lists that cooperate with ChannelControl to handle
 * the dynamically created gates. This means EVERY SnrEval (the lowest
 * layer in a host) has to be derived from this class!!!! And please
 * follow the instructions on how to declare a physical layer in a
 * .ned file in "The Design of a Mobility Framework in OMNeT++"
 * paper. 
 *
 * Please don't touch this class.
 *
 * @author Marc Loebbers
 * @ingroup channelControl
 * @ingroup phyLayer
 * @ingroup basicModules
 **/
class ChannelAccess : public BasicModule
{

  
protected:
    /** @brief use sendDirect or not?*/
    bool useSendDirect;

    /** @brief Pointer to the ChannelControl module*/
    ChannelControl* cc;

    /** @brief debug this core module? */
    bool coreDebug;

    /** @brief Sends a message to all nics connected to this one. Waits
        delay seconds before sending*/
    void sendToChannel(cMessage *msg, simtime_t delay);

    /** @brief Last move of this host */
    HostMove hostMove;
    /** @brief category number given by bb for RSSI */
    int catHostMove;

    /**
     * @brief Is this module already registered with channelControl?
     */
    bool isRegistered;
    
public:
    /** @brief Register with ChannelControl and subscribe to hostPos*/
    virtual void initialize(int stage);
    
    /**
     * called by Blackboard to inform of changes
     */
    virtual void receiveBBItem(int category, const BBItem *details, int scopeModuleId);
};

#endif
 
