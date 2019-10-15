/***************************************************************************
                          serial_windows.h  -  description
                             -------------------
    begin                :
    copyright            : (C) 2003 Max Planck Institute for Dynamics
                                    of Complex Dynamical Systems
    Author               :  Nils-Otto Negård

    email                : negaard@mpi-magdburg.mpg.de

    Modified by Henrik Gollee <henrik@mech.gla.ac.uk> Nov 2006:
    *    Added more COM port (up to 20)
    *    include <iostream> instead of <iostream.h> for compatibility with
    *    VC++ 2003 (also compatible with BCC, no check with gcc)
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef SERIALWINDOWS_H
#define SERIALWINDOWS_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
static const char* SerialPortList[]={"COM1","COM2","COM3","COM4","COM5","COM6","COM7","COM8","COM9","COM10","COM11","COM12","COM13","COM14","COM15","COM16","COM17","COM18","COM19","COM20",0};
static const  int NrofPortsInTheList=20;
class serial_windows
{
 public:
 serial_windows();
  ~serial_windows();
int serial_openport (char *Portname);
int serial_setupport (long Baud_Rate,unsigned char HandShake, unsigned char TwoStopBits);
int serial_closeport();
int serial_sendstring( char *buffer, DWORD nb);
int serial_readstring(char *buffer, DWORD nb);

 private:
HANDLE hCom;
};
#endif

