#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

int height=600,width=600;
float a[2][2];
int i=0,c,d,dst;
char k;
void myMouse(int,int,int,int);
void myKeyboard(unsigned char,int,int);
void circle_mid(float,int,int);
void points(int,int);
float radius();
void show();
void display();

void myMouse(int button,int state,int x,int y){
if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
a[i][0]=x-300;
a[i][1]=300-y;
printf("THe x coordinates=%d, the y coordinate =%d\n\n",x-300,300-y);
show();
i++;
}
}

void myKeyboard(unsigned char Key,int x,int y)
{
k=Key;
glutPostRedisplay();
}

void circle_mid(float dp,int x,int y)
{
if(x<=y){
if(dp<0){
if(x==0)
{
printf("The initial point is :%d %d\n\n",x,y);
points(x,y);
points(y,x);
points(x,-y);
points(-y,x);
circle_mid(dp,x+1,y);
}

else
{
printf("The point is %d%d\n",x,y);
printf("The decision parameter is: %f\n\n",dp);
points(x,y);
points(x,-y);
points(-x,-y);
points(-x,y);
points(y,x);
points(y,-x);
points(-y,x);
points(-y,-x);
circle_mid(dp+(2*x)+1,x+1,y);
}
}
else
{
printf("The point is %d%d\n",x,y);
printf("The decision parameter is: %f\n\n",dp);
points(x,y);
points(x,-y);
points(-x,-y);
points(-x,y);
points(y,x);
points(y,-x);
points(-y,x);
points(-y,-x);
circle_mid(dp+(2*x)-(2*y)+1,x+1,y-1);
}
}
}


void points(int x,int y)
{
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(x,y);
glEnd();
glFlush();
}

float radius()
{
int dx,dy;
dx=pow(a[1][0]-a[0][0],2);
dy=pow(a[1][1]-a[0][1],2);
dst=sqrt(dx+dy);
printf("The radius is: %d\n",dst);
return(0.0);
}

void show()
{
glPointSize(3);
glBegin(GL_POINTS);
glColor4f(1,0,0,1);
glVertex2f(a[i][0],a[i][1]);
glEnd();
glFlush();
}

void display()
{
glClearColor(1,1,0,1);
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
switch(k){
case 109:
radius();
float p=1-dst;
printf("P0 is %f\n",p);
circle_mid(p,a[0][0],a[0][1]+dst);
}
}



int main(int argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutCreateWindow("Mouse click:500045306");
gluOrtho2D(-width/2,width/2,-height/2,height/2);
glutDisplayFunc(display);
glutMouseFunc(myMouse);
glutKeyboardFunc(myKeyboard);
glutMainLoop();
return 0;
}


