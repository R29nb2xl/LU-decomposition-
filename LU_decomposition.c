
/*LU decomposition*/
#include<stdio.h>
void main()
{ float L[10][10],U[10][10],a[10][10],c[10];
  float z[10],x[10], temp;
  int i,j,k;
  int n;

printf("\n please enter the size of the matrix: ");
scanf("%d", &n);

printf("\n please enter the constant matrix :");
for(i=0;i<n;i++)
{ printf("\n C[%d] = ",i+1);
scanf("%f",&c[i]);}

printf("please enter the elements of lefthand side matrix: ");
printf("\n");
for(i=0;i<n;i++)
{ for(j=0;j<n;j++)
  { printf("\n a [%d] [%d] = ",i+1,j+1);
    scanf("%f",&a[i][j]);}}

for(i=0;i<n;i++) /* it initialises all elements of U and L to zero*/
{ for(j=0;j<n;j++)
  { L[i][j]=0;
    U[i][j]=0;}}

for(j=0;j<n;j++)/*the first row elements of U is re-defined*/
{ U[0][j]=a[0][j];}

for (i=0;i<n;i++)/*all the diagonal elements of L is redefined*/
{ L[i][i]=1;}

for(i=1;i<n;i++)/*elements of first column of L is redefined*/
{ L[i][0]=a[i][0]/U[0][0];}

for(i=1;i<n;i++)/*all other elements of L and U are redefined using modified Dolittle algorithm*/
{ for(j=1;j<n;j++)
  { if(j<i)
    { temp=0;
      for (k=0;k<=j-1;k++)
      { temp=temp+L[i][k]*U[k][j];}
      L[i][j]=(a[i][j]-temp)/U[j][j];}
    else if(j>=i)
    { temp=0;
      for (k=0;k<=i-1;k++)
      { temp=temp+L[i][k]*U[k][j];}
      U[i][j]=a[i][j]-temp; }}}
      
printf("\n The matrix L looks like: "); /* it prints Matrix L */
printf("\n");
for(i=0;i<n;i++)
{ for(j=0;j<n;j++)
  { printf(" %f",L[i][j]);} 
  printf("\n");}
  
printf("\n The matrix U looks like: ");/*it prints Matrix U */
 printf("\n");
for(i=0;i<n;i++)
{ for(j=0;j<n;j++)
  { printf(" %f",U[i][j]);} 
  printf("\n");}
  
z[0]=c[0];/*backword substitution*/
for(i=1;i<n;i++)
{ temp=0;
for(j=0;j<i;j++)
{ temp=temp+L[i][j]*z[j];}
 z[i]=c[i]-temp; }
 
x[n-1]=z[n-1]/U[n-1][n-1];/*forward substitution*/
for(i=n-2;i>=0; i--)
{ temp=0;
for(j=n-1;j>i;j--)
{ temp=temp+U[i][j]*x[j];}
x[i]=(z[i]-temp)/U[i][i];}

printf("\n The solution is: "); /*it prints the solution*/
for (i=0;i<n;i++)
{ printf("\n x[%d] = %f",i+1,x[i]);}}

    
