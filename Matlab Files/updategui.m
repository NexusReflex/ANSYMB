function varargout = updategui(varargin)

%create a run time object that can return the value of the gain block's

%output and then put the value in a string.  

rto = get_param('Final_Project/Angle','RuntimeObject');
curAngle = (rto.OutputPort(1).Data(1));

%get a handle to the GUI's 'current state' window
statestxt = findobj('Tag','curAngle');

%update the gui
set(statestxt,'Title',curAngle);

rto = get_param('Final_Project/Vorsteuerung','RuntimeObject');
curPulse = (rto.OutputPort(1).Data(1));

%get a handle to the GUI's 'current state' window
statestxt = findobj('Tag','curPulse');

%update the gui
set(statestxt,'Title',curPulse);

end

