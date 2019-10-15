function varargout = Final_Project_GUI(varargin)
% FINAL_PROJECT_GUI MATLAB code for Final_Project_GUI.fig
%      FINAL_PROJECT_GUI, by itself, creates a new FINAL_PROJECT_GUI or raises the existing
%      singleton*.
%
%      H = FINAL_PROJECT_GUI returns the handle to a new FINAL_PROJECT_GUI or the handle to
%      the existing singleton*.
%
%      FINAL_PROJECT_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in FINAL_PROJECT_GUI.M with the given input arguments.
%
%      FINAL_PROJECT_GUI('Property','Value',...) creates a new FINAL_PROJECT_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Final_Project_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Final_Project_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
%
%See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Final_Project_GUI

% Last Modified by GUIDE v2.5 17-Feb-2017 13:20:19

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Final_Project_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @Final_Project_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Final_Project_GUI is made visible.
function Final_Project_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Final_Project_GUI (see VARARGIN)

% Choose default command line output for Final_Project_GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Final_Project_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);

handles.modelname='Final_Project';
handles.SetpointEdit.String = get_param('Final_Project/Sollwert','Value');


% --- Outputs from this function are returned to the command line.
function varargout = Final_Project_GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in StopButton.
function StopButton_Callback(hObject, eventdata, handles)
% hObject    handle to StopButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.modelname='Final_Project';
flag=get(hObject,'string');
if strcmp(flag,'RUN')==1
% never start control when starting simulation    
set_param('Final_Project/ControlActive','Value',num2str(0));
set(hObject,'string','ON');
set(hObject,'BackgroundColor','g');
%
set_param(handles.modelname,'SimulationCommand','Start');
set(hObject,'string','STOP');
set(hObject,'BackgroundColor','r');
else
set_param(handles.modelname,'SimulationCommand','Stop');
set(hObject,'string','RUN');
set(hObject,'BackgroundColor','g');
end
guidata(hObject,handles);


% --- Executes on button press in ControlButton.
function ControlButton_Callback(hObject, eventdata, handles)
% hObject    handle to ControlButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

flag=get(hObject,'string');
if strcmp(flag,'ON')==1
set_param('Final_Project/ControlActive','Value',num2str(10));
set(hObject,'string','OFF');
set(hObject,'BackgroundColor','r');
else
set_param('Final_Project/ControlActive','Value',num2str(-10));
set(hObject,'string','ON');
set(hObject,'BackgroundColor','g');
end



function SetpointEdit_Callback(hObject, eventdata, handles)
% hObject    handle to SetpointEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of SetpointEdit as text
%        str2double(get(hObject,'String')) returns contents of SetpointEdit as a double

set_param('Final_Project/Sollwert','Value',(handles.SetpointEdit.String));
% --- Executes during object creation, after setting all properties.
