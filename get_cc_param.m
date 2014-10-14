
prompt = {'Enter the 3 phase Control current frequencies:','Enter the 3 phase Control current amplitudes:','Enter the 3 phase Control current phases:','Enter the 3 phase Control current DC components:'};
dlg_title = 'Control current parameters';
num_lines = 1;
defAns = {'20 30 40','0 0 0','0 2/3*pi 4/3*pi','0 0 0'};
options = 'off';
answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);

% Error handling
for i=1:4
    if(max(size(str2num(answer{i})))~=3)
        errordlg('The control Current elements must consist of three scalars separated by space!')
    end
end

Control_Current_frequency = str2num(answer{1});       %[Hz]
Control_Current_Amplitude = str2num(answer{2});       %[A]
Control_Current_Phase = str2num(answer{3});   %[rad]
Control_Current_DC = str2num(answer{4});        %[A]


% Control_Current_frequency=[20,     30,     40];       %[Hz]
% Control_Current_Amplitude=[0,     0,     0];       %[A]
% Control_Current_Phase=    [0,      2/3*pi, 4/3*pi];   %[rad]
% Control_Current_DC=       [0,      0,      0];        %[A]


