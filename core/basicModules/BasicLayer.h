/* -*- mode:c++ -*- ********************************************************
 * file:        BasicLayer.h
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
 * description: basic MAC layer class
 *              subclass to create your own MAC layer
 **************************************************************************/


#ifndef BASIC_LAYER_H
#define BASIC_LAYER_H

#include <omnetpp.h>
#include "BasicModule.h"

/**
 * @brief A very simple layer template
 *
 * This module provides basic abstractions that ease development of a
 * network or MAC layer.
 *
 * @ingroup basicModules
 * @author Andreas Koepke
 */
class BasicLayer : public BasicModule
{
 protected:

    /** @brief gate id*/
    /*@{*/
    int uppergateIn;
    int uppergateOut;
    int lowergateIn;
    int lowergateOut;
    int upperControlOut;
    int lowerControlIn;

    /*@}*/  

public:


    /** @brief Initialization of the module and some variables*/
    virtual void initialize(int);
  
    /** @brief Called every time a message arrives*/
    virtual void handleMessage( cMessage* );

protected:
    /** 
     * @name Handle Messages
     * @brief Functions to be redefined by the programmer
     *
     * These are the functions provided to add own functionality to
     * your modules. These functions are called whenever a blackboard
     * message, a self message or a data message from the upper or
     * lower layer arrives respectively.
     *
     **/
    /*@{ */

    /** @brief Handle self messages such as timer... */
    virtual void handleSelfMsg(cMessage* msg) = 0;
    
    /** @brief Handle messages from upper layer
     *
     * This function is pure virtual here, because there is no
     * reasonable guess what to do with it by default.
     */
    virtual void handleUpperMsg(cMessage *msg) = 0;
    
    
    /** @brief Handle messages from lower layer */
    virtual void handleLowerMsg(cMessage *msg) = 0;

    /** @brief Handle control messages from lower layer */
    virtual void handleLowerControl(cMessage *msg) = 0;

    /*@}*/
  

    /** 
     * @name Convenience Functions
     * @brief Functions for convenience - NOT to be modified
     *
     * These are functions taking care of message encapsulation and
     * message sending. Normally you should not need to alter these.
     *
     * All these functions assume that YOU do all the necessary handling
     * of control information etc. before you use them. 
     **/
    /*@{*/
    
    /** @brief Sends a message to the lower layer
     *
     * Short hand for send(msg, lowergateOut);
     *
     * You have to take care of encapsulation We recommend that you
     * use a pair of functions called encapsMsg/decapsMsg.
     */
    void sendDown(cMessage *msg);
    
    /** @brief Sends a message to the upper layer
     *
     * Short hand for send(msg, uppergateOut);
     * You have to take care of decapsulation and deletion of
     * superflous frames. We recommend that you use a pair of
     * functions decapsMsg/encapsMsg.
     */
    void sendUp(cMessage *msg);
    
    /** @brief Sends a control message to an upper layer */
    void sendControlUp(cMessage *msg);
    
    /*@}*/
};

#endif
