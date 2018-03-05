#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void draw(){
glClearColor(0,0,0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,1.0);

int x,y,x1,y1,x2,y2,dx,dy;
x1=2,y1=2,x2=18,y2=12;
x=x1;
y=y1;
dx=x2-x1;
dy=y2-y1;
int p=2*dy-dx;
while(x<=x2){
if(p<0){
glColor3f(1,1,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
x=x+1;
y=y;
p=p+2*dy;
printf("Decision parameter: %d\n\n",p);
printf("%d,%d\n\n",x,y);
}
else{
glColor3f(1,1,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();

x=x+1;
y=y+1;
p=p+2*(dx-dy);
printf("Decision parameter: %d\n\n",p);
printf("%d,%d\n\n",x,y);
}
}
}



int main(int argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);

glutCreateWindow("BRESENHAM:500044600");
gluOrtho2D(0,20,0,20);
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}

