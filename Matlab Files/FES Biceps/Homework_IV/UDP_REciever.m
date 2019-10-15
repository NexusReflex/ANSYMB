%%
%
%  Homework assignment #4
%
%  ANSYMB2, Week2
%  Jan Scheibe
%  Laura Bielenberg
%
% 192.168.1.178  is the remote (Arduino) IP address
% 8888          is the remote (Arduino) UDP port number
% 192.168.1.192   is the local (your computer) IP address
% 4012         is the local (your computer) UDP port number


clear
close all
fclose('all');


%echoudp('on',8888)
UDPComIn = udp('192.168.1.178',8888,'LocalHost', '192.168.1.192', ...
    'LocalPort',4012);

fopen(UDPComIn);
fwrite(UDPComIn,1);
    orientation = fscanf(UDPComIn);
  %disp(cast(orientation,'double'));
echoudp('off')
fclose(UDPComIn);

roll = [dec2bin(orientation(1),8) dec2bin( orientation(2),8)];
pitch = [dec2bin(orientation(3),8) dec2bin( orientation(4),8)];
heading =[dec2bin(orientation(5),8) dec2bin( orientation(6),8)];

roll = cast(typecast(uint16(bin2dec(roll)),'int16'),'double')/10
pitch = cast(typecast(uint16(bin2dec(pitch)),'int16'),'double')/10
heading = cast(typecast(uint16(bin2dec(heading)),'int16'),'double')/10