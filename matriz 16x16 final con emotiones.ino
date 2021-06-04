#include "LedControl.h"
#include <Keypad.h>
/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
#define NUMBER_OF_BOARDS 4 
const byte rowsCount = 4;
const byte columsCount = 4;
 
LedControl lc=LedControl(12,10,11,NUMBER_OF_BOARDS);


char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { 9, 8, 7, 6 };
const byte columnPins[columsCount] = { 5, 4, 3, 2 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);



 

void setup() {

  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.shutdown(3,false);

  lc.setIntensity(0,5);
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);
  lc.setIntensity(3,5);

  /* clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}

int data[2][4][8] = {

//   
//    {{0,0,56,68,68,68,56,0}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
//    {{112,136,132,66,99,132,136,112}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
// {{0,1,2,4,4,4,100,255}, {255,100,4,4,4,2,1,0}, {0,0,0,0,15,16,32,192}, {192,32,16,15,0,0,0,0}},
//  {{12,10,9,8,8,24,99,128}, {128,99,24,8,8,9,10,12}, {3,13,49,194,2,4,132,8}, {8,132,4,2,194,49,13,3}},
//  {{12,10,9,8,8,24,99,128}, {128,99,24,8,8,9,10,12}, {3,13,49,194,2,4,132,8}, {8,132,4,2,194,49,13,3}}
  {{0,1,2,4,4,4,100,255}, {255,100,4,4,4,2,1,0}, {0,0,0,224,16,8,4,3}, {3,4,8,16,224,0,0,0}},
{{0,1,2,4,4,4,100,255}, {255,100,4,4,4,2,1,0}, {0,0,0,224,16,8,4,3}, {3,4,8,16,224,0,0,0}}

};


int data1[2][4][8] = {
//    {{0,0,56,68,68,68,56,0}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
//    {{112,136,132,66,99,132,136,112}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
{{1,14,16,39,79,204,132,128}, {128,135,207,76,36,16,14,1}, {127,128,128,64,129,129,64,128}, {128,64,129,129,64,128,128,127}},
{{1,14,16,39,79,207,135,128}, {128,135,207,79,39,16,14,1}, {255,128,64,128,65,129,64,128}, {128,64,129,65,128,64,128,255}},


};

int data2[2][4][8] = {
//    {{0,0,56,68,68,68,56,0}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
//    {{112,136,132,66,99,132,136,112}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
{{12,10,9,8,8,24,96,128}, {128,96,24,8,8,9,10,12}, {192,176,140,67,64,32,32,16}, {16,32,32,64,67,140,176,192}},
{{12,10,9,8,8,24,96,128}, {128,96,24,8,8,9,10,12}, {192,176,140,67,64,32,32,16}, {16,32,32,64,67,140,176,192}}


};

int data3[2][4][8] = {
//    {{0,0,56,68,68,68,56,0}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
//    {{112,136,132,66,99,132,136,112}, {66,64,64,32,16,8,0,0}, {0,0,4,8,16,33,66,66}, {0,56,68,68,68,56,1,2}},
{{0,0,0,1,35,23,14,7}, {7,14,23,35,1,0,0,0}, {0,2,7,0,31,55,38,39}, {39,38,55,31,0,7,2,0}},
{{0,0,0,1,3,6,62,7}, {7,62,6,3,1,0,0,0}, {0,2,7,0,31,38,62,39}, {39,62,38,31,0,7,2,0}}


};



void loop() { 

   char key = keypad.getKey();

 switch (key)        //Switch-case de acuerdo a la tecla presionada
  {
    case 'A':                      //La tecla A es la espaciadora. Aumenta en +1 la posicion del cursor
    
int i,j;
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data[0][i][j]);
  }
  delay(500);
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data[1][i][j]);
  }
  delay(500);

      break;
/////////////////////////////////////////

    case 'B': 

 // int i,j;
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data1[0][i][j]);
  }
  delay(500);
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data1[1][i][j]);
  }
  delay(500);
  break;

/////////////////////////////////////////

    case 'C': 

 // int i,j;
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data2[0][i][j]);
  }
  delay(500);
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data2[1][i][j]);
  }
  delay(500);
  break;

/////////////////////////////////////////

    case 'D': 

 // int i,j;
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data3[0][i][j]);
  }
  delay(500);
  for(i=0;i<NUMBER_OF_BOARDS;i++)
  {
      for(j=0;j<8;j++)
        lc.setRow(i,j,data3[1][i][j]);
  }
  delay(500);
  break;
  
   }

////////////////////////////////////////



  
}
