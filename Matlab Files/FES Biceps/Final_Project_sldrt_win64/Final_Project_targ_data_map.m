  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Final_Project_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Final_Project_P.PacketOutput_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Final_Project_P.PacketInput_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Final_Project_P.PacketOutput_YieldWhenWaiting
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Final_Project_P.PacketInput_YieldWhenWaiting
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Final_Project_P.PacketOutput_PacketID
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Final_Project_P.PacketInput_PacketID
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% Final_Project_P.P_Gain
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Final_Project_P.curPulse_Gain
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Final_Project_P.Quantizer_Interval
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Final_Project_P.Saturation_UpperSat
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Final_Project_P.Saturation_LowerSat
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Final_Project_P.Constant1_Value
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Final_Project_P.Umrechnung_Value
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Final_Project_P.Angle_Gain
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Final_Project_P.Sollwert_Value
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Final_Project_P.Filter_A
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Final_Project_P.Filter_C
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Final_Project_P.ControlActive_Value
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Final_Project_P.Integrator_IC
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Final_Project_P.Off_Value
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Final_Project_P.ControlSwitch_Threshold
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Final_Project_P.Current_Value
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Final_Project_P.I_Gain
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Final_Project_P.stimmode_Value
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Final_Project_P.SFunction_P1_Size
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Final_Project_P.SFunction_P1
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 20;
	
	  ;% Final_Project_P.SFunction_P2_Size
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 21;
	
	  ;% Final_Project_P.SFunction_P2
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Final_Project_P.SFunction_P3_Size
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 24;
	
	  ;% Final_Project_P.SFunction_P3
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 26;
	
	  ;% Final_Project_P.SFunction_P4_Size
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 27;
	
	  ;% Final_Project_P.SFunction_P4
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 29;
	
	  ;% Final_Project_P.SFunction_P5_Size
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 30;
	
	  ;% Final_Project_P.SFunction_P5
	  section.data(28).logicalSrcIdx = 35;
	  section.data(28).dtTransOffset = 32;
	
	  ;% Final_Project_P.SFunction_P6_Size
	  section.data(29).logicalSrcIdx = 36;
	  section.data(29).dtTransOffset = 33;
	
	  ;% Final_Project_P.SFunction_P6
	  section.data(30).logicalSrcIdx = 37;
	  section.data(30).dtTransOffset = 35;
	
	  ;% Final_Project_P.SFunction_P7_Size
	  section.data(31).logicalSrcIdx = 38;
	  section.data(31).dtTransOffset = 36;
	
	  ;% Final_Project_P.SFunction_P8_Size
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 38;
	
	  ;% Final_Project_P.Constant_Value
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 40;
	
	  ;% Final_Project_P.SFunction_P1_Size_i
	  section.data(34).logicalSrcIdx = 43;
	  section.data(34).dtTransOffset = 41;
	
	  ;% Final_Project_P.SFunction_P1_f
	  section.data(35).logicalSrcIdx = 44;
	  section.data(35).dtTransOffset = 43;
	
	  ;% Final_Project_P.SFunction_P2_Size_m
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 44;
	
	  ;% Final_Project_P.SFunction_P2_k
	  section.data(37).logicalSrcIdx = 46;
	  section.data(37).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Final_Project_B)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Final_Project_B.DataTypeConversion2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Final_Project_B.Divide
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% Final_Project_B.Sum2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% Final_Project_B.Abs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 13;
	
	  ;% Final_Project_B.Angle
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 14;
	
	  ;% Final_Project_B.ArmAngle
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 15;
	
	  ;% Final_Project_B.Sum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% Final_Project_B.Integrator
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% Final_Project_B.ControlSwitch
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% Final_Project_B.Current
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 19;
	
	  ;% Final_Project_B.I
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% Final_Project_B.stimmode
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 21;
	
	  ;% Final_Project_B.SFunction
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% Final_Project_B.SFunction_e
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% Final_Project_B.Vorsteuerung
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% Final_Project_B.P
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% Final_Project_B.Sum1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% Final_Project_B.curPulse
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
	  ;% Final_Project_B.Quantizer
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 28;
	
	  ;% Final_Project_B.Saturation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Final_Project_B.PacketOutput
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Final_Project_B.PacketInput_o2
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Final_Project_B.PacketInput_o1
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Final_Project_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Final_Project_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Final_Project_DW.SFunction_RWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Final_Project_DW.PacketOutput_PWORK
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Final_Project_DW.PacketInput_PWORK
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4061985548;
  targMap.checksum1 = 2770466373;
  targMap.checksum2 = 1634856377;
  targMap.checksum3 = 302652773;

