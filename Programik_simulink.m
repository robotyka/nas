%{
drukarka = serial('/dev/ttyUSB0')
drukarka.BaudRate = 57600;
drukarka.Terminator = 'CR/LF';
fopen(drukarka)
%}

%%  instrukcje
%{
while (1)
    fprintf(drukarka, 'a -100 b 100 c -100');
    while(drukarka.BytesAvailable == 0)
        end
        while(drukarka.BytesAvailable > 0)
           fscanf(drukarka); 
        end
       
        fprintf(drukarka, 'a 100 b -100 c 100');

        while(drukarka.BytesAvailable == 0)
        end
        while(drukarka.BytesAvailable > 0)
           fscanf(drukarka); 
        end
end
%}
%%
stare_a = 0;
stare_b = 0;
stare_c = 0;
for t = 0:0.1:4*pi
        a=round(100*sin(t));
        b=round(100*sin(t + 2*pi/3));
        c=round(100*sin(t + 4*pi/3));
        nowe_a = a - stare_a;
        nowe_b = b - stare_b;
        nowe_c = c - stare_c;
        fprintf(drukarka, 'a %d b %d c %d\n',[nowe_a,nowe_b,nowe_c]);
        while(drukarka.BytesAvailable == 0)
        end
        while(drukarka.BytesAvailable > 0)
           fscanf(drukarka); 
        end
        stare_a = a;
        stare_b = b;
        stare_c = c;
end
%%
%{
while(1)
    figure('units', 'normalized', 'outerposition', [0 0 1 1])
    spy
    pause(0.1)
    close all
    pause(0.1)
end
%}