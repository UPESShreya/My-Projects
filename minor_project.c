#include<GL/glut.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

static int TriangleHeight[6];//Data Structure to show heights

void drawTriangle()
{
  int a=20, b=60;
  for (int z=0; z<5; z++)
  {// Drawing all the triangles of same base but different height from the array
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f,0.7f,0.3f);
    glVertex2d(a,400);
    glVertex2d(b,400);
    glVertex2d(a,(400-TriangleHeight[z]));
    glEnd();
    glFlush();
    a+=100;//Putting up space
    b+=100;
    printf("%d |", TriangleHeight[z]);
  }
  printf("\n" );
}

void sortTriangle()
{// Use any sorting algorithm here,
  // Using bubble sort
  int key;
  for(int a=0; a<5; a++)
    for(int b=0; b<5-1-a; b++)
    {
      if(TriangleHeight[b]>TriangleHeight[b+1])
      {
        key = TriangleHeight[b+1];
        TriangleHeight[b+1]=TriangleHeight[b];
        TriangleHeight[b]=key;
      }
      usleep(8000);
      drawTriangle();
    }
}

void sortTriangle1()
{
   int key,min=0;
   for(int a=0;a<6;a++){
	min=a;
	for(int b=a+1;b<6;b++){
	    if(TriangleHeight[b]>TriangleHeight[b+1])
      	    {
		min = b;
        	key = TriangleHeight[b+1];
        	TriangleHeight[b+1]=TriangleHeight[b];
        	TriangleHeight[b]=key;
     	     }
        usleep(8000);
        
	}
	drawTriangle();
   }
}

void search()
{
  //Linear search
  int n=100,count=0;
  //scanf("%d",&n);
  printf("Enter the triangle height to search: %d",n);
  int copy[6],num_of_elements,max;
  for(int b=0;b<5;b++)
  {
	copy[b]=TriangleHeight[b];
  }
  int j;
  for(int b=0;b<5;b++)
  {
	printf("%d\n",copy[b]);}

   num_of_elements=2;
   max=0;
   while(num_of_elements < 5)
   {
     for(int i=0;i<5;i++)
	for(j=i+1;j<=5;j++)
	{
	    int count=1;
	    if((5-j)>=(num_of_elements-1))
	    {
	     printf("%d",TriangleHeight[i]);
	     int x=j;
	     if(copy[j]==n){
		usleep(8000);
		drawTriangle();
	     int sum=TriangleHeight[i];
	    }
	
  	
  //drawTriangle();  
  }
  //printf("%d\t",count);
  
}
}
}

void search1()
{
int n=100;
printf("Enter the triangle height to search: %d",n);
int first =0;
int last=5;
int middle=(first+last)/2;
while(first<=last){
 if(TriangleHeight[middle]<n)
	first=middle+1;
 else if (TriangleHeight[middle] == n){
	printf("%d found at location %d\n\n",n,middle+1);
	drawTriangle();
	break;
 }
 else
    last=middle-1;

 middle=(first+last)/2;
 drawTriangle();
}

 if(first > last)
    printf("Not found");

}

	

void myKey(unsigned char key, int x, int y)
{
  if(key==32)// 32 is ASCII code for SPACEBAR
      {
        glClear(GL_COLOR_BUFFER_BIT);
      	glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
        glFlush();
      }
  else if ((key==83)||(key==115))// ASCII code for "S" or "s"
  {
    sortTriangle();
  }
  else if((key==84) || (key==116) ){ //ASCII code for "T" or "t"
	   sortTriangle1();
	}
  else if((key==76) || (key ==108))//ASCII code for "L" or "l"
  {
  	search();
  }
  else if ((key==77) || (key == 109)){
	search1();
  } 
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);// For clearing the screen
  glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
  glFlush();

  const char *str="Press SPACEBAR to clear Screen , 'S' and 'T'to Sort & 'L' and 'M' to search ";
  int j = strlen( str );
  glColor3f(1,1,1);
  glRasterPos2f( 180, 550 );
  for( int i = 0; i < j; i++ )
  {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str[i] );
  }

  const char *str2="Sorting";
  j = strlen( str2 );
  glColor3f( 0.2, 0.5, 1.0 );
  glRasterPos2f( 10, 50 );
  for( int i = 0; i < j; i++ )
  {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
  }

  const char *str3="Searching";
  j=strlen(str3);
  glColor3f(0.5,0.3,0.7);
  glRasterPos2f( 10,10);
  for(int i=0;i<j;i++)
  {
     glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,str3[i] );
  }


  glFlush();
  drawTriangle();
}

int main(int argc, char** argv)
{
  printf("Enter heights of the triange ( 0 to 300):\n");
  for (int z=0; z<6; z++)
    {
      scanf("%d ", &TriangleHeight[z]);
    }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Sort and Search");
  
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  
  gluOrtho2D(0,500,500,0);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
 
  glutMainLoop();
}
