#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct point
{
	int x;
	int y;
}*p;
typedef struct point po;

float dist(po m,po n)                               //Function to find the Euclidian distance between two nodes
{
    float result;
    result = sqrt((m.x - n.x) * (m.x - n.x) + (m.y - n.y) *(m.y - n.y));
    return result;
}

const char *readLine(FILE *file)                    //Function to extract lines from the text input file in form of string
{

    if (file == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    int maximumLineLength = 128;
    char *lineBuffer = (char *)malloc(sizeof(char) * maximumLineLength);

    if (lineBuffer == NULL) {
        printf("Error allocating memory for line buffer.");
        exit(1);
    }

    char ch = getc(file);
    int count = 0;

    while ((ch != '\n') && (ch != EOF)) {
        if (count == maximumLineLength) {
            maximumLineLength += 128;
            lineBuffer = realloc(lineBuffer, maximumLineLength);
            if (lineBuffer == NULL) {
                printf("Error reallocating space for line buffer.");
                exit(1);
            }
        }
        lineBuffer[count] = ch;
        count++;

        ch = getc(file);
    }

    lineBuffer[count] = '\0';
    char line[count + 1];
    strncpy(line, lineBuffer, (count + 1));
    free(lineBuffer);
    const char *constLine = line;
    return constLine;
}


int main()
{
	FILE *ptr;
	char x[1000],y[1000];
	float d;
	int a=0,b=0,countX=0,countY=0,size=0,i;
	ptr = fopen("coor.txt","r"); //coor is the text file where all the coordinates are stored
    if ((ptr = fopen("coor.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
	//const char *line = readLine(ptr);
	while (!feof(ptr)) 
       {
       	 const char *line = readLine(ptr);
	 if(line[0]=='y')                       // Extracts X coordinates
	 {		
		a=line[2]-48;
		b=line[3]-48;
		if(b!=-2)		
			a=a*10+b;
		y[countY]=a;
		countY++;
	 }
	 else if(line[0]=='x')                 // Extracts Y coordinates     
	 {		
		a=line[2]-48;
		b=line[3]-48;
		a=a*10+b;
		x[countX]=a;
		countX++;
	 }
       }
	p=(po*)malloc((countY-1)*sizeof(po));    // "p" is a structure pointer whose size is being dynamically allocate i.e size = number of nodes present.
	for(i=0;i<=countX-1;i++)
	{
		p[i].x=x[i];                     // The extracted x & y coordinates are stored into array of points.
		p[i].y=y[i];                     
	}
	printf("\n");
	int ch,s1;	
	for(i=0;i<=countY-1;i++)
		printf("NODE%d: %d , %d\n",i+1,p[i].x,p[i].y);
	printf("Enter SINK NODE number\n");
	scanf("%d",&ch);                         // Server node is taken as user input.
	
	for(i=0;i<=countY-1;i++)
	{	
		if((ch)==(i+1))
			continue;
		d=dist(p[ch-1],p[i]);
		printf("Distance between node:%d and node:%d = %f\n",ch,i+1,d);
	}
	return 0;
}













	
