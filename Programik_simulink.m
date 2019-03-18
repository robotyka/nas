drukarka = serial('/dev/ttyUSB0')
drukarka.BaudRate = 57600;
drukarka.Terminator = 'CR/LF';
fopen(drukarka)
