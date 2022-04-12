#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define linemax 200
struct csvtype {char *LAT;char *LON;char *o3;char *pubtime;char *outname;};
char *cat_wang(char *str1,char *str2)
{
 char *s1;
 char *s2;
 char *sums;
 sums=(char *)malloc(14*sizeof(char));
 s1=str1;
 s2=str2;
 int i;
 for(i=0;i<6;i++){sums[i]=s1[i];}
 sums[6]=',';
 for(i=7;i<13;i++){sums[i]=s2[i-7];}
 sums[13]=',';
 return sums;
}
char *savename(char *s,char *d)
{
 int i,control;
 control=strlen(s);
 printf("size is %d\n",control);
 d=(char *)malloc(control*sizeof(char));
 for(i=0;i<control;i++){d[i]=s[i];}
 return d;
}
int main()
{
FILE *fp;
int ln=1;
fp=fopen("o3.csv","r");
if(fp!=NULL){printf("read successfully\n");}
char line[linemax];
char *temp;
FILE *outo3;
while(fgets(line,sizeof(line),fp)){
 struct csvtype file_c;
 char *token;
 int i;
 int scani;

 i=0;
 printf("now line[%d] is %s",ln,line);
 token=strtok(line,",");
 
 while(token!=NULL){
  if(i==5){file_c.LAT=token;}
  if(i==6){file_c.LON=token;}
  if(i==11){file_c.o3=token;}
  if(i==15){file_c.pubtime=token;}
  token=strtok(NULL,",");
  i++;
  }
  file_c.outname=cat_wang(file_c.LAT,file_c.LON);
  
  printf(",so the LAT,LON, is : %s o3 is : %s pubtime is : %ss    \n" ,file_c.outname,file_c.o3,file_c.pubtime);
  if (temp==NULL){temp=savename(file_c.outname,temp);printf("<<notice now temp is empty give a name %s>>\n ",temp);}
  for(scani=0;scani<strlen(file_c.outname);scani++){
  if(temp[scani]!=file_c.outname[scani]){
    printf("<<the content is different from line change from %s to %s>>\n",temp,file_c.outname);
    temp=savename(file_c.outname,temp);
    break;}
    }
  file_c.pubtime[10]='_';
  outo3=fopen(temp,"a");
  if(outo3!=NULL){printf("open successful\n");}
// fseek(outo3,0,SEEK_END);
  fprintf(outo3,"%s%s,%s",file_c.outname,file_c.o3,file_c.pubtime);
 
  ln++; 
  fclose(outo3);
 }

return 0;
}
