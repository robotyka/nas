%tablica wartosci z karty katalogowej

temptable = [...
     1, 713;
    17, 300; 
    20, 290;
    23, 280;
    27, 270;
    31, 260;
    37, 250;
    43, 240;
    51, 230;
    61, 220;
    73, 210;
    87, 200;
   106, 190;
   128, 180;
   155, 170;
   189, 160;
   230, 150;
   278, 140;
   336, 130;
   402, 120;
   476, 110;
   554, 100;
   635,  90;
   713,  80;
   784,  70;
   846,  60;
   897,  50;
   937,  40;
   966,  30;
   986,  20;
  1000,  10;
  1010,   0];


% wykreślenie krzywej
plot(temptable(:,1),temptable(:,2))
grid on
xlabel('bity')
ylabel('temperatura')


% wyznaczenie 4 punktow, potrzebnych do wyliczenia a,b,c,d
x1 = temptable(12,1);
y1 = temptable(12,2);

x2 = temptable(18,1);
y2 = temptable(18,2);

x3 = temptable(24,1);
y3 = temptable(24,2);

x4 = temptable(30,1);
y4 = temptable(30,2);

X = [ x1^3 x1^2 x1 1;
      x2^3 x2^2 x2 1;
      x3^3 x3^2 x3 1;
      x4^3 x4^2 x4 1
    ];

Y = [ y1;
      y2;
      y3;
      y4
    ];

Z = inv(X)*Y;

% wykreslenie krzywej o znanych a,b,c,d
hold on 
for x = 0:10:1000
   y = Z(1)*x^3 + Z(2)*x^2 + Z(3)*x^1 +Z(4);
   plot(x,y,'*','MarkerSize',10);
end
hold off
