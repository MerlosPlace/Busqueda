int liberarvector (int *vector)
{
    free(vector);
     
    return 0;          
}
int * reservarmemoria (int dimension)
{
    int *vector;
     
    if((vector=(int*)calloc((dimension),sizeof(int)))==NULL)
        printf("\nNo hay memoria suficiente\n");
         
    return vector;
}
int * llenarvector (int *vector,int dimension)
{
    int i;
     
    for(i=0;i<dimension;i++)
    {
         vector[i]=rand()%1000;
    }
}
 
void mostrarvector (int *vector,int dimension)
{
     int i;
     printf("\nEl vector es:");
     for (i=0;i<dimension;i++)
     {
         printf("%d;",vector[i]);
     }
}
 
int secuencial (int *vector,int DIM,int buscar)
{
    int i;
    for (i=0;i<DIM;i++)
    {
        if (vector[i]==buscar)
           return i;
    }
    return -1;
     
}
 
int binaria (int *vector,int DIM,int buscar)
{
    int *vector2;
    int i=1,j=DIM,k;
     vector2=ordenarvector(vector,DIM);
     mostrarvector (vector2,DIM);
     while (i<j)
     {
          k=(i+j)/2;
          if (buscar<vector2[k])
              j=k-1;
          else if (buscar==vector2[k])
          {
               i=k;
               j=k;
          }    
          else if(buscar>vector2[k])
               i=k+1;
     }
     if ((i<0)||(i>DIM))
        return -1;
     return i;
      
}
 
int * ordenarvector (int *ordenar,int DIM)
{
    int i,*vector,j,temp;
    vector=reservarmemoria (DIM);
    for(i=0;i<DIM;i++)
    {
        vector[i]=ordenar[i];
    }
    for (i=0;i<DIM-1;i++)
    {
        for(j=DIM-1;j>i;j--)
        {
            if (vector[j]>vector[j+1])
            {
               temp=vector[j+1];
               vector[j+1]=vector[j];
               vector[j]=temp;
            }
        }
    }
    return vector;
}
int binariarecursiva (int *vector,int DIM,int buscar)
{
    int *vector2;
    int i=1,j=DIM,k;
     vector2=ordenarvector(vector,DIM);
     mostrarvector (vector2,DIM);
     if (i>j)
        return 0;
     else
     {   
          k=(i+j)/2;
          if (buscar<vector2[k])
              j=k-1;
          else if (buscar==vector2[k])
          {
               return k;
          }    
          else if(buscar>vector2[k])
               i=k+1;
          return binariarecursiva(vector2,DIM,buscar);
     }     
} 
