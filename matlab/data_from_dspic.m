%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Script para comparar señales procesadas por el dspic
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Levantamos la señal de entrada
entrada = 1:1:192;

fileID = fopen('test_dataout_PILOTO_FIR_19_COEF_03_08_ruido.csv','r');
%fileID = fopen('test_dataout_PILOTO_FIR_30_COEF_2.csv','r');
for i=1:1:size(entrada,2)
    a = fscanf(fileID,'%s,');
    a = fscanf(fileID,'%s,');
    
    a = a(3:6);
    entrada(i) = hex2dec(a);
    
    if ( entrada(i) <= 32767 )
        entrada(i) = (entrada(i))*2^-15;
    else
        entrada(i) = (entrada(i) - 2^16)*2^-15;
    end;
end;
fclose(fileID);

figure(1);
subplot(221);
plot(entrada);
title('Entrada');
subplot(223);
plot(20*log(abs(fft(entrada))));
title('Espectro de la entrada en dB');

% Levantamos la señal procesada

%fileID = fopen('test_dataout_NOTCH_FIR_19_COEF_03_08.csv','r');
fileID = fopen('test_dataout_NOTCH_FIR_19_COEF_03_08_ruido.csv','r');
for i=1:1:size(entrada,2)
    a = fscanf(fileID,'%s,');
    a = fscanf(fileID,'%s,');
    
    a = a(3:6);
    salida(i) = hex2dec(a);
    
    if ( salida(i) <= 32767 )
        salida(i) = (salida(i))*2^-15;
    else
        salida(i) = (salida(i) - 2^16)*2^-15;
    end;
end;
fclose(fileID);

figure(1);
subplot(222);
plot(salida);
title('Salida');
subplot(224);
plot(20*log(abs(fft(salida))));
title('Espectro de la salida en dB');
