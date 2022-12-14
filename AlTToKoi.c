#include<stdio.h>
#include<stdlib.h>
//Use TURBO C To compile ...BUT FOR ANDROID DEVICE??
   void usage()
{
  printf("Usage:\n");
  printf("alt2koi [-|+cr] infile outfile\n");
  printf("converts infile in ALT coding to outfile in KOI-8 coding\n");
  printf("Options: -cr - remove carrige returns at the ends of lines\n");
  printf(" +cr - add carrige returns at the ends of lines.\n"); 
}

  int main(int argc, char *argv[])
{
   int alt[64]=
  {160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174,
   175, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237,
   238, 239, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
   141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155,
   156, 157, 158, 159};
   int koi[64]=
   {193, 194, 215, 199, 196, 197, 214, 218, 201, 202, 203, 204, 205, 206, 207,
   208, 210, 211, 212, 213, 198, 200, 195, 222, 219, 221, 223, 217, 216, 220,
   192, 209, 225, 226, 247, 231, 228, 229, 246, 250, 233, 234, 235, 236, 237,
   238, 239, 240, 242, 243, 244, 245, 230, 232, 227, 254, 251, 253, 255, 249,
   248, 252, 224, 241};
   int buf;
   int i=1, cr=0;
   FILE *fp, *fq;
   if (argc!=3 && argc!=4)
  {
    usage();
    exit(1);
  }
  if (argc==4)
  {
    i=2;
    if (strcmp(argv[1], "-cr")==0) cr=-1;
    else if (strcmp(argv[1], "+cr")==0) cr=1;
    else
    {
     usage();
     exit(1);
    }
  }
  if ((fp=fopen(argv[i], "rb"))==NULL)
  {
    fprintf(stderr, "Cannot open file %s for reading!\n", argv[i]);
    exit(2);
  }
    if ((fq=fopen(argv[i+1], "wb"))==NULL)
  {
    fprintf(stderr, "Cannot open file %s for writing!\n", argv[i+1]);
    exit(3);
  }
    while ((buf=fgetc(fp))!=EOF)
  {
    if (cr==-1 && buf=='\r') continue;
    if (cr==1 && buf=='\n') fputc('\r', fq);
    if (buf>127)
    {
      for (i=0; (buf!=alt[i]) && (i<64); ++i);
      if (i<64) fputc(koi[i], fq);
      else fputc(buf, fq);
    }
    else fputc(buf, fq);
  }
  return 0;
}
/*
getting an ERROR THEN DEFINE STRCMP :)
FOR ANDROID DEVICE : define strcmp (Simple)  :) 
*/
