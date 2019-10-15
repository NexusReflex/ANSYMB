/***************************************************************************
                          serial_windows.cpp  -  description
                             -------------------
    begin                :
    copyright            : (C) 2003 Max Planck Institute for Dynamics
                                    of Complex Dynamical Systems
    Author               :  Nils-Otto Negård
                            Thomas Schauer

    email                : negaard@mpi-magdburg.mpg.de
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "serial_windows.h"


serial_windows::serial_windows()
{
}

serial_windows::~serial_windows()
{
}
/*-------------------------------------------------------------------------
  openserial()
  Opens COM1 and returns a handle 
  ------------------------------------------------------------------------- */

int serial_windows::serial_openport(char *Portname)
{

	DWORD dwError;

  this->hCom = CreateFile(Portname,
                    GENERIC_READ | GENERIC_WRITE,
                    0,    /* comm devices must be opened w/exclusive-access */
                    NULL, /* no security attrs */
                    OPEN_EXISTING, /* comm devices must use OPEN_EXISTING */
                    0,    /* if 1 overlapped I/O, ie asynchronous */
                    NULL  /* hTemplate must be NULL for comm devices */
                    );

  if (this->hCom == INVALID_HANDLE_VALUE) {
    /* handle error */
    dwError = GetLastError();
 //   printerrorvalue("Error! Invalid Handle while opening COM1: ",dwError);
	return 1;
  }
  return 0;

}


/*-------------------------------------------------------------------------
  setupserial()
  Set the input and output buffer size.
  Set the COM port for use with the stimulator.
  Fill in a DCB structure with the current configuration. 
  The DCB structure is then modified and used to reconfigure the device.
  Set the time-out parameters.
  ------------------------------------------------------------------------- */
int serial_windows::serial_setupport(long Baud_Rate, unsigned char HandShake, unsigned char TwoStopBits)    // handle to serial port
              
{
  DCB dcb;
  DWORD dwError;
  BOOL fSuccess;
  COMMTIMEOUTS ct;
  DWORD InQueue=100;  // size of the input buffer (in bytes)
  DWORD OutQueue=100;  // size of the output buffer (in bytes)
    

  /* set up the input / output buffers */
  fSuccess = SetupComm(this->hCom, InQueue, OutQueue);
  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
//    printerrorvalue("Error setup COM: ", dwError);
   printf("Error setup COM: ", dwError);
 
	return !fSuccess;
  }

   /* Get the current configuration. */
  fSuccess = GetCommState(this->hCom, &dcb);
  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
 //  printerrorvalue("Error getting COM state: ", dwError);
	   printf("Error getting COM state: ", dwError);
	return !fSuccess;
  }

  /* Fill in the DCB: baud=9600, 8 data bits, no parity, 1 stop bit. */
    switch (Baud_Rate)
      {
      case 115200:
      default:
	dcb.BaudRate = 115200;           // current baud rate 
	break;
      case 19200:
	dcb.BaudRate = 19200;           // current baud rate 
	break;
      case 9600:
	dcb.BaudRate = 9600;           // current baud rate 
	break;
      }  //end of switch baud_rate

  dcb.fBinary = FALSE;           // binary mode, no EOF check   
  dcb.fParity = FALSE;           // enable parity checking 
  
  dcb.fOutxCtsFlow = FALSE;      // CTS output flow control off	
  dcb.fOutxDsrFlow = FALSE;      // DSR output flow control     
  dcb.fDtrControl = DTR_CONTROL_DISABLE; // DTR flow control type       
  dcb.fDsrSensitivity = FALSE;   // DSR sensitivity             
  dcb.fTXContinueOnXoff = FALSE; // XOFF continues Tx           
  dcb.fOutX = FALSE;             // XON/XOFF out flow control       
  dcb.fInX = FALSE;              // XON/XOFF in flow control        
  if (HandShake==1)
    dcb.fRtsControl = RTS_CONTROL_HANDSHAKE; // RTS flow control
  else
  	dcb.fRtsControl = RTS_CONTROL_DISABLE; // RTS flow control
     
  dcb.ByteSize = 8;              // number of bits/byte, 4-8        
  dcb.Parity = NOPARITY;         // 0-4=no,odd,even,mark,space    
  if (TwoStopBits==1)
  	dcb.StopBits = TWOSTOPBITS;     // 0,1,2 = 1, 1.5, 2
  else	
  	dcb.StopBits = ONESTOPBIT;     // 0,1,2 = 1, 1.5, 2
	  
  /* Set the new DCB configuration */
  fSuccess = SetCommState(this->hCom, &dcb);
  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
//    printerrorvalue("Error setting COM state: ", dwError);
      printf("Error setting COM state: ", dwError);
	return !fSuccess;
  }

  /* Get the current time-outs. */
  fSuccess = GetCommTimeouts(this->hCom, &ct);
  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
  //    printerrorvalue("Error setting COM state: ", dwError);
	    printf("Error setting COM state: ", dwError);
    return !fSuccess;
  }
  /* Fill in the COMMTIMEOUTS: Disable all of them by setting them to 0 */
  ct.ReadIntervalTimeout=MAXDWORD;
  ct.ReadTotalTimeoutMultiplier=10;
  ct.ReadTotalTimeoutConstant=10;
  ct.WriteTotalTimeoutMultiplier=0;
  ct.WriteTotalTimeoutConstant=0;
  fSuccess = SetCommTimeouts(this->hCom, &ct);
  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
  //  printerrorvalue("Error setting COM time-outs: ", dwError);
	  printf("Error setting COM time-outs: ", dwError);
     return !fSuccess;

  }

  return !fSuccess;
}

/*-------------------------------------------------------------------------
  closeserial()
  close the serial port
  ------------------------------------------------------------------------- */
int serial_windows::serial_closeport()
{
  DWORD dwError;
  int fSuccess;

  fSuccess=CloseHandle(this->hCom);
  if (!fSuccess) {
    /* handle error */
    dwError = GetLastError();
//    printerrorvalue("Error closing COM: ", dwError);
	    printf("Error closing COM: ", dwError);
  }
  return !fSuccess;
}

/*-------------------------------------------------------------------------
  sendstring()
  send a string to the serial port 
  ------------------------------------------------------------------------- */
int serial_windows::serial_sendstring(	char *buffer,   //pointer to the string
                DWORD nb        //number of bytes in the string
                )
{
  DWORD  dwBytesWritten, dwError;
  BOOL fSuccess;

  fSuccess =  WriteFile(this->hCom, (LPSTR) buffer, nb, &dwBytesWritten, NULL);

  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
 //   printerrorvalue("Error writing to COM: ", dwError);
	   printf("Error writing to COM: ", dwError);
  }

  return !fSuccess;
}

/*-------------------------------------------------------------------------
  readstring()
  reads a string from the serial port
  ------------------------------------------------------------------------- */
int serial_windows::serial_readstring(
                char *buffer,   //pointer to the string
                DWORD nb        //number of bytes in the string
                )
{
  DWORD  dwBytesRead, dwError;
  BOOL fSuccess;

  fSuccess = ReadFile(this->hCom, (LPVOID ) buffer, nb, &dwBytesRead, NULL);

  if (!fSuccess) {
    /* Handle error */
    dwError = GetLastError();
//    printerrorvalue("Error reading from COM: ", dwError);
	    printf("Error reading from COM: ", dwError);
  }

  return dwBytesRead;
}
