#include<stdio.h>
#include<GL/glut.h>

float xr=0,yr=0;
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,1);
glBegin(GL_QUADS);
  glVertex2i(200+xr,100+yr);
  glVertex2i(300+xr,100+yr);
  glVertex2i(300+xr,200+yr);
  glVertex2i(200+xr,200+yr);
glEnd();
glutSwapBuffers();
}

void SpecialKey(int key,int x,int y){
switch(key)
{
case GLUT_KEY_UP :
yr++;
glutPostRedisplay();
break;
case GLUT_KEY_DOWN :
yr--;
glutPostRedisplay();
break;
case GLUT_KEY_LEFT :
xr--;
glutPostRedisplay();
break;
case GLUT_KEY_RIGHT :
xr++;
glutPostRedisplay();
break;
}
}

void drawText(const char *text,int length,int x,int y)
{
glMatrixMode(GL_PROJECTION);
double *matrix=new double[16];
glGetDoublev(GL_PROJECTION_MATRIX,matrix);
glLoadIdentity();
glOrtho(0,800,0,600,-5,5);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix;
glLoadIdentity();
glRasterPos2i(x,y);
int i;
for(i=0;i<length;i++){
  glutBitMapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
}
glPopMatrix();
glMatrixMode(GL_PROJECTION);
glLoadMatrixd(matrix);
glMatrixMode(GL_MODELVIEW);
}



int main(int argc,char** argv)
{
printf("Use to moving the object");
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(400,400);
glutInitWindowPosition(600,50);
glutCreateWindow("Moving Objects in OPenGl");
glutDisplayFunc(display);
glClearColor(0,1,0,0);
gluOrtho2D(0.0,400,0.0,400);
glutSpecialFunc(SpecialKey);

glutMainLoop();
return 0;
}


