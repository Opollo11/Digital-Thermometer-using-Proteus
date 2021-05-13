#include<reg51.h>
#include<intrins.h>
sbit sda=P2^1;
sbit sc1=P2^0;
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit a0=B^0;
sbit a1=B^1;
sbit a2=B^2;
sbit a3=B^3;
sbit a4=B^4;
sbit a5=B^5;
sbit a6=B^6;
sbit a7=B^7;
void start();
void stop();
void check();
void display();
void conversion(unsigned char);
void write(unsigned char);
unsigned char read();
unsigned char num();
void ack();
void disp(unsigned char *);
void enable();
unsigned char v;
void main()
{
unsigned char com[4]={0x38,0x10,0x0e,0x80},s1;
for(s1=0;s1<4;s1++)
{
P3=com[s1];
rs=0;
rw=0;
enable();
}
disp("TEMPRATURE:");
start();
write(0x90);
check();
write(0x00);
check();
start();
write(0x91);
check();
while(1)
{
v=read();
ack();
conversion(v);
}
stop();
}
void start()
{
sc1=1;
sda=1;
_nop_();_nop_();
sda=0;
sc1=0;
}
void write(unsigned char val)
{
unsigned char v1,v2,v3=0x80;
v2=val;
for(v1=0;v1<8;v1++)
{
sda=v2&v3;
sc1=1;
_nop_();_nop_();
sc1=0;
v2=v2<<1;
}
}
void check()
{
bit c;
sc1=1;
c=sda;
for(v=0;v<12;v++);
sc1=0;
if(c==1)
{
stop();
}
}
void stop()
{
sc1=1;
sda=0;
_nop_();_nop_();
sda=1;
sc1=0;
}
void enabe()
{
unsigned int s2;
en=1;
for(s2=0;s2<2000;s2++);
en=0;
}
void disp(unsigned char *s)
{
unsigned char s3;
for(s3=0;s[s3]!='\0';s3++)
{
P3=s[s3];
rs=1;
enable();
}
}
unsigned char read()
{
sda=1;
a7=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a6=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a5=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a4=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a3=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a2=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a1=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
a0=sda;
sc1=1;
_nop_();_nop_();
sc1=0;
v=B;
return v;
}
void ack()
{
sda=0;
sc1=1;
_nop_();_nop_();
sc1=0;
}
void conversion(unsigned char val)
{
unsigned char s4,s5,s6;
s4=val;
s5=s4/10;
s6=s4%10;
s5=s5|0x30;
s6=s6|0x30;
P3=0x8b;
rs=0;
enable();
P3=s5;
rs=1;
enable();
}

unsigned char num()
{
sda=1;
a7=sda;
sc1=1;

sc1=0;
	return 0;
}