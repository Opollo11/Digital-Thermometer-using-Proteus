/*this program is for displaying the temperature on 16*2 lcd display using 8051 microcontroller , LM35 sensor and ADC0804*/
 
#include<reg51.h>
 
sbit rs=P2^7; //Register Select(RS) pin of 16*2 lcd
sbit rw=P2^6; //Read/Write(RW) pin of 16*2 lcd
sbit en=P2^5; //Enable(E) pin of 16*2 lcd
 
sbit rd_adc=P3^0; //Read(RD) pin of ADC0804
sbit wr_adc=P3^1; //Write(WR) pin of ADC0804
sbit intr_adc=P3^2; //Interrupt(INTR) pin of ADC0804
 
void delay(unsigned int)  ; //function for creating delay
void cmdwrt(unsigned char); //function for sending commands to 16*2 lcd display
void datawrt(unsigned char); //function for sending data to 16*2 lcd display
void convert_display(unsigned char); //function for converting ADC value to temperature and display it on 16*2 lcd display
 
void main(void) //main function
{
   unsigned char i;
   unsigned char cmd[]={0x38,0x01,0x06,0x0c,0x82};//16*2 lcd initialization commands
   unsigned char data1[]="Temperature:";
   unsigned char value;
 
   P1=0xFF; //make Port 1 as input port
   P0=0x00; //make Port 0 as output port
 
   for(i=0;i<5;i++) //send commands to 16*2 lcd display one command at a time
   {
      cmdwrt(cmd[i]); //function call to send commands to 16*2 lcd display
  delay(1);
   }
 
   for(i=0;i<12;i++) //send data to 16*2 lcd display one character at a time
   {
      datawrt(data1[i]);  //function call to send data to 16*2 lcd display
  delay(1);
   }
 
   intr_adc=1; //make INTR pin as input
   rd_adc=1;    //set RD pin HIGH
   wr_adc=1; //set WR pin LOW
 
   while(1)    //repeat forever
   {
  wr_adc=0; //send LOW to HIGH pulse on WR pin
  delay(1);
  wr_adc=1;
  while(intr_adc==1); //wait for End of Conversion
  rd_adc=0; //make RD = 0 to read the data from ADC0804
  value=P1; //copy ADC data
  convert_display(value); //function call to convert ADC data into temperature and display it on     16*2 lcd display
  delay(1000);  //interval between every cycles
  rd_adc=1;   //make RD = 1 for the next cycle
   }
 
}
void cmdwrt (unsigned char x)
{ 
   P0=x;  //send the command to Port 0 on which 16*2 lcd is connected
   rs=0;  //make RS = 0 for command
   rw=0;  //make RW = 0 for write operation
   en=1;  //send a HIGH to LOW pulse on Enable(E) pin to start commandwrite operation 
   delay(1);
   en=0;
}
void datawrt (unsigned char y)
{ 
   P0=y; //send the data to Port 0 on which 16*2 lcd is connected
   rs=1; //make RS = 1 for command
   rw=0; //make RW = 0 for write operation
   en=1; //send a HIGH to LOW pulse on Enable(E) pin to start datawrite operation
   delay(1);
   en=0;
}
void convert_display(unsigned char value)
{
  unsigned char x1,x2,x3;
 
  cmdwrt(0xc6);  //command to set the cursor to 6th position of 2nd line on 16*2 lcd
 
  x1=(value/10); //divide the value by 10 and store quotient in variable x1
  x1=x1+(0x30); //convert variable x1 to ascii by adding 0x30
  x2=value%10; //divide the value by 10 and store remainder in variable x2
  x2=x2+(0x30); //convert variable x2 to ascii by adding 0x30
  x3=0xDF; //ascii value of degree(°) symbol
 
  datawrt(x1);  //display temperature on 16*2 lcd display
  datawrt(x2);
  datawrt(x3);
  datawrt('C'); 
}
 
void delay(unsigned int z)
{
  unsigned int p,q;
  for(p=0;p<z;p++)    //repeat for 'z' times
  {
    for(q=0;q<1375;q++);   //repeat for 1375 times
  }
}