%% 3#
Fs = 100;
A = V.signals.values(:,1);
B = V.signals.values(:,2);
s = length(A);
samplesize=16;
DispvsInput=zeros(1,s);
Displacement=zeros(samplesize,1);
Input=zeros(samplesize,1);
n=1;
p=1;
j=1;
for i=2:s
    Displacement(j,1)=B(i);
    Input(j,1)=A(i);

    if n==samplesize

        NFFT = 2^nextpow2(samplesize); % Next power of 2 

        %% Create Hanning Window and Buffer the Data
        window=hann(NFFT);

        Displacement_Buffered=buffer(Displacement,NFFT,10);
        Input_Buffered=buffer(Input,NFFT,10);

        Displacement_Buffered=Displacement_Buffered'*diag(window);
        Input_Buffered=Input_Buffered'*diag(window);

        %% Calculate the FFT of the Signals now
        Displacement_FFT=fft(Displacement_Buffered,NFFT)/samplesize;
        Input_FFT=fft(Input_Buffered,NFFT)/samplesize;

        %Calculate the length of the frequency axis to be displayed
        f = Fs/2*linspace(0,1,NFFT/2+1);

        %Take the average
        Displacement_FFT=mean(Displacement_FFT);
        Input_FFT=mean(Input_FFT);

        %Calculate the phase angles
        Displacement_Phase=(angle(Displacement_FFT));
        Input_Phase=(angle(Input_FFT));

        %Identify the largest component
        [Displacement_Max_Value Displacement_Max_Index]=max(abs(Displacement_FFT));
        [Input_Max_Value Input_Max_Index]=max(abs(Input_FFT));

        %Get the Phase angles that correspond to the largest harmonic
        Z_Displacement=Displacement_Phase(Displacement_Max_Index);
        Z_Input=Input_Phase(Input_Max_Index);

        %Calculate the Phase angle differences
        Z_Displacement_Input=Z_Displacement-Z_Input;

        %Consolidate them in a matrix

        DispvsInput(i)=Z_Displacement_Input*180/pi;

        p=p+1;
        j=1;
        n=1;

    
%     else
%         if DispvsInput(i)==0
%           DispvsInput(i,1)=DispvsInput(i-1,1);
%         end
%         DispvsInput(i,1)=DispvsInput(i-1,1);
    end
    
    %Counter
    n=n+1;
    j=j+1;
end

plot(DispvsInput)