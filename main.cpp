#include<stdio.h>
#include<graphics.h>
#include<math.h>

//make a windmill with the given x,y points
void wind(float x[7],float y[7]);
//main program code
int main()
{
int gd=DETECT,gm;
//required vertices
float x[7],y[7],maxx,maxy,xw1,yw1,xw2,yw2;
float theta=30;//angle of rotation
initgraph(&gd,&gm," ");
maxx=getmaxx();//get maximum x coordinate
maxy=getmaxy();//get maximum y coordinate
//calculating the midpoint of the window
x[0]=maxx/2;
y[0]=maxy/2;
//making equal distant from x[0] to final blades position
x[1]=y[4]=x[2]=-90;
//making equal distant from y[0] to final blades position
y[6]=y[5]=y[1]=60;
//calculating others blades co-ordinates
y[2]=35;
y[3]=-100;
x[4]=20;
x[3]=0;
x[5]=90;
x[6]=65;
//converting value of theta from degree into radient
theta=theta*22/7/180;

//kbhit funtion returns non-zero value if key is pressed otherwise returns 0
while(kbhit()==0)
{
wind(x,y);
//rotating first blades by theta degree
xw1=cos(theta)*x[1]+sin(theta)*y[1];
yw1=-sin(theta)*x[1]+cos(theta)*y[1];
xw2=cos(theta)*x[2]+sin(theta)*y[2];
yw2=-sin(theta)*x[2]+cos(theta)*y[2];
//assigning new coordinates for first blade
x[1]=xw1;
y[1]=yw1;
x[2]=xw2;
y[2]=yw2;
//rotating second blades by theta degree
xw1=cos(theta)*x[3]+sin(theta)*y[3];
yw1=-sin(theta)*x[3]+cos(theta)*y[3];
xw2=cos(theta)*x[4]+sin(theta)*y[4];
yw2=-sin(theta)*x[4]+cos(theta)*y[4];
//assigning new coordinates for second blade
x[3]=xw1;
y[3]=yw1;
x[4]=xw2;
y[4]=yw2;
//rotating third blades by theta degree
xw1=cos(theta)*x[5]+sin(theta)*y[5];
yw1=-sin(theta)*x[5]+cos(theta)*y[5];
xw2=cos(theta)*x[6]+sin(theta)*y[6];
yw2=-sin(theta)*x[6]+cos(theta)*y[6];
//assigning new coordinates for third blade
x[5]=xw1;
y[5]=yw1;
x[6]=xw2;
y[6]=yw2;
//adding delay of 50
delay(50);
//clearing a device
cleardevice();
}
closegraph();
}

void wind(float x[7],float y[7])
{
cleardevice();
//make a circle at center of the window
circle(x[0],y[0],10);
//make a cone shape for windmill
//make a left line of windmill
setcolor(BROWN);
setfillstyle(5,BLUE);
line(x[0],y[0],x[0]-50,y[0]+200);
//make a right line of windmill
line(x[0],y[0],x[0]+50,y[0]+200);
//draw a bottom line of windmill
line(x[0]-60,y[0]+200,x[0]+60,y[0]+200);
floodfill(x[0],y[0]+10,BROWN);
//making rotating blades as
setcolor(RED);//setting red color for borders
//1st blade
line(x[0],y[0],x[0]+x[1],y[0]-y[1]);
line(x[0],y[0],x[0]+x[2],y[0]-y[2]);
line(x[0]+x[1],y[0]-y[1],x[0]+x[2],y[0]-y[2]);
//2nd blade
line(x[0],y[0],x[0]+x[3],y[0]-y[3]);
line(x[0],y[0],x[0]+x[4],y[0]-y[4]);
line(x[0]+x[3],y[0]-y[3],x[0]+x[4],y[0]-y[4]);
//3rd blade
line(x[0],y[0],x[0]+x[5],y[0]-y[5]);
line(x[0],y[0],x[0]+x[6],y[0]-y[6]);
line(x[0]+x[5],y[0]-y[5],x[0]+x[6],y[0]-y[6]);
}
